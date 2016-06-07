	#include"List.h"
	#include<stdlib.h>
#include<iostream>
using namespace std;

	void Test1()
	{
		List list1;
		list1.PushBack(1);
		list1.PushBack(2);
		list1.PushBack(3);
		list1.PushBack(4);
		list1.PushBack(5);
		list1.PushBack(6);
		list1.PrintSList();

	/*	List list2(list1);
		list2.PrintSList();*/

		List list2=list1;
		list2.PrintSList();
		//list2.PopBack();
		//list2.Clear();
		//list2.PushFront(0);
		//list2.PopFront();

		//////¼ìÑéFindº¯Êý
		////LinkNode* ret=list2.Find(4);
		////if (ret != NULL)
		////{
		////	cout << "ret:" << ret << " " << ret->_data << endl;
		////}
		////else
		////{
		////	cout << "Not exit !" << endl;
		////}
		
	/*	int ret=list2.Amount();
		cout << ret << endl;*/

		//list2.Erase(list2.Find(5));
		//list2.Insert(list2.Find(2), 0);
		//list2.Remove(3);
		list2.Reverse();
		list2.PrintSList();
	}

	int main()
	{
		Test1();
		system("pause");
	}


