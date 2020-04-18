/*
Nick Thoms
Data Structures 2020
Due: 4/17/2020
Lab 5: Binary Tree
Description: This lab is an example of how a binary search tree can be implemented in c++.
*/

#include<iostream>
#include"BiTree.h"

using namespace std;

int main()
{
	BiTree intTree;
	intTree.add(10);
	intTree.add(5);   // Items are added to the tree
	intTree.add(7);
	intTree.add(6);
	intTree.add(8);
	intTree.add(11);

	intTree.updateLevels(); // Levels are updated

	intTree.print();        // Tree is printed in numerical order
	intTree.reversePrint(); // Tree is printed in reverse order
	intTree.treePrint();    // Tree is printed in tree order

	intTree.remove(5);     // Item is removed

	intTree.updateLevels();

	intTree.print();
	intTree.reversePrint();
	intTree.treePrint();

	return 0;
}