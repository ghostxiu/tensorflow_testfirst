#coding=utf-8

'''
tf.estimator是一个简化机器学习的tensorflow高级库
包括：运行训练循环，运行评估循环，管理数据集

tf.estimator is a high-level TensorFlow library that simplifies the mechanics of machine learning, including the following:

running training loops
running evaluation loops
managing data sets
tf.estimator defines many common models.
'''

import tensorflow as tf 
import numpy as np


feature_columns = [tf.feature_column.numeric_column("x", shape=[1])]

'''
Declare list of features. We only have one numeric feature. There are many
other types of columns that are more complicated and useful.
feature_columns = [tf.feature_column.numeric_column("x", shape=[1])]
An estimator is the front end to invoke training (fitting) and evaluation
(inference). There are many predefined types like linear regression,
linear classification, and many neural network classifiers and regressors.
The following code provides an estimator that does linear regression.
estimator是调用训练（拟合）和评估（推理）的前端。有许多预定义的类型，如线性回归，线性分类和许多神经网络分类器和回归。
以下代码提供了一个线性回归的estimator。
'''
estimator = tf.estimator.LinearRegressor(feature_columns=feature_columns)

'''
TensorFlow provides many helper methods to read and set up data sets.
Here we use two data sets: one for training and one for evaluation
We have to tell the function how many batches of data (num_epochs) we 
want and how big each batch should be.

TensorFlow提供了许多帮助方法来读取和设置数据集。
这里我们使用两个数据集：一个用于训练，一个用于评估
我们必须告诉功能我们想要多少批次数据（num_epochs），每个批次应该有多大。
'''
x_train = np.array([1., 2., 3., 4.])
y_train = np.array([0., -1., -2., -3.])
x_eval = np.array([2., 5., 8., 1.])
y_eval = np.array([-1.01, -4.1, -7, 0.])
input_fn = tf.estimator.inputs.numpy_input_fn(
    {"x": x_train}, y_train, batch_size=4, num_epochs=None, shuffle=True)
train_input_fn = tf.estimator.inputs.numpy_input_fn(
    {"x": x_train}, y_train, batch_size=4, num_epochs=1000, shuffle=False)
eval_input_fn = tf.estimator.inputs.numpy_input_fn(
    {"x": x_eval}, y_eval, batch_size=4, num_epochs=1000, shuffle=False)

# We can invoke 1000 training steps by invoking the  method and passing the
# training data set.
#我们可以通过调用该方法并传递训练数据集经过1000个训练步骤
estimator.train(input_fn=input_fn, steps=1000)

# Here we evaluate how well our model did.
#我们用下面的方法来评估模型的好坏
train_metrics = estimator.evaluate(input_fn=train_input_fn)
eval_metrics = estimator.evaluate(input_fn=eval_input_fn)
print("train metrics: %r"% train_metrics)
print("eval metrics: %r"% eval_metrics)