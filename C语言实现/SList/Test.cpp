#include "SList.h"
#include<stdlib.h>

void Test1()
{
	// β�� ��ӡ βɾ ͷ�� ͷɾ �������
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
	// ���ҽڵ�  ��ĳλ�ò���ڵ� ɾ��ĳλ�ýڵ�  
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
	// ɾ��һ����ͷ������ķ�β�ڵ�  
	/*SListNode* pos = Find(list, 2);
	DelNonTailNode(pos);
	PrintSlist(list);*/

	// ����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
	/*SListNode* pos = Find(list, 2);
	InsertFrontNode(pos, 0);
	PrintSlist(list);*/

	//�����м�ڵ�
	//PrintSlist(FindMidNode(list));

	//���ҵ�����k���ڵ�
	//SListNode* ret = FindKNode(list, 2);
	//PrintSlist(ret);

	//���Ŵ�ӡ�������ݹ飩
	//PrintTailToHead(list);

	//���õ�����
	//SListNode* ret = Reverse(list);
	//PrintSlist(ret);
	PrintSlist(Reverse_(list));
	PrintSlist(list);
}
void Test4()
{   //�ϲ��������������ϲ�����Ȼ����
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