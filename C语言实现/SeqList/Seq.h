
//////////////////////////////////////////////////////////  By: Lynn-Zhang
#define MAX_SIZE 5          //定义数组的容量

typedef int DataType;

//顺序表的结构体声明
typedef struct SeqList
{
	DataType array[MAX_SIZE];   //定义数组
	size_t size;     //定义当前顺序表大小
}SeqList;

void InitSeqList(SeqList* pSeq);     //初始化顺序表
void PrintSeqList(SeqList* pSeq);    //打印
void PushBack(SeqList* pSeq, DataType x);    //尾插
void PopBack(SeqList* pSeq);                 //尾删
void PushFront(SeqList* pSeq, DataType x);   //头插
void PopFront(SeqList* pSeq);                //头删
void Insert(SeqList* pSeq, size_t pos,DataType x);  //具体位置插入数据
int Find(SeqList* pSeq, size_t pos, DataType x);    //查找数据
void Erase(SeqList* pSeq, size_t pos);              //具体位置删除数据
int Remove(SeqList* pSeq, DataType x);              //删除顺序表的第一个x
void RemoveAll(SeqList* pSeq, DataType x);          //删除顺序表的所有x
void BubbleSort(SeqList* pSeq);                     //冒泡排序
void SeclectSort(SeqList* pSeq);                    //选择排序
int BinarySearch(SeqList* pSeq, DataType x);        //二分查找
 
 

