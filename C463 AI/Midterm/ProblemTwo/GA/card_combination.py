# File: card_combination.py
# Author: Ben Heil and Justin Butler
# Since: 3/23/18
# This module has a class for the combination of cards

import numpy


class CardComb:

    sum = 0         # The sum of all cards
    product = 0     # The product of all cards
    val = []        # The bit value as a bool array

    def __init__(self):
        count = 0
        self.val = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        while count < 5:
            val = numpy.random.randint(2)
            pos = numpy.random.randint(10)
            self.val[pos] = val
            if val == 1:
                count += 1
        self.sum = 0
        self.product = 1
        for i in range(10):
            if self.val[i] > 0:
                self.product *= i + 1
            else:
                self.sum += i + 1

    def __str__(self):
        return str(self.val) + "Sum: " + str(self.sum) + " Product: " + str(self.product)

    def __repr__(self):
        return self.__str__()


    def process(self):
        self.sum = 0
        self.product = 1
        for i in range(10):
            if self.val[i] > 0:
                self.product *= i + 1
            else:
                self.sum += i + 1