#include <iostream>
using namespace std;


template<typename T>
struct TreeNode
{
	T data;
	TreeNode* pLChild;
	TreeNode* pRChild;
};

// Ҫ�������������Ҫ��ʼ��ΪNULL
// ������˼·�ǣ��൱�ڰ�ÿһ��visit�Ľ�㣬���뵽pListLast����,����µ�list����Ҫ��˫������pListHead��˫�������ͷ����pListLast��˫�������β����

//�õ�һ�����������
template<typename T>
void ConvertBSTree2List_MiddleOrder(TreeNode<T>* pTreeRoot/*���ĸ��ڵ�*/, TreeNode<T>*& pListHead/*˫�������ͷָ��*/, TreeNode<T>*& pListLast/*˫�������βָ��*/)
{
	if (pTreeRoot == NULL)
	{
		return;
	}

	// �������������
	ConvertBSTree2List(pTreeRoot->pLChild, pListHead, pListLast);

	/* ����ǰ�ڵ㣬�ѽڵ�����˫������β��*/

	// �޸ĵ�ǰ�ڵ���ָ�룬ָ��˫������β��
	pTreeRoot->pLChild = pListLast;
	if (pListLast)		// �ǵ�һ���ڵ�
	{
		pListLast->pRChild = pTreeRoot;
	}
	else				// ��һ���ڵ�
	{
		pListHead = pTreeRoot;
	}
	pListLast = pTreeRoot;

	// �������������
	ConvertBSTree2List(pTreeRoot->pRChild, pListHead, pListLast);
}

//�ĵ�һ�����������
template<typename T>
void ConvertBSTree2List_PreOrder(TreeNode<T>* pTreeRoot/*���ĸ��ڵ�*/, TreeNode<T>*& pListHead/*˫�������ͷָ��*/, TreeNode<T>*& pListLast/*˫�������βָ��*/) {

	if (pTreeRoot == NULL) {
		return;
	}

	/* ����ǰ�ڵ㣬�ѽڵ�����˫������β��*/
	TreeNode<int> * temp_left;
	TreeNode<int> * temp_right;

	temp_left = pTreeRoot->pLChild;
	temp_right = pTreeRoot->pRChild;

	pTreeRoot->pLChild = pListLast;

	if (pListLast) {
		pListLast->pRChild = pTreeRoot;
	}
	else {
		pListHead = pTreeRoot;
	}
	pListLast = pTreeRoot;

	//����������
	ConvertBSTree2List_preorder(temp_left, pListHead, pListLast);
	ConvertBSTree2List_preorder(temp_right, pListHead, pListLast);
}

//���Ҫ�ĵ�����������ͱȽ��鷳��

int main() {
	TreeNode<int> *root = new TreeNode<int>();
	root->data = 10;
	root->pLChild = NULL;
	root->pRChild = NULL;

	TreeNode<int> *node_level1_1 = new TreeNode<int>();
	node_level1_1->data = 6;
	node_level1_1->pLChild = NULL;
	node_level1_1->pRChild = NULL;

	TreeNode<int> *node_level1_2 = new TreeNode<int>();
	node_level1_2->data = 14;
	node_level1_2->pLChild = NULL;
	node_level1_2->pRChild = NULL;


	TreeNode<int> *node_level2_1 = new TreeNode<int>();
	node_level2_1->data = 4;
	node_level2_1->pLChild = NULL;
	node_level2_1->pLChild = NULL;

	TreeNode<int> *node_level2_2 = new TreeNode<int>();
	node_level2_2->data = 8;
	node_level2_2->pLChild = NULL;
	node_level2_2->pRChild = NULL;


	TreeNode<int> *node_level2_3 = new TreeNode<int>();
	node_level2_3->data = 12;
	node_level2_3->pLChild = NULL;
	node_level2_3->pRChild = NULL;

	TreeNode<int> *node_level2_4 = new TreeNode<int>();
	node_level2_4->data = 16;
	node_level2_4->pLChild = NULL;
	node_level2_4->pRChild = NULL;

	root->pLChild = node_level1_1;
	root->pRChild = node_level1_2;

	node_level1_1->pLChild = node_level2_1;
	node_level1_1->pRChild = node_level2_2;

	node_level1_2->pLChild = node_level2_3;
	node_level1_2->pRChild = node_level2_4;

	TreeNode<int> *head = NULL;
	TreeNode<int> *last = NULL;

	//ConvertBSTree2List_MiddleOrder(root, head, last);
	ConvertBSTree2List_PreOrder(root, head);

	int val = head->data;
	cout << val << endl;

	TreeNode<int> * p = head;
	while (p != NULL) {
		cout << p->data << "  ";
		p = p->pRChild;
	}

	cout << endl;
	TreeNode<int> * q = last;
	while (q != NULL) {
		cout << q->data << "  ";
		q = q->pLChild;
	}

	return 0;
}