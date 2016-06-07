	#define _CRT_SECURE_NO_WARNINGS 1


	///////////////////

	typedef int DataType;

	//struct LinkNode     //�ڵ��ࣨ������̬��
	//{
	//	friend class SList;      //��SList��Ϊ��Ԫ������SList����Է��ʽڵ����˽�г�Ա
	//public:
	//	LinkNode(const DataType x);	
	//private:
	//	DataType _data;    //�ڵ������
	//	LinkNode* _next;    //ָ��ýڵ����һ���ڵ�
	//};

	//ֱ����struct����LinkNode�࣬��Ϊstruct�ĳ�ԱĬ��Ϊ�������ݳ�Ա�����Կ�ֱ�ӷ���
	struct LinkNode      //�ڵ���(����д��)
	{
		LinkNode(const DataType x);
		DataType _data;    //�ڵ������
		LinkNode* _next;    //���ָ��
		LinkNode* _prev;      //ǰ��ָ��
	};

	class List
	{
	public:
		List();         //���캯��
		List(const List& s);        //��������
		List &operator=(List& s);    //��ֵ�����������
		~List();

	public:
		void Reverse();
		void Swap(List& s);
		void PrintSList();   //��ӡ����
		void PushBack(const DataType& x);    //��β������һ���ڵ�
		void Clear();         //�����ÿ�
		void PopBack();
		void PushFront(DataType x);  //ͷ��
		void PopFront();    //ɾ���׽ڵ�
		void Insert(LinkNode* pos, DataType x);//�̶�λ�ò���һ���ڵ�
		void Erase(LinkNode* pos);        //ɾ��ĳһ�ڵ�
		LinkNode* Find(DataType x);       //���ҽڵ㲢��������ڵ�ĵ�ַ
		int Amount();   //��������ڵ����Ŀ
		void Remove(DataType x);     //����ĳ�ڵ㲢ɾ��

	private:
		LinkNode* _head;    //ָ��ͷ���
		LinkNode* _tail;    //ָ��β�ڵ�
	};



