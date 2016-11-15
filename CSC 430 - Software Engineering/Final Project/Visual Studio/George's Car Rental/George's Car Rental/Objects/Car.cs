using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace George_s_Car_Rental.Objects
{
    public class Car : CartItem
    {
        public int ID { get; set; }
        public int StoreID { set; get; }
        public BitmapImage Image { get; set; }
        public string Make { get; set; }
        public string Model { get; set; }
        public string Year { get; set; }
        public string Condition { get; set; }
        public string Mileage { get; set; }
        public string Type { get; set; }
        public string Availability { get; set; }
        public double PricePerDay { get; set; }
        public int RentForHowManyDays { private set; get; }
        
        public Car()
        {
            ID = 0;
            StoreID = 0;
            Image = new BitmapImage(new Uri("../Images/NoPhoto.png", UriKind.Relative));
            Make = "Unknown";
            Model = "Unknown";
            Year = "Unknown";
            Condition = "Unknown";
            Mileage = "Unknown";
            Type = "Unknown";
            Availability = "Unknown";
            PricePerDay = 0.0;
            RentForHowManyDays = 0;
        }
        public Car(BitmapImage image, string make, string model, string year, string condition, string mileage, string type, string availability, double priceperday, int storeID, string description)
        {
            init(image, make, model, year, condition, mileage, type, availability, priceperday, storeID);
            ItemDescription = description;
        }
        public Car(BitmapImage image, string make, string model, string year, string condition, string mileage, string type, string availability, double priceperday, int storeID, int rentForHowManyDays)
        {
            init(image, make, model, year, condition, mileage, type, availability, priceperday, storeID);
            setRentForHowManyDays(rentForHowManyDays);
        }

        public Car(BitmapImage image, string make, string model, string year, string condition, string mileage, string type, string availability, double priceperday, int storeID, int rentForHowManyDays, string description)
        {
            init(image, make, model, year, condition, mileage, type, availability, priceperday, storeID);
            setRentForHowManyDays(rentForHowManyDays);
            ItemDescription = description;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="image"></param>
        /// <param name="make"></param>
        /// <param name="model"></param>
        /// <param name="year"></param>
        /// <param name="condition"></param>
        /// <param name="mileage"></param>
        /// <param name="type"></param>
        /// <param name="availability"></param>
        /// <param name="priceperday"></param>
        /// <param name="storeID"></param>
        public void init(BitmapImage image, string make, string model, string year, string condition, string mileage, string type, string availability, double priceperday, int storeID)
        {
            Image = image;
            Make = make;
            Model = model;
            Year = year;
            Condition = condition;
            Mileage = mileage;
            Type = type;
            Availability = availability;
            PricePerDay = priceperday;
            ID = 0;
            StoreID = storeID;
            ItemInfo = getCarInfo();
            ItemTitle = getTitle();
        }

        public void setRentForHowManyDays(int howmanydays)
        {
            RentForHowManyDays = howmanydays;
            Price = PricePerDay * RentForHowManyDays;
        }

        public string getTitle()
        {
            return String.Format("{0}, {1}, {2}",Year,Make,Model);
        }
        public string getCarInfo()
        {
            return String.Format("Condition: {0}\tMileage: {1}\tType: {2}\nAvailability: {3}\tPrice Per Day: ${4}", Condition,Mileage,Type,Availability,PricePerDay);
        }

    }
}
