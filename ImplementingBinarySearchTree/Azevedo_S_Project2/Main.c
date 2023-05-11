#include <stdio.h>
#include "Functions.h"

int main(void) {
		
	struct Tree* tree = createTree();
	insert(tree, 2);
	insert(tree, 8);
	insert(tree, 5);
	insert(tree, 1);
	insert(tree, 6);
	insert(tree, 3);
	insert(tree, 4);
	insert(tree, 7);
	insert(tree, 0);

	printf("\nDisplaying the Binary Search Tree inOrder...\n");
	inOrder(tree->root);
	printf("\n");
	
	printf("\nSearching for a key in Binary Search Tree...\n");
	search(tree, 8);
	search(tree, 10);

	printf("\nDeleting a node by key in the Binary Search Tree...\n");
	deleteNode(tree, 8);
	deleteNode(tree, 10);

	printf("\nDisplaying the Binary Search Tree preOrder...\n");
	preOrder(tree->root);
	printf("\n");

	printf("\nDisplaying the Binary Search Tree postOrder...\n");
	postOrder(tree->root);
	printf("\n");

	printf("\nDeleting the tree...\n");
	deleteTree(tree->root);

	printf("\nDisplaying the Binary Search Tree inOrder...\n");
	inOrder(tree->root);
	printf("\n");

	return 0;
}