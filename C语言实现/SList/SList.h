
#pragma once

typedef int DataType;

//���嵥����Ľڵ�����
typedef struct SListNode
{
	DataType data;   //ֵ
	struct SListNode* next;  //ָ����һ���ڵ��ָ��
}SListNode;

// ���Ҫ�޸�����ͱ��������
SListNode* _BuyNode(DataType x);    //�����ڵ�
void PrintSlist(SListNode* pHead);     //��ӡ������
void PushBack(SListNode* & pHead, DataType x);   //β��   �������������ã�ָ����list�ı���������ʱ���Σ����ô���ַ����������.c�ļ��в����ã�
//void PushBack(SListNode** pHead, DataType x);   // ����ĵ�һ������ָ�������һ���ڵ��ָ��ĵ�ַ������ʱ���Σ������ǵ�ַ��

void PopBack(SListNode* & pHead);   //βɾ
void PushFront(SListNode* & pHead, DataType x);    //ͷ��
void PopFront(SListNode* & pHead);    //ͷɾ
void DestoryList(SListNode*& pHead);     //�����������

int GetSize(SListNode* pHead);     //��ȡ������
SListNode* Find(SListNode* pHead, DataType x);    //��������
void Insert(SListNode* pos, DataType x);     //��ĳλ�ú��������
void Erase(SListNode*& pHead, SListNode* pos);        //ɾ��ĳλ�õ�����
void DelNonTailNode(SListNode* pos);  //ɾ��һ����ͷ������ķ�β�ڵ�
void InsertFrontNode(SListNode* pos, DataType x);    // ����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
SListNode* FindMidNode(SListNode* pHead);   //�����м�ڵ�
SListNode* FindKNode(SListNode* pHead, int k);   //���ҵ�����k���ڵ�(Ҫ��ֻ�ܱ���һ��)
void PrintTailToHead(SListNode* pHead);    //���Ŵ�ӡ�������ݹ飩

//SListNode* Reverse_(SListNode* pHead);  //���õ�������Ҫ���շ���ֵ����ԭ����ᱻ��
SListNode* Reverse_(SListNode*& pHead);  //���õ�������Ҫ���շ���ֵ�������ƣ�
void Reverse(SListNode*& pHead);  // ��ԭ��������

SListNode* Merge(SListNode* pHead1, SListNode* pHead2);   //�ϲ��������������ϲ�����Ȼ���򣩣��ݹ飩
void Sort(SListNode* pHead);   //ð������


