import math


def dx(f, x):
    return abs(0-f(x))


def newtons_method(f, df, x0, e):
    delta = dx(f, x0)
    while delta > e:
        x0 = x0 - f(x0)/df(x0)
        delta = dx(f, x0)
        print(delta)
        print(e)
    print('Root is at: ', x0)
    print('f(x) at root is: ', f(x0))


def f(x):
    return x*math.log2(x)


def df(x):
    return math.log2(x)**x + (1/math.log(2))


newtons_method(f, df, 10**6, 1e-5)
