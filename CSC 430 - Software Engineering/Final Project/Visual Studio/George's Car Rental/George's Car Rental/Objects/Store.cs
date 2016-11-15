
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace George_s_Car_Rental.Objects
{
    public class Store
    {
        public int ID { get; set; }
        public BitmapImage Image { get; set; }
        public string Name { get; set; }
        public string Street { get; set; }
        public string SecondStreet { get; set; }
        public string City { get; set; }
        public string State { get; set; }
        public string Country { get; set; }
        public string ZipCode { get; set; }

        public Store()
        {
            ID = 0;
            Image = new BitmapImage(new Uri("../Images/NoPhoto.png", UriKind.Relative));
            Name = "Store Name";
            Street = "Store's Street";
            SecondStreet = "Store's Second Street";
            City = "Store's City";
            State = "Store's State";
            Country = "Store's Country";
            ZipCode = "Store's ZipCode";
        
        }
        public Store(BitmapImage image, string name, string street, string city, string state, string country, string zipcode)
        {
            init(image, name, street, city, state, country, zipcode);
        }
        public Store(BitmapImage image, string name, string street, string secondstreet, string city, string state, string country, string zipcode)
        {
            init(image, name, street, city, state, country, zipcode);
            SecondStreet = secondstreet;
        }

        public void init(BitmapImage image, string name, string street, string city, string state, string country, string zipcode)
        {
            Image = image;
            Name = name;
            Street = street;
            City = city;
            State = state;
            Country = country;
            ZipCode = zipcode;
            SecondStreet = string.Empty;
            ID = 0;
        }
        public override string ToString()
        {
            if (SecondStreet != string.Empty && SecondStreet.Equals("Store's Second Street") == false)
                return (string.Format("{0}. {1},\n{2}, {3},\n{4} {5}", Street, SecondStreet, City, State, Country, ZipCode));
            else
                return (string.Format("{0}.\n{1}, {2},\n{3} {4}", Street, City, State, Country, ZipCode));

        }
    }
}
