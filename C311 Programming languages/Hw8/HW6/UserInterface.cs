using System;
using System.Windows.Forms;
using System.Drawing;

public abstract class UserInterface : Form
{
    private TextBox neg;
    public bool negativeNum { get; set; }
    private TextBox display;
    private EventHandler handler;
    private Panel keypad;

    public UserInterface()
    {
        negativeNum = false;
        keypad = new Panel();
        display = new TextBox();
        neg = new TextBox();
        handler = new EventHandler(buttonHandler);

        this.Text = "Calculator";
        this.Size = new Size(200, 225);
        this.Controls.Add(neg);
        this.Controls.Add(display);       
        this.Controls.Add(keypad);

        display.Location = new Point(10, 10);
        display.Size = new Size(150, 10);
        display.ReadOnly = true;
        display.RightToLeft = RightToLeft.Yes;
       
        neg.Location = new Point(12, 13);
        neg.Size = new Size(10, 10);
        neg.ReadOnly = true;        
        neg.RightToLeft = RightToLeft.Yes;
        neg.BorderStyle = BorderStyle.None;
      
        keypad.Size = new Size(200, 200);
        keypad.BackColor = Color.Blue;
    }

    public abstract void onClick(char c);

    public void addButton(string s, int x, int y)
    {
        Button b = new Button();
        b.Text = s;
        b.Size = new Size(27, 27);
        b.BackColor = Color.White;
        b.Location = new Point(x, y);
        b.Click += handler;
        keypad.Controls.Add(b);


    }

   
    public void updateDisplay(string s)
    {
        display.Text = s;
        if (negativeNum) neg.Text = "-";
        else neg.Text = "";       
    }

    private void buttonHandler(object obj, EventArgs ea)
    {
        Button button = (Button)obj;
        onClick(button.Text[0]);
    }
}
