//迭代器和流一起工作
//任何迭代器都可以和流一起工作
#include <iostream>
#include <stdlib.h>    // Need random(), srandom()
#include <time.h>    // Need time()
#include <algorithm>   // Need sort(), copy()
#include <vector>      // Need vector 
#include<iterator>// ostream_iterator Need
using namespace std;
void Display(vector<int>& v, const char* s);
int main()
{
    //Seed the random number generator
    srand( time(NULL) );
    //VC++的头文件stdlib.h中没有srandom()和random(),所以用srand()和rand()替代。
    //Construct vector and fill with random integer values
    vector<int> collection(10);
    for(int i = 0; i < 10; i++)
    collection[i] = rand() % 10000;

    //Display, sort, and redisplay
    Display(collection, "Before sorting");
    sort(collection.begin(), collection.end());
    Display(collection, "After sorting");
    return 0;
}
//Display label s and contents of integer vector v
void Display(vector<int>& v, const char* s)
{
    cout << endl << s << endl;
    copy(v.begin(), v.end(),ostream_iterator<int>(cout,"\t"));
    cout << endl;
}
