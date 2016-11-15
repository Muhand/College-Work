using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUIPrototype
{
    public partial class ControlPanel : Form
    {
        public ControlPanel()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            StoreLocator st = new StoreLocator();
            st.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            AddCar addcar = new AddCar();
            addcar.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            DisplayInventory d = new DisplayInventory();
            d.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            AccountManagement acc = new AccountManagement();
            acc.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click_1(object sender, EventArgs e)
        {
            AddGadgets addg = new AddGadgets();
            addg.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Checkout chk = new Checkout();
            chk.Show();
        }
    }
}
