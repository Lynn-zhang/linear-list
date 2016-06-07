#include"SList.h"
#include<stdlib.h>
  
void Test3()
{
    //排序 去重 合并
    cout << "list 1:" << endl;
    SList list1;
  /*list1.PushBack(2);
    list1.PushBack(3);
    list1.PushBack(2);
    list1.PushBack(2);
    list1.PushBack(1);
    list1.PrintSList();
    list1.Sort();
    list1.PrintSList();
  list1.Uniqe();
    list1.PrintSList();*/
  
    list1.PushBack(5);
    list1.PushBack(3);
    list1.PushBack(8);
    list1.PushBack(2);
    list1.PushBack(9);
    list1.PushBack(10);
    list1.PushBack(2);
    list1.PushBack(2);
    list1.PushBack(1);
    list1.PrintSList();
    list1.Sort();
    list1.PrintSList();
      
    cout << "list 2:" << endl;
    SList list2;
    list2.PushBack(1);
    list2.PushBack(6);
    list2.PushBack(4);
    list2.PushBack(0);
    list2.PushBack(7);
    list2.PrintSList();
    list2.Sort();
    list2.PrintSList();
  
    cout << "list 1:" << endl<<endl;
    list1.Merge(list2);
    list1.PrintSList();
}
void Test2()
{
    SList list1;
    list1.PushBack(1);
    list1.PushBack(3);
    list1.PushBack(4);
    list1.PushBack(2);
    list1.PushBack(6);
    list1.PrintSList();
  
    /*list1.RemoveAll(2);
    list1.PrintSList();*/
  
    SList list2 = list1;
    /*list2.PushBack(2);
    list2.PushBack(3);
    list2.PushBack(4);
    list2.PushBack(2);
    list2.PushBack(2);*/
    list2.PrintSList();
    list2.Reverse();
    list2.PrintSList();
      
}
void Test1()
{
    //SList list1;
    //list1.PushBack(1);
    //list1.PushBack(2);
    //list1.PushBack(3);
    //list1.PushBack(4);
    //list1.PushBack(5);
    //list1.PrintSList();
  
    //list1.Remove(2);
    //list1.PrintSList();
  
    //int num =list1.Amount();
    //cout <<"节点个数："<< num << endl;
  
    /*//检验Erase函数
    LinkNode* del = list1.Find(2);
    list1.Erase(del);
    list1.PrintSList();
    */
  
    /*//找到某节点并在其后插入新节点
    LinkNode* In =list1.Find(5);
    list1.Insert(In, 0);
    list1.PrintSList();*/
  
    /* //删除头结点
    list1.PopFront();
    list1.PrintSList();
    *//////
  
    /*//////查找节点
    LinkNode* ret=list1.Find(5);
    if (ret != NULL)
    {
    cout << "要查找的节点data是：" << ret->_data << endl;
    cout << "要查找的节点adress是：" <<ret<< endl;
    }
    else
    {
    cout << "not exit !" << endl;
    }*////////
  
    //验证构造函数
    //SList list2(list1);
    //list2.PrintSList();
  
    //验证赋值运算符的重载
    //SList list3 = list2;
    //list3.PrintSList();
  
    //验证析构函数
    //list3.Clear();
    //list3.PrintSList();
  
    //验证尾删和头插
    ///*list3.PopBack();
    //list3.PrintSList();*/
    //list3.PushFront(0);
    //list3.PrintSList();
}
  
int main()
{
    //Test1();
    Test2();
    system("pause");
}