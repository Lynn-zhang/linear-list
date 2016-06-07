#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<assert.h>

template<typename  T>
class SeqList
{
public:
		    SeqList();
			SeqList(const SeqList & sList);
			SeqList& operator=(const SeqList& sList);

			//函数实现
           void CheckCapacity();
           void PushBack(const T & x);
           void PopBack();
           void PushFront(const T & x);
           void PopFront();
           int Find(const T & x);
           void Print();
           void Insert(size_t pos, const T& x);
           void Erase(size_t pos);
           int Remove(const T & x);

           ~SeqList()
           {
                    if (_array != NULL )
                    {
                              delete[] _array;
                              _size = 0;
                              _capicity = 0;
                    }
           }

private:
           T* _array;
           size_t  _size;
           size_t _capicity;

};

		template<typename T>
		SeqList<T>::SeqList()
		:_array(NULL)
		, _size(0)
		, _capicity(0)
		{}

		template<typename T>
		SeqList<T>::SeqList(const SeqList & sList)
		:_array(new T[sList._size])
		, _size(sList._size)
		, _capicity(sList._capicity)
		{
			memcpy(_array, sList._array, sizeof(T)*_size);
		}

		template<typename T>
		SeqList<T>& SeqList<T>:: operator=(const SeqList<T>& sList)
		{
			if (&sList != this)
			{
				T *tmp = new T[sList._size];
				delete[] _array;

				_array = tmp;
				_size = sList._size;
				_capicity = sList._capicity;
				memcpy(_array, sList._array, sizeof(T)*_size);
			}
			return *this;
		}

		template<typename T>
		void SeqList<T>::CheckCapacity()
		{
				   if (_size >= _capicity)
				   {
							_capicity = 2 * _capicity + 5;
							_array = (T *)realloc(_array, _capicity*sizeof (T ));
				   }
		}
		template<typename T>
		void SeqList<T>::Print()
		{
				   for (int i = 0; i < _size; ++i)
				   {
							cout << _array[i] << " " ;
				   }
				   cout << endl;
		}
		template<typename T>
		void SeqList<T>::PushBack(const T & x)
		{
				   CheckCapacity();
				   _array[_size++] = x ;
		}
		template<typename T>
		void SeqList<T>::PopBack()
		{
				   if (_size == 0)
				   {
							cout << "This SeqList is Empty !" << endl;
							return;
				   }
				   else
				   {
							_array[--_size]=NULL ;
				   }
		}
		template<typename T>
		void SeqList<T>::PushFront(const T & x)
		{
				   if (_size == 0)
				   {
							PushBack(x );
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
		template<typename T>
		void SeqList<T>::PopFront()
		{
				   if (_size == 0||_size==1)
				   {
							PopBack();
				   }
				   else
				   {
							for (int i = 0; i < _size-1;i++)
							{
									  _array[i] = _array[i + 1];
							}
							--_size;
				   }
		}
		template<typename T>
		void SeqList<T>::Insert(size_t pos , const T& x)
		{
				   assert( pos<_size);
				   CheckCapacity();
				   if (pos == _size - 1)
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
		template<typename T>
		int SeqList<T>::Find(const T & x)
		{
				   assert(_array != NULL);
				   for (int i = 0; i < _size; i++)
				   {
							if (_array[i] == x )
									  return i;
				   }
				   return -1;
		}
		template<typename T>
		void SeqList<T>::Erase(size_t pos )
		{
				   assert(_array!= NULL);
				   assert( pos < _size);
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
				   for (int i = pos; i < _size-1; i++)
				   {
							_array[i] = _array[i + 1];
				   }
				   --_size;
		}
		template<typename T>
		int  SeqList<T>::Remove(const T & x)
		{
				   assert(_array);
				   int pos=Find(x );
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

void Test1()
{
   SeqList<int> list1;
   list1.PushBack(1);
   list1.PushBack(2);
   list1.PushBack(3);
   list1.PushBack(4);
   list1.PushBack(5);
   cout << "list 1: ";
   list1.Print();

   SeqList<int> list2;
   list2 = list1;
   cout << "list 2: ";
   list2.Print();

   list1 = list2;
   cout << "list 1: ";
   list1.Print();

   SeqList<int> list3(list1);
   cout << "list 3: ";
   list3.Print();
}

void Test2()
{
           SeqList<int>  list1;

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
          
           int ret=list1.Remove(7);
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
           Test1();
           //Test2();
           system("pause" );
           return 0;
}
