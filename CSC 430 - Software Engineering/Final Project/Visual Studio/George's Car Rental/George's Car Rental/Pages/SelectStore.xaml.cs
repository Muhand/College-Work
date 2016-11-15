////////////////////////////////////////////////////////////
//                George's Car Rental V1.0
//This class is responsible on displaying to the user the available stores and handleing which store is being selected.
////////////////////////////////////////////////////////////
using System.Windows.Controls;
using George_s_Car_Rental.ViewModels;
using George_s_Car_Rental.Objects;

namespace George_s_Car_Rental.Pages
{
    /// <summary>
    /// Interaction logic for SelectStore.xaml
    /// </summary>
    public partial class SelectStore : Page
    {
        StoreViewModel storesviewmodel;                                     //Create a viewmodel object to get the data from.

        /// <summary>
        /// Default Constructor.
        /// </summary>
        public SelectStore()
        {
            InitializeComponent();

            storesviewmodel = new StoreViewModel();

            //Loop through all the stores that exist in the viewmodel and add each one to the list.
            foreach (var store in storesviewmodel.StoresList)
            {
                if (store.ZipCode == Classes.Globals.searchedZipCode)
                    addStoreToResult(store);
            }
         
            #region OLD
            //for (int i = 0; i < 20; i++)
            //{
            //    ListBoxItem ls = new ListBoxItem();
            //    CustomControls.CustomListboxItem s = new CustomControls.CustomListboxItem();
            //    ls.Content = s;
            //    searchResult.Items.Add(ls);
            //}

            //List<StoreViewModel> items = new List<StoreViewModel>();
            //Store s = new Store()
            //{
            //    Name = "Test Store",
            //    Street = "934 Post Ave",
            //    City = "Staten Island",
            //    State= "NY",
            //    Country = "USA",
            //    ZipCode= "10302",
            //};
            //Store s2 = new Store();

            //StoreViewModel newstore = new StoreViewModel(s);
            //StoreViewModel newstore2 = new StoreViewModel(s2);
            //items.Add(newstore);
            //items.Add(newstore2);

            //searchResult.ItemsSource = items;
            #endregion
        }

        /// <summary>
        /// This methods is responsible on adding the store to the reuslt, by taking a store object as an argument.
        /// </summary>
        /// <param name="s">Any object of type Store.</param>
        private void addStoreToResult(Objects.Store s)
        {
            Classes.Globals.FoundStores.Add(s);

            CustomListBoxItems.StoreTemplate newitemcontent = new CustomListBoxItems.StoreTemplate
            {
               StoreImage = s.Image,
               StoreName = s.Name,
               StoreAddress = s.ToString(),
               Store = s
            };


            searchResult.Items.Add(newitemcontent);
        }

    }
}
