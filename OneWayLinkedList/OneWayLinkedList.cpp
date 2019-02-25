#include <iostream>
#include <vector>
#include <stack>
using namespace std;




//OneWayLinkedList Definition



struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;

};


//print the LinkedList

void PrintAllNode(ListNode** pHead)
{
	ListNode* p = *pHead;
	while (p!= nullptr)
	{
		cout << p->m_nValue << " ";
		p = p->m_pNext;
	}
	cout << endl;
}

//Add a node To the tail
/*为什么要将函数的第一个参数pHead设为指向指针的指针。
因为当我们往一个空链表中插入一个节点时，新插入的节点就是
链表的头指针。由于此时会改动头指针，因此必须把pHead参数
设置为指向指针的指针，否则出了这个函数pHead仍是一个空指针
*/
void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		//find the old tail
		ListNode* pNode = *pHead;

		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}

		//add the new tail after the old one
		pNode->m_pNext = pNew;

	}
}

//Remove the Node

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}



	ListNode* pDeleteBefore = *pHead;
	ListNode* pDelete = pDeleteBefore->m_pNext;

	if (pDeleteBefore->m_nValue == value)
	{
		*pHead = pDelete;
		delete *pHead;
		*pHead = nullptr;
		return;
	}

	while (pDeleteBefore->m_pNext != nullptr)
	{
		pDelete = pDeleteBefore->m_pNext;

		if (pDelete->m_nValue == value)
		{
			pDeleteBefore->m_pNext = pDelete->m_pNext;
			delete pDelete;
			pDelete = nullptr;
			break;
		}

		pDeleteBefore = pDeleteBefore->m_pNext;

	}
}


//从尾到头打印链表
void ReversePrint(ListNode* pHead)
{

	if (pHead == nullptr)
	{
		return;
	}

	ListNode* pNode = pHead;
	vector<int> vecValue;
	int value;
	while (pNode->m_pNext != nullptr)
	{
		value = pNode->m_nValue;
		vecValue.push_back(value);
		pNode = pNode->m_pNext;
	}
	value = pNode->m_nValue;
	vecValue.push_back(value);
	vector<int>::iterator it;
	for (it = vecValue.end() - 1; it != vecValue.begin(); --it)
	{
		cout << *it << " ";
	}
	cout << *it << endl;
}



//use stack

void PrintListReversingly_Iteratively(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;

	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;

	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		cout << pNode->m_nValue << "\t";
		nodes.pop();

	}
	
}
int main()
{
	ListNode* OneWayLinkedList = nullptr;
	int add_value;
	cin >> add_value;
	AddToTail(&OneWayLinkedList, add_value);
	while (cin.get() != '\n')
	{
		cin >> add_value;
		AddToTail(&OneWayLinkedList, add_value);
	}

	//PrintAllNode(&OneWayLinkedList);

	//input the node value to delete
	/*int value_delete;
	cin >> value_delete;

	RemoveNode(&OneWayLinkedList, value_delete);

	*/
	PrintAllNode(&OneWayLinkedList);

	ReversePrint(OneWayLinkedList);

	PrintListReversingly_Iteratively(OneWayLinkedList);

	system("pause");

	return 0;

}