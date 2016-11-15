////////////////////////////////////////////////////////////
//                George's Car Rental V1.0
//This view model is responsible on holding all the gadgets data.
//Look at the SotreViewModel.cs for the documentation.
////////////////////////////////////////////////////////////
using George_s_Car_Rental.Objects;
using George_s_Car_Rental.Classes;
using System.Collections.ObjectModel;

namespace George_s_Car_Rental.ViewModels
{
    /// <summary>
    /// This is the view model for the gadgets, where it's used somewhere else to import all the gadgets from it.
    /// </summary>
    public class GadgetViewModel
    {
        GadgetsData source = new GadgetsData();
        private ObservableCollection<Gadget> gadgetsList = new ObservableCollection<Gadget>();

        public ObservableCollection<Gadget> GadgetsList
        {
            get
            {
                return gadgetsList;
            }
        }

        /// <summary>
        /// Default Constructor.
        /// </summary>
        public GadgetViewModel()
        {
            foreach (var gadget in source.getGadgets())
                gadgetsList.Add(gadget);
        }
    }
}
