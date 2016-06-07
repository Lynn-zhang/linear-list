/****************************************************************************************************/
/*
     功能：应用C++语言实现顺序表的各项操作
         
     基本的成员函数：
	               构造函数、拷贝构造函数、赋值运算符的重载、析构函数      


          **                  1：动态增容
          **                  2：打印单链表    
          **                  3：尾插
          **                  4：尾删
          **                  5：头插       
          **                  6：头删    
          **                  7：查找数据   
          **                  8：在某位置后插入数据   
          **                  9：删除某位置的数据
          **                 10：删除x    
          **
          **                              By ：Lynn-Zhang
          **                    																				  
												 				                              */
/*****************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <assert.h>

typedef int DataType;

class SeqList
{
public:
	SeqList();   //构造函数
	SeqList(const SeqList & sList);   //拷贝构造
	SeqList& operator=(const SeqList& sList);  //赋值运算符重载
	~SeqList();   //析构函数

	void CheckCapacity();    // 测容/扩容
	void Print();                    // 打印顺序表
	void PushBack(const DataType & x);  // 尾插
	void PopBack();                                   // 尾删
	void PushFront(const DataType & x);   // 头插
	void PopFront();                                    // 头删
	   
	int Find(const DataType & x);                //查找数据
	void Insert(size_t pos, const DataType & x);   //某位置后插入数据
	void Erase(size_t pos);                                    //删除某位置的数据
	int Remove(const DataType & x);                   //删除数据x

private:
	DataType* _array;      //数据块指针
	size_t   _size;             //定义当前有效数据的个数
	size_t _capicity;         //容量

};

SeqList::SeqList()
	:_array(NULL)
	, _size(0)
	, _capicity(0)
{}
SeqList::SeqList(const SeqList & sList)
	:_array(new DataType[sList._size])
	, _size(sList._size)
	, _capicity(sList._capicity)
{
	memcpy(_array, sList._array, sizeof(DataType)*_size);
}
SeqList& SeqList::operator=(const SeqList& sList)
{
	if (&sList != this)
	{
		DataType *tmp = new DataType[sList._size];
		delete[] _array;

		_array = tmp;
		_size = sList._size;
		_capicity = sList._capicity;
		memcpy(_array, sList._array, sizeof(DataType)*_size);
	}
	return *this;
}
SeqList::~SeqList()
{
	if (_array != NULL)
	{
		delete[] _array;
		_size = 0;
		_capicity = 0;
	}
}

void SeqList::CheckCapacity()
{
	if (_size >= _capicity)
	{
		_capicity = 2 * _capicity + 5;
		_array = (DataType *)realloc(_array, _capicity*sizeof (DataType));
	}
}

void SeqList::Print()
{
	for (int i = 0; i < _size; ++i)
	{
		cout << _array[i] << " ";
	}
	cout << endl;
}

void SeqList::PushBack(const DataType & x)
{
           CheckCapacity();    //添加数据前要进行测容
           _array[_size++] = x ;     //这里注意：添加完数据意思要给size加1
}

void SeqList::PopBack()
{
	if (_size == 0)
	{
		cout << "This SeqList is Empty !" << endl;
		return;
	}
	else
	{
		_array[--_size] = NULL;
	}
}
void SeqList::PushFront(const DataType & x)
{
	if (_size == 0)
	{
		PushBack(x);
		return;
	}
	else
	{
		CheckCapacity();
		int key = _size;
		while (key)
		{
			_array[key--] = _array[key - 1];
		}
		_array[0] = x;
		_size++;
	}
}
void SeqList::PopFront()
{
	if (_size == 0 || _size == 1)
	{
		PopBack();
	}
	else
	{
		for (int i = 0; i < _size - 1; i++)
		{
			_array[i] = _array[i + 1];
		}
		--_size;
	}
}
void SeqList::Insert(size_t pos , const DataType& x)  
{
           assert( pos<_size);    //需检验pos的合法性
           CheckCapacity();
           if (pos == _size - 1)   //在最后一个位置插入数据等于尾插
           {
                    PushBack(x );
                    return;
           }
           else
           {
                    for (int i = _size; i > pos; --i)
                    {
                              _array[i] = _array[i - 1];
                    }
                    _array[pos ] = x ;
                    _size++;
           }
}
int SeqList::Find(const DataType & x)
{
	assert(_array != NULL);
	for (int i = 0; i < _size; i++)
	{
		if (_array[i] == x)
			return i;
	}
	return -1;
}
void SeqList::Erase(size_t pos)
{
	assert(_array != NULL);
	assert(pos < _size);
	if (pos == _size - 1)
	{
		PopBack();
		return;
	}
	if (pos == 0)
	{
		PopFront();
		return;
	}
	for (int i = pos; i < _size - 1; i++)
	{
		_array[i] = _array[i + 1];
	}
	--_size;
}
int   SeqList::Remove(const DataType & x)
{
	assert(_array);
	int pos = Find(x);
	if (pos != -1)
	{
		Erase(pos);
		return 1;
	}
	else
	{
		return -1;
	}

}

//void Test1()
//{
//   SeqList list1;
//   list1.PushBack(1);
//   list1.PushBack(2);
//   list1.PushBack(3);
//   list1.PushBack(4);
//   list1.PushBack(5);
//
//   list1.Print();
//
//   SeqList list2;
//   list2.PushBack(0);
//   list2.PushBack(9);
//   list2.PushBack(8);
//   list2.PushBack(7);
//   list2.PushBack(6);
//   list2.Print();
//
//   list1 = list2;
//   list1.Print();
//
//   SeqList list3(list1);
//   list3.Print();
//}

void Test2()
{
	SeqList list1;

	//list1.PushFront(0);
	//list1.Print();

	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	list1.PushBack(5);
	list1.Print();

	//list1.PopFront();
	//list1.Print();
	/*list1.Insert(2, 0);
	list1.Print();*/
	//cout <<"该数字出现在：_array["<< list1.Find(5) <<"]"<< endl;
	//list1.Erase(2);

	int ret = list1.Remove(7);
	if (ret == -1)
	{
		cout << "not exit !" << endl;
	}
	else
	{
		list1.Print();
	}
}
int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}