# File: main.py
# Authors: Ben Heil and Justin Butler
# Since: 3/29/18
# This is the driver for the neural network


from NN import  train
import os



def main():
    estimator = train.build_estimator("../temp/out")
    path = os.path.abspath("..")

    def train_input_fn():
        return train.input_fn(
            path + "/titanic.csv", 2, True, 40
        )

    def eval_input_fn():
        return train.input_fn(
            path + "/titanic.csv", 1 , False, 40
        )

    for n in range(train.training_ex):
        estimator.train(input_fn=train_input_fn)
        results = estimator.evaluate(input_fn=eval_input_fn)
        print('Results at epoch', (n + 1))
        print('-' * 60)

        for key in sorted(results):
            print('%s: %s' % (key, results[key]))



if __name__ == '__main__':
    main()