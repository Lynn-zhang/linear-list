
#include<iostream>
using namespace std;
#include<assert.h>
#include"SList.h"
  
   LinkNode::LinkNode(const DataType x)
           :_data(x)
           , _next(NULL)
           {}
  
    SList::SList()         //构造函数
        :_head(NULL)
        , _tail(NULL)
    {}
    SList::SList(const SList& s)          //拷贝构造
        :_head(NULL)
        , _tail(NULL)
    {
        if (s._head == NULL)
        {
            return;
        }
        LinkNode* tmp = s._head;
        do{
            PushBack(tmp->_data);
            tmp = tmp->_next;
            } while (tmp != s._head);
          
    }
    //赋值运算符的重载（传统方法）
    //SList & SList::operator=(const SList& s)   
    //{
    //  if (this != &s)
    //  {
    //      _head = NULL;
    //      _tail = NULL;
    //      LinkNode* tmp = s._head;
    //  do{
    //      PushBack(tmp->_data);
    //      tmp = tmp->_next;
    //       } while (tmp != s._head);
    //  }
    //  return *this;
    //}
      
    //赋值运算符的重载（高效写法）
    /*void SList::Swap(SList& s)    
    {
    swap(_head, s._head);
    swap(_tail, s._tail);
  
    }
    SList&  SList::operator=(SList &s)
    {
    if (this != &s)
    {
    SList tmp(s);
    Swap(tmp);
    }
    return *this;
    }*/
  
    SList&  SList::operator=(SList &s)     //赋值运算符的重载再优化(推荐写法)
    {
        if (this != &s)
        {
            swap(_head, s._head);
            swap(_tail, s._tail);
        }
        return *this;
    }
    SList::~SList()    //析构
    {
        Clear();
    }
          
        void SList::Reverse()   //链表逆置（利用头插新节点的方法）
    {
        if (_head == NULL||_head->_next==_tail)
        {
            return;
        }
        int ret = Amount();
        _tail = new LinkNode(_head->_data);
        LinkNode* begin=NULL;
        LinkNode* tmp = _tail;
        while (--ret)
        {
            LinkNode* del = _head;
            _head = _head->_next;
            delete del;    //这里不要忘记做清理工作，否则内存泄漏
            begin = new LinkNode(_head->_data);
            begin->_next = tmp;
            _tail->_next = begin;
            tmp = begin;
        }
        _head = begin;
    } 
  
        //打印链表
    void SList::PrintSList() 
    {
        //头结点为空时，无需打印链表
        if (_head==NULL)
        {
            cout << "This SList is Empty !" << endl;
            return;
        }
        else
        {
            LinkNode* tmp = _head;
            do{
                cout << tmp->_data << "-->";
                tmp = tmp->_next;
                } while (tmp != _head);
            cout << endl;
        }
    }
    void SList::PushBack(const DataType& x)    //在尾部插入一个节点
    {
        //如果链表为空，插入节点后只有一个节点，此时_head=_tail
        if (_head == NULL)
        {
            _head = new LinkNode(x);
            _tail = _head;
            _tail->_next = _head;
        }
        else
        {
            _tail->_next = new LinkNode(x);
            _tail = _tail->_next;
            _tail->_next = _head;
        }
    }
    void SList::Clear()         //链表置空
    {
        LinkNode* begin = _head;
        while (begin != _tail)
        {
            _head = _head->_next;
            delete begin;
            begin = _head;
        }
        _head = NULL;
        _tail = NULL;
    }
    void SList::PopBack()    //尾删
    {
        if (_head == NULL)
        {
            cout << "This SList is empty !" << endl;
        }
        else if (_head == _tail)
        {
            delete _head;
            _head = NULL;
            _tail = NULL;
        }
        else
        {
            LinkNode* cur = _head;
            while (cur->_next != _tail)
            {
                cur = cur->_next;
            }
            delete _tail;
            _tail = cur;
            _tail->_next = _head;
         }
    }
    void SList::PushFront(DataType x)  //头插
    {
        if (_head == NULL)
        {
            PushBack(x);
        }
        else
        {
            LinkNode* tmp = _head;
            _head = new LinkNode(x);
            _head->_next = tmp;
            _tail->_next = _head;
        }
    }
    void SList::PopFront()    //删除首节点
    {
        if (_head == NULL)
        {
            cout << "This SList is empty !" << endl;
            return;
        }
        LinkNode* tmp = _head;
        _head = _head->_next;
        _tail->_next = _head;
        delete tmp;
    }
  
    //固定位置插入一个节点（这个函数需和Find函数搭配使用）
    //先用Find函数找到新节点需要插入的位置
    //（将Find函数的返回值传给Insert函数的参数pos）,再在pos节点后面插入新节点x
    void SList::Insert(LinkNode* pos, DataType x)
    {
        assert(pos);
        if (pos==_tail)
        {
            PushBack(x);
        }
        else
        {
            LinkNode* tmp = new LinkNode(x);
            tmp->_next = pos->_next;
            pos->_next = tmp;
        }
    }
      
        //删除某一节点，同样，要先找到该节点并传参给Erase函数
    void SList::Erase(LinkNode* pos)       
    {
        assert(pos);
        if (pos == _tail)
        {
            PopBack();
        }
        if (pos == _head)
        {
            PopFront();
        }
        else
        {
            LinkNode* prev = _head;
            while (prev->_next != pos)
            {
                prev = prev->_next;
            }
            prev->_next = pos->_next;
            delete pos;
        }
    }
    LinkNode* SList::Find(DataType x)       //查找节点并返回这个节点的地址
    {
        if (_head == NULL)
        {
            cout << "This SList is empty !" << endl;
            return NULL;
        }
        else
        {
            LinkNode* tmp = _head;
            do{
                    if (tmp->_data == x)
                    {
                        return tmp;
                    }
                        tmp = tmp->_next;
            } while (tmp != _head);
            return NULL;
        }
    }
    int SList::Amount()   //计算链表节点的数目
    {
        if (_head == NULL)
        {
            return 0;
        }
        else
        {
            int count = 0;
            LinkNode* cur = _head;
            while (cur != _tail)
            {
                count++;
                cur = cur->_next;
            }
            return ++count;
        }
    }
    void SList::Remove(DataType x)      //查找某节点并删除
    {
        if (_head == NULL)
        {
            cout << "This SList is empty !" << endl;
        }
        else
        {
            LinkNode* tmp = Find(x);
            if (tmp != NULL)
            {
                Erase(tmp);
            }
        }
    }
    void SList::RemoveAll(DataType x)       //删除链表中所有的x
    {
        if (_head == NULL)
        {
            cout << "This SList is empty !" << endl;
            return;
        }
//如果链表不为空，设置left和right前后指针，从头至尾遍历一遍，delete节点的data为x的节点
  
            LinkNode* left = _tail;
            LinkNode* right = _head;
            int count = Amount();
            while (count--)
            {
             //当要删掉的节点是头节点时，需要注意头节点要指向它的下一个节点
             //当要删掉的节点是尾节点时，需要注意尾节点要指向它的上一个节点
             //当left和right指向同一块要删掉的节点时，将链表置空
               
                if (right->_data == x)
                {
                    if (_head == right)  
                    {
                        _head = _head->_next;
                    }
                    if (_tail == right)  
                    {
                        _tail =left;
                    }
                    if (right == left)   
                    {
                        _head = NULL;
                        _tail = NULL;
                        return;
                    }
                    LinkNode* tmp = right;
                    right = right->_next;
                    delete tmp;
                    left->_next = right;
                }
                else
                {
                    left = right;
                    right = right->_next;
                }
            } 
    }
    void SList::Uniqe()       //去重(针对有序链表)
    {
        assert(_head &&_head!= _tail);
        LinkNode* left = _head;
        LinkNode* right = _head->_next;
        while (left != _tail)
        {
            while(left->_data == right->_data)
            {
                LinkNode* tmp = right;
                right = right->_next;
                left->_next = right;
                delete tmp;
            }
            left = left->_next;
            right = right->_next;
        }
    }
    void SList::Merge(SList &s)    //合并（针对有序链表）,合并后依然有序
    {
        //  1. _head为空
        //  2. 链表s为空
        if (_head == NULL)
        {
            _head = s._head;
            _tail = s._tail;
        }
        if (s._head == NULL)
        {
            return;
        }
        //  3. 两个链表都不为空
        LinkNode* phead = _head;
        if (phead->_data <= s._head->_data)
        {
            phead = phead->_next;
        }
        else
        {
            _head = s._head;
            s._head = s._head->_next;
        }
        LinkNode* cur = _head;
        while (1)
        {
            if (phead->_data <= s._head->_data)
            {
                _head->_next = phead;
                _head = _head->_next;
                if (phead == _tail)
                {
                    _head->_next = s._head;  
                    _tail=s._tail;
                    _tail->_next = cur;
                    break;
                }
                phead = phead->_next;
            }
            else
            {
                _head->_next = s._head;
                _head = _head->_next;
                if (s._head ==s._tail)
                {
                    _head->_next = phead;
                    _tail->_next = cur;
                    break;
                }
                s._head = s._head->_next;
            }
              
        }
        _head = cur;
    }
    void SList::Sort()                      //冒泡排序
    {
        assert(_head);
        if (_head == _tail)
        {
            return;
        }
        int size = Amount();
        for (int i = 0; i < size-1 ; i++) 
        {
            LinkNode* left = _head;
            LinkNode* right = _head->_next;
            for (int j = 0; j < size - i-1 ; j++)
            {             
                if (left->_data>right->_data)
                {
                    swap(left->_data, right->_data);
                }
                right = right->_next;
                left = left->_next;
            }     
        }
    }
///************************