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
    public class CarsData
    {
        private ObservableCollection<Objects.Car> cars = new ObservableCollection<Objects.Car>();
        private MySqlManagement manager;

        public CarsData()
        {
            manager = new MySqlManagement();
        }

        public void createCarsData()
        {

            var dataset = manager.GetData("*", "cars").Tables["cars"];

            for (var i = 0; i < dataset.Rows.Count; i++)
            {
                //Retrieve the store info 
                int cID = (int)dataset.Rows[i][0];
                byte[] imgData = { 0 };
                try
                {
                    imgData = (byte[])dataset.Rows[i][1];
                }
                catch (Exception)
                {


                }

                BitmapImage cImage = new BitmapImage();
                if (imgData.Length > 1)
                {
                    using (var stream = new MemoryStream(imgData))
                    {
                        cImage.BeginInit();
                        cImage.StreamSource = stream;
                        cImage.CacheOption = BitmapCacheOption.OnLoad;
                        try
                        {
                            cImage.EndInit();
                        }
                        catch (NotSupportedException)
                        {
                            
                        }
                        
                        cImage.Freeze();
                    }
                }

                var cMake = dataset.Rows[i][2].ToString();
                var cModel = dataset.Rows[i][3].ToString();
                var cYear = dataset.Rows[i][4].ToString();
                var cCondition = dataset.Rows[i][5].ToString();
                var cMileage = dataset.Rows[i][6].ToString();
                var cType = dataset.Rows[i][7].ToString();
                var cAvailability = dataset.Rows[i][8].ToString();
                var cPriceperday = (double)dataset.Rows[i][9];
                var cStoreID = (int)dataset.Rows[i][10];
                var cDescription = dataset.Rows[i][11].ToString();
                var cQuantityAvailable = (int)dataset.Rows[i][12];
                Objects.Car c = new Objects.Car()
                {
                 ID = cID,
                 StoreID = cStoreID,
                 Make = cMake,
                 Model = cModel,
                 Year = cYear,
                 Condition = cCondition,
                 Mileage = cMileage,
                 Type = cType,
                 Availability = cAvailability,
                 PricePerDay = cPriceperday,
                 ItemDescription = cDescription,
                 QuantityAvailable = cQuantityAvailable
                };

                if (imgData.Length > 1)
                    c.Image = cImage;
                cars.Add(c);
            }
        }

        public ObservableCollection<Objects.Car> getCars()
        {
            cars.Clear();
            createCarsData();
            return cars;
        }

    }
}
