public class Calculator : UserInterface
{
    private double accumulator = 0.0, operand;
    private char operation;

    public Calculator()
    {
        addButton("1", 10, 40);
        addButton("+", 50, 40);
        addButton("=", 90, 40);
    }

    public override void onClick(char c)
    {
        switch (c)
        {
            case '1': Accumulator = Accumulator * 10 + 1;
                break;
            case '=': equal();
                break;
            case '+': Operation = c;
                Operand = Accumulator;
                Accumulator = 0.0;
                break;
        }
        updateDisplay(Accumulator + "");
    }

    public void equal()
    {
        switch (Operation)
        {
            case '+': Accumulator = Accumulator + Operand;
                break;
        }
    }

    public double Accumulator
    {
        set { this.accumulator = value; }
        get { return this.accumulator; }
    }

    public double Operand
    {
        set { this.operand = value; }
        get { return this.operand; }
    }

    public char Operation
    {
        set { this.operation = value; }
        get { return this.operation; }
    }
}
