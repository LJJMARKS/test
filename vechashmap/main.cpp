#include<iostream>
#include"vechashtable.h"
using std::cout;
using std::endl;

int main()
{
    VecHashMap hashmap;
    Entry *p=new Entry[5];
    p[0].key=12836;
    p[0].val="hello";
    p[1].key=1563135;
    p[1].val="world";
    p[2].key=12345;
    p[2].val="C++";
    p[3].key=43435;
    p[3].val="Python";
    p[4].key=458735;
    p[4].val="JJ";
    cout<<"tra:"<<endl;
    for (int i=0;i<5;i++)
    {
        hashmap.put(p[i].key,p[i].val);
        cout<<p[i].key<<"->"<<p[i].val<<endl;
    }
    cout<<"search:"<<endl;
    cout<<1563135<<"->"<<hashmap.get(1563135)<<endl;
    cout<<43435<<"->"<<hashmap.get(43435)<<endl;
    cout<<458735<<"->"<<hashmap.get(458735)<<endl;\
    cout<<"remove:"<<43435<<endl;
    cout<<hashmap.remove(43435)<<endl;
    cout<<43435<<"->";
    cout<<hashmap.get(43435)<<endl;
    return 0;


}
