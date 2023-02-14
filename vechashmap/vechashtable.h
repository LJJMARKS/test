#ifndef VECHASHTABLE_H
#define VECHASHTABLE_H
#include<vector>
#include<string>
#include<list>
using std::vector;
using std::string;
//链址法解决哈希冲突
class Entry {
    friend class VecHashMap;
private:

public:
    int key;
    string val;
    Entry *next;
    explicit Entry(Entry *ptr=nullptr){
        key=0;
        next=ptr;
    }
    Entry(int &key, string &val,Entry *ptr=nullptr) {
        this->key = key;
        this->val = val;
        this->next=ptr;
    }
};

/* 基于向量简易实现的哈希表 */
class VecHashMap {
private:
    vector<Entry*> bucket;
public:
    VecHashMap() {
        // 初始化一个长度为 100 的桶（数组）
        bucket= vector<Entry*>(100);
    }

    /* 哈希函数 */
    static int hashFunc(int key) {
        int index = key % 100;
        return index;
    }


    /* 查询操作 */
    string get(int key)
    {
        int index = hashFunc(key);
        Entry *p=bucket[index];
        while (p)
        {

            if(p->key==key)//查找的key 与每一个元素的key比较
            {
                return p->val;
            }
            else
            {
                p=p->next;
            }

        }

        return "cannot find";
    }

    /* 添加操作 */
    void put(int key, string val) {
        int index = hashFunc(key);
        Entry *p=bucket[index];
        while (p)
        {
            if(index==hashFunc(bucket[index]->key))
            p=p->next;
        }
        p=new Entry(key,val,nullptr);
        p->next=bucket[index];

        bucket[index] = p;
    }

    /* 删除操作 */
    bool remove(int key) {
        int index = hashFunc(key);
        Entry *p=bucket[index];
        while (p)
        {
            if(p->key==key)
            {
                delete p;
                return true;

            }
            else
            {
                p=p->next;
            }
        }
        return false;

    }
};
#endif // VECHASHTABLE_H
