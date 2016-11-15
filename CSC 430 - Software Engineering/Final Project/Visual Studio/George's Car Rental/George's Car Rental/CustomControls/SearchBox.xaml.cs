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

namespace George_s_Car_Rental.CustomControls
{
    /// <summary>
    /// Interaction logic for SearchBox.xaml
    /// </summary>
    public partial class SearchBox : UserControl
    {
        public SearchBox()
        {
            InitializeComponent();
            searchBox.MaxLength = 5;
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            Classes.Globals.allowOnlyNumbers(searchBox);
            searchBox.BorderBrush = new SolidColorBrush(Colors.Black);
         
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            startSearch();
        }

        private void searchBox_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.Key == Key.Return)
            {
                startSearch();
            }
        }

        private void startSearch()
        {
            if (searchBox.Text.Length == 5)
            {
                Classes.Globals.searchedZipCode = searchBox.Text;
                Classes.Globals.mainWindow.mainFrame.Navigate(new Pages.SelectStore());
                Classes.Globals.errorMessage = string.Empty;
            }
            else
            {
                searchBox.BorderBrush = new SolidColorBrush(Colors.Red);
                Classes.Globals.errorMessage = "Please input a valid zipcode.";
            }
        }
    }
}
