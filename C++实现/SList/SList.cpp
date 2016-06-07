
#include<iostream>
using namespace std;
#include<assert.h>
#include"SList.h"
  
   LinkNode::LinkNode(const DataType x)
           :_data(x)
           , _next(NULL)
           {}
  
    SList::SList()         //���캯��
        :_head(NULL)
        , _tail(NULL)
    {}
    SList::SList(const SList& s)          //��������
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
    //��ֵ����������أ���ͳ������
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
      
    //��ֵ����������أ���Чд����
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
  
    SList&  SList::operator=(SList &s)     //��ֵ��������������Ż�(�Ƽ�д��)
    {
        if (this != &s)
        {
            swap(_head, s._head);
            swap(_tail, s._tail);
        }
        return *this;
    }
    SList::~SList()    //����
    {
        Clear();
    }
          
        void SList::Reverse()   //�������ã�����ͷ���½ڵ�ķ�����
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
            delete del;    //���ﲻҪ�������������������ڴ�й©
            begin = new LinkNode(_head->_data);
            begin->_next = tmp;
            _tail->_next = begin;
            tmp = begin;
        }
        _head = begin;
    } 
  
        //��ӡ����
    void SList::PrintSList() 
    {
        //ͷ���Ϊ��ʱ�������ӡ����
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
    void SList::PushBack(const DataType& x)    //��β������һ���ڵ�
    {
        //�������Ϊ�գ�����ڵ��ֻ��һ���ڵ㣬��ʱ_head=_tail
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
    void SList::Clear()         //�����ÿ�
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
    void SList::PopBack()    //βɾ
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
    void SList::PushFront(DataType x)  //ͷ��
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
    void SList::PopFront()    //ɾ���׽ڵ�
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
  
    //�̶�λ�ò���һ���ڵ㣨����������Find��������ʹ�ã�
    //����Find�����ҵ��½ڵ���Ҫ�����λ��
    //����Find�����ķ���ֵ����Insert�����Ĳ���pos��,����pos�ڵ��������½ڵ�x
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
      
        //ɾ��ĳһ�ڵ㣬ͬ����Ҫ���ҵ��ýڵ㲢���θ�Erase����
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
    LinkNode* SList::Find(DataType x)       //���ҽڵ㲢��������ڵ�ĵ�ַ
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
    int SList::Amount()   //��������ڵ����Ŀ
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
    void SList::Remove(DataType x)      //����ĳ�ڵ㲢ɾ��
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
    void SList::RemoveAll(DataType x)       //ɾ�����������е�x
    {
        if (_head == NULL)
        {
            cout << "This SList is empty !" << endl;
            return;
        }
//�������Ϊ�գ�����left��rightǰ��ָ�룬��ͷ��β����һ�飬delete�ڵ��dataΪx�Ľڵ�
  
            LinkNode* left = _tail;
            LinkNode* right = _head;
            int count = Amount();
            while (count--)
            {
             //��Ҫɾ���Ľڵ���ͷ�ڵ�ʱ����Ҫע��ͷ�ڵ�Ҫָ��������һ���ڵ�
             //��Ҫɾ���Ľڵ���β�ڵ�ʱ����Ҫע��β�ڵ�Ҫָ��������һ���ڵ�
             //��left��rightָ��ͬһ��Ҫɾ���Ľڵ�ʱ���������ÿ�
               
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
    void SList::Uniqe()       //ȥ��(�����������)
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
    void SList::Merge(SList &s)    //�ϲ��������������,�ϲ�����Ȼ����
    {
        //  1. _headΪ��
        //  2. ����sΪ��
        if (_head == NULL)
        {
            _head = s._head;
            _tail = s._tail;
        }
        if (s._head == NULL)
        {
            return;
        }
        //  3. ����������Ϊ��
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
    void SList::Sort()                      //ð������
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