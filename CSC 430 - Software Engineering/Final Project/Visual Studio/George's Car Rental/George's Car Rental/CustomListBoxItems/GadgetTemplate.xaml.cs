using System;
using System.Collections.Generic;
using System.Diagnostics;
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
    /// Interaction logic for GadgetTemplate.xaml
    /// </summary>
    public partial class GadgetTemplate : UserControl
    {
        public static readonly DependencyProperty GadgetImageProperty =
DependencyProperty.Register("GadgetImage", typeof(BitmapImage), typeof(GadgetTemplate), new UIPropertyMetadata(new BitmapImage(new Uri("../Images/NoPhoto.png", UriKind.Relative))));

        public BitmapImage GadgetImage
        {
            get { return (BitmapImage)GetValue(GadgetImageProperty); }
            set { SetValue(GadgetImageProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetTitleProperty =
DependencyProperty.Register("GadgetTitle", typeof(string), typeof(GadgetTemplate), new UIPropertyMetadata(null));

        public string GadgetTitle
        {
            get { return (string)GetValue(GadgetTitleProperty); }
            set { SetValue(GadgetTitleProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetDescriptionProperty =
DependencyProperty.Register("GadgetDescription", typeof(string), typeof(GadgetTemplate), new UIPropertyMetadata(null));

        public string GadgetDescription
        {
            get { return (string)GetValue(GadgetDescriptionProperty); }
            set { SetValue(GadgetDescriptionProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetInfoProperty =
DependencyProperty.Register("GadgetInfo", typeof(string), typeof(GadgetTemplate), new UIPropertyMetadata(null));

        public string GadgetInfo
        {
            get { return (string)GetValue(GadgetInfoProperty); }
            set { SetValue(GadgetInfoProperty, value); }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetPriceProperty =
DependencyProperty.Register("GadgetPrice", typeof(double), typeof(GadgetTemplate), new UIPropertyMetadata(null));

        public double GadgetPrice
        {
            get { return (double)GetValue(GadgetPriceProperty); }
            set { SetValue(GadgetPriceProperty, value); }
        }
        
        /////////////////////////////////////////////////////////////////////////////////////////////

        public static readonly DependencyProperty GadgetProperty =
DependencyProperty.Register("Gadget", typeof(Objects.Gadget), typeof(GadgetTemplate), new UIPropertyMetadata(null));

        public Objects.Gadget Gadget
        {
            get { return (Objects.Gadget)GetValue(GadgetProperty); }
            set { SetValue(GadgetProperty, value); }
        }

        //////////////////////////////////////////////////////////////////////////////////////////////
        public GadgetTemplate()
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
                if (quant > Gadget.QuantityAvailable)
                    Classes.Globals.errorMessage = "Too many quantities, this item's max available quantity is: "+Gadget.QuantityAvailable;
                else
                {
                    Classes.Globals.errorMessage = string.Empty;
                    Gadget.setQuantityToPurchase(quant);
                    switch (Classes.Globals.cart.addItemToCart(Gadget))
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
                    //    if (cart[i] == Gadget)
                    //    {
                    //        cart[i].setQuantityToPurchase(cart[i].QuantityToPurchase+quant);
                    //        Classes.Globals.cartQuantity += quant;
                    //        found = true;
                    //        break;
                    //    }
                    //}

                    //if (!found)
                    //{
                    //    Gadget.setQuantityToPurchase(quant);
                    //    Classes.Globals.Cart.Add(Gadget);
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
