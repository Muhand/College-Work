////////////////////////////////////////////////////////////
//                George's Car Rental V1.0
//This is an enum class which is responsible on holding 
//different enums and their values.
////////////////////////////////////////////////////////////
namespace George_s_Car_Rental
{
    public class enums
    {
        /// <summary>
        /// This enum is used to hold all cases when someone tries to insert something to the cart.
        /// </summary>
        public enum InsertToCart
        {
            ItemExist,
            CartIsFull,
            Success,
            UnknownError
        }
        /// <summary>
        /// This enum is used to hold all cases when someone tries to remove something to the cart.
        /// </summary>
        public enum RemoveFromCart
        {
            CartIsEmpty,
            DoesntExist,
            Success,
            UnknownError
        }
    }
}
