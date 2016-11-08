//容器迭代器范例
//实现和iterdemo一样的功能
//两个典型的容器方法是end()和begin(),有些反向迭代器还有rend()和rebegin()功能
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> intVector(100);

int main()
{
    intVector[20] =50;
    vector<int>::iterator InteRator =
        find(intVector.begin(),intVector.end(),50);
    if(InteRator == intVector.end())
        cout << "50 is not in vector\n" ;
    else
        cout << "Vector contains value " << *InteRator << endl ;

    return 0;
}
