//============================================================================  
// Name        : BinaryTree.cpp  
// Author      : Yuhang_Shang  
// Date        : 2021.10.27  
// Copyright   : all rights reserved  
// Description : 实现《数据结构（严蔚敏）》中二叉树的以下功能：  
//               1.先序建立二叉树  
//               2.二叉树的先序、中序、后序递归算法  
//               3.二叉树的中序遍历非递归算法  
//               4.求二叉树的叶子节点  
//               5.求二叉树的深度  
//               程序说明：使用封装BinaryTree类实现二叉树功能，我觉得更好看也更方便。  
//============================================================================

#include <iostream>  
#include <stack>  
#include <stdlib.h>  

using namespace std;

//定义二叉树结点  
typedef struct _BinaryTreeNode {
	int data;
	_BinaryTreeNode* LeftChild;
	_BinaryTreeNode* RightChild;
}BinaryTreeNode;

class BinaryTree {
public:

	//先序创建二叉树（根左右）  
	void create(BinaryTreeNode*& node)
	{
		int _data;
		cin >> _data;
		if (_data) {
			node = new BinaryTreeNode;
			node->data = _data;  //生成根结点  
			create(node->LeftChild);  //构造左子树  
			create(node->RightChild);  //构造右子树  
		}
		else {
			node = NULL;
		}
	}//注：传参是因为二叉树的结点是point，需要二级指针才能改变其内容，因此在这里使用引用方法。  

	//释放内存  
	void clear(BinaryTreeNode*& node) {
		BinaryTreeNode* p = node;
		if (p != NULL) {
			clear(node->LeftChild);
			clear(node->RightChild);
			delete p;
		}
	}

	//先序遍历（根左右）  
	void preOrderTraverse(BinaryTreeNode* node) {
		if (node != NULL) {
			//输出遍历到的当前字符  
			cout << node->data << " ,";
			preOrderTraverse(node->LeftChild);
			preOrderTraverse(node->RightChild);
		}
	}

	//中序遍历（左根右）  
	void inOrderTraverse(BinaryTreeNode* node) {
		if (node != NULL) {
			inOrderTraverse(node->LeftChild);
			//输出遍历到的当前字符  
			cout << node->data << " ,";
			inOrderTraverse(node->RightChild);
		}
	}

	//后序遍历（左右根）  
	void postOrderTraverse(BinaryTreeNode* node) {
		if (node != NULL) {
			postOrderTraverse(node->LeftChild);
			//输出遍历到的当前字符  
			postOrderTraverse(node->RightChild);
			cout << node->data << " ,";
		}
	}

	//非递归中序遍历  
	void unRecursion_InOrderTraverse(BinaryTreeNode* node) {
		stack<BinaryTreeNode*> s;
		BinaryTreeNode* p = node;
		while (p != NULL || !s.empty())
		{
			while (p != NULL)
			{
				s.push(p);
				//遍历左子树  
				p = p->LeftChild;
			}
			if (!s.empty())
			{
				//获取栈顶元素，也就是最终结点  
				p = s.top();
				//输出结点  
				cout << p->data << " ,";
				//将此次结点出栈  
				s.pop();
				//遍历右子树  
				p = p->RightChild;
			}
		}
	}

	//二叉树深度  
	int depthOfTree(BinaryTreeNode* node) {
		if (node) {
			return max(depthOfTree(node->LeftChild), depthOfTree(node->RightChild)) + 1;
		}
		else {
			return 0;
		}
	}

	//叶子节点数目  
	int getLeafNum(BinaryTreeNode* node) {
		if (!node) {
			return 0;
		}
		else if (node->LeftChild == NULL && node->RightChild == NULL) {
			return 1;
		}
		else {
			return getLeafNum(node->LeftChild) + getLeafNum(node->RightChild);
		}
	}
};

int main()
{
	//页面初始化（也是为了美观）  
	system("title BinaryTree @ShangYuhang");
	system("mode con cols=85 lines=30");
	system("color F0");
	//声明二叉树变量tree  
	BinaryTree tree;
	//声明节点e  
	BinaryTreeNode* e;
	//提示信息  
	cout << "请按照先序输入二叉树数值（0代表空）：" << endl;
	//先序创建二叉树  
	tree.create(e);
	//先序遍历结果  
	cout << "先序遍历（递归）结果";
	tree.preOrderTraverse(e);
	cout << endl;
	//中序遍历结果  
	cout << "中序遍历（递归）结果：";
	tree.inOrderTraverse(e);
	cout << endl;
	//中序遍历（非递归）结果  
	cout << "中序遍历（非递归）结果：";
	tree.unRecursion_InOrderTraverse(e);
	cout << endl;
	//后序遍历结果  
	cout << "后序遍历（递归）结果：";
	tree.postOrderTraverse(e);
	cout << endl;
	//叶子节点数  
	cout << "叶子节点数：" << tree.getLeafNum(e) << endl;
	//二叉树深度  
	cout << "二叉树深度：" << tree.depthOfTree(e) << endl;
	//释放内存  
	tree.clear(e);
	return 0;
}
