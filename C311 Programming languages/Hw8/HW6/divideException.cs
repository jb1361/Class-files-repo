using System;
using System.Collections.Generic;
using System.Text;


public class divideException : Exception
{
    string field;

    public divideException()
    {
        field = "Cannot Divide By 0";
    }

    public string toString()
    {

        return field;
    }

}

