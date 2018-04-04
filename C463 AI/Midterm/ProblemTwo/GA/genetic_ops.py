# File: genetic_ops.py
# Authors: Ben Heil and Justin Butler
# Since: 3/28/18
# This module performs genetic operations on card combinations


import numpy
from . import card_combination


def crossover(c1, c2):
    '''crosses over c1 with c2
    returning a new combination
    with the recombination operator'''
    count = 0
    c = card_combination.CardComb()
    c.val = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    while count < numpy.random.randint(4):
        pos = numpy.random.randint(10)
        if c2.val[pos]:
            c.val[pos] = 1
            count += 1
    count = 0
    while count < numpy.random.randint(4):
        pos = numpy.random.randint(10)
        if c1.val[pos]:
            c.val[pos] = 1
            count += 1
    # add a one in a random spot, don't care if already one
    c.process()
    return c


def eval_fitness(c, tsum, tproduct):
    '''evaluates how close the sum
    and product are to determine fitness'''
    sum_score = abs(c.sum - tsum) / tsum
    pro_score = abs(c.product - tproduct) / tproduct
    return sum_score + pro_score


def make_pop(size):
    pop = []
    for i in range(size):
        pop.append((card_combination.CardComb(), 0))  # second val is fitness
    return pop


def recombine_pop(pop, threshold):
    '''recombines all members
    below a certain fitness threshold
    and throws away the rest

    threshold <= len(pop) / 2'''
    actual = threshold // 2
    pop.sort(key=lambda x: x[1], reverse=True)  # sorts by lowest fitness
    for i in range(actual):
        pop[i] = (crossover(pop[i][0], pop[i + actual][0]), 0)
    for i in range(actual, len(pop)):
        pop[i] = (card_combination.CardComb(), 0)
    return pop


def evel_pop(pop, tsum, tproduct):
    '''evaluates the fitness of a population'''
    for i in range(len(pop)):
        pop[i] = (pop[i][0], eval_fitness(pop[i][0], tsum, tproduct))
    return pop


def print_lowest_if_found(pop, lowest):
    for i in range(len(pop)):
        if pop[i][1] < lowest:
            print("Found better solution!!!")
            print(str(pop[i][0]) + " Fitness: " + str(pop[i][1]))
            lowest = pop[i][1]
    return lowest


def print_pop(pop):
    for i in range(len(pop)):
        print(str(pop[i][0]) + " Fitness: " + str(pop[i][1]))