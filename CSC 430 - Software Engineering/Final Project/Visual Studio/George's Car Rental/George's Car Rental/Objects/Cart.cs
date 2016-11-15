using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace George_s_Car_Rental.Objects
{
    public class Cart
    {

        ///////////////////////////////////////////
        //Private Data Members
        ///////////////////////////////////////////
        //Constants
        private const int MAX_ITEMS_IN_CART = 100;
        private const double TAX_RATE = 8.75;

        //Variables
        private List<Car> _cars;
        private List<Gadget> _gadgets;
        private List<CartItem> _allItems;
        private double _totalItemsPrice;
        private double _carsTotal;
        private double _gadgetsTotal;
        private double _totalBeforeTax;
        private double _estimatedTax;
        private double _orderTotal;
        private int _totalItemsInCart;

        public int TotalItemsInCart
        {
            get { return _totalItemsInCart; }
            set { _totalItemsInCart = value; }
        }
        private int _totalCarsInCart;
        private int _totalGadgetsInCart;


        public List<CartItem> AllItems
        {
            get { return _allItems; }
            private set { _allItems = value; }
        }

        public List<Car> Cars
        {
            get { return _cars; }
            private set { _cars = value; }
        }

        public List<Gadget> Gadgets
        {
            get { return _gadgets; }
            private set { _gadgets = value; }
        }
        public double TotalItemsPrice
        {
            get { return _totalItemsPrice; }
            set { _totalItemsPrice = value; }
        }
        public double TotalBeforeTax
        {
            get { return _totalBeforeTax; }
            set { _totalBeforeTax = value; }
        }

        public double EstimatedTax
        {
            get { return _estimatedTax; }
            set { _estimatedTax = value; }
        }

        public double OrderTotal
        {
            get { return _orderTotal; }
            set { _orderTotal = value; }
        }

        public double CarsTotal
        {
            get { return _carsTotal; }
            set { _carsTotal = value; }
        }

        public double GadgetsTotal
        {
            get { return _gadgetsTotal; }
            set { _gadgetsTotal = value; }
        }
        public Cart()
        {
            init();
        }
        private void init()
        {
            _cars = new List<Car>();
            _gadgets = new List<Gadget>();
            _allItems = new List<CartItem>();
            TotalItemsPrice = 0.0;
            TotalBeforeTax = 0.0;
            EstimatedTax = 0.0;
            OrderTotal = 0.0;
            TotalItemsInCart = 0;
            _totalCarsInCart = 0;
            _totalGadgetsInCart = 0;
            _carsTotal = 0;
            _gadgetsTotal = 0;
        }

        public bool isEmpty()
        {
            return TotalItemsInCart == 0;
        }

        private bool isFull()
        {
            return TotalItemsInCart > MAX_ITEMS_IN_CART;
        }

        public bool itemExist(CartItem item)
        {
            for (int i = 0; i < _allItems.Count; i++)
            {
                if (_allItems[i] == item)
                    return true;
            }

            return false;
        }

        public void updateCart()
        {
            TotalItemsPrice = 0.0;
            TotalBeforeTax = 0.0;
            EstimatedTax = 0.0;
            OrderTotal = 0.0;
            TotalItemsInCart = 0;
            _totalCarsInCart = 0;
            _totalGadgetsInCart = 0;
            _carsTotal = 0;
            _gadgetsTotal = 0;

            foreach (var item in _allItems)
            {
                updateCart(item);
                TotalItemsInCart += item.QuantityToPurchase;

                if (item is Car)
                    _totalCarsInCart += item.QuantityToPurchase;
                else if (item is Gadget)
                    _totalGadgetsInCart += item.QuantityToPurchase;
            }
            Classes.Globals.cartQuantity = TotalItemsInCart;
        }
        private void updateCart(CartItem item)
        {
            item.TotalPrice = item.QuantityToPurchase * item.Price;
            TotalItemsPrice += item.TotalPrice;
            TotalBeforeTax += item.TotalPrice;
            EstimatedTax = (TAX_RATE * TotalBeforeTax)/100.00;
            OrderTotal = TotalBeforeTax + EstimatedTax;

            if (item is Car)
                CarsTotal += item.TotalPrice;
            else if (item is Gadget)
                GadgetsTotal += item.TotalPrice;
        }

        public enums.InsertToCart addItemToCart(CartItem item)
        {

            //If cart is full
            if (isFull())
                return enums.InsertToCart.CartIsFull;

  
            if (!itemExist(item))
            {
                //If item wasn't found
                if (item is Car)
                {
                    Car c = (Car)item;
                    _cars.Add(c);
                    _totalCarsInCart += c.QuantityToPurchase;
                }
                else if (item is Gadget)
                {
                    Gadget g = (Gadget)item;
                    _gadgets.Add(g);
                    _totalGadgetsInCart += g.QuantityToPurchase;
                }
                else
                    return enums.InsertToCart.UnknownError;

                _allItems.Add(item);
                
            }

            TotalItemsInCart += item.QuantityToPurchase;
            Classes.Globals.cartQuantity = TotalItemsInCart;
            updateCart(item);

            return enums.InsertToCart.Success;
        }

        public enums.RemoveFromCart removeItemFromCart(CartItem item)
        {

            if (isEmpty())
                return enums.RemoveFromCart.CartIsEmpty;

            for (int i = 0; i < _allItems.Count; i++)
            {
                if(_allItems[i] == item)
                {
                    _allItems.RemoveAt(i);
                    if (item is Car)
                    {
                        Car c = (Car)item;
                        Cars.Remove(c);
                    }
                    else if (item is Gadget)
                    {
                        Gadget g = (Gadget)item;
                        Gadgets.Remove(g);
                    }
                    updateCart();
                    return enums.RemoveFromCart.Success;
                }
            }


            return enums.RemoveFromCart.DoesntExist;
        }

        public void clearCart()
        {
            init();
            Classes.Globals.cartQuantity = 0;
        }

    }
}
