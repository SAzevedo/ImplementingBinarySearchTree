#pragma once

struct Node {
	int key;
	struct Node* leftChild;
	struct Node* rightChild;
};

struct Tree {
	struct Node* root;
};

extern struct Tree* createTree();

extern struct Node* createNode(int);

extern struct Node* insert(struct Tree*, int);

extern struct Node* search(struct Tree*, int);

extern struct Node* getSuccessor(struct Node* node);

extern void deleteNode(struct Tree*, int);

extern void deleteTree(struct Node*);

extern void inOrder(struct Node*);

extern void preOrder(struct Node*);

extern void postOrder(struct Node*);