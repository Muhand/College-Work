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

namespace George_s_Car_Rental.Pages
{
    /// <summary>
    /// Interaction logic for PlaceOrder.xaml
    /// </summary>
    public partial class PlaceOrder : Page
    {
        public PlaceOrder()
        {
            InitializeComponent();

            carsTotal.Text = string.Format("${0:0.00}", Classes.Globals.cart.CarsTotal);
            gadgetsTotal.Text = string.Format("${0:0.00}", Classes.Globals.cart.GadgetsTotal);
            estimatedtax.Text = string.Format("${0:0.00}", Classes.Globals.cart.EstimatedTax);
            totalbeforetax.Text = string.Format("${0:0.00}", Classes.Globals.cart.TotalBeforeTax);

            ordertoal.Text = string.Format("${0:0.00}", Classes.Globals.cart.OrderTotal);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if(!agreedToAgreement())
            {
                Classes.Globals.errorMessage = "You have to agree to our terms to continue.";
                return;
            }

            if(!validPersonalInfo())
            {
                Classes.Globals.errorMessage = "Please fill everything that has star next to it.";
                return;
            }

            if(!validEmail())
            {
                Classes.Globals.errorMessage = "Make sure that your email address is correct.";
                return;
            }

            if(creditRadioButton.IsChecked.Value)
            {
                if (!validCreditCardInfo())
                {
                    Classes.Globals.errorMessage = "There was an error with your card information, Please verify everything is good.";
                    return;
                }
            }
            else if(payPalRadioButton.IsChecked.Value)
            {
                if (!validPayPalInfo())
                {
                    Classes.Globals.errorMessage = "Either your PayPal username or password is wrong or this account doesn't exist.";
                    return;
                }
            }


            //If everything is good process purchase
            Debug.WriteLine("Thanks for your purchase.");
            Classes.Globals.buyerFirstName = firstName.field.Text;
            Classes.Globals.buyerMiddleName = middleName.field.Text;
            Classes.Globals.buyersLastName = lastName.field.Text;
            Classes.Globals.buyersEmail = email.field.Text;
            Classes.Globals.errorMessage = string.Empty;

            Classes.Globals.mainWindow.mainFrame.Navigate(new Pages.ThankYouPage());
        }
        private bool validEmail()
        {
            if (email.field.Text.Contains('.') && email.field.Text.Contains('@'))
                return true;
            return false;
        }

        private bool agreedToAgreement()
        {
            return (agreement.IsChecked.Value);
        }
        private bool validPersonalInfo()
        {
            foreach (var item in personalInfoStackPanel.Children)
            {
                if(item is CustomControls.InputField)
                {
                    CustomControls.InputField inp = (CustomControls.InputField)item;
                    if (inp.Important && inp.field.Text == string.Empty)
                        return false;
                }
                else if(item is CustomControls.NumberInputField)
                {
                    CustomControls.NumberInputField inp = (CustomControls.NumberInputField)item;
                    if (inp.Important && (inp.field.Text == string.Empty || inp.field.Text.Length < inp.field.MaxLength))
                        return false;
                }
                else if (item is CustomControls.PasswordInputField)
                {
                    CustomControls.PasswordInputField inp = (CustomControls.PasswordInputField)item;
                    if (inp.Important && inp.field.Password == string.Empty)
                        return false;
                }
            }



            return true;
        }

        private bool validCreditCardInfo()
        {

            foreach (var item in creditGrid.Children)
            {
                if (item is CustomControls.InputField)
                {
                    CustomControls.InputField inp = (CustomControls.InputField)item;
                    if (inp.Important && inp.field.Text == string.Empty)
                        return false;
                }
                else if (item is CustomControls.NumberInputField)
                {
                    CustomControls.NumberInputField inp = (CustomControls.NumberInputField)item;
                    if (inp.Important && (inp.field.Text == string.Empty || inp.field.Text.Length < inp.field.MaxLength))
                        return false;
                }
                else if (item is CustomControls.PasswordInputField)
                {
                    CustomControls.PasswordInputField inp = (CustomControls.PasswordInputField)item;
                    if (inp.Important && inp.field.Password == string.Empty)
                        return false;
                }
            }



            return true;
        }

        private bool validPayPalInfo()
        {

            foreach (var item in PayPalGrid.Children)
            {
                if (item is CustomControls.InputField)
                {
                    CustomControls.InputField inp = (CustomControls.InputField)item;
                    if (inp.Important && inp.field.Text == string.Empty)
                        return false;
                }
                else if (item is CustomControls.NumberInputField)
                {
                    CustomControls.NumberInputField inp = (CustomControls.NumberInputField)item;
                    if (inp.Important && (inp.field.Text == string.Empty || inp.field.Text.Length < inp.field.MaxLength))
                        return false;
                }
                else if (item is CustomControls.PasswordInputField)
                {
                    CustomControls.PasswordInputField inp = (CustomControls.PasswordInputField)item;
                    if (inp.Important && inp.field.Password == string.Empty)
                        return false;
                }
            }



            return true;
        }
        private void RadioButton_Checked(object sender, RoutedEventArgs e)
        {
            creditGrid.Visibility = Visibility.Visible;
            CashGrid.Visibility = Visibility.Hidden;
            PayPalGrid.Visibility = Visibility.Hidden;
        }
        private void RadioButton_Checked_1(object sender, RoutedEventArgs e)
        {
            creditGrid.Visibility = Visibility.Hidden;
            CashGrid.Visibility = Visibility.Hidden;
            PayPalGrid.Visibility = Visibility.Visible;
        }
        private void RadioButton_Checked_2(object sender, RoutedEventArgs e)
        {
            creditGrid.Visibility = Visibility.Hidden;
            CashGrid.Visibility = Visibility.Visible;
            PayPalGrid.Visibility = Visibility.Hidden;
        }

        private void Page_Loaded(object sender, RoutedEventArgs e)
        {
            creditRadioButton.IsChecked = true;
        }
    }
}
