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
using George_s_Car_Rental.Classes;

namespace George_s_Car_Rental
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();


            //While initializing the window
            this.WindowState = WindowState.Maximized; //Maximize the window
            this.ResizeMode = ResizeMode.CanMinimize; //Disable maximize box
            searchZipTextBox.MaxLength = 5;           //Limit length of search box
            
        }


        private void SearchZipTextBox_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            if (!Globals.isNumber(searchZipTextBox.Text, searchZipTextBox))
            {
                //ToolTip t = new ToolTip();
                //t.Content = "You can only enter numbers.";
                //t.
            }
        }
    }
}