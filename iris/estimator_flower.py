#coding=utf-8
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
import urllib

import numpy as np
import tensorflow as tf

'''
ensorFlow的高级机器学习API（tf.estimator）可以轻松配置，训练和评估各种机器学习模型。
在本教程中，您将使用tf.estimator构建神经网络分类器，并在Iris数据集上进行训练，以基于
萼片/花瓣几何来预测花种。您将编写代码以执行以下五个步骤：
将包含Iris训练/测试数据的CSV加载到TensorFlow数据集中
构建神经网络分类器
使用训练数据训练模型
评估模型的准确性
分类新样本
'''

# Data sets
# 设定数据集
# 120个样本的训练集（iris_training.csv） 和一个30个样本的测试集iris_test.csv
IRIS_TRAINING = "iris_training.csv"
IRIS_TRAINING_URL = "http://download.tensorflow.org/data/iris_training.csv"

IRIS_TEST = "iris_test.csv"
IRIS_TEST_URL = "http://download.tensorflow.org/data/iris_test.csv"
# 如果培训和测试集尚未存储在本地，则下载

def main():
  # If the training and test sets aren't stored locally, download them.
  if not os.path.exists(IRIS_TRAINING):
    raw = urllib.urlopen(IRIS_TRAINING_URL).read()
    with open(IRIS_TRAINING, "w") as f:
      f.write(raw)

  if not os.path.exists(IRIS_TEST):
    raw = urllib.urlopen(IRIS_TEST_URL).read()
    with open(IRIS_TEST, "w") as f:
      f.write(raw)

  # 接下来使用learn.datasets.base中的load_csv_with_header()方法将训练和测试集加载到datasets中。
  # Load datasets.
  '''
  load_csv_with_header（）方法需要三个必需的参数：
  1文件名，将文件路径引入CSV文件
  2target_dtype，它采用数据集目标值的numpy数据类型。
  3features_dtype，它使用数据集的特征值的numpy数据类型。
  在这里，目标（你正在训练模型预测的值）是花种，它是0-2的整数，所以适当的numpy数据类型是np.int：
  '''
  training_set = tf.contrib.learn.datasets.base.load_csv_with_header(
      filename=IRIS_TRAINING,
      target_dtype=np.int,
      features_dtype=np.float32)
  test_set = tf.contrib.learn.datasets.base.load_csv_with_header(
      filename=IRIS_TEST,
      target_dtype=np.int,
      features_dtype=np.float32)
  '''
  tf.contrib.learn中的数据集被命名为元组;您可以通过数据和目标字段访问特征数据和目标值。
  这里，training_set.data和training_set.target分别包含训练集的特征数据和目标值，
  test_set.data和test_set.target包含测试集的要素数据和目标值。
  稍后，在“将DNNC分类器安装到Iris训练数据”中，您将使用training_set.data和training_set.target
  来训练您的模型，并在“评估模型精度”中使用test_set.data和test_set.target 。但首先，您将在下一节中构建您的模型。
  '''
	
	
	
  '''
  配置深层神经网络分类器模型以适应Iris数据。使用tf.estimator，
  您可以使用几行代码实例化tf.estimator.DNNClassifier：
  '''
  # Specify that all features have real-value data
  feature_columns = [tf.feature_column.numeric_column("x", shape=[4])]

  # Build 3 layer DNN with 10, 20, 10 units respectively.
  classifier = tf.estimator.DNNClassifier(feature_columns=feature_columns,
                                          hidden_units=[10, 20, 10],
                                          n_classes=3,
                                          model_dir="/tmp/iris_model")
  '''
  上面的代码首先定义了模型的特征列，它们指定数据集中的要素的数据类型。所有的特征数据是连续的，所以tf.feature_column.numeric_colum
  是用来构造特征列的适当函数。数据集中有四个特征（萼片宽度，萼片高度，花瓣宽度和花瓣高度），因此必须将形状设置为[4]以保存所有数据。
  然后，代码使用以下参数创建一个DNNClassifier模型：
  feature_columns = feature_columns。上面定义的特征列集合。
  hidden_units = [10，20，10]。三个隐藏层，分别含有10,20和10个神经元。
  n_classes = 3。三个目标类，代表三种Iris物种。
  model_dir = / TMP / iris_model，保存一些Checkpoint，
  这样Tensorflow就可以随时保存训练情况了（还可以暂停后继续训练）
  '''
  # Define the training inputs
  # 使用tf.estimator.inputs.numpy_input_fn来生成输入管道
  train_input_fn = tf.estimator.inputs.numpy_input_fn(
      x={"x": np.array(training_set.data)},
      y=np.array(training_set.target),
      num_epochs=None,
      shuffle=True)

  # Train model.
  classifier.train(input_fn=train_input_fn, steps=2000)
  '''
  迭代训练2000步，相当于： 
	classifier.train(input_fn=train_input_fn, steps=1000)
	classifier.train(input_fn=train_input_fn, steps=1000)
  '''
  # Define the test inputs
  test_input_fn = tf.estimator.inputs.numpy_input_fn(
      x={"x": np.array(test_set.data)},
      y=np.array(test_set.target),
      num_epochs=1,
      shuffle=False)

  # Evaluate accuracy.
  accuracy_score = classifier.evaluate(input_fn=test_input_fn)["accuracy"]

  print("\nTest Accuracy: {0:f}\n".format(accuracy_score))
  #加入了三个花，去预测它们，这里的预测结果可能是1,1,0
  # Classify two new flower samples.
  new_samples = np.array(
      [[6.4, 3.2, 4.5, 1.5],
       [5.8, 3.1, 5.0, 1.7],
	   [4.7, 3.0, 1.3, 0.2]], dtype=np.float32)
  predict_input_fn = tf.estimator.inputs.numpy_input_fn(
      x={"x": new_samples},
      num_epochs=1,
      shuffle=False)

  predictions = list(classifier.predict(input_fn=predict_input_fn))
  predicted_classes = [p["classes"] for p in predictions]

  print(
      "New Samples, Class Predictions:    {}\n"
      .format(predicted_classes))

if __name__ == "__main__":
    main()