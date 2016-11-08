#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<iterator>
using namespace std ;

//Data to randomsize
int arr[10]= {1,2,3,4,5,6,7,8,9,10};

vector<int> v(arr,arr+10);
template<class Arg>
class FiboRand : public unary_function<Arg,Arg>
{
    int i , j ;
    Arg sequence[18];
public:
    FiboRand();
    Arg operator()(const Arg &arg);
};
/*Arg是用户自定义数据类型。该类还定以了两个成员函数，
一个是构造函数，另一个是operator()（）函数，该操作符允许
random_shuffle()算法象一个函数一样“调用”一个FiboRand对象。
*/
template<class Arg>
FiboRand<Arg>::FiboRand()
{
    sequence[17] = 1 ;
    sequence[16] = 2 ;
    for(int n = 15 ;n > 0 ; n--)
    {
        sequence[n] = sequence[n+1] + sequence[n+2];

    }
    i = 17 ;
    j = 5 ;
}

//FiboRand class fuction operator
template<class Arg>
Arg FiboRand<Arg>::operator()(const Arg &arg)
{
    Arg k = sequence[i] + sequence[j];
    sequence[i] = k ;
    i-- ;
    j-- ;
    if(i== 0)
        i = 17;
    if(j == 0)
        j = 17;
    return k%arg;
}

void Display(vector<int> &vx, const char *s)
{
    cout << endl << s << endl ;
    copy(vx.begin(),vx.end(),ostream_iterator<int>(cout," "));
    cout << endl;
}

int main()
{
    FiboRand<int> fibogen;//Construct generator object
    cout << "Fibonacci random number generator " << endl;
    cout << "using radom_shuffle and a function object " << endl;
    Display(v,"Before shuffle:");
    random_shuffle(v.begin(),v.end(),fibogen);
    Display(v,"After shuffle:");
    return 0;
}

