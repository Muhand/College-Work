////////////////////////////////////////////////////////////
//                George's Car Rental V1.0
//This view model is responsible on holding all the car data.
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
    public class CarViewModel
    {
        CarsData source = new CarsData();
        private ObservableCollection<Car> carsList = new ObservableCollection<Car>();
        public ObservableCollection<Car> CarsList
        {
            get
            {
                return carsList;
            }
        }


        /// <summary>
        /// Default Constructor.
        /// </summary>
        public CarViewModel()
        {
            foreach (var car in source.getCars())
                carsList.Add(car);
        }
    }
}
