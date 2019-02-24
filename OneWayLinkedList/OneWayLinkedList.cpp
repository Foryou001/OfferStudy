#include <iostream>

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
	while (p->m_pNext != nullptr)
	{
		cout << p->m_nValue << " ";
		p = p->m_pNext;
	}
	cout << endl;
}

//Add a node To the tail

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


int main()
{
	ListNode* OneWayLinkedList = nullptr;
	int add_value;
	while (cin >> add_value)
	{
		AddToTail(&OneWayLinkedList, add_value);
	}

	PrintAllNode(&OneWayLinkedList);

	system("pause");

	return 0;

}