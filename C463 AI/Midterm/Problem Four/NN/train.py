# File: train.py
# Authors: Ben Heil and Justin Butler
# Since: 3/29/18
# This file trains the neural network for survived along Pclass, sex, age, and fare
# made with tutorial code found at https://github.com/tensorflow/models/blob/master/official/wide_deep/wide_deep.py


import tensorflow as tf
import shutil


training_ex = int(891 * .7)
test_ex = int(891 * .3)


def build_columns():
    """builds the columns for this data set"""

    Pclass = tf.feature_column.numeric_column('Pclass', default_value=1)
    Age = tf.feature_column.numeric_column('Age', default_value=30.0)
    Sex = tf.feature_column.categorical_column_with_vocabulary_list('Sex', ['male', 'female'])
    Fare = tf.feature_column.numeric_column('Fare', default_value=0.0)

    return [Pclass, Sex, Age, Fare]


def build_estimator(model_dir):
    """creates a linear estimator
    from tensorflow API"""
    columns = build_columns()
    shutil.rmtree(model_dir, ignore_errors=True)
    return tf.estimator.LinearClassifier(
        model_dir=model_dir,
        feature_columns=columns
    )


def input_fn(file, num_epochs, shuffle, batch_size):
    """The input function for the network"""
    assert tf.gfile.Exists(file), ('%s file not found!' % file)


    def parse_csv(value):
        columns = tf.decode_csv(value, record_defaults=[[0], [''], [0.0], [0.0], [0]])
        print(columns)
        features = dict(zip(['Pclass', 'Sex', 'Age', 'Fare', 'Survived'], columns))
        labels = features.pop('Survived')
        return features, tf.equal(labels, 1)

    dataset = tf.data.TextLineDataset(file)

    if shuffle:
        dataset = dataset.shuffle(buffer_size=training_ex)

    dataset = dataset.map(parse_csv, num_parallel_calls=None)

    dataset = dataset.repeat(num_epochs)
    dataset = dataset.batch(batch_size)

    return dataset






