#include<iostream>
#include<vector>
#include<iterator>
#include<list>
#include<algorithm> //find() need
//两个迭代器函数
//advance()是顶数目的增减迭代器
//distance()返回两个迭代器之间的距离。
using namespace std;
int arr[5]={1,2,3,4,5};
void Display(list<int> &v,const char *s)
{
    cout << endl << s << endl ;
    copy(v.begin(),v.end(),std::ostream_iterator<int>(cout , " "));
    cout << endl;
}
int main()
{
    list<int> iList;
    //如果使用front_inserter 会依次将元素插入前端，导致数组倒置
    copy(arr,arr+5,back_inserter(iList));
    list<int>::iterator p =
                find(iList.begin(),iList.end(),2);
    Display(iList,"Before advance");
    cout << "before: p == " << *p << endl;
    advance(p,4);//same as p = p+2;
    cout << "after : p == " << *p << endl;
    Display(iList,"After advance");

    int k = 0 ;
    k = distance(p,iList.end());
    cout << "k == " << k << endl;
    return 0;

}
