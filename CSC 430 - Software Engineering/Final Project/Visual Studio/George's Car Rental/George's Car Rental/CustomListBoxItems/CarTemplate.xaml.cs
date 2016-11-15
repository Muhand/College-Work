using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace George_s_Car_Rental.CustomListBoxItems
{
    /// <summary>
    /// Interaction logic for CarTemplate.xaml
    /// </summary>
    public partial class CarTemplate : UserControl
    {
        public static readonly DependencyProperty CarImageProperty =
DependencyProperty.Register("CarImage", typeof(BitmapImage), typeof(CarTemplate), new UIPropertyMetadata(new BitmapImage(new Uri("../Images/NoPhoto.png", UriKind.Relative))));

        public BitmapImage CarImage
        {
            get { return (BitmapImage)GetValue(CarImageProperty); }
            set { SetValue(CarImageProperty, value); }
        }
        
        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty CarTitleProperty =
DependencyProperty.Register("CarTitle", typeof(string), typeof(CarTemplate), new UIPropertyMetadata(null));

        public string CarTitle
        {
            get { return (string)GetValue(CarTitleProperty); }
            set { SetValue(CarTitleProperty, value); }
        }
        
        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty CarDescriptionProperty =
DependencyProperty.Register("CarDescription", typeof(string), typeof(CarTemplate), new UIPropertyMetadata(null));

        public string CarDescription
        {
            get { return (string)GetValue(CarDescriptionProperty); }
            set { SetValue(CarDescriptionProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty CarInfoProperty =
DependencyProperty.Register("CarInfo", typeof(string), typeof(CarTemplate), new UIPropertyMetadata(null));

        public string CarInfo
        {
            get { return (string)GetValue(CarInfoProperty); }
            set { SetValue(CarInfoProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty CarProperty =
DependencyProperty.Register("Car", typeof(Objects.Car), typeof(CarTemplate), new UIPropertyMetadata(null));

        public Objects.Car Car
        {
            get { return (Objects.Car)GetValue(CarProperty); }
            set { SetValue(CarProperty, value); }
        }

        //////////////////////////////////////////////////////////////////////////////////////////////

        public CarTemplate()
        {
            InitializeComponent();
        }

        private void AddToCart_Click(object sender, RoutedEventArgs e)
        {
            int quant = quantity.NumValue;
            //var cart = Classes.Globals.Cart;
            //bool found = false;

            quantityLabel.Foreground = new SolidColorBrush(Colors.Black);

            if (quant > 0)
            {
                Classes.Globals.errorMessage = string.Empty;
                if (quant > Car.QuantityAvailable)
                    Classes.Globals.errorMessage = "Too many quantities, this item's max available quantity is: " + Car.QuantityAvailable;
                else
                {
                    Classes.Globals.errorMessage = string.Empty;
                    Car.setRentForHowManyDays(days.NumValue);
                    Car.setQuantityToPurchase(quant);

                    switch (Classes.Globals.cart.addItemToCart(Car))
                    {
                        case enums.InsertToCart.CartIsFull:
                            Classes.Globals.errorMessage = "Cart is full.";
                            break;
                        case enums.InsertToCart.UnknownError:
                            Classes.Globals.errorMessage = "Unknown Error.";
                            break;
                        default:
                            break;
                    }
                    //for (int i = 0; i < cart.Count; i++)
                    //{
                    //    if (cart[i] == Car)
                    //    {
                    //        cart[i].setQuantityToPurchase(cart[i].QuantityToPurchase + quant);
                    //        Classes.Globals.cartQuantity += quant;
                    //        found = true;
                    //        break;
                    //    }
                    //}

                    //if (!found)
                    //{
                    //    Car.setQuantityToPurchase(quant);
                    //    Classes.Globals.Cart.Add(Car);
                    //    Classes.Globals.cartQuantity += quant;
                    //}

                }
            }
            else if (quant < 0)
            {
                quantityLabel.Foreground = new SolidColorBrush(Colors.Red);
                Classes.Globals.errorMessage = "Sorry, you can't have items less than 0.";
            }
        }


    }
}
