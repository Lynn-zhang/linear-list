#include"SList.h"

#include <stdio.h>
#include<assert.h>
#include <malloc.h>

SListNode* _BuyNode(DataType x)    //�����ڵ�
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	tmp->data = x;
	tmp->next = NULL;

	return tmp;
}
void PrintSlist(SListNode* pHead)   // ��ӡ������
{
	SListNode* cur = pHead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

	printf("NULL\n");
}
//void PushBack(SListNode** ppHead, DataType x)   //β��
//{
//	assert(ppHead);
//	// 1.��
//	// 2.��Ϊ��
//	if(*ppHead == NULL)
//	{
//		*ppHead = _BuyNode(x);
//	}
//	else
//	{
//		// ��β
//		SListNode* tail = *ppHead;
//		while(tail->next != NULL)
//		{
//			tail = tail->next;
//		}
//
//		tail->next = _BuyNode(x);
//	}
//}
void PushBack(SListNode* & pHead, DataType x)  //β��
{
	// 1.��
	// 2.��Ϊ��
	if (pHead == NULL)
	{
		pHead = _BuyNode(x);
	}
	else
	{
		// ��β
		SListNode* tail = pHead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = _BuyNode(x);
	}
}
void PopBack(SListNode* & pHead)      //  βɾ
{
	//
	// 1.��
	// 2.һ���ڵ�
	// 3.����ڵ�
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
void PushFront(SListNode* & pHead, DataType x)   //ͷ��
{
	// 1.��
	// 2.����
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
void PopFront(SListNode*& pHead)   //ͷɾ
{
	//
	// 1.��
	// 2.һ���ڵ�
	// 3.һ�����ϵĽڵ�
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
void DestoryList(SListNode*& pHead)   //�����������
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

int GetSize(SListNode* pHead)   //��ȡ������
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
SListNode* Find(SListNode* pHead, DataType x)  //���ҽڵ�
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
void Insert(SListNode* pos, DataType x)   // ĳλ�ú����ڵ�
{
	assert(pos);

	SListNode* tmp = _BuyNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
void Erase(SListNode*& pHead, SListNode* pos)   //ɾ��ĳλ�õĽڵ�
{
	assert(pos);
	assert(pHead);

	//posΪͷ���
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
void DelNonTailNode(SListNode* pos)  //// ɾ��һ����ͷ������ķ�β�ڵ�
{
	assert(pos);
	assert(pos->next);
	SListNode* del = pos->next;
	SListNode* dnext = del->next;
	pos->data = del->data;
	pos->next = dnext;
	free(del);
}
void InsertFrontNode(SListNode* pos, DataType x)     // ����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
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
void Sort(SListNode* pHead)    //ð������
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
SListNode* FindMidNode(SListNode* pHead)   //�����м�ڵ�
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
SListNode* FindKNode(SListNode* pHead, int k)   //���ҵ�����k���ڵ�
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
void PrintTailToHead(SListNode* pHead)    //���Ŵ�ӡ�������ݹ飩
{
	if (pHead)
	{
		PrintTailToHead(pHead->next);
		printf("%d ", pHead->data);
	}
}
//SListNode* Reverse_(SListNode*& pHead) //���õ�������Ҫ���շ���ֵ����ԭ�������Ŀȫ��
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
void Reverse(SListNode*& pHead)  //���õ�����
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
//��ָoffer
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

SListNode* Merge(SListNode* pHead1, SListNode* pHead2)   //�ϲ��������������ϲ�����Ȼ���򣩵ݹ�
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
