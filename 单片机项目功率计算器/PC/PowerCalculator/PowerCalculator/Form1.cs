using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace PowerCalculator
{
    public partial class Form1 : Form
    {
        public double _gamma;
        public double _g;
        public double _h;
        public double _fai;
        public double _beta;
        public double _A;
        public double _s;
        public double _t;
        public double _w;
        public double _F;
        public double _P;
        public double _T;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _gamma = 1800;
            gamma.Text = _gamma.ToString();
            _g = 9.8;
            g.Text = _g.ToString();
            _h = 30;
            h.Text = _h.ToString();
            _fai = 45;
            fai.Text = _fai.ToString();
            _beta = Math.Tan(_fai * Math.PI / 180);
            beta.Text = _beta.ToString();
            _A = 0.0653;
            A.Text = _A.ToString();
            _s = 0.04;
            s.Text = _s.ToString();
            _t = 60;
            t.Text = _t.ToString();
            _w = 50;
            w.Text = _w.ToString();
            _F = _gamma * _g * _h * _beta * _A;
            F.Text = _F.ToString();
            _P = _w * _s * _F / _t;
            P.Text = _P.ToString();
            _T = 9550 * _P / _w / 1000;
            niuju.Text = _T.ToString();
            trackBar1.Value = 45;
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            _fai = trackBar1.Value;
            fai.Text = _fai.ToString();
            _beta = Math.Tan(_fai * Math.PI / 180);
            beta.Text = _beta.ToString();
        }

        private void fai_TextChanged(object sender, EventArgs e)
        {
            if (fai.Text == String.Empty)
            {
                //MessageBox.Show("空的！");
                _fai = 0;
                fai.Text = "0";
            }
            /*else if (double.TryParse(fai.Text, out tmp) == false)
            {
                fai.Text = fai.Text.TrimEnd('.');
            }*/
            else
            {
                _fai = Convert.ToDouble(fai.Text);
            }
            _beta = Math.Tan(_fai * Math.PI / 180);
            beta.Text = _beta.ToString();
        }

        private void calc_Click(object sender, EventArgs e)
        {
            F.Text = (Convert.ToDouble(gamma.Text) * Convert.ToDouble(g.Text) * Convert.ToDouble(h.Text) * Convert.ToDouble(beta.Text) * Convert.ToDouble(A.Text)).ToString();
            P.Text = (Convert.ToDouble(w.Text) * Convert.ToDouble(s.Text) * Convert.ToDouble(F.Text) / Convert.ToDouble(t.Text)).ToString();
            niuju.Text = (9.55 * Convert.ToDouble(P.Text) / Convert.ToDouble(w.Text)).ToString();
        }

        private void gamma_TextChanged(object sender, KeyPressEventArgs e)
        {
            System.Windows.Forms.TextBox textBox = (System.Windows.Forms.TextBox)sender;
            char kc = e.KeyChar;
            if ((kc < 48 || kc > 57) && kc != 8 && kc != 127 && kc != 45 && kc != 46)
                e.Handled = true;
            if (kc == 46)                       //小数点
            {
                if (textBox.Text.Length <= 0 || textBox.Text == "-")
                    e.Handled = true;           //小数点不能在第一位并且不能直接跟在减号后面
                else
                {
                    double f;
                    double oldf;
                    bool b1 = false, b2 = false;
                    b1 = double.TryParse(textBox.Text, out oldf);
                    b2 = double.TryParse(textBox.Text + e.KeyChar.ToString(), out f);
                    if (b2 == false)
                    {
                        if (b1 == true)
                            e.Handled = true;
                        else
                            e.Handled = false;
                    }
                }
            }
            if (kc == 45)                       //减号
            {
                if (textBox.Text.Length != 0)
                    e.Handled = true;           //减号只能在第一位
                else
                {
                    double f;
                    double oldf;
                    bool b1 = false, b2 = false;
                    b1 = double.TryParse(textBox.Text, out oldf);
                    b2 = double.TryParse(textBox.Text + e.KeyChar.ToString(), out f);
                    if (b2 == false)
                    {
                        if (b1 == true)
                            e.Handled = true;
                        else
                            e.Handled = false;
                    }
                }
            }
        }
    }
}
