using dmanager;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace George_s_Car_Rental.Classes
{
    public class GadgetsData
    {
        private ObservableCollection<Objects.Gadget> gadgets = new ObservableCollection<Objects.Gadget>();
        private MySqlManagement manager;

        public GadgetsData()
        {
            manager = new MySqlManagement();
        }
        public void createGadgetsData()
        {

            var dataset = manager.GetData("*", "gadgets").Tables["gadgets"];

            for (var i = 0; i < dataset.Rows.Count; i++)
            {
                //Retrieve the store info 
                int gID = (int)dataset.Rows[i][0];

                byte[] imgData = { 0 };
                try
                {
                    imgData = (byte[])dataset.Rows[i][1];
                }
                catch (Exception)
                {


                }

                BitmapImage gImage = new BitmapImage();
                if (imgData.Length > 1)
                {
                    using (var stream = new MemoryStream(imgData))
                    {
                        gImage.BeginInit();
                        gImage.StreamSource = stream;
                        gImage.CacheOption = BitmapCacheOption.OnLoad;
                        try
                        {
                            gImage.EndInit();
                        }
                        catch (NotSupportedException ex)
                        {
                            Globals.errorMessage = ex.Message;
                        }
                        gImage.Freeze();
                    }
                }

                var gName = dataset.Rows[i][2].ToString();
                var gDescription = dataset.Rows[i][3].ToString();
                var gPrice = (double)dataset.Rows[i][4];
                var gCarID = (int)dataset.Rows[i][5];
                var gStoreID = (int)dataset.Rows[i][6];
                var gQuantityAvailable = (int)dataset.Rows[i][7];

                Objects.Gadget c = new Objects.Gadget()
                {
                    ID = gID,
                    StoreID = gStoreID,
                    CarID = gCarID,
                    Price = gPrice,
                    Name = gName,
                    ItemDescription = gDescription,
                    QuantityAvailable = gQuantityAvailable
                };

                if (imgData.Length > 1)
                    c.Image = gImage;
                gadgets.Add(c);
            }
        }

        public ObservableCollection<Objects.Gadget> getGadgets()
        {
            gadgets.Clear();
            createGadgetsData();
            return gadgets;
        }
    }
}
