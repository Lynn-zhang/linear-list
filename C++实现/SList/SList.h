/****************************************************************************************************/
/*
���ܣ�Ӧ��C++����ʵ�ֵ�����ĸ������
    ��������Ľڵ���LinkNode����װһ��SList�ཫ��Ч�ڵ���������
�����ĳ�Ա������
           ���캯�����������캯������ֵ����������ء���������
**
**������ľ��������
**                  1����β������ڵ�
**                  2����ӡ������
**                  3�������ÿ�
**                  4��β��β�ڵ�
**                  5��ͷ��
**                  6��ɾ���׽ڵ�
**                  7���̶�λ�ò���һ���ڵ�
**                  8��ɾ��ĳһ�ڵ�
**                  9������ĳ�ڵ㲢��������ڵ��λ��
**                 10����������ڵ����Ŀ
**                 11������ĳ�ڵ㲢ɾ��
**                 12��ɾ�����������е�x
**                 13��ȥ��
**                 14���ϲ���������
**                 15��ð������
**                 16����ת������
**
**                                                             By ��Lynn-Zhang
**
*/
/*****************************************************************************************************
  
typedef int DataType;
  
//�ڵ��ࣨ������̬��
//struct LinkNode    
//{
//  friend class SList;      //��SList��Ϊ��Ԫ������SList����Է��ʽڵ����˽�г�Ա
//public:
//  LinkNode(const DataType x); 
//private:
//  DataType _data;    //�ڵ������
//  LinkNode* _next;    //ָ��ýڵ����һ���ڵ�
//};
  
//ֱ����struct����LinkNode�࣬��Ϊstruct�ĳ�ԱĬ��Ϊ�������ݳ�Ա�����Կ�ֱ�ӷ���
struct LinkNode      //�ڵ���(����д��)
{
    LinkNode(const DataType x);
    DataType _data;    //�ڵ������
    LinkNode* _next;    //ָ��ýڵ����һ���ڵ�
};

class SList
{
public:
    SList();         //���캯��
    SList(const SList& s);        //��������
    SList &operator=(SList& s);    //��ֵ�����������
    ~SList();
  
public:  
        //������ľ������
    void Uniqe();         //ȥ��
    void Merge(SList &s);  //�ϲ�
    void Sort();       //ð��
    void Reverse();   //��ת
    void Swap(SList& s);      //����
    void PrintSList();   //��ӡ����
    void PushBack(const DataType& x);    //��β������һ���ڵ�
    void Clear();         //�����ÿ�
    void PopBack();       //ɾ��β�ڵ�
    void PushFront(DataType x);  //ͷ��
    void PopFront();    //ɾ���׽ڵ�
    void Insert(LinkNode* pos, DataType x);//�̶�λ�ò���һ���ڵ�
    void Erase(LinkNode* pos);        //ɾ��ĳһ�ڵ�
    LinkNode* Find(DataType x);       //���ҽڵ㲢��������ڵ�ĵ�ַ
    int Amount();   //��������ڵ����Ŀ
    void Remove(DataType x);     //����ĳ�ڵ㲢ɾ��
    void RemoveAll(DataType x);      //ɾ�����������е�x
      
private:  
    LinkNode* _head;     //ָ��ͷ�ڵ�
    LinkNode* _tail;        //ָ��β�ڵ�
};
//*********************//