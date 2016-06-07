/****************************************************************************************************/
/*
功能：应用C++语言实现单链表的各项操作
    建立链表的节点类LinkNode，封装一个SList类将有效节点链接起来
基本的成员函数：
           构造函数、拷贝构造函数、赋值运算符的重载、析构函数
**
**单链表的具体操作：
**                  1：在尾部插入节点
**                  2：打印单链表
**                  3：链表置空
**                  4：尾除尾节点
**                  5：头插
**                  6：删除首节点
**                  7：固定位置插入一个节点
**                  8：删除某一节点
**                  9：查找某节点并返回这个节点的位置
**                 10：计算链表节点的数目
**                 11：查找某节点并删除
**                 12：删除链表中所有的x
**                 13：去重
**                 14：合并两个链表
**                 15：冒泡排序
**                 16：翻转单链表
**
**                                                             By ：Lynn-Zhang
**
*/
/*****************************************************************************************************
  
typedef int DataType;
  
//节点类（复合形态）
//struct LinkNode    
//{
//  friend class SList;      //将SList设为友元，便于SList类可以访问节点类的私有成员
//public:
//  LinkNode(const DataType x); 
//private:
//  DataType _data;    //节点的数据
//  LinkNode* _next;    //指向该节点的下一个节点
//};
  
//直接用struct定义LinkNode类，因为struct的成员默认为公有数据成员，所以可直接访问
struct LinkNode      //节点类(建议写法)
{
    LinkNode(const DataType x);
    DataType _data;    //节点的数据
    LinkNode* _next;    //指向该节点的下一个节点
};

class SList
{
public:
    SList();         //构造函数
    SList(const SList& s);        //拷贝构造
    SList &operator=(SList& s);    //赋值运算符的重载
    ~SList();
  
public:  
        //单链表的具体操作
    void Uniqe();         //去重
    void Merge(SList &s);  //合并
    void Sort();       //冒泡
    void Reverse();   //翻转
    void Swap(SList& s);      //交换
    void PrintSList();   //打印链表
    void PushBack(const DataType& x);    //在尾部插入一个节点
    void Clear();         //链表置空
    void PopBack();       //删除尾节点
    void PushFront(DataType x);  //头插
    void PopFront();    //删除首节点
    void Insert(LinkNode* pos, DataType x);//固定位置插入一个节点
    void Erase(LinkNode* pos);        //删除某一节点
    LinkNode* Find(DataType x);       //查找节点并返回这个节点的地址
    int Amount();   //计算链表节点的数目
    void Remove(DataType x);     //查找某节点并删除
    void RemoveAll(DataType x);      //删除链表中所有的x
      
private:  
    LinkNode* _head;     //指向头节点
    LinkNode* _tail;        //指向尾节点
};
//*********************//