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
using George_s_Car_Rental.ViewModels;
using George_s_Car_Rental.Objects;
using System.Diagnostics;

namespace George_s_Car_Rental.Pages
{
    /// <summary>
    /// Interaction logic for SelectCarAndGadgets.xaml
    /// </summary>
    public partial class SelectCarAndGadgets : Page
    {
        CarViewModel carssviewmodel;
        GadgetViewModel gadgetsviewmodel;

        public SelectCarAndGadgets()
        {
            InitializeComponent();

            carssviewmodel = new CarViewModel();
            gadgetsviewmodel = new GadgetViewModel();

          
        }

        private void DatePicker_SelectedDateChanged(object sender, SelectionChangedEventArgs e)
        {
            DatePicker dp = (DatePicker)sender;
            populateCarSearchResult(dp.SelectedDate.Value.Date.ToShortDateString());

        }

        private void populateCarSearchResult(string date)
        {
            carsSearchResult.Items.Clear();

            foreach (var car in carssviewmodel.CarsList)
            {
                if (car.Availability == date && car.StoreID == Classes.Globals.selectedStore.ID)
                    addCarToResult(car);
            }

        }

        private void populateGadgetSearchResult(Car car)
        {
            gadgetsSearchResult.Items.Clear();

            foreach (var gadget in gadgetsviewmodel.GadgetsList)
            {
                if (gadget.CarID == car.ID && car.StoreID == Classes.Globals.selectedStore.ID)
                    addGadgetToResult(gadget);
            }

        }

        private void addCarToResult(Objects.Car c)
        {
            //Classes.Globals.FoundStores.Add(s);
            //ListBoxItem newitem = new ListBoxItem();

            CustomListBoxItems.CarTemplate newitemcontent = new CustomListBoxItems.CarTemplate
            {
                CarImage = c.Image,
                CarTitle = c.getTitle(),
                CarInfo = c.getCarInfo(),
                CarDescription = c.ItemDescription,
                Car = c
            };


            //newitem.Content = newitemcontent;

            carsSearchResult.Items.Add(newitemcontent);
        }

        private void addGadgetToResult(Objects.Gadget g)
        {
            //Classes.Globals.FoundStores.Add(s);
            ListBoxItem newitem = new ListBoxItem();

            CustomListBoxItems.GadgetTemplate newitemcontent = new CustomListBoxItems.GadgetTemplate
            {
                GadgetImage = g.Image,
                GadgetDescription = g.ItemDescription,
                //GadgetInfo = g.getGadgetInfo(),
                GadgetPrice = g.Price,
                GadgetTitle = g.getTitle(),
                Gadget = g
            };


            newitem.Content = newitemcontent;

            gadgetsSearchResult.Items.Add(newitem);
        }

        private void carsSearchResult_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            CustomListBoxItems.CarTemplate c = (CustomListBoxItems.CarTemplate)carsSearchResult.SelectedItem;

            try
            {
                populateGadgetSearchResult(c.Car);
            }
            catch (NullReferenceException)
            {
                gadgetsSearchResult.Items.Clear();
            }
        }
    }
}
