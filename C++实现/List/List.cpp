
	#include<iostream>
	using namespace std;
	#include<assert.h>
	#include"List.h"

	//�ڵ��๹�캯��*
	LinkNode::LinkNode(const DataType x)
	:_data(x)
	, _next(NULL)
	, _prev(NULL)
	{}

	//������*
	List::List()         //���캯��
	: _head(NULL)
	, _tail(NULL)
	{}
	List::List(const List& s)          //��������
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
	//��ֵ����������أ���ͳ������
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

	//��ֵ����������أ���Чд����*
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

	List&  List::operator=(List &s)     //��ֵ��������������Ż�(�Ƽ�д��)
	{
		if (this != &s)
		{
			swap(_head, s._head);
			swap(_tail, s._tail);
		}
		return *this;
	}
	List::~List()    //����
	{
		Clear();
	}

	void List::Reverse()   //�������ã�����ͷ���½ڵ�ķ�����
	{
		if (_head == NULL || _head== _tail)
		{
			return;
		}
		int ret = Amount();

	/*  //  ����һ���൱����ͷ��ķ�ʽ���½�������
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

	//////  ��������ֻ�ǽ����Գ�λ�ýڵ�����ݣ�**����Ч��
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
	
		 // ������  ����ǰ���ͺ��ָ��
		  swap(_head, _tail);
		  LinkNode* cur = _head;
		  while (cur)
		  {
		      swap(cur->_prev,cur->_next);
		      cur = cur->_next;
		  }
	}

	//��ӡ����*
	void List::PrintSList()
	{
		//ͷ���Ϊ��ʱ�������ӡ����
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
	void List::PushBack(const DataType& x)    //��β������һ���ڵ�*
	{
		//�������Ϊ�գ�����ڵ��ֻ��һ���ڵ㣬��ʱ_head=_tail
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
	void List::Clear()         //�����ÿ�*
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
	void List::PopBack()    //βɾ*
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
	void List::PushFront(DataType x)  //ͷ��*
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
	void List::PopFront()    //ɾ���׽ڵ�
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

	//�̶�λ�ò���һ���ڵ㣨����������Find��������ʹ�ã�
	//����Find�����ҵ��½ڵ���Ҫ�����λ�ã���Find�����ķ���ֵ����Insert�����Ĳ���pos��������pos�ڵ��������½ڵ�x
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

	void List::Erase(LinkNode* pos)        //ɾ��ĳһ�ڵ㣬ͬ����Ҫ���ҵ��ýڵ㲢���θ�Erase����
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
	LinkNode* List::Find(DataType x)       //���ҽڵ㲢��������ڵ�ĵ�ַ
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
	int List::Amount()   //��������ڵ����Ŀ
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
	void List::Remove(DataType x)      //����ĳ�ڵ㲢ɾ��
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
