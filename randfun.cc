//发生器函数对象
#include<iostream>
#include<cstdlib>//rand , srand
#include<ctime>//need time
#include<algorithm> //random_shuffle()
#include<vector>
#include<functional> // ptr_fun()
#include<iterator>
using namespace std ;

//Data to randomsize
int arr[10]= {1,2,3,4,5,6,7,8,9,10};

vector<int> v(arr,arr+10);
//注意这种vector的声明方式


//Funtion prototypes
void Display(vector<int> &vr, const char *s)
{
    cout << endl << s << endl ;
    copy(vr.begin(),vr.end(),ostream_iterator<int>(cout," "));
    cout << endl ;
}
unsigned int RandInt(const unsigned int n)
{
    return rand() % n;
}

int main()
{
    srand(time(NULL));
    Display(v,"Before shuffle");

    pointer_to_unary_function<unsigned int ,unsigned int >
        ptr_RandInt = ptr_fun(RandInt);

    //这儿使用STL的单目函数模板定义了一个变量ptr_RandInt，并将地址初始化到我们的函数RandInt()。
    //单目函数接受一个参数，并返回一个值。现在random_shuffle()可以如下调用：
    //random_shuffle(v.begin(), v.end(), ptr_RandInt);在本例子中，发生器只是简单的调用rand()函数。

    //ptr_fun是将一个普通的函数适配成一个仿函数(functor),
    random_shuffle(v.begin(),v.end(),ptr_RandInt);
    Display(v,"After shuffle");
    return 0;
}


/* std::random_shuffle //xxx-?随机排序
template <class RandomAccessIterator, class RandomNumberGenerator>
  void random_shuffle (RandomAccessIterator first, RandomAccessIterator last,
                       RandomNumberGenerator& gen)
{
  iterator_traits<RandomAccessIterator>::difference_type i, n;
  n = (last-first);
  for (i=n-1; i>0; --i) {
    swap (first[i],first[gen(i+1)]);
  }
}
*/
