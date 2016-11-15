////////////////////////////////////////////////////////////
//                George's Car Rental V1.0
//This view model is responsible on holding all the stores data.
////////////////////////////////////////////////////////////
using George_s_Car_Rental.Objects;
using George_s_Car_Rental.Classes;
using System.Collections.ObjectModel;

namespace George_s_Car_Rental.ViewModels
{
    /// <summary>
    /// This is the view model for the store, where it's used somewhere else to import all the stores from it.
    /// </summary>
    public class StoreViewModel
    {
        StoresData source = new StoresData();                                                       //Get the stores from the storesData class.
        private ObservableCollection<Store> storesList = new ObservableCollection<Store>();         //Create a new empty list
        
        //Set the list to be a read-only property. 
        public ObservableCollection<Store> StoresList
        {
            get
            {
                return storesList;
            }
        }
        
        /// <summary>
        /// Default Constructor.
        /// </summary>
        public StoreViewModel( )
        {
            /// <summary>
            /// Uppon creation of the viewmodel object,
            /// Fill the list by looping through every store in the 'source' object of type 'StoresData'
            /// and add it to the list.
            /// </summary>
            foreach (var store in source.getStores())
                storesList.Add(store);
        }

        public override string ToString()
        {
            return base.ToString();
        }
    }
}
