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
    /// Interaction logic for CustomListboxItem.xaml
    /// </summary>
    public partial class StoreTemplate : UserControl
    {
        public StoreTemplate()
        {
            InitializeComponent();
        }
        
        public static readonly DependencyProperty StoreImageProperty =
DependencyProperty.Register("StoreImage", typeof(BitmapImage), typeof(StoreTemplate), new UIPropertyMetadata(new BitmapImage(new Uri("../Images/NoPhoto.png", UriKind.Relative))));

        public BitmapImage StoreImage
        {
            get { return (BitmapImage)GetValue(StoreImageProperty); }
            set { SetValue(StoreImageProperty, value); }
        }

        public static readonly DependencyProperty StoreNameProperty =
DependencyProperty.Register("StoreName", typeof(string), typeof(StoreTemplate), new UIPropertyMetadata(null));

        public string StoreName
        {
            get { return (string)GetValue(StoreNameProperty); }
            set { SetValue(StoreNameProperty, value); }
        }

        public static readonly DependencyProperty StoreAddressProperty =
DependencyProperty.Register("StoreAddress", typeof(string), typeof(StoreTemplate), new UIPropertyMetadata(null));

        public string StoreAddress
        {
            get { return (string)GetValue(StoreAddressProperty); }
            set { SetValue(StoreAddressProperty, value); }
        }

        public static readonly DependencyProperty StoreProperty =
DependencyProperty.Register("Store", typeof(Objects.Store), typeof(StoreTemplate), new UIPropertyMetadata(null));

        public Objects.Store Store
        {
            get { return (Objects.Store)GetValue(StoreProperty); }
            set { SetValue(StoreProperty, value); }
        }

        private void Select_Click(object sender, RoutedEventArgs e)
        {
            Button btn = (Button)sender;
            Classes.Globals.selectedStore = (Objects.Store)btn.DataContext;
            Debug.WriteLine(Classes.Globals.selectedStore.Name + "\n" + Classes.Globals.selectedStore.Street);
            Classes.Globals.mainWindow.mainFrame.Navigate(new Pages.SelectCarAndGadgets());
        }
    }
}
