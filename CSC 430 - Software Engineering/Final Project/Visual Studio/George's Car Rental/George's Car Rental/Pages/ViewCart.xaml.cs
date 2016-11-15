////////////////////////////////////////////////////////////
//                George's Car Rental V1.0
//This class is responsible on the logic of inserting, removing the items
//in the cart list and displaying it to the user.
////////////////////////////////////////////////////////////
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;


namespace George_s_Car_Rental.Pages
{
    /// <summary>
    /// Interaction logic for ViewCart.xaml
    /// </summary>
    public partial class ViewCart : Page
    {
        /// <summary>
        /// Default constructor
        /// </summary>
        public ViewCart()
        {
            
            InitializeComponent();                                                  //Initialize the components of this page


            /// <summary>
            /// The next 5 lines are used to get the data (e.g. total price) from the globals class,
            /// and setting the values of the appropriate field to that data.
            /// </summary>
            carsTotal.Text = string.Format("${0:0.00}", Classes.Globals.cart.CarsTotal);
            gadgetsTotal.Text = string.Format("${0:0.00}", Classes.Globals.cart.GadgetsTotal);
            estimatedtax.Text = string.Format("${0:0.00}", Classes.Globals.cart.EstimatedTax);
            totalbeforetax.Text = string.Format("${0:0.00}", Classes.Globals.cart.TotalBeforeTax);
            ordertoal.Text = string.Format("${0:0.00}", Classes.Globals.cart.OrderTotal);


            /// <summary>
            /// The next 2 loops are responsible on adding the cars and gadgets to the same result.
            /// This is important in order to display the items that were bought to the user.
            /// </summary>
            foreach (var item in Classes.Globals.cart.Cars)
                addCarToResult(item);
            foreach (var item in Classes.Globals.cart.Gadgets)
                addGadgetToResult(item);
        }

        /// <summary>
        /// This is responsible on adding an object of type car to the result.
        /// </summary>
        /// <param name="c">Any object of type car.</param>
        private void addCarToResult(Objects.Car c)
        {
            //Create a new listboxitem of type 'EditCarTemplate' and fill it with the appropiate values.
            CustomListBoxItems.EditCarTemplate newitemcontent = new CustomListBoxItems.EditCarTemplate
            {
                CarImage = c.Image,
                CarTitle = c.getTitle(),
                CarInfo = c.getCarInfo(),
                CarDescription = c.ItemDescription,
                Car = c
            };


            //Add the created listboxitem to the listbox.
            cartItems.Items.Add(newitemcontent);
        }

        /// <summary>
        /// This is responsible on adding an object of type gadget to the result.
        /// </summary>
        /// <param name="g">Any object of type car.</param>
        private void addGadgetToResult(Objects.Gadget g)
        {
            //Look at methods 'addCarToResult' for similar documentation.
            CustomListBoxItems.EditGadgetTemplate newitemcontent = new CustomListBoxItems.EditGadgetTemplate
            {
                GadgetImage = g.Image,
                GadgetDescription = g.ItemDescription,
                GadgetPrice = g.Price,
                GadgetTitle = g.getTitle(),
                Gadget = g
            };


            cartItems.Items.Add(newitemcontent);
        }


        /// <summary>
        /// This button is responsible confirming the order and moving to the placeorder page.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Cursor = Cursors.Wait;
            //Check if cart is empty or not.
            if (Classes.Globals.cart.isEmpty())
            {
                Classes.Globals.errorMessage = "Your cart is empty.";
                return;
            }

            //Check if any of the item's quantity is larger than what's in stock
            foreach (var item in cartItems.Items)
            {
                if (item is CustomListBoxItems.EditCarTemplate)
                {
                    CustomListBoxItems.EditCarTemplate i = (CustomListBoxItems.EditCarTemplate)item;
                    if (i.quantity.NumValue > i.Car.QuantityAvailable)
                    {
                        Classes.Globals.errorMessage = i.CarTitle + ", have exceeded the available amount.";
                        return;
                    }
                }
                else if (item is CustomListBoxItems.EditGadgetTemplate)
                {
                    CustomListBoxItems.EditGadgetTemplate i = (CustomListBoxItems.EditGadgetTemplate)item;
                    if (i.quantity.NumValue > i.Gadget.QuantityAvailable)
                    {
                        Classes.Globals.errorMessage = i.GadgetTitle + ", have exceeded the available amount.";
                        return;
                    }
                }
            }

            //If everything is good, move to the placeorder page
            this.Cursor = Cursors.Arrow;
            Classes.Globals.mainWindow.mainFrame.Navigate(new Pages.PlaceOrder());
        }
    }
}
