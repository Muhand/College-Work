using System.Windows;
using System.Windows.Input;
using George_s_Car_Rental.Classes;
using dmanager;

namespace George_s_Car_Rental
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        /// <summary>
        /// Mainwindow Initialization
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();

            //While initializing the window
            this.WindowState = WindowState.Maximized;           //Maximize the window
            this.ResizeMode = ResizeMode.CanMinimize;           //Disable maximize box
            mainFrame.Navigate(new Pages.HomePage());           //Navigate to the home page at first

            Globals.mainWindow = this;                          //Set the main window instance

            //Configure the database
            DbConfig.ConnectionUsername = Globals.CONNECTION_USERNAME;
            DbConfig.ConnectionPassword = Globals.CONNECTION_PASSWORD;
            DbConfig.DatabaseName = Globals.DATABASE_NAME;
            DbConfig.ServerIp = Globals.SERVER_IP;
            DbConfig.ServerPort = Globals.SERVER_PORT;
            
        }

        /// <summary>
        /// View Cart Button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void StackPanel_MouseDown(object sender, MouseButtonEventArgs e)
        {
            //Whenever the view cart button is pressed, navigate to the cart view.
            Classes.Globals.mainWindow.mainFrame.Navigate(new Pages.ViewCart());
        }
    }
}