using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace George_s_Car_Rental.Objects
{
    public class CartItem
    {
        public double Price
        {
            set;
            get;
        }
        public double TotalPrice
        {
            set;
            get;
        }
        public string ItemTitle
        {
            set;
            get;
        }
        public string ItemInfo
        {
            set;
            get;
        }
        public string ItemDescription
        {
            set;
            get;
        }

        public int QuantityAvailable
        {
            set;
            get;
        }

        public int QuantityToPurchase
        {
            private set;
            get;
        }


        public CartItem()
        {
            Price = 0.0;
            ItemDescription = "No description available.\n";
            QuantityAvailable = 0;
            QuantityToPurchase = 0;
            TotalPrice = 0;
        }

        public CartItem(double price, string desc, int quantityAvailable, int quantityToPurchase)
        {
            Price = price;
            ItemDescription = desc;
            QuantityAvailable = quantityAvailable;
            setQuantityToPurchase(quantityToPurchase);
            TotalPrice = Price * QuantityAvailable;
        }

        public bool setQuantityToPurchase(int quantity)
        {
            if (quantity > QuantityAvailable)
                return false;
            else
            {
                QuantityToPurchase = quantity;
                //TotalPrice = Price * quantity;
                return true;
            }
        }

    }
}
