using System;


public class Calculator : UserInterface
{
    private double accumulator = 0.0, operand;
    private char operation;
    public bool displayException = false;
    public Calculator()
    {
        addButton("0", 40, 130);
        addButton("1", 10, 100);
        addButton("2", 40, 100);
        addButton("3", 70, 100);
        addButton("4", 10, 70);
        addButton("5", 40, 70);
        addButton("6", 70, 70);
        addButton("7", 10, 40);
        addButton("8", 40, 40);
        addButton("9", 70, 40);
        addButton("C", 100, 40);
        addButton("÷", 100, 70);
        addButton("x", 100, 100);
        addButton("-", 130, 70);
        addButton("+", 130, 100);
        addButton("=", 130, 40);
       
    }

    public override void onClick(char c) 
    {
      
        if (negativeNum == true)
        {
            switch (c)
            {
                case '0':
                    Accumulator = Accumulator * 10 + 0;
                    break;
                case '1':
                    Accumulator = Accumulator * 10 - 1;
                    break;
                case '2':
                    Accumulator = Accumulator * 10 - 2;
                    break;
                case '3':
                    Accumulator = Accumulator * 10 - 3;
                    break;
                case '4':
                    Accumulator = Accumulator * 10 - 4;
                    break;
                case '5':
                    Accumulator = Accumulator * 10 - 5;
                    break;
                case '6':
                    Accumulator = Accumulator * 10 - 6;
                    break;
                case '7':
                    Accumulator = Accumulator * 10 - 7;
                    break;
                case '8':
                    Accumulator = Accumulator * 10 - 8;
                    break;
                case '9':
                    Accumulator = Accumulator * 10 - 9;
                    break;
                case '=':
                    negativeNum = false;
                    equal();
                    break;
                case '÷':
                    Operation = c;
                    Operand = Accumulator;
                    Accumulator = 0.0;
                    negativeNum = false;
                    break;
                case 'x':
                    Operation = c;
                    Operand = Accumulator;
                    Accumulator = 0.0;
                    negativeNum = false;
                    break;
                case '+':
                    Operation = c;
                    Operand = Accumulator;
                    Accumulator = 0.0;
                    negativeNum = false;
                    break;
                case '-':
                    Operation = c;
                    Operand = Accumulator;
                    Accumulator = 0.0;
                    negativeNum = false;
                    break;
                case 'C':
                    clear();
                    break;
            }
        }
        else
        {
            switch (c)
            {
                case '0':
                    Accumulator = Accumulator * 10 + 0;
                    break;
                case '1':
                    Accumulator = Accumulator * 10 + 1;
                    break;
                case '2':
                    Accumulator = Accumulator * 10 + 2;
                    break;
                case '3':
                    Accumulator = Accumulator * 10 + 3;
                    break;
                case '4':
                    Accumulator = Accumulator * 10 + 4;
                    break;
                case '5':
                    Accumulator = Accumulator * 10 + 5;
                    break;
                case '6':
                    Accumulator = Accumulator * 10 + 6;
                    break;
                case '7':
                    Accumulator = Accumulator * 10 + 7;
                    break;
                case '8':
                    Accumulator = Accumulator * 10 + 8;
                    break;
                case '9':
                    Accumulator = Accumulator * 10 + 9;
                    break;
                case '=':
                    negativeNum = false;
                    equal();
                    break;
                case '÷':
                    Operation = c;
                    Operand = Accumulator;
                    Accumulator = 0.0;
                    negativeNum = false;
                    break;
                case 'x':
                    Operation = c;
                    Operand = Accumulator;
                    Accumulator = 0.0;
                    negativeNum = false;
                    break;
                case '+':
                    Operation = c;
                    Operand = Accumulator;
                    Accumulator = 0.0;
                    negativeNum = false;
                    break;
                case '-':
                    if (Accumulator == 0.0)
                    {
                        negativeNum = true;
                        break;
                    }
                    Operation = c;
                    Operand = Accumulator;
                    Accumulator = 0.0;
                    negativeNum = false;
                    break;
                case 'C':
                    clear();
                    break;
            }

        }

        if (displayException) { }
        else updateDisplay(Accumulator + "");
     
    }

    public void clear()
    {
        
        Accumulator = 0.0;
        operand = 0.0;
        operation = ' ';
        negativeNum = false;
        displayException = false;
        updateDisplay("");
    }

    public void equal()
    {
        switch (Operation)
        {
            
            case '÷':
               try{
                    if (Accumulator == 0.0)  throw new divideException();      
                    else
                    {
                        Accumulator = operand / Accumulator;
                        break;
                    }
                } catch(divideException e)
                {
                    displayException = true;
                    Console.WriteLine(e.toString());
                    Console.WriteLine(e.ToString());           
                   updateDisplay(e.toString());
                   
                   break;                  
                }
              
            case 'x':
                Accumulator = Accumulator * Operand;
                break;
            case '+':
                Accumulator = Operand + Accumulator;
                break;
            case '-':
                Accumulator = Operand - Accumulator;
                break;
        }
       
        if (Accumulator >= 0.0) negativeNum = false;
        else if (Accumulator < 0.0) negativeNum = true;
         
        
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
