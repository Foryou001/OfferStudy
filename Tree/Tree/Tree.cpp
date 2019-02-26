#include <iostream>
#include <vector>
using namespace std;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};


BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInoder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInoder && *startPreorder == *startInorder)
		{
			return root;
		}
		else
		{
			throw exception("Invalid input!");
		}
	}

	int* rootInorder = startInorder;
	while (rootInorder <= endInoder && *rootInorder != rootValue)
	{
		++rootInorder;
	}

	if (rootInorder == endInoder && *rootInorder != rootValue)
	{
		throw exception("Invalid input!");
	}

	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		//����������
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}

	if (leftLength < endPreorder - startPreorder)
	{
		//����������
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInoder);
	}

	return root;
}


BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
	{
		return nullptr;
	}

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}



void RebuildBinaryTree()
{
	//vector<int> vecPre;
	//vector<int> vecMid;

	//cout << "Please input the PreOrder:\n";
	//int tmp;
	//cin >> tmp;
	//vecPre.push_back(tmp);
	//while (cin.get() != '\n')
	//{
	//	cin >> tmp;
	//	vecPre.push_back(tmp);

	//}

	//cout << "Please input hte MidOrder:\n";
	//cin >> tmp;
	//vecMid.push_back(tmp);
	//while (cin.get() != '\n')
	//{
	//	cin >> tmp;
	//	vecMid.push_back(tmp);

	//}




}


//���һ���ڵ�������������ô������һ���ڵ���������������е�������ӽڵ㡣Ҳ����˵�������ӽڵ����һֱ����ֻ�����ӽڵ��ָ�룬���Ǿ����ҵ�������һ���ڵ㡣
//û�����ӽڵ�����������ýڵ������ĸ��ڵ����ڵ㣬��ô������һ���ڵ�������ĸ��ڵ�
//���һ���ڵ��û�������������������Ǹ��ڵ���нڵ㣬��ô��������Ƚϸ��ӡ������Կ�����ָ�򸸽ڵ��ָ��һֱ���ϱ�����ֱ���ҵ�һ���������ڵ�����ӽڵ�Ľڵ㡣


BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}

	//�����ӽڵ㣬��һ���ڵ�������ӽڵ��������ӽڵ�
	BinaryTreeNode* pNext = nullptr;
	if (pNode->m_pRight != nullptr)
	{
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
		{
			pRight = pRight->m_pLeft;
		}
		pNext = pRight;
	}

	//û�����ӽڵ��и��ڵ�
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		//ѭ�������ǵ�ǰ�ڵ��Ǹ��ڵ�����ӽڵ�
		while (pParent != nullptr && pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}

int main()
{
	int PreOrder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int InOrder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	BinaryTreeNode* Tree = Construct(PreOrder, InOrder, 8);

	system("pause");
	return 0;
}