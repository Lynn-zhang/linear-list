#pragma once

#include<iostream>
using namespace std;
#include<assert.h>

template<class T>

struct LinkNode      //节点类(建议写法)
{
	LinkNode(const T x);
	T _data;    //节点的数据
	LinkNode<T>* _next;    //指向该节点的下一个节点
};
template<class T>
class SList
{
public:
	SList();         //构造函数
	SList(const SList& s);        //拷贝构造
	SList &operator=(SList s);    //赋值运算符的重载
	~SList();

   //单链表的具体操作
	void Reverse();   //翻转
	void Swap(SList& s);
	void PrintSList();   //打印链表
	void PushBack(const T& x);    //在尾部插入一个节点
	void Clear();         //链表置空
	void PopBack();       //删除尾节点
	void PushFront(T x);  //头插
	void PopFront();    //删除首节点
	void Insert(LinkNode<T>* pos, T x);//固定位置插入一个节点
	void Erase(LinkNode<T>* pos);        //删除某一节点
	LinkNode<T>* Find(T x);       //查找节点并返回这个节点的地址
	int Amount();   //计算链表节点的数目
	void Remove(T x);     //查找某节点并删除
	void RemoveAll(T x);      //删除链表中所有的x

private:
	LinkNode<T>* _head;     //指向头节点
	LinkNode<T>* _tail;        //指向尾节点
};


template<class T>
LinkNode<T>::LinkNode(const T x)
:_data(x)
, _next(NULL)
{}

template<class T>
SList<T>::SList()         //构造函数
: _head(NULL)
, _tail(NULL)
{}

template<class T>
SList<T>::SList(const SList<T>& s)          //拷贝构造
: _head(NULL)
, _tail(NULL)
{
	if (s._head == NULL)
	{
		return;
	}
	LinkNode<T>* tmp = s._head;
	do{
		PushBack(tmp->_data);
		tmp = tmp->_next;
	} while (tmp != s._head);

}

template<class T>
SList<T>&  SList<T>::operator=(SList<T> s)     //赋值运算符的重载再优化(推荐写法)
{
	if (this != &s)
	{
		swap(_head, s._head);
		swap(_tail, s._tail);
	}
	return *this;
}

template<class T>
SList<T>::~SList()    //析构
{
	Clear();
}

template<class T>
void SList<T>::Reverse()   //链表逆置（利用头插新节点的方法）
{
	if (_head == NULL || _head->_next == _tail)
	{
		return;
	}
	int ret = Amount();
	_tail = new LinkNode<T>(_head->_data);
	LinkNode<T>* begin = NULL;
	LinkNode<T>* tmp = _tail;
	while (--ret)
	{
		LinkNode<T>* del = _head;
		_head = _head->_next;
		delete del;    //这里不要忘记做清理工作，否则内存泄漏
		begin = new LinkNode<T>(_head->_data);
		begin->_next = tmp;
		_tail->_next = begin;
		tmp = begin;
	}
	_head = begin;
}

template<class T>
void SList<T>::PrintSList()//打印链表
{
	//头结点为空时，无需打印链表
	if (_head == NULL)
	{
		cout << "This SList is Empty !" << endl;
		return;
	}
	else
	{
		LinkNode<T>* tmp = _head;
		do{
			cout << tmp->_data << "-->";
			tmp = tmp->_next;
		} while (tmp != _head);
		cout << endl;
	}
}

template<class T>
void SList<T>::PushBack(const T& x)    //在尾部插入一个节点
{
	//如果链表为空，插入节点后只有一个节点，此时_head=_tail
	if (_head == NULL)
	{
		_head = new LinkNode<T>(x);
		_tail = _head;
		_tail->_next = _head;
	}
	else
	{
		_tail->_next = new LinkNode<T>(x);
		_tail = _tail->_next;
		_tail->_next = _head;
	}
}

template<class T>
void SList<T>::Clear()         //链表置空
{
	LinkNode<T>* begin = _head;
	while (begin != _tail)
	{
		_head = _head->_next;
		delete begin;
		begin = _head;
	}
	_head = NULL;
	_tail = NULL;
}

template<class T>
void SList<T>::PopBack()    //尾删
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
		LinkNode<T>* cur = _head;
		while (cur->_next != _tail)
		{
			cur = cur->_next;
		}
		delete _tail;
		_tail = cur;
		_tail->_next = _head;
	}
}
template<class T>
void SList<T>::PushFront(T x)  //头插
{
	if (_head == NULL)
	{
		PushBack(x);
	}
	else
	{
		LinkNode<T>* tmp = _head;
		_head = new LinkNode<T>(x);
		_head->_next = tmp;
		_tail->_next = _head;
	}
}
template<class T>
void SList<T>::PopFront()    //删除首节点
{
	if (_head == NULL)
	{
		cout << "This SList is empty !" << endl;
		return;
	}
	LinkNode<T>* tmp = _head;
	_head = _head->_next;
	_tail->_next = _head;
	delete tmp;
}

//固定位置插入一个节点（这个函数需和Find函数搭配使用）
//先用Find函数找到新节点需要插入的位置
//（将Find函数的返回值传给Insert函数的参数pos）,再在pos节点后面插入新节点x
template<class T>
void SList<T>::Insert(LinkNode<T>* pos, T x)
{
	assert(pos);
	if (pos == _tail)
	{
		PushBack(x);
	}
	else
	{
		LinkNode<T>* tmp = new LinkNode<T>(x);
		tmp->_next = pos->_next;
		pos->_next = tmp;
	}
}

//删除某一节点，同样，要先找到该节点并传参给Erase函数
template<class T>
void SList<T>::Erase(LinkNode<T>* pos)
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
		LinkNode<T>* prev = _head;
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}
		prev->_next = pos->_next;
		delete pos;
	}
}

template<class T>
LinkNode<T>* SList<T>::Find(T x)       //查找节点并返回这个节点的地址
{
	if (_head == NULL)
	{
		cout << "This SList is empty !" << endl;
		return NULL;
	}
	else
	{
		LinkNode<T>* tmp = _head;
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
template<class T>
int SList<T>::Amount()   //计算链表节点的数目
{
	if (_head == NULL)
	{
		return 0;
	}
	else
	{
		int count = 0;
		LinkNode<T>* cur = _head;
		while (cur != _tail)
		{
			count++;
			cur = cur->_next;
		}
		return ++count;
	}
}
template<class T>
void SList<T>::Remove(T x)      //查找某节点并删除
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
template<class T>
void SList<T>::RemoveAll(T x)       //删除链表中所有的x
{
	if (_head == NULL)
	{
		cout << "This SList is empty !" << endl;
		return;
	}
	//如果链表不为空，设置left和right前后指针，从头至尾遍历一遍，delete节点的data为x的节点

	LinkNode<T>* left = _tail;
	LinkNode<T>* right = _head;
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
				_tail = left;
			}
			if (right == left)
			{
				_head = NULL;
				_tail = NULL;
				return;
			}
			LinkNode<T>* tmp = right;
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


