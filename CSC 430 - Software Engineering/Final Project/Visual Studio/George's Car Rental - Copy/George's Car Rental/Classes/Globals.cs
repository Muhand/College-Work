using System.Windows.Controls;

namespace George_s_Car_Rental.Classes
{
    public class Globals
    {
        public static bool isNumber(string text, TextBox t)
        {
            int temp;

            return (int.TryParse(text, out temp));
        }
    }
}
