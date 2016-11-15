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
    /// Interaction logic for InputField.xaml
    /// </summary>
    public partial class InputField : UserControl
    {
        public static readonly DependencyProperty FieldTitleProperty =
 DependencyProperty.Register("FieldTitle", typeof(string), typeof(InputField), new UIPropertyMetadata(null));

        public string FieldTitle
        {
            get { return (string)GetValue(FieldTitleProperty); }
            set { SetValue(FieldTitleProperty, value); }
        }

        public static readonly DependencyProperty ImportantProperty =
DependencyProperty.Register("Important", typeof(bool), typeof(InputField), new UIPropertyMetadata(null));
        
        public bool Important
        {
            get { return (bool)GetValue(ImportantProperty); }
            set { SetValue(ImportantProperty, value); }
        }


        public InputField()
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

        private void InputFieldName_Loaded(object sender, RoutedEventArgs e)
        {
            if (Important)
                importanceNote.Visibility = Visibility.Visible;
            else
                importanceNote.Visibility = Visibility.Hidden;
        }
    }
}
