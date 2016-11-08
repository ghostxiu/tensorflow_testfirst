//函数和断言
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std ;//std 中包含了 vector 等
const long VS = 24 ;//size of vector
vector<long> v(VS);//vector object




void initialize(long &ri);
void show(const long &ri);
bool  isMinus(const long &ri);

int main()
{
    srand(time(NULL));


    for_each(v.begin(),v.end(),initialize);
    //调用普通函数
    //for_each的作用是
    cout  << "Vector of signed long integers" << endl ;
    for_each(v.begin(),v.end(),show);
    cout << endl ;


    int count = 0 ;

    vector<long> :: iterator p =
        find_if(v.begin(),v.end(),isMinus);
        //断言函数,查找负数
    while(p != v.end())
    {
        count++ ;
        p = find_if(p+1,v.end(),isMinus);

    }

    cout << "Number of values: " << VS << endl;
    cout << "Negative values:" << count << endl;

    return 0 ;
}

void initialize(long &ri)
{
    ri = (rand()-(RAND_MAX/2));
    // ri is a random value
}
void show(const long &ri)
{
    cout << ri << " " ;

}

bool isMinus(const long &ri)
{
    return (ri < 0);
}



//这里的断言不同于assert()，是指返回值为bool

/* for_each()的用法
template<typename InputIterator, typename Function>
Function for_each(InputIterator beg, InputIterator end, Function f) {
  while(beg != end) 
    f(*beg++);
}
*/
/* find_if()的用法
template<class InputIterator, class Predicate>  
  InputIterator find_if ( InputIterator first, InputIterator last, Predicate pred )  
  {  
    for ( ; first!=last ; first++ ) if ( pred(*first) ) break;  
    return first;  
  }  

它在区间[first,end)中搜寻使一元判断式pred为true的第一个元素。
*/
