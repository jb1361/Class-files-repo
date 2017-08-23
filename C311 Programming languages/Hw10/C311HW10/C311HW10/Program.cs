using System;
using System.Collections.Generic;

class HW10
{
    static void Main()
    {
        MyList<int> x = MyList<int>.NIL;
        x = x.cons(3);
        x = x.cons(2);
        x = x.cons(1);

        Console.WriteLine("\n\nx.filter(element => element > 1);");
        MyList<int> t = x.filter(element => element > 1);
        t.apply(element => Console.WriteLine(element));

        Console.WriteLine("\n\nx.tailfilter(element => element > 1, MyList<int>.NIL);");
        t = x.tailfilter(element => element > 1, MyList<int>.NIL);
        t.apply(element => Console.WriteLine(element));

        MyList<string> y = MyList<string>.NIL.cons("Three").cons("Two").cons("One");
        Console.WriteLine("\n\ny");
        y.apply(element => Console.WriteLine(element));

        Console.WriteLine("\n\nTODO: x.map(element => element + 1);");
        t = x.map(element => element + 1);
              t.apply(element => Console.WriteLine(element));

        Console.WriteLine("\n\nTODO: x.reduce((a,b) => a+b, 0)");
             Console.WriteLine(x.reduce((a,b) => a+b, 0));

        Console.WriteLine("\n\nTODO: x.map2((a,b) => a+b);");
        //      t = x.map2((a, b) => a + b, x);
        //      t.apply(element => Console.WriteLine(element));

        Console.WriteLine("\n\nx");
        x.apply(element => Console.WriteLine(element));

        Console.WriteLine("\n\nx");
        x.apply(e => Console.WriteLine(e));
        Console.WriteLine("\n\nabove(x, 1)");
        above(x, 1).apply(e => Console.WriteLine(e));

        Console.WriteLine("\n\nTODO: vecadd");
        //      t = vecadd(x, x);
        //      t.apply(element => Console.WriteLine(element));


        MyList<MyList<int>> z = MyList<MyList<int>>.NIL.cons(x).cons(x);
        Console.WriteLine("\n\nz");
        z.apply(e1 => e1.apply(e2 => Console.WriteLine(e2)));

        //      MyList<MyList<int>> sum = matadd(z, z);
        Console.WriteLine("\n\nTODO: matadd");
        //      sum.apply(e1 => e1.apply(e2 => Console.WriteLine(e2)));

        Func<MyList<int>, MyList<int>> p = stagedFilter(element => element > 1);
        Console.WriteLine("\n\nstagedFilter: p(x)");
        p(x).apply(e => Console.WriteLine(e));

        Console.WriteLine("\n\nmember: x.member(1)");
        Console.WriteLine(x.member(1));
        Console.WriteLine("\n\nmember: x.member(9)");
        Console.WriteLine(x.member(9));
        Console.WriteLine("\n\nTODO: stagedMap");
    }

    static MyList<int> above(MyList<int> L, int x)
    {
        return L.filter(element => element > x);
    }

    static Func<MyList<int>, MyList<int>> stagedFilter(Func<int, bool> p)
    {
        Func<MyList<int>, MyList<int>> filtered = delegate (MyList<int> L)
        {
            return L.filter(p);
        };
        return filtered;
    }
}

class MyList<T>
{
    public delegate void voidFunction(T i);

    public static MyList<T> NIL = new MyList<T>();

    public MyList<T> next;
    private T data;

    public MyList(T n)
    {
        data = n;
        next = NIL;
    }

    private MyList() { }

    private MyList<T> copy()
    {
        MyList<T> head = NIL;
        MyList<T> L = this;
        while (L != NIL)
        {
            MyList<T> t = new MyList<T>(L.data);
            t.next = head;
            head = t;
            L = L.next;
        }
        return head;
    }

    public MyList<T> cons(T h)
    {
        MyList<T> result = this.copy();
        MyList<T> head = new MyList<T>(h);
        head.next = result;
        return head;
    }

    public T hd()
    {
        return this.data;
    }

    public MyList<T> tl()
    {
        if (this.next == NIL) return NIL;
        MyList<T> tail = this.next.copy();
        return tail;
    }

    public MyList<T> filter(Func<T, bool> p)
    {
        if (this == NIL) return NIL;
        if (p(hd())) return tl().filter(p).cons(hd());
        else return tl().filter(p);
    }

    public MyList<T> tailfilter(Func<T, bool> p, MyList<T> a)
    {
        if (this == NIL) return a;
        if (p(hd())) return tl().tailfilter(p, a.cons(hd()));
        else return tl().tailfilter(p, a);
    }

    public void apply(voidFunction f)
    {
        if (this == NIL) return;
        f(hd());
        tl().apply(f);
    }

    public bool member(T a)
    {
        if (this == NIL) return false;
        else
            if (hd().Equals(a)) return true;
        else return tl().member(a);
    }
    public MyList<T> map(Func<T,T> f)
    {
        if (this == NIL) return NIL;
        else return tl().map(f).cons(f(hd()));
    }

    public T reduce(Func<T,T,T> f, T b)
    {
        if (this == NIL) return b;
        else return f(hd(), tl().reduce(f, b));

    }
}