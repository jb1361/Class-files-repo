# File: main.py
# Authors: Ben Heil and Justin Butler
# Since: 3/28/18
# This is the driver for the GA


from GA import genetic_ops


def main():
    pop = genetic_ops.make_pop(30)
    lowest = 10000000
    while lowest != 0.0:
        pop = genetic_ops.recombine_pop(pop, 15)
        genetic_ops.evel_pop(pop, 36, 360)
        lowest = genetic_ops.print_lowest_if_found(pop, lowest)




if __name__ == '__main__':
    main()

'''
Output:
Found better solution!!!
[1, 1, 0, 0, 0, 0, 1, 0, 0, 0]Sum: 45 Product: 14 Fitness: 1.2111111111111112
Found better solution!!!
[0, 0, 0, 0, 1, 1, 0, 0, 0, 0]Sum: 44 Product: 30 Fitness: 1.1388888888888888
Found better solution!!!
[0, 1, 0, 0, 1, 1, 0, 0, 0, 0]Sum: 42 Product: 60 Fitness: 1.0
Found better solution!!!
[0, 0, 1, 0, 0, 0, 0, 1, 1, 0]Sum: 35 Product: 216 Fitness: 0.4277777777777778
Found better solution!!!
[0, 0, 0, 0, 1, 0, 0, 1, 1, 0]Sum: 33 Product: 360 Fitness: 0.08333333333333333
Found better solution!!!
[0, 1, 0, 1, 0, 1, 1, 0, 0, 0]Sum: 36 Product: 336 Fitness: 0.06666666666666667
Found better solution!!!
[1, 0, 1, 1, 1, 1, 0, 0, 0, 0]Sum: 36 Product: 360 Fitness: 0.0

Process finished with exit code 0
'''