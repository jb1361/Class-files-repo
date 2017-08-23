using System;

public class MemoryCalculator : Calculator
{
    private double memory;
    public MemoryCalculator() {
        addButton("sm", 70, 130);
        addButton("rm", 100, 130);
        addButton("cm", 130, 130);
    }

    public override void onClick(char c)
    {
        switch (c)
        {
            case 's':
                memory = Accumulator;
                break;
            case 'r':
                Accumulator = Accumulator  * 10 + memory;             
                updateDisplay(Accumulator + "");
                break;
            case 'c':
                memory = 0.0;
                break;


            default:
                base.onClick(c);
                break;
        }

       
    }
}