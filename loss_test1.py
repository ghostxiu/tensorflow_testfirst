#coding=utf-8
#简单描述模型和损失函数
import tensorflow as tf

#使用linear_model来评测x占位符
W = tf.Variable([.3], dtype=tf.float32)
b = tf.Variable([-.3], dtype=tf.float32)
x = tf.placeholder(tf.float32)
linear_model = W * x + b

tf.global_variables_initializer
init_op = tf.initialize_all_variables()
sess = tf.Session()
sess.run(init_op)
#此处出现变量未声明的错误，使用以上四行声明初始化变量
print(sess.run(linear_model, {x: [1, 2, 3, 4]}))

#创建损失函数，来评价误差
y = tf.placeholder(tf.float32)
squared_deltas = tf.square(linear_model - y)
loss = tf.reduce_sum(squared_deltas)
print('loss = %f'%sess.run(loss, {x: [1, 2, 3, 4], y: [0, -1, -2, -3]}))
#loss = sum(((W * x + b)-y)^2)

#手动修正W和b(通过tf.assign())来确定最佳参数,损失函数值为0时效果最佳
fixW = tf.assign(W,[-1.])
fixb = tf.assign(b,[1.])
sess.run([fixW,fixb])
print('fixed loss = %f'%sess.run(loss,{x:[1,2,3,4],y:[0,-1,-2,-3]}))
#当前模型的W和b的最优值为-1和1



#__________________________________________________________________________
#使用api tf.train
#tensorflow 使用函数tf,gradients自动生成给出模型描述的倒数，优化器自动为我们完整这些，下面是简单的例子

optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)
for i in range(1000):
	sess.run(train,{x:[1,2,3,4],y:[0,-1,-2,-3]})
print(sess.run([W,b])) 


