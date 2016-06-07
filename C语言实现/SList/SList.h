
#pragma once

typedef int DataType;

//定义单链表的节点类型
typedef struct SListNode
{
	DataType data;   //值
	struct SListNode* next;  //指向下一个节点的指针
}SListNode;

// 如果要修改链表就必须加引用
SListNode* _BuyNode(DataType x);    //建立节点
void PrintSlist(SListNode* pHead);     //打印单链表
void PushBack(SListNode* & pHead, DataType x);   //尾插   （这里用了引用，指明是list的别名，调用时传参，不用传地址）（引用在.c文件中不可用）
//void PushBack(SListNode** pHead, DataType x);   // 这里的第一个参数指向链表第一个节点的指针的地址（调用时传参，传的是地址）

void PopBack(SListNode* & pHead);   //尾删
void PushFront(SListNode* & pHead, DataType x);    //头插
void PopFront(SListNode* & pHead);    //头删
void DestoryList(SListNode*& pHead);     //清空整个链表

int GetSize(SListNode* pHead);     //获取链表长度
SListNode* Find(SListNode* pHead, DataType x);    //查找数据
void Insert(SListNode* pos, DataType x);     //在某位置后插入数据
void Erase(SListNode*& pHead, SListNode* pos);        //删除某位置的数据
void DelNonTailNode(SListNode* pos);  //删除一个无头单链表的非尾节点
void InsertFrontNode(SListNode* pos, DataType x);    // 在无头单链表的一个非头节点前插入一个节点
SListNode* FindMidNode(SListNode* pHead);   //查找中间节点
SListNode* FindKNode(SListNode* pHead, int k);   //查找倒数第k个节点(要求只能遍历一次)
void PrintTailToHead(SListNode* pHead);    //倒着打印单链表（递归）

//SListNode* Reverse_(SListNode* pHead);  //逆置单链表（需要接收返回值），原链表会被改
SListNode* Reverse_(SListNode*& pHead);  //逆置单链表（需要接收返回值）（改善）
void Reverse(SListNode*& pHead);  // 将原链表逆置

SListNode* Merge(SListNode* pHead1, SListNode* pHead2);   //合并两个有序链表（合并后依然有序）（递归）
void Sort(SListNode* pHead);   //冒泡排序


