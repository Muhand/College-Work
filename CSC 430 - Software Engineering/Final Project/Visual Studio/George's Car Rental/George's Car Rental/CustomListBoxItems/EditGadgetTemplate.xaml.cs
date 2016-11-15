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
    /// Interaction logic for EditGadgetTemplate.xaml
    /// </summary>
    public partial class EditGadgetTemplate : UserControl
    {
        private double origWidth;
        private double origHeight;

        public static readonly DependencyProperty GadgetImageProperty =
DependencyProperty.Register("GadgetImage", typeof(BitmapImage), typeof(EditGadgetTemplate), new UIPropertyMetadata(new BitmapImage(new Uri("../Images/NoPhoto.png", UriKind.Relative))));

        public BitmapImage GadgetImage
        {
            get { return (BitmapImage)GetValue(GadgetImageProperty); }
            set { SetValue(GadgetImageProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetTitleProperty =
DependencyProperty.Register("GadgetTitle", typeof(string), typeof(EditGadgetTemplate), new UIPropertyMetadata(null));

        public string GadgetTitle
        {
            get { return (string)GetValue(GadgetTitleProperty); }
            set { SetValue(GadgetTitleProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetDescriptionProperty =
DependencyProperty.Register("GadgetDescription", typeof(string), typeof(EditGadgetTemplate), new UIPropertyMetadata(null));

        public string GadgetDescription
        {
            get { return (string)GetValue(GadgetDescriptionProperty); }
            set { SetValue(GadgetDescriptionProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetInfoProperty =
DependencyProperty.Register("GadgetInfo", typeof(string), typeof(EditGadgetTemplate), new UIPropertyMetadata(null));

        public string GadgetInfo
        {
            get { return (string)GetValue(GadgetInfoProperty); }
            set { SetValue(GadgetInfoProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetPriceProperty =
DependencyProperty.Register("GadgetPrice", typeof(double), typeof(EditGadgetTemplate), new UIPropertyMetadata(null));

        public double GadgetPrice
        {
            get { return (double)GetValue(GadgetPriceProperty); }
            set { SetValue(GadgetPriceProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetProperty =
DependencyProperty.Register("Gadget", typeof(Objects.Gadget), typeof(EditGadgetTemplate), new UIPropertyMetadata(null));

        public Objects.Gadget Gadget
        {
            get { return (Objects.Gadget)GetValue(GadgetProperty); }
            set { SetValue(GadgetProperty, value); }
        }

        //////////////////////////////////////////////////////////////////////////////////////////////

        public EditGadgetTemplate()
        {
            InitializeComponent();
        }

        private void UpdateCart_Click(object sender, RoutedEventArgs e)
        {
            if (quantity.NumValue <= 0)
            {
                Classes.Globals.errorMessage = "You can't have a quantity of 0.\nIf you would like to remove the item, please remove it by pressing the 'X' button on the top right corner of the item.";
                return;
            }

            //Rmove the item
            Objects.Gadget newGadget = Gadget;
            switch (Classes.Globals.cart.removeItemFromCart(Gadget))
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
            newGadget.setQuantityToPurchase(quantity.NumValue);
            
            Classes.Globals.cart.addItemToCart(newGadget);
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
            RemoveItem.Width = origWidth - ((5 * origWidth) / 100);
            RemoveItem.Height = origHeight - ((5 * origHeight) / 100);
            switch (Classes.Globals.cart.removeItemFromCart(Gadget))
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
        private void EditGadgetListBoxItem_Loaded(object sender, RoutedEventArgs e)
        {
            quantity.NumValue = Gadget.QuantityToPurchase;
        }
    }
}
