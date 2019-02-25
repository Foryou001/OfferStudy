#include <iostream>
#include <vector>
using namespace std;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void RebuildBinaryTree()
{
	vector<int> vecPre;
	vector<int> vecMid;

	cout << "Please input the PreOrder:\n";
	int tmp;
	cin >> tmp;
	vecPre.push_back(tmp);
	while (cin.get() != '\n')
	{
		cin >> tmp;
		vecPre.push_back(tmp);

	}

	cout << "Please input hte MidOrder:\n";
	cin >> tmp;
	vecMid.push_back(tmp);
	while (cin.get() != '\n')
	{
		cin >> tmp;
		vecMid.push_back(tmp);

	}


	//this is just a test
	
}