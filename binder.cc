//绑定函数器对象
#include<iostream>
#include<algorithm>
#include<functional>
#include<list>


using namespace std;

int arr[10] = {1,2,3,4,5,6,7,8,9,10};
list<int> L(arr,arr+10);

int main()
{
    int k = 0 ;
    k = count_if(L.begin(),L.end(),bind1st(greater<int>(),8));
    cout << "Number elements < 8 == " << k  <<endl ;
    return 0 ;
}

/*
一个绑定器使用另一个函数对象f()和参数值V创建一个函数对象。
被绑定函数对象必须为双目函数，也就是要有两个参数A和B；
STL中的绑定器有：
bind1st() 创建一个函数对象，该函数对象值V作为第一个参数A；
bind2st() 创建一个函数对象，该函数对象值V作为第二个参数B。
*/
/* std::count_if
原型：
  template<class InputIterator, class Predicate>
   typename iterator_traits<InputIterator>::difference_type count_if(
      InputIterator _First,
      InputIterator _Last,
      Predicate _Pred
   );
_First 输入迭代器，指向将被搜索的区间第一个元素的位置。
_Last 输入迭代器，指向将被搜索的区间最后一个元素后面的。
_Pred 用户自定义的 predicate function object ，定义了元素被计数需满足的条件。
predicate 只带一个参数，返回 true 或 false.
*/
/*
bind1st(greater<int>(), 8)
该表达式将greater<int>()和一个参数值8捆绑
为一个函数对象。由于使用了bind1st()，
所以该函数相当于计算下述表达式：
8 > q
*/
