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

namespace George_s_Car_Rental.CustomControls
{
    /// <summary>
    /// Interaction logic for NumberInputField.xaml
    /// </summary>
    public partial class NumberInputField : UserControl
    {
        public static readonly DependencyProperty FieldTitleProperty =
DependencyProperty.Register("FieldTitle", typeof(string), typeof(NumberInputField), new UIPropertyMetadata(null));

        public string FieldTitle
        {
            get { return (string)GetValue(FieldTitleProperty); }
            set { SetValue(FieldTitleProperty, value); }
        }

        public static readonly DependencyProperty MaxDigitsProperty =
DependencyProperty.Register("maxDigits", typeof(int), typeof(NumberInputField), new UIPropertyMetadata(null));

        public int maxDigits
        {
            get { return (int)GetValue(MaxDigitsProperty); }
            set { SetValue(MaxDigitsProperty, value); }
        }

        public static readonly DependencyProperty ImportantProperty =
DependencyProperty.Register("Important", typeof(bool), typeof(NumberInputField), new UIPropertyMetadata(null));

        public bool Important
        {
            get { return (bool)GetValue(ImportantProperty); }
            set { SetValue(ImportantProperty, value); }
        }

        public NumberInputField()
        {
            InitializeComponent();
        }

        private void TextBlock_MouseDown(object sender, MouseButtonEventArgs e)
        {
            field.Text = string.Empty;
        }

        private void TextBlock_MouseEnter(object sender, MouseEventArgs e)
        {
            bord.Background = new SolidColorBrush(Colors.LightGray);
        }

        private void TextBlock_MouseLeave(object sender, MouseEventArgs e)
        {
            bord.Background = new SolidColorBrush(Colors.Transparent);
        }

        private void field_TextChanged(object sender, TextChangedEventArgs e)
        {
            Classes.Globals.allowOnlyNumbers(field);
        }

        private void NumberInputFieldName_Loaded(object sender, RoutedEventArgs e)
        {
            if (Important)
                importanceNote.Visibility = Visibility.Visible;
            else
                importanceNote.Visibility = Visibility.Hidden;
        }
    }
}
