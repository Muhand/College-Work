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
    /// Interaction logic for EditCarTemplate.xaml
    /// </summary>
    public partial class EditCarTemplate : UserControl
    {
        private double origWidth;
        private double origHeight;
        public static readonly DependencyProperty CarImageProperty =
DependencyProperty.Register("CarImage", typeof(BitmapImage), typeof(EditCarTemplate), new UIPropertyMetadata(new BitmapImage(new Uri("../Images/NoPhoto.png", UriKind.Relative))));

        public BitmapImage CarImage
        {
            get { return (BitmapImage)GetValue(CarImageProperty); }
            set { SetValue(CarImageProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty CarTitleProperty =
DependencyProperty.Register("CarTitle", typeof(string), typeof(EditCarTemplate), new UIPropertyMetadata(null));

        public string CarTitle
        {
            get { return (string)GetValue(CarTitleProperty); }
            set { SetValue(CarTitleProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty CarDescriptionProperty =
DependencyProperty.Register("CarDescription", typeof(string), typeof(EditCarTemplate), new UIPropertyMetadata(null));

        public string CarDescription
        {
            get { return (string)GetValue(CarDescriptionProperty); }
            set { SetValue(CarDescriptionProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty CarInfoProperty =
DependencyProperty.Register("CarInfo", typeof(string), typeof(EditCarTemplate), new UIPropertyMetadata(null));

        public string CarInfo
        {
            get { return (string)GetValue(CarInfoProperty); }
            set { SetValue(CarInfoProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty CarProperty =
DependencyProperty.Register("Car", typeof(Objects.Car), typeof(EditCarTemplate), new UIPropertyMetadata(null));

        public Objects.Car Car
        {
            get { return (Objects.Car)GetValue(CarProperty); }
            set { SetValue(CarProperty, value); }
        }

        //////////////////////////////////////////////////////////////////////////////////////////////


        public EditCarTemplate()
        {
            InitializeComponent();
            //quantity.NumValue = Car.QuantityToPurchase;
        }

        private void UpdateCart_Click(object sender, RoutedEventArgs e)
        {

            if (quantity.NumValue <= 0 || days.NumValue <= 0)
            {
                Classes.Globals.errorMessage = "You can't have a quantity of 0.\nIf you would like to remove the item, please remove it by pressing the 'X' button on the top right corner of the item.";
                return;
            }

            //Rmove the item
            Objects.Car newCar = Car;
            switch (Classes.Globals.cart.removeItemFromCart(Car))
            {
                case enums.RemoveFromCart.CartIsEmpty:
                    Classes.Globals.errorMessage = "Cart is empty.";
                    break;
                case enums.RemoveFromCart.DoesntExist:
                    Classes.Globals.errorMessage = "Item doesn't exist.";
                    break;
                default:
                    break;
            }

            Classes.Globals.errorMessage = string.Empty;
            newCar.setQuantityToPurchase(quantity.NumValue);
            newCar.setRentForHowManyDays(days.NumValue);

            Classes.Globals.cart.addItemToCart(newCar);
            //And reinsert

            Classes.Globals.mainWindow.mainFrame.Navigate(new Pages.ViewCart());
        }

        private void Grid_MouseEnter(object sender, MouseEventArgs e)
        {
            RemoveItem.Background = new SolidColorBrush(Colors.LightGray);

        }

        private void Grid_MouseLeave(object sender, MouseEventArgs e)
        {
            RemoveItem.Background = new SolidColorBrush(Colors.Transparent);

        }

        private void Grid_MouseDown(object sender, MouseButtonEventArgs e)
        {
           
            origHeight = RemoveItem.Height;
            origWidth = RemoveItem.Width;
            RemoveItem.Width = origWidth - ((5*origWidth)/100);
            RemoveItem.Height = origHeight - ((5 * origHeight) / 100);
            switch ( Classes.Globals.cart.removeItemFromCart(Car))
            {
                case enums.RemoveFromCart.CartIsEmpty:
                    Classes.Globals.errorMessage = "Cart is empty.";
                    break;
                case enums.RemoveFromCart.DoesntExist:
                    Classes.Globals.errorMessage = "Item doesn't exist.";
                    break;
                case enums.RemoveFromCart.Success:
                    Classes.Globals.cart.updateCart();
                    Classes.Globals.mainWindow.mainFrame.Navigate(new Pages.ViewCart());
                    Classes.Globals.errorMessage = string.Empty;
                    break;
                default:
                    break;
            }
        }

        private void Grid_MouseUp(object sender, MouseButtonEventArgs e)
        {
            RemoveItem.Width = origWidth;
            RemoveItem.Height = origHeight;
        }

        private void EditCarListBoxItem_Loaded(object sender, RoutedEventArgs e)
        {
            quantity.NumValue = Car.QuantityToPurchase;
            days.NumValue = Car.RentForHowManyDays;
        }
    }
}
