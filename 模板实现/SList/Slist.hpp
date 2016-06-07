#pragma once

#include<iostream>
using namespace std;
#include<assert.h>

template<class T>

struct LinkNode      //�ڵ���(����д��)
{
	LinkNode(const T x);
	T _data;    //�ڵ������
	LinkNode<T>* _next;    //ָ��ýڵ����һ���ڵ�
};
template<class T>
class SList
{
public:
	SList();         //���캯��
	SList(const SList& s);        //��������
	SList &operator=(SList s);    //��ֵ�����������
	~SList();

   //������ľ������
	void Reverse();   //��ת
	void Swap(SList& s);
	void PrintSList();   //��ӡ����
	void PushBack(const T& x);    //��β������һ���ڵ�
	void Clear();         //�����ÿ�
	void PopBack();       //ɾ��β�ڵ�
	void PushFront(T x);  //ͷ��
	void PopFront();    //ɾ���׽ڵ�
	void Insert(LinkNode<T>* pos, T x);//�̶�λ�ò���һ���ڵ�
	void Erase(LinkNode<T>* pos);        //ɾ��ĳһ�ڵ�
	LinkNode<T>* Find(T x);       //���ҽڵ㲢��������ڵ�ĵ�ַ
	int Amount();   //��������ڵ����Ŀ
	void Remove(T x);     //����ĳ�ڵ㲢ɾ��
	void RemoveAll(T x);      //ɾ�����������е�x

private:
	LinkNode<T>* _head;     //ָ��ͷ�ڵ�
	LinkNode<T>* _tail;        //ָ��β�ڵ�
};


template<class T>
LinkNode<T>::LinkNode(const T x)
:_data(x)
, _next(NULL)
{}

template<class T>
SList<T>::SList()         //���캯��
: _head(NULL)
, _tail(NULL)
{}

template<class T>
SList<T>::SList(const SList<T>& s)          //��������
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
SList<T>&  SList<T>::operator=(SList<T> s)     //��ֵ��������������Ż�(�Ƽ�д��)
{
	if (this != &s)
	{
		swap(_head, s._head);
		swap(_tail, s._tail);
	}
	return *this;
}

template<class T>
SList<T>::~SList()    //����
{
	Clear();
}

template<class T>
void SList<T>::Reverse()   //�������ã�����ͷ���½ڵ�ķ�����
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
		delete del;    //���ﲻҪ�������������������ڴ�й©
		begin = new LinkNode<T>(_head->_data);
		begin->_next = tmp;
		_tail->_next = begin;
		tmp = begin;
	}
	_head = begin;
}

template<class T>
void SList<T>::PrintSList()//��ӡ����
{
	//ͷ���Ϊ��ʱ�������ӡ����
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
void SList<T>::PushBack(const T& x)    //��β������һ���ڵ�
{
	//�������Ϊ�գ�����ڵ��ֻ��һ���ڵ㣬��ʱ_head=_tail
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
void SList<T>::Clear()         //�����ÿ�
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
void SList<T>::PopBack()    //βɾ
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
void SList<T>::PushFront(T x)  //ͷ��
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
void SList<T>::PopFront()    //ɾ���׽ڵ�
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

//�̶�λ�ò���һ���ڵ㣨����������Find��������ʹ�ã�
//����Find�����ҵ��½ڵ���Ҫ�����λ��
//����Find�����ķ���ֵ����Insert�����Ĳ���pos��,����pos�ڵ��������½ڵ�x
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

//ɾ��ĳһ�ڵ㣬ͬ����Ҫ���ҵ��ýڵ㲢���θ�Erase����
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
LinkNode<T>* SList<T>::Find(T x)       //���ҽڵ㲢��������ڵ�ĵ�ַ
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
int SList<T>::Amount()   //��������ڵ����Ŀ
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
void SList<T>::Remove(T x)      //����ĳ�ڵ㲢ɾ��
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
void SList<T>::RemoveAll(T x)       //ɾ�����������е�x
{
	if (_head == NULL)
	{
		cout << "This SList is empty !" << endl;
		return;
	}
	//�������Ϊ�գ�����left��rightǰ��ָ�룬��ͷ��β����һ�飬delete�ڵ��dataΪx�Ľڵ�

	LinkNode<T>* left = _tail;
	LinkNode<T>* right = _head;
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


