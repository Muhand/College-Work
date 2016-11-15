using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace George_s_Car_Rental.Objects
{
    public class Gadget : CartItem
    {
        public int ID { get; set; }
        public int CarID { set; get; }
        public int StoreID { set; get; }
        public BitmapImage Image { get; set; }
        public string Name { get; set; }
        
        public Gadget()
        {
            ID = 0;
            CarID = 0;
            StoreID = 0;
            Image = new BitmapImage(new Uri("../Images/NoPhoto.png", UriKind.Relative));
            Name = "Unknown";
        }
        public Gadget(BitmapImage image, string name, int carID, int storeID, double price)
        {
            init(image, name, carID, storeID, price);
        }

        public Gadget(BitmapImage image, string name, int carID, int storeID, double price, string description)
        {
            init(image, name, carID, storeID, price);
            ItemDescription = description;
        }

        private void init(BitmapImage image, string name, int carID, int storeID, double price)
        {
            Image = image;
            Name = name;
            CarID = carID;
            StoreID = storeID;
            Price = price;
            ItemTitle = getTitle();
            ItemInfo = getGadgetInfo();
        }

        public string getTitle()
        {
            return String.Format("{0}", Name);
        }
        public string getGadgetInfo()
        {
            return String.Format("Price: ${0}", Price);
        }
    }
}
