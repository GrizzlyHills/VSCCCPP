/* 啊，那这个push_back呢它显然是 嗯，比较低效的。因为你每一次往这个数组添加一个元素，它都要重新分配存储空间。
这个 时间上是有比较大的开销。嗯，那比较好的做法是什么呢？ 嗯，就是说我这个，空，空间嘛可以预先分配多一点。 
比如说这个数组哪怕是只有一个元素，我一开始也给他32个元素的存储空间， 
那么，这个数组的元素个数1 变到32的过程中，我这个空间都不需要重新分配。 
对吧？然後你加第33个元素进去的时候，我一下就让这个数组的空间里面变成有64个。 
那从33到64这部分，嗯，元素添加的时候呢，也都不需要再重新分配空间了。啊。 
然後，你要添加到6，第65个的时候，我让数组空间一下子变到128个。啊 以此类推。
这样我们重新分配存储空间的次数就会大大减少。当然这个效率也就，嗯，提高了。 
那实际上这个c++,嗯，嗯，标准模版空间有一个vector就是这个可变长的数组， 
它的，它也有push_back的成员函数，然後它push_back的实现方法， 
就跟我刚才说的这样，采用一种比较搞笑的实现发方法。 */


#include <iostream>
#include <cstring>
using namespace::std;

class CArray {
    private:
        int size;                               //数组元素的个数
        int *ptr;                               //指向动态分配的数组
    public:
        CArray(int s = 0);              //s代表数组元素的个数
        CArray(CArray &a);
        ~CArray();
        void push_back(int v);                  //用于在数组尾部添加一个元素v
        CArray &operator=(const CArray &a);     //用于数组元素间的赋值
        int length()                            
        {
            return size;                        //返回数组元素个数
        }
        int &operator[](int i)          //返回值是什么类型？？？返回值为int不行！不支持a[i] = 4;因为返回值可能要作为左值使用，只能返回引用类型
        {
            //用以支持根据下标访问数组元素，
            //如 n = a[i] 和 a[i] = 4; 这样的语句
            return ptr[i];
        }
};
CArray::CArray(int s):size(s)
{
    if(s == 0)
        ptr = NULL;
    else
        ptr = new int[s];
}
CArray::CArray(CArray &a)
{
    if(!a.ptr) {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr,a.ptr,sizeof(int) * a.size);
    size = a.size;
}
CArray::~CArray()
{
    if(ptr)
        delete []ptr;
}
CArray &CArray::operator=(const CArray &a)       //赋值号的作用是使 “=” 左边对象里存放的数组，大小和内容都和右边的对象一样
{
    if(ptr == a.ptr)                            //防止 a = a 这样的赋值导致出错
        return *this;
    if(a.ptr == NULL) {
        if(ptr)
            delete []ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }
    if(size < a.size) {                         //如果原有空间足够大，就不用分配新的空间
        if(ptr)
            delete []ptr;
        ptr = new int [a.size];
    }
    memcpy(ptr,a.ptr,sizeof(int) * a.size);
    size = a.size;
    return *this;
}
void CArray::push_back(int v)                   //在数组尾部添加一个元素
{
    if(ptr) {
        int *tmpPtr = new int[size + 1];        //重新分配空间
        memcpy(tmpPtr,ptr,sizeof(int) * size);   //拷贝原数组内容
        delete []ptr;
        ptr = tmpPtr;
    } else                                      //数组本来是空的
        ptr = new int[1];
    ptr[size++] = v;                            //加入新的数组元素
}

int main()
{
    CArray a;                               //开始数组是空的
    for(int i = 0;i < 50;++i)
        a.push_back(i);                     //输入：0 1 2 3 4
    CArray a2,a3;
    a2 = a;                                 //a2是空的
    for(int i = 0;i < a.length();++i)
        cout << a2[i] <<" ";
    a2 = a3;                                //a2是空的
    for(int i = 0;i < a2.length();++i)      //a2.length()返回0
        cout << a2[i] << " ";
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for(int i = 0;i < a4.length();++i)
        cout << a4[i] << " ";               //输出：0 1 2 100 4
    system("pause");
    return 0;
}
