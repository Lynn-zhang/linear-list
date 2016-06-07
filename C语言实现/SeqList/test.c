#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#include"Seq.h"

//初始化
void InitSeqList(SeqList* pSeq)
{
	assert(pSeq);
	memset(pSeq->array, 0, sizeof(DataType)*MAX_SIZE);
	pSeq->size = 0;
}

//1.检查参数
//2.边界条件的检查
//3.完成功能函数

//尾插
void PushBack(SeqList* pSeq, DataType x)
{
	/*assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("SeqList is Full !");
		printf("\n");
		return;
	}
	pSeq->array[pSeq->size++] = x;*/
	Insert(pSeq,pSeq->size,x);

}
//尾删
void PopBack(SeqList* pSeq)
{
	assert(pSeq);
	if (pSeq->size <=0)
	{
		printf("SeqList is empty !");
		printf("\n");
		return;
	} 
	//pSeq->array[--pSeq->size] = 0;
	--pSeq->size;
}
//打印
void PrintSeqList(SeqList* pSeq)
{
	assert(pSeq);
	int i = 0;
	for (; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}
//头插
void PushFront(SeqList* pSeq, DataType x)        
{
	/*assert(pSeq);
	int begin = pSeq->size - 1;
	if (pSeq->size >= MAX_SIZE)
	{
		printf("SeqList is Full !");
		printf("\n");
		return;
	}
	for (; begin >= 0; --begin)
	{
		pSeq->array[begin + 1] = pSeq->array[begin];
	}
	pSeq->array[0] = x;
	++pSeq->size;*/
	Insert(pSeq, 0, x);
}
//头删
void PopFront(SeqList* pSeq)            
{
	assert(pSeq);
	int begin = 0;
	if (pSeq->size <= 0)
	{
		printf("SeqList is empty !\n");
	}
	for (; begin <pSeq->size-1; begin++)
	{
		pSeq->array[begin] = pSeq->array[begin + 1];
	}
	--pSeq->size;
}
//固定位置插入
void Insert(SeqList* pSeq, size_t pos, DataType x)     
{
	assert(pSeq);
	assert(pos<=pSeq->size);
	int begin = pSeq->size - 1;
	if (pSeq->size >= MAX_SIZE)
	{
		printf("SeqList is Full !");
		printf("\n");
		return;
	}
	for (; begin >=(int) pos; begin--)
	{
		pSeq->array[begin+1] = pSeq->array[begin];
	}
	pSeq->array[pos] = x;
	++pSeq->size;
}
//查找
int Find(SeqList* pSeq, size_t pos, DataType x)
{
	assert(pSeq);
	int i= pos;
	for (;i < pSeq->size; i++)
	{
		if (pSeq->array[i] == x)
			return i;
	}
	return -1;
}
//固定位置删除
void Erase(SeqList* pSeq, size_t pos)
{
	assert(pSeq);
	assert(pos < pSeq->size);
	int begin = pos;
	if (pSeq->size <= 0)
	{
		printf("SeqList is empty !");
		printf("\n");
		return;
	}
	for (; begin <= pSeq->size - 1; begin++)
	{
		pSeq->array[begin] = pSeq->array[begin + 1];
	}
	--pSeq->size;
}
//查找并删除
int Remove(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	int pos = Find(pSeq, 0,x);
	if (pos != -1)
	{
		Erase(pSeq, pos);
	}
	return pos;
}
//删除所有x
void RemoveAll(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	int pos = Find(pSeq, 0, x);
	while (pos !=-1)
	{
		Erase(pSeq, pos);
		pos = Find(pSeq,pos, x);
	}
}
void removeall(SeqList* pSeq, DataType x)          //优化
{
	assert(pSeq);
	int i = 0;
	int count = 0;
	for (; i < pSeq->size; i++)
	{
		if (pSeq->array[i] == x)
		{
			count++;
		}
		else
		{
		pSeq->array[i-count] = pSeq->array[i];
		}
	}
	pSeq->size -= count;
}

//冒泡排序
void BubbleSort(SeqList* pSeq)
{
	assert(pSeq);
	int i, j;
	int ret = 0;
	for (i = 0; i < pSeq->size - 1; i++)
	{
		for (j = 0; j < pSeq->size - i - 1; j++)
		{
			int exchange = 0;
			if (pSeq->array[j]> pSeq->array[j + 1])
			{
				ret = pSeq->array[j];
				pSeq->array[j] = pSeq->array[j + 1];
				pSeq->array[j + 1] = ret;
				exchange = 1;
			}
			if (exchange == 0)
				return;
		}
	}

}
//选择排序
void Swap(DataType* left,DataType*right)
{
	DataType tmp = *left;
	*left = *right;
	*right = tmp;
}
void SeclectSort(SeqList* pSeq)
{
	assert(pSeq);
	int left = 0;
	int right = pSeq->size - 1;
	int ret ,min,max;
	while (left<right)
	{
		min = left;
		max = right;
		for (int i = left; i<right; ++i)
		{
			if (pSeq->array[min]>pSeq->array[i])
			{
				Swap(&pSeq->array[min], &pSeq->array[i]);
			}
			if (pSeq->array[max]<pSeq->array[i])
			{
				Swap(&pSeq->array[max], &pSeq->array[i]);
			}	
		}
		++left;
		--right;
	}
}

//二分查找
int BinarySearch(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	int left = 0;
	//int right = pSeq->size - 1;          //  [  ]
	int right = pSeq->size;                                        //  [  )
	//while (left <= right)
	while (left<right)
	{
		int mid = left - (left - right) / 2;
		if (pSeq->array[mid] == x)
		{
			return mid;
		}
		else if (pSeq->array[mid]>x)
		{
			right = mid - 1;
			//right = mid;
		}
		else if (pSeq->array[mid]<x)
		{
			left = mid + 1;
		}
	}
	return -1;
}
void Test1()
{
	SeqList seq;
	InitSeqList(&seq);

	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);

	PrintSeqList(&seq);

	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);
	PopBack(&seq);

	PrintSeqList(&seq);
}

void Test2()
{
	SeqList seq;
	InitSeqList(&seq);

	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);

	PushFront(&seq, 0);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);

	Insert(&seq, 2, 2);
	PrintSeqList(&seq);
}

void Test3()
{
	SeqList seq;
	InitSeqList(&seq);

	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 4);
	PushBack(&seq, 5);

	PushFront(&seq, 0);
	Remove(&seq, 5);
	//Insert(&seq, 2, 3);
	PrintSeqList(&seq);
}

void Test4()
{
	SeqList seq;
	InitSeqList(&seq);

	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 2);
	PushBack(&seq, 2);

	PrintSeqList(&seq);

	//Erase(&seq, 2);
	//Remove(&seq, 4);
	removeall(&seq, 2);

	PrintSeqList(&seq);
	
}

void Test5()
{
	SeqList seq;
	InitSeqList(&seq);

	PushBack(&seq, 1);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 2);
	PushBack(&seq, 3);

	PrintSeqList(&seq);

	/*int ret = BinarySearch(&seq,4);
	if (ret != -1)
	{
		printf("pos=%d  ", ret);
	}
	else
	{
		printf("not exist !");
	}*/

	//BubbleSort(&seq);
	SeclectSort(&seq);
	PrintSeqList(&seq);
}
int main()
{
	Test5();
	//Test4();
	//Test3();
	//Test2();
	//Test1();
	system("pause");
	return 0;
}