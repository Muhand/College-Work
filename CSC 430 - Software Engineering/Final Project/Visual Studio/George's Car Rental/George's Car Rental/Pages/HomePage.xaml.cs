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

namespace George_s_Car_Rental.Pages
{
    /// <summary>
    /// Interaction logic for HomePage.xaml
    /// </summary>
    public partial class HomePage : Page
    {
        public HomePage()
        {
            InitializeComponent();
            //searchZipTextBox.MaxLength = 5;    
            //Limit length of search box
        }

        //private void searchZipTextBox_TextChanged(object sender, TextChangedEventArgs e)
        //{
        //    Classes.Globals.allowOnlyNumbers(searchZipTextBox);
        //}
    }
}
