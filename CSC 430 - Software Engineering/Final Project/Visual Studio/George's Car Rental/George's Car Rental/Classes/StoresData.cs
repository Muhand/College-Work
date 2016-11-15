using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using dmanager;
using System.Collections.ObjectModel;
using System.Windows.Media.Imaging;
using System.IO;

namespace George_s_Car_Rental.Classes
{
    public class StoresData
    {
        private ObservableCollection<Objects.Store> stores = new ObservableCollection<Objects.Store>();
        private MySqlManagement manager;
        
        public StoresData()
        {
            manager = new MySqlManagement();
        }

        public void createStoresData()
        {

            var dataset = manager.GetData("*", "stores").Tables["stores"];

            for (var i = 0; i < dataset.Rows.Count; i++)
            {
                //Retrieve the store info 
                int sID = (int)dataset.Rows[i][0];
                byte[] imgData = {0};
                try
                {
                    imgData = (byte[])dataset.Rows[i][1];
                }
                catch (Exception)
                {
                    
                
                }
               
                BitmapImage sImage = new BitmapImage();
                if (imgData.Length > 1)
                {
                    using (var stream = new MemoryStream(imgData))
                    {
                        sImage.BeginInit();
                        sImage.StreamSource = stream;
                        sImage.CacheOption = BitmapCacheOption.OnLoad;

                        try
                        {
                            sImage.EndInit();
                        }
                        catch (Exception ex)
                        {
                            
                        }
                        sImage.Freeze();
                    }
                }
                
                var sName = dataset.Rows[i][2].ToString();
                var sFirstStreet = dataset.Rows[i][3].ToString();
                var sSecondStreet = dataset.Rows[i][4].ToString();
                var sCity = dataset.Rows[i][5].ToString();
                var sState = dataset.Rows[i][6].ToString();
                var sCountry = dataset.Rows[i][7].ToString();
                var sZip = dataset.Rows[i][8].ToString();

                Objects.Store s = new Objects.Store()
                {
                    ID = sID,
                    Name = sName,
                    Street = sFirstStreet,
                    SecondStreet = sSecondStreet,
                    City = sCity,
                    State = sState,
                    Country = sCountry,
                    ZipCode = sZip
                };
                if (imgData.Length > 1)
                    s.Image = sImage;
                stores.Add(s);
            }
        }

        public ObservableCollection<Objects.Store> getStores()
        {
            stores.Clear();
            createStoresData();
            return stores;
        }
    }
}
