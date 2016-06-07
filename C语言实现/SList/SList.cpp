#include"SList.h"

#include <stdio.h>
#include<assert.h>
#include <malloc.h>

SListNode* _BuyNode(DataType x)    //建立节点
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	tmp->data = x;
	tmp->next = NULL;

	return tmp;
}
void PrintSlist(SListNode* pHead)   // 打印单链表
{
	SListNode* cur = pHead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

	printf("NULL\n");
}
//void PushBack(SListNode** ppHead, DataType x)   //尾插
//{
//	assert(ppHead);
//	// 1.空
//	// 2.不为空
//	if(*ppHead == NULL)
//	{
//		*ppHead = _BuyNode(x);
//	}
//	else
//	{
//		// 找尾
//		SListNode* tail = *ppHead;
//		while(tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//
//		tail->next = _BuyNode(x);
//	}
//}
void PushBack(SListNode* & pHead, DataType x)  //尾插
{
	// 1.空
	// 2.不为空
	if (pHead == NULL)
	{
		pHead = _BuyNode(x);
	}
	else
	{
		// 找尾
		SListNode* tail = pHead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = _BuyNode(x);
	}
}
void PopBack(SListNode* & pHead)      //  尾删
{
	//
	// 1.空
	// 2.一个节点
	// 3.多个节点
	//
	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->next == NULL)
	{
		free(pHead);
		pHead = NULL;
	}
	else
	{
		SListNode* tail = pHead;
		SListNode* prev = NULL;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		prev->next = NULL;
	}
}
void PushFront(SListNode* & pHead, DataType x)   //头插
{
	// 1.空
	// 2.不空
	if (pHead == NULL)
	{
		pHead = _BuyNode(x);
	}
	else
	{
		SListNode* tmp = _BuyNode(x);
		tmp->next = pHead;
		pHead = tmp;
	}
}
void PopFront(SListNode*& pHead)   //头删
{
	//
	// 1.空
	// 2.一个节点
	// 3.一个以上的节点
	//
	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->next == NULL)
	{
		free(pHead);
		pHead = NULL;
	}
	else
	{
		SListNode* tmp = pHead;
		pHead = pHead->next;

		free(tmp);
	}
}
void DestoryList(SListNode*& pHead)   //清空整个链表
{
	SListNode* cur = pHead;
	while (cur)
	{
		SListNode* tmp = cur;
		cur = cur->next;
		free(tmp);
	}

	pHead = NULL;
}

int GetSize(SListNode* pHead)   //获取链表长度
{
	assert(pHead);
	SListNode* cur = pHead;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
SListNode* Find(SListNode* pHead, DataType x)  //查找节点
{
	SListNode* cur = pHead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void Insert(SListNode* pos, DataType x)   // 某位置后插入节点
{
	assert(pos);

	SListNode* tmp = _BuyNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
void Erase(SListNode*& pHead, SListNode* pos)   //删除某位置的节点
{
	assert(pos);
	assert(pHead);

	//pos为头结点
	if (pHead == pos)
	{
		pHead = pHead->next;
		free(pos);
		return;
	}
	////
	SListNode* prev = pHead;
	while (prev)
	{
		if (prev->next == pos)
		{
			prev->next = pos->next;
			free(pos);
			break;
		}
		prev = prev->next;
	}
}
void DelNonTailNode(SListNode* pos)  //// 删除一个无头单链表的非尾节点
{
	assert(pos);
	assert(pos->next);
	SListNode* del = pos->next;
	SListNode* dnext = del->next;
	pos->data = del->data;
	pos->next = dnext;
	free(del);
}
void InsertFrontNode(SListNode* pos, DataType x)     // 在无头单链表的一个非头节点前插入一个节点
{
	assert(pos);

	SListNode* tmp = _BuyNode(pos->data);
	tmp->next = pos->next;
	pos->next = tmp;
	pos->data = x;
}
//
////struct Ret
////{	
////	SListNode* first;
////	SListNode* second;
////};
//
void Sort(SListNode* pHead)    //冒泡排序
{

	assert(pHead);
	int size = GetSize(pHead);
	for (int i = 0; i < size - 1; i++)
	{
		SListNode* left = pHead;
		SListNode* right = pHead->next;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (left->data>right->data)
			{
				int tmp = left->data;
				left->data = right->data;
				right->data = tmp;
			}
			right = right->next;
			left = left->next;
		}
	}
}
SListNode* FindMidNode(SListNode* pHead)   //查找中间节点
{
	SListNode* fast = pHead;
	SListNode* slow = pHead;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
SListNode* FindKNode(SListNode* pHead, int k)   //查找倒数第k个节点
{
	SListNode* fast = pHead;
	SListNode* slow = pHead;
	while (fast && k--)
	{
		fast = fast->next;
	}
	if (k > 0)
	{
		return NULL;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
void PrintTailToHead(SListNode* pHead)    //倒着打印单链表（递归）
{
	if (pHead)
	{
		PrintTailToHead(pHead->next);
		printf("%d ", pHead->data);
	}
}
//SListNode* Reverse_(SListNode*& pHead) //逆置单链表（需要接收返回值），原链表会面目全非
//{
//	SListNode* cur = pHead;
//	SListNode* newHead = NULL;
//	while (cur)
//	{
//		SListNode* tmp = cur;
//		cur = cur->next;
//		tmp->next = newHead;
//		newHead = tmp;
//	}
//	pHead = newHead;
//	return newHead;
//}
void Reverse(SListNode*& pHead)  //逆置单链表
{
	SListNode* cur = pHead;
	SListNode* newHead = NULL;
	while (cur)
	{
		SListNode* tmp = cur;
		cur = cur->next;   
		tmp->next = newHead;
		newHead = tmp;
	}
	pHead = newHead;
}
//剑指offer
/*
ListNode* ReverseList(ListNode* pHead)
{
ListNode* pReversedHead = NULL;
ListNode* pNode = pHead;
ListNode* pPrev = NULL;
while (pNode != NULL)
{
ListNode* pNext = pNode->m_pNext;

if (pNext == NULL)
pReversedHead = pNode;

pNode->m_pNext = pPrev;

pPrev = pNode;
pNode = pNext;
}
return pReversedHead;
}
*/

SListNode* Merge(SListNode* pHead1, SListNode* pHead2)   //合并两个有序链表（合并后依然有序）递归
{
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	SListNode* pMergedHead = NULL;

	if (pHead1->data < pHead2->data)
	{
		pMergedHead = pHead1;
		pMergedHead->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		pMergedHead = pHead2;
		pMergedHead->next = Merge(pHead1, pHead2->next);
	}

	return pMergedHead;
}
