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
    k  = count_if(L.begin(), L.end(),
        not1(bind2nd(greater<int>(), 6)));
    cout << "Number elements < 8 == " << k  <<endl ;
    return 0 ;
}
