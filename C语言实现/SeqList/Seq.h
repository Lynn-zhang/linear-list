
//////////////////////////////////////////////////////////  By: Lynn-Zhang
#define MAX_SIZE 5          //�������������

typedef int DataType;

//˳���Ľṹ������
typedef struct SeqList
{
	DataType array[MAX_SIZE];   //��������
	size_t size;     //���嵱ǰ˳����С
}SeqList;

void InitSeqList(SeqList* pSeq);     //��ʼ��˳���
void PrintSeqList(SeqList* pSeq);    //��ӡ
void PushBack(SeqList* pSeq, DataType x);    //β��
void PopBack(SeqList* pSeq);                 //βɾ
void PushFront(SeqList* pSeq, DataType x);   //ͷ��
void PopFront(SeqList* pSeq);                //ͷɾ
void Insert(SeqList* pSeq, size_t pos,DataType x);  //����λ�ò�������
int Find(SeqList* pSeq, size_t pos, DataType x);    //��������
void Erase(SeqList* pSeq, size_t pos);              //����λ��ɾ������
int Remove(SeqList* pSeq, DataType x);              //ɾ��˳���ĵ�һ��x
void RemoveAll(SeqList* pSeq, DataType x);          //ɾ��˳��������x
void BubbleSort(SeqList* pSeq);                     //ð������
void SeclectSort(SeqList* pSeq);                    //ѡ������
int BinarySearch(SeqList* pSeq, DataType x);        //���ֲ���
 
 

