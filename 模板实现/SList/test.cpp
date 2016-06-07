#include"Slist.hpp"

void Test()
{
	SList<int> list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	list1.PushBack(5);
	cout << "SList 1: ";
	list1.PrintSList();

    SList<int> list2 = list1;
	cout << "SList 2: ";
	list2.PrintSList();

	SList<int> list3 (list1);
	cout << "SList 3: ";
	list3.PrintSList();

	SList<int> list4;
	list4 = list1;
	cout << "SList 4: ";
	list4.PrintSList();

	cout << endl;
	list1.RemoveAll(2);
	cout << "SList 1: ";
	list1.PrintSList();

    list2.Reverse();
	cout << "SList 2: ";
	list2.PrintSList();

	list3.PopBack();
	cout << "SList 3: ";
	list3.PrintSList();

	list4.Clear();
	cout << "SList 4: ";
	list4.PrintSList();

	cout << endl;
	list1.Erase(list1.Find(4));
	cout << "SList 1: ";
	list1.PrintSList();

	list1.PopFront();
	cout << "SList 1: ";
	list1.PrintSList();
	list1.PushFront(0);
	cout << "SList 1: ";
	list1.PrintSList();

	list1.Insert(list1.Find(3), 0);
	cout << "SList 1: ";
	list1.PrintSList();

	list1.RemoveAll(0);
	cout << "SList 1: ";
	list1.PrintSList();

}


int main()
{
	Test();
	system("pause");
}

