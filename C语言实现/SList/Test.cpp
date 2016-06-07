#include "SList.h"
#include<stdlib.h>

void Test1()
{
	// 尾插 打印 尾删 头插 头删 清空链表
	SListNode* list = NULL;
	PushBack(list, 1);
	PushBack(list, 2);
	PushBack(list, 3);
	PushBack(list, 4);
	PrintSlist(list);
	PopBack(list);
	PrintSlist(list);
	PushFront(list,0);
	PrintSlist(list);
	PopFront(list);
	PrintSlist(list);
	DestoryList(list);
	PrintSlist(list);
}
void Test2()
{
	// 查找节点  在某位置插入节点 删除某位置节点  
	SListNode* list = NULL;
	PushBack(list, 1);
	PushBack(list, 2);
	PushBack(list, 3);
	PushBack(list, 4);
	PrintSlist(list);
	SListNode* pos = Find(list, 2);
	Insert(pos, 0);
	PrintSlist(list);
	Erase(list, Find(list, 0));
	PrintSlist(list);

}
void Test3()
{
	SListNode* list = NULL;
	PushBack(list, 1);
	PushBack(list, 2);
	PushBack(list, 3);
	PushBack(list, 4);
	PushBack(list, 5);
	PushBack(list, 6);
	PrintSlist(list);
	// 删除一个无头单链表的非尾节点  
	/*SListNode* pos = Find(list, 2);
	DelNonTailNode(pos);
	PrintSlist(list);*/

	// 在无头单链表的一个非头节点前插入一个节点
	/*SListNode* pos = Find(list, 2);
	InsertFrontNode(pos, 0);
	PrintSlist(list);*/

	//查找中间节点
	//PrintSlist(FindMidNode(list));

	//查找倒数第k个节点
	//SListNode* ret = FindKNode(list, 2);
	//PrintSlist(ret);

	//倒着打印单链表（递归）
	//PrintTailToHead(list);

	//逆置单链表
	//SListNode* ret = Reverse(list);
	//PrintSlist(ret);
	PrintSlist(Reverse_(list));
	PrintSlist(list);
}
void Test4()
{   //合并两个有序链表（合并后依然有序）
	SListNode* list = NULL;
	PushBack(list, 4);
	PushBack(list, 2);
	PushBack(list, 1);
	PushBack(list, 4);
	PrintSlist(list);
	Sort(list);
	PrintSlist(list);

	/*SListNode* list1 = NULL;
	PushBack(list1, 2);
	PushBack(list1, 3);
	PushBack(list1, 3);
	PushBack(list1, 0);
	PrintSlist(list);
	Sort(list1);
	PrintSlist(list1);

	SListNode* ret = Merge(list, list1);
	PrintSlist(ret);
	PrintSlist(list);
	PrintSlist(list1);*/
}
int main()
{
	//Test1();
	//Test2();
	Test3();
	//Test4();
	system("pause");
	return 0;
}