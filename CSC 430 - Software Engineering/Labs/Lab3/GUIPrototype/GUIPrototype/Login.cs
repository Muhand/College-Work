﻿using System;
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
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SignUp s = new SignUp();
            s.Show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ControlPanel c = new ControlPanel();
            c.Show();
        }
    }
}