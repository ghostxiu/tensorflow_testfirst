//函数对象
#include<iostream>
#include<numeric>//accumulate
#include<vector>
#include<functional>// multiplies()(or times())


using namespace std;
const long MAX = 10 ;

vector<long> v(MAX);

int main()
{
    for(int i = 0 ; i <MAX;i++)
    {
        v[i]=i+1;
    }

    long sum = accumulate(v.begin(),v.end(),0);
    cout << "Sum of value ==" << sum << ".\n";

    long product =
        accumulate(v.begin(),v.end(),1,multiplies<long>());
    cout << "Product of value == " << product << ".\n" ;

    return 0 ;
}

/* std::accumulate() 函数用法
accumulate()累积 中包含product求乘积和sum 求和
求和用法：
acculumate(arr,arr+size,0)
求积用法:
acculumate(arr,arr+size,1,multiplies<int>)
template <class InputIterator, class T>  
   T accumulate (InputIterator first, InputIterator last, T init)  
{  
  while (first!=last) {  
    init = init + *first;  // or: init=binary_op(init,*first) for the binary_op version  
    ++first;  
  }  
  return init;  
}  
*/
/* std::multiplies() 函数
c++ 98
template <class T> struct multiplies : binary_function <T,T,T> {
  T operator() (const T& x, const T& y) const {return x*y;}
};
c++ 11
template <class T> struct multiplies {
  T operator() (const T& x, const T& y) const {return x*y;}
  typedef T first_argument_type;
  typedef T second_argument_type;
  typedef T result_type;
};
*/
