#include"SList.h"
#include<stdlib.h>
  
void Test3()
{
    //���� ȥ�� �ϲ�
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
    //cout <<"�ڵ������"<< num << endl;
  
    /*//����Erase����
    LinkNode* del = list1.Find(2);
    list1.Erase(del);
    list1.PrintSList();
    */
  
    /*//�ҵ�ĳ�ڵ㲢���������½ڵ�
    LinkNode* In =list1.Find(5);
    list1.Insert(In, 0);
    list1.PrintSList();*/
  
    /* //ɾ��ͷ���
    list1.PopFront();
    list1.PrintSList();
    *//////
  
    /*//////���ҽڵ�
    LinkNode* ret=list1.Find(5);
    if (ret != NULL)
    {
    cout << "Ҫ���ҵĽڵ�data�ǣ�" << ret->_data << endl;
    cout << "Ҫ���ҵĽڵ�adress�ǣ�" <<ret<< endl;
    }
    else
    {
    cout << "not exit !" << endl;
    }*////////
  
    //��֤���캯��
    //SList list2(list1);
    //list2.PrintSList();
  
    //��֤��ֵ�����������
    //SList list3 = list2;
    //list3.PrintSList();
  
    //��֤��������
    //list3.Clear();
    //list3.PrintSList();
  
    //��֤βɾ��ͷ��
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