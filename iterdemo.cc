//指针迭代器
#include<iostream>
#include<algorithm>

using namespace std ;

#define S 100

int arr[S];

int main ()
{
    arr[20] = 50 ;
    int *ip = find(arr,arr+S,50);
    if(ip == arr + S)
        //为了判断find()是否成功在例子中测试ip 和past-end是否相等。
        cout << "50 is not in arr\n";
    else
        cout << *ip << " find in arr\n";

    return 0;
}
