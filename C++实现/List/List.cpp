
	#include<iostream>
	using namespace std;
	#include<assert.h>
	#include"List.h"

	//节点类构造函数*
	LinkNode::LinkNode(const DataType x)
	:_data(x)
	, _next(NULL)
	, _prev(NULL)
	{}

	//链表类*
	List::List()         //构造函数
	: _head(NULL)
	, _tail(NULL)
	{}
	List::List(const List& s)          //拷贝构造
	: _head(NULL)
	, _tail(NULL)
	{
		if (s._head == NULL)
		{
			return;
		}
		LinkNode* tmp = s._head;
		while (tmp)
		{
			PushBack(tmp->_data);
			tmp = tmp->_next;
		} 

	}
	//赋值运算符的重载（传统方法）
	//SList & SList::operator=(const SList& s)    
	//{
	//	if (this != &s)
	//	{
	//		_head = NULL;
	//		_tail = NULL;
	//		LinkNode* tmp = s._head;
	//	do{
	//		PushBack(tmp->_data);
	//		tmp = tmp->_next;
	//	     } while (tmp != s._head);
	//	}
	//	return *this;	
	//}

	//赋值运算符的重载（高效写法）*
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

	List&  List::operator=(List &s)     //赋值运算符的重载再优化(推荐写法)
	{
		if (this != &s)
		{
			swap(_head, s._head);
			swap(_tail, s._tail);
		}
		return *this;
	}
	List::~List()    //析构
	{
		Clear();
	}

	void List::Reverse()   //链表逆置（利用头插新节点的方法）
	{
		if (_head == NULL || _head== _tail)
		{
			return;
		}
		int ret = Amount();

	/*  //  方法一（相当于用头插的方式重新建立链表）
   	_tail = new LinkNode(_head->_data);
		LinkNode* begin = NULL;
		LinkNode* tmp = _tail;
		while (--ret)
		{
			LinkNode* del = _head;
			_head = _head->_next;
			delete del;			
			begin = new LinkNode(_head->_data);
			begin->_next = tmp;
			tmp->_prev = begin;
			tmp = begin;
		}
		_head = begin;*/

	//////  方法二（只是交换对称位置节点的数据）**（高效）
		/*LinkNode* begin = _head;
		LinkNode* end = _tail;
		while (ret)
		{
			if (end->_next == begin)
				break;
			ret /= 2;
			swap(begin->_data, end->_data);
			begin = begin->_next;
			end = end->_prev;
		}*/
	
		 // 方法三  交换前驱和后继指针
		  swap(_head, _tail);
		  LinkNode* cur = _head;
		  while (cur)
		  {
		      swap(cur->_prev,cur->_next);
		      cur = cur->_next;
		  }
	}

	//打印链表*
	void List::PrintSList()
	{
		//头结点为空时，无需打印链表
		if (_head == NULL)
		{
			cout << "This SList is Empty !" << endl;
			return;
		}
		else
		{
			LinkNode* tmp = _head;	
		   while (tmp)
		   {
				cout << tmp->_data << "-->";
				tmp = tmp->_next;
			} 
			cout <<"NULL"<< endl;
		}
	}
	void List::PushBack(const DataType& x)    //在尾部插入一个节点*
	{
		//如果链表为空，插入节点后只有一个节点，此时_head=_tail
		if (_head == NULL)
		{
			_head = new LinkNode(x);
			_tail = _head;
		}
		else
		{
			_tail->_next = new LinkNode(x);
		    _tail->_next->_prev=_tail;
			_tail = _tail->_next;
		}
	}
	void List::Clear()         //链表置空*
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
	void List::PopBack()    //尾删*
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
			_tail->_prev = cur->_prev;
			_tail->_next = NULL;
		}
	}
	void List::PushFront(DataType x)  //头插*
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
			tmp->_prev = _head;
		}
	}
	void List::PopFront()    //删除首节点
	{
		if (_head == NULL)
		{
			cout << "This SList is empty !" << endl;
			return;
		}
		LinkNode* tmp = _head;
		_head = _head->_next;
		_head->_prev = NULL;
		delete tmp;
	}

	//固定位置插入一个节点（这个函数需和Find函数搭配使用）
	//先用Find函数找到新节点需要插入的位置（将Find函数的返回值传给Insert函数的参数pos），再在pos节点后面插入新节点x
	void List::Insert(LinkNode* pos, DataType x)   //*
	{
		assert(pos);
		if (pos == _tail)
		{
			PushBack(x);
		}
		else
		{
			LinkNode* tmp = new LinkNode(x);
			tmp->_next = pos->_next;
			pos->_next = tmp;
			tmp->_next->_prev = tmp;
			tmp->_prev = pos;
		}
	}

	void List::Erase(LinkNode* pos)        //删除某一节点，同样，要先找到该节点并传参给Erase函数
	{
		assert(pos);
		if (pos == _tail)
		{
			PopBack();
		}
		else if (pos == _head)
		{
			PopFront();
		}
		else
		{
			pos->_prev->_next = pos->_next;
			pos->_next->_prev = pos->_prev;
			delete pos;
		}
	}
	LinkNode* List::Find(DataType x)       //查找节点并返回这个节点的地址
	{
		if (_head == NULL)
		{
			cout << "This SList is empty !" << endl;
			return NULL;
		}
		else
		{
			LinkNode* tmp = _head;
			while (tmp != NULL)
			{
				if (tmp->_data == x)
				{
					return tmp;
				}
				tmp = tmp->_next;
			} 
			return NULL;
		}
	}
	int List::Amount()   //计算链表节点的数目
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
	void List::Remove(DataType x)      //查找某节点并删除
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
