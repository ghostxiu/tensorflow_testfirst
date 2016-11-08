//插入迭代器
//只用单个copy()语句就可以完成将矢量中的对象插入到链表的前端的操作
#include<iostream>
#include<algorithm>
#include<list>
#include<iterator>//front_inserter(),ostream_iterator need
#include <algorithm>//copy() need
using namespace std;
void Display(list<int> &v,const char *s)
{
    cout << endl << s << endl ;
    copy(v.begin(),v.end(),std::ostream_iterator<int>(cout , " "));
    cout << endl;
}
int iArray[5] = {1,2,3,4,5};
int main()
{
    list<int> iList;
//Copy iArr backwards into iList
    copy(iArray,iArray+5,front_inserter(iList));
    Display(iList,"Before find and copy");
//将对象插入到数据集前面
    //Locate value 3 in iList
    list<int>:: iterator p =
        find(iList.begin(),iList.end(),3) ;

    //Copy fist two iArray values to iList ahead of p
    copy(iArray,iArray+2,inserter(iList,p));
    //将对象插入到容器的p对象前面
    Display(iList,"After find and copy");


    copy(iArray,iArray+2,back_inserter(iList));
    Display(iList,"After  copy to the end");
    return 0 ;
}
/*三种插入迭代器
普通插入器 inserter 将对象插入到容器的任何对象前面
front_inserter 将对象插入数据集的前面————例如，链表表头。
back_inserter 将对象插入到集合的尾部————例如，矢量的尾部。
*/
