#include <iostream>
#include "EmpBinaryTree.h"
#include "Employee.h"
using namespace std;

void EmpBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	if (nodePtr == nullptr) {
		nodePtr = newNode;
	}
	else if (newNode->e.getNumber() <= nodePtr->e.getName()) {
		insert(nodePtr->left, newNode);
	}
	else {
		insert(nodePtr->right, newNode);
	}
}

void EmpBinaryTree::destroySubTree(TreeNode *nodePtr) {
	if (nodePtr) {
		if (nodePtr -> left) {
			destroySubTree(nodePtr->left);
		}
		if (nodePtr -> right) {
			destroySubTree(nodePtr->right);
		}
		delete nodePtr;
	}
}
void EmpBinaryTree::deleteNode(Employee e, TreeNode *&nodePtr) {
	if (e.getName() < nodePtr->e.getName()) {
		deleteNode(e, nodePtr->left);
	}
	else if (e.getName() > nodePtr->e.getName()) {
		deleteNode(e, nodePtr->right);
	}
	else {
		makeDeletion(nodePtr);
	}
}

void EmpBinaryTree::makeDeletion(TreeNode *&nodePtr) {
	TreeNode *tempNodePtr = nullptr;
	if (nodePtr == nullptr) {
		cout << "Cannot delete an empty node.\n";
	}
	else if(nodePtr->right == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else {
		tempNodePtr = nodePtr;
		TreeNode* workPtr=nodePtr->right;
		/*
		while (tempNodePtr->left) {
			tempNodePtr = tempNodePtr->left;
			tempNodePtr->left = nodePtr->left;
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNodePtr;
		}*/
		while (workPtr->left != nullptr) {
			workPtr = workPtr-> left;
		}
		tempNodePtr->e.setName(workPtr->e.getName());
		delete workPtr;
		//this doesn't delete the node. it finds the proper employee name to overwrite the node with employee to be deleted. this way is cheaper

	}
}

void EmpBinaryTree::displayInOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->e.getName() << endl;
		displayInOrder(nodePtr->right);
	}
}

void EmpBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->e.getName() << endl;
		displayInOrder(nodePtr->right);
	}
}

void EmpBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->e.getName() << endl;
	}
}

void EmpBinaryTree::insertEmployee(Employee e) {}

Employee getEmployee(string) {
	Employee e;
	return e;
}

void EmpBinaryTree::remove(Employee) {
	//Find the node that has the employee name

}

bool searchEmployee(Employee) {

}

