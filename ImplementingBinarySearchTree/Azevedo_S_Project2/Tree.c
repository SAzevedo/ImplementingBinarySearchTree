#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Functions.h"

struct Node* root;

struct Tree* createTree() {  // works
	struct Tree* ptr = (struct Node*)malloc(sizeof(struct Node));
	if (ptr != NULL) {
		ptr->root = NULL;
	}
	else {
		printf("\nMemory allocation failed to allocate memory for Tree.\n");
	}
	return ptr;
}

struct Node* createNode(int value) {  // works
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));  // make a new Node and set pointer to ptr
	if (ptr != NULL) {
		ptr->key = value;
		ptr->leftChild = NULL;
		ptr->rightChild = NULL;
	}
	else {
		printf("\nMemory allocation failed to allocate memory for Node.\n");
	}
	return ptr;
}

struct Node* insert(struct Tree* tree, int value) {  //works
	struct Node* newNode = createNode(value);
	if (tree->root == NULL) {
		tree->root = newNode;
		struct Node* ptr = tree->root;
		printf("Node with key value of %d added to binary search tree.\n", ptr->key);
		return ptr;
	}
	else {
		struct Node* current = tree->root;
		struct Node* parent = tree->root;
		while (1 == 1) {
			parent = current;
			if (value < current->key) {
				current = current->leftChild;
				if (current == NULL) {
					parent->leftChild = newNode;
					struct Node* ptr = parent->leftChild;
					printf("Node with key value of %d added to binary search tree.\n", ptr->key);
					return ptr;
				}
			}
			else {
				current = current->rightChild;
				if (current == NULL) {
					parent->rightChild = newNode;
					struct Node* ptr = parent->rightChild;
					printf("Node with key value of %d added to binary search tree.\n", ptr->key);
					return ptr;
				}
			}
		}
	}
}

struct Node* search(struct Tree* tree, int value) {  //works
	struct Node* current = tree->root;
	while (current->key != value) {
		if (value < current->key) {
			current = current->leftChild;
		}
		else {
			current = current->rightChild;
		}
		if (current == NULL) {
			printf("The node with value of %d does not exist in the Binary Search Tree.\n", value);
			return NULL;
		}
	}
	printf("The node with value of %d was found in the Binary Search Tree.\n", current->key);
	return current;
}

void deleteNode(struct Tree* tree, int value) { //works
	struct Node* current = tree->root;
	struct Node* parent = tree->root;
	bool isLeftChild = true;
	while (current->key != value) {
		if (value < current->key) {
			isLeftChild = true;
			current = current->leftChild;
		}
		else {
			isLeftChild = false;
			current = current->rightChild;
		}
		if (current == NULL) {
			printf("No node with key of %d was found in the Binary Search Tree, nothing deleted.\n", value);
			return NULL;
		}
	}
	// case 1: no children
	if (current->leftChild == NULL && current->rightChild == NULL) {
		if (current == tree->root) {
			tree->root = NULL;
		}
		else if (isLeftChild) {
			parent->leftChild = NULL;
		}
		else {
			parent->rightChild = NULL;
		}
	}
	// case 2: only a left child
	else if (current->rightChild == NULL) {
		if (current == tree->root) {
			tree->root = current->leftChild;
		}
		else if (isLeftChild) {
			parent->leftChild = current->leftChild;
		}
		else {
			parent->rightChild = current->leftChild;
		}
	}
	// case 3: only a right child
	else if (current->leftChild == NULL) {
		if (current == tree->root) {
			tree->root = current->rightChild;
		}
		else if (isLeftChild) {
			parent->leftChild = current->rightChild;
		}
		else {
			parent->rightChild = current->rightChild;
		}
	}
	// case 4: has two children
	else {
		struct Node* successor = getSuccessor(current);
		if (current == tree->root) {
			tree->root = successor;
		}
		else if (isLeftChild) {
			parent->leftChild = successor;
		}
		else {
			parent->rightChild = successor;
		}
		successor->leftChild = current->leftChild;
	}
	printf("The node with key of %d has been found and deleted from the Binary Search Tree.\n", current->key);
	free(current);
}

struct Node* getSuccessor(struct Node* node) { //works
	struct Node* parent = node;
	struct Node* successor = node;
	struct Node* current = node->rightChild;
	while (current != NULL) {
		parent = successor;
		successor = current;
		current = current->leftChild;
	}
	if (successor != node->rightChild) {
		parent->leftChild = successor->rightChild;
		successor->rightChild = node->rightChild;
	}
	return successor;
}

void deleteTree(struct Node* root) {  //works
	if (root != NULL) {
		deleteTree(root->leftChild);
		deleteTree(root->rightChild);
		free(root);
	}
}

void inOrder(struct Node* root) {  // works
	if (root != NULL) {
		inOrder(root->leftChild);
		printf("%d ", root->key);
		inOrder(root->rightChild);
	}
}

void preOrder(struct Node* root) {  //works
	if (root != NULL) {
		printf("%d ", root->key);
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}

void postOrder(struct Node* root) {  //works
	if (root != NULL) {
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		printf("%d ", root->key);
	}
}