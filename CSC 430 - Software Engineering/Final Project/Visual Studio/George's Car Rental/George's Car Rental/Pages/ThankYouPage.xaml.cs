////////////////////////////////////////////////////////////
//                George's Car Rental V1.0
//This class is responsible on thanking the user for using our platform to make their purcheses
//and to send a receipt of the order to their email.
////////////////////////////////////////////////////////////
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using George_s_Car_Rental.Classes;

namespace George_s_Car_Rental.Pages
{
    /// <summary>
    /// Interaction logic for ThankYouPage.xaml
    /// </summary>
    public partial class ThankYouPage : Page
    {
        public ThankYouPage()
        {
            InitializeComponent();

            /// <summary>
            /// The next 5 lines are used to get the data (e.g. total price) from the globals class,
            /// and setting the values of the appropriate field to that data.
            /// </summary>
            carsTotal.Text = string.Format("${0:0.00}", Classes.Globals.cart.CarsTotal);
            gadgetsTotal.Text = string.Format("${0:0.00}", Classes.Globals.cart.GadgetsTotal);
            estimatedtax.Text = string.Format("${0:0.00}", Classes.Globals.cart.EstimatedTax);
            totalbeforetax.Text = string.Format("${0:0.00}", Classes.Globals.cart.TotalBeforeTax);
            ordertoal.Text = string.Format("${0:0.00}", Classes.Globals.cart.OrderTotal);

            //Create a message to send it to by email.
            string message = string.Format("Dear {0} {1}\nThank you for shopping with us, your order have been processed.",Globals.buyerFirstName, Globals.buyersLastName);
            message += string.Format("\n\nOrder Details\n-------------\n\nCars: ${0:0.00}\nGadgets: ${1:0.00}\nTotal Before Tax: ${2:0.00}\nEstimated Tax to be Collected: ${3:0.00}\n\nOrder Total: ${4:0.00}",
                Globals.cart.CarsTotal, Globals.cart.GadgetsTotal,Globals.cart.TotalBeforeTax,Globals.cart.EstimatedTax, Globals.cart.OrderTotal);
            
            //Now clear the cart, send the email and set the cursors back to normal.
            Globals.cart.clearCart();
            Globals.sendEmail(Globals.buyersEmail, "George's Car Rental - Confirmation", message);
            this.Cursor = Cursors.Arrow;
        }

        /// <summary>
        /// Uppon the page being loaded successfully.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Page_Loaded(object sender, RoutedEventArgs e)
        {
            //Get the buyer's name.
            if(Globals.buyerMiddleName == string.Empty)
                Name.Text = string.Format("{0} {1}", Globals.buyerFirstName, Globals.buyersLastName);
            else
                Name.Text = string.Format("{0} {1} {2}", Globals.buyerFirstName, Globals.buyerMiddleName, Globals.buyersLastName);

            //Create a message to view to the user.
            TextBeforeEmail.Text = "Thank you for shopping with us, your order have been processed.\nYou should recieve a confirmation email to ";
            Email.Text = Globals.buyersEmail;
            TextAfterEmail.Text = " soon.";
        }

        /// <summary>
        /// Go back to the home page.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Globals.mainWindow.mainFrame.Navigate(new Pages.HomePage());
        }
    }
}
