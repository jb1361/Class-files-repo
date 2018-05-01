from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import tensorflow as tf
import pandas as pd
import math
import numpy as np

"""
data = pd.read_csv('creditcard.csv')

# Drop date variable
data = data.drop(['Time'], 1)
data = data.drop(['Class'], 1)
data = data.drop(['Amount'], 1)
percent = math.floor((len(data)/2))
training_data = data[0:percent]
testing_data = data[percent+1:len(data)]

# Make data a numpy array
#training_data = np.array(training_data).transpose()
#testing_data = np.array(testing_data).transpose()
training_data = training_data.astype(int)
testing_data = testing_data.astype(int)
training_data.to_csv('training_set.csv', index = False,header = False)
testing_data.to_csv('testing_set.csv',index = False,header = False)
#training_data.to_csv('training_set.csv', index = False)
#testing_data.to_csv('testing_set.csv',index = False)
"""


_CSV_COLUMNS = [
    'Time', 'V1', 'V2', 'V3', 'V4', 'V5', 'V6', 'V7', 'V8', 'V9', 'V10', 'V11', 'V12', 'V13',
    'V14', 'V15', 'V16', 'V17', 'V18', 'V19', 'V20', 'V21', 'V22', 'V23', 'V24', 'V25', 'V26',
    'V27', 'V28', 'Amount', 'Class'
]
_CSV_COLUMN_DEFAULTS = [[0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0],
                        [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0],
                        [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0], [0.0],[0.0]]

def parse_csv(value):
    columns = tf.decode_csv(value, record_defaults=_CSV_COLUMN_DEFAULTS)
    features = dict(zip(_CSV_COLUMNS, columns))
    labels = features.pop('Class')
    return features, tf.equal(labels,1)

def input_fn(data_file, num_epochs, batch_size,start,end):
    dataset = tf.data.TextLineDataset(data_file)
    dataset = dataset.map(parse_csv, num_parallel_calls=2)
    dataset = dataset.skip(start)
    dataset = dataset.take(end)
    dataset = dataset.repeat(num_epochs)
    dataset = dataset.batch(batch_size)
    return dataset
	
	
feature_columns = [tf.feature_column.numeric_column(k) for k in _CSV_COLUMNS[1:29]]
classifier = tf.estimator.DNNClassifier(
	temp_dir = "\HW5",
	feature_columns= feature_columns,
	hidden_units=[1024, 512, 256])

classifier.train(lambda: input_fn('creditcardnoheaders.csv',1,100,0,50000), steps = 2000)


  
# Evaluate accuracy.
accuracy_score = classifier.evaluate(lambda: input_fn('creditcardnoheaders.csv',1,100,50000,100000))["accuracy"]

print("\nTest Accuracy: {0:f}\n".format(accuracy_score))
