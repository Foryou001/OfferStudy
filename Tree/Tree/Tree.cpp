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
		//构建左子树
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}

	if (leftLength < endPreorder - startPreorder)
	{
		//构建右子树
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


//如果一个节点有右子树，那么它的下一个节点就是它的右子树中的最左的子节点。也就是说，从右子节点出发一直沿着只想左子节点的指针，我们就能找到它的下一个节点。
//没有右子节点的情况：如果该节点是它的父节点的左节点，那么它的下一个节点就是它的父节点
//如果一个节点既没有右子树，并且它还是父节点的有节点，那么这种情况比较复杂。我们以可沿着指向父节点的指针一直向上遍历，直到找到一个是它父节点的左子节点的节点。


BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}

	//有右子节点，下一个节点就是右子节点的最左的子节点
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

	//没有右子节点有父节点
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		//循环条件是当前节点是父节点的右子节点
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