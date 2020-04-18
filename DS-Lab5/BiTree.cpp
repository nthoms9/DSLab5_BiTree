/*
Nick Thoms
Data Structures 2020
Due: 4/17/2020
Lab 5: Binary Tree
Description: This lab is an example of how a binary search tree can be implemented in c++. The implementation file contains the method 
			 definitions.
*/

#include <iostream>
#include "BiTree.h"

using namespace std;

BiTree::BiTree()
{
	root = nullptr;
	numOfLevels = 0;
}

BiTree::~BiTree()
{

}

void BiTree::add(int item)
{
	if(IsFull==false)
		insert(root, item);
}

void BiTree::remove(int item)
{
	if(IsEmpty()==false)
		Delete(root, item);
}

bool BiTree::IsEmpty()
{
	if (root == nullptr)
		return true;

	return false;
}

bool BiTree::IsFull()
{
	try
	{
		treeNode* temp = new treeNode;

		delete temp;
		return false;
	}
	catch (bad_alloc e)
	{
		return true;
	}
}

void BiTree::print()
{
	cout << "Ascending: ";
	aprint(root);
	cout << endl;
}

void BiTree::treePrint()
{
	int level = 1;
	for (int i = 1; i < (numOfLevels+1); i++)
	{
		cout << "level " << i << ": ";
		tprint(root, level, i);
		cout << endl;
	}
}

void BiTree::reversePrint()
{
	cout << "Descending: ";
	dprint(root);
	cout << endl;
}

//updateLevels updates numOfLevels to the correct integer value this is used for treeprint.
void BiTree::updateLevels()
{
		numOfLevels = 0;
		int level = 1;
		updateL(root, level, numOfLevels);
		
}

//Insert uses recursive calls to add items into the correct place
void BiTree::insert(treeNode* &node, int item)
{
	if (node == nullptr)
	{
		node = new treeNode;
		node->left = nullptr;
		node->right = nullptr;
		node->info = item;
	}
	else if (item < node->info)
		insert(node->left, item);
	else
		insert(node->right, item);
}

//Delete uses recursive calls to delete nodes
void BiTree::Delete(treeNode* &node, int item)
{
	if (item < node->info)
		Delete(node->left, item);
	else if (item > node->info)
		Delete(node->right, item);
	else
	{
		deleteNode(node);
	}
}

void BiTree::deleteNode(treeNode* &node)
{
	treeNode* temp = node;
	treeNode* parent = nullptr;
	if (node->left == nullptr && node->right == nullptr)
	{
		delete node;
	}
	else if (node->left != nullptr && node->right == nullptr)
	{
		node->info = node->left->info;
		temp = node->left;
		node->right = node->left->right;
		node->left = node->left->left;
		delete temp;
	}
	else if (node->left == nullptr && node->right != nullptr)
	{
		node->info = node->right->info;
		temp = node->right;
		node->left = node->right->left;
		node->right = node->right->right;
		delete temp;
	}
	else
	{
		temp = node->right;
		parent = temp;
		while (temp->left != nullptr)
		{
			parent = temp;
			temp = temp->left;
		}
		parent->left = temp->right;
		node->info = temp->info;
		delete temp;
	}
}

void BiTree::aprint(treeNode* node)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
			aprint(node->left);
		cout << node->info << "  ";
		if (node->right != nullptr)
			aprint(node->right);
	}
}

void BiTree::dprint(treeNode* node)
{
	if (node != nullptr)
	{
		if (node->right != nullptr)
			dprint(node->right);
		cout << node->info << "  ";
		if (node->left != nullptr)
			dprint(node->left);
	}
}

	void BiTree::tprint(treeNode* node, int &level, int currentLevel)
	{
		if (node != nullptr)
		{
			if (node->left != nullptr)
			{
				level++;
				tprint(node->left, level, currentLevel);
				level--;
			}
			if (level == currentLevel)
			{
				cout << node->info << "  ";
			}
			if (node->right != nullptr)
			{
				level++;
				tprint(node->right, level, currentLevel);
				level--;
			}
		}
	}

	void BiTree::updateL(treeNode* node, int& level, int& numOfLevels )
	{
		if (node != nullptr)
		{
			if (level > numOfLevels)
			{
				numOfLevels = level;
			}
			if (node->left != nullptr)
			{
				level++;
				if (level > numOfLevels)
				{
					numOfLevels = level;
				}
				updateL(node->left, level, numOfLevels);
				level--;
			}
			if (node->right != nullptr)
			{
				level++;
				if (level > numOfLevels)
				{
					numOfLevels = level;
				}
				updateL(node->right, level, numOfLevels);
				level--;
			}
		}
	}
