/*
Nick Thoms
Data Structures 2020
Due: 4/17/2020
Lab 5: Binary Tree
Description: This lab is an example of how a binary search tree can be implemented in c++. The specification file contain the BiTree class.
*/

#ifndef BITREE_H
#define BITREE_H

using namespace std;

struct treeNode
{
	int info;
	treeNode* left;
	treeNode* right;
};

class BiTree
{
public:
	//Preconditions:  The object is created.
	//Postconditions: The attributes are assigned default values
	BiTree();

	//Preconditions: The oject has been created.
	//Postconditions: Memory is deallocated.
	~BiTree();

	//Preconditions:  The object is created and there is room on the computer for memory to be allocated.
	//Postconditions: The private function insert is called and an item is added to the tree.
	void add(int item);

	//Preconditions:  The object is created and the list is not empty.
	//Postconditions: Memory is deallocated and an item is removed from the tree.
	void remove(int item);

	//Preconditions:  The object is created.
	//Postconditions: A bool value is returned depending on if the tree is empty or not.
	bool IsEmpty();

	//Preconditions:  The object is created.
	//Postconditions: A bool value is returned depending on if the tree is full or not.
	bool IsFull();

	//Preconditions:  The object is created.
	//Postconditions: The private function aprint is called and the items are outputted to the screen in numerical order.
	void print();

	//Preconditions:  The object is created.
	//Postconditions: The private function tprint is called and the items are outputted to the screen in tree order.
	void treePrint();

	//Preconditions:  The object is created.
	//Postconditions: The private function dprint is called and the items are outputted to the screen in descending order.
	void reversePrint();

	//Preconditions:  The object is created.
	//Postconditions: The attribute numOfLevels is updated to the correct number of levels ( this should be called afetr and item is added or
	//				  deleted)
	void updateLevels();

private:

	treeNode* root;   //base node
	int numOfLevels; // int value that represents number of levels in the tree.

	void insert(treeNode* &node, int item);  // Called in the add method.
	void Delete(treeNode* &node, int item);  // Called in the remove method.
	void deleteNode(treeNode* &node);        // Called in the Delete function.
	void aprint(treeNode* node);             // Called in the print method.
	void dprint(treeNode* node);             // Called in the reverseprine method.
	void tprint(treeNode* node, int &level, int currentLevel); // Called in the treeprint method.
	void updateL(treeNode* node, int& level, int& numOfLevels); // Called in the updatelevels method.

};

#endif
