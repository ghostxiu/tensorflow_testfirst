#include<iostream>
#include<algorithm>//Need copy()
#include<vector> //Need vector
//输出迭代器
using namespace std;

double darray[10] =
{1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9
};

vector<double> vdouble(10);

int main()
{
    vector<double>::iterator outputIterator = vdouble.begin();
    copy(darray,darray+10,outputIterator);
    while(outputIterator != vdouble.end())
    {
        cout << *outputIterator << endl ;
        outputIterator++;
    }
    return 0;
}
//当使用copy算法的时候，你必须确保容器有足够大恶的空间活着容器本身是自动拓展的
