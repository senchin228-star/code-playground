#include <stdio.h>
#include <stlib.h>

typedef struct Node {
	int data;
	Node *left;
	Node *right;
} Node;

Node* insert(Node *root; int val)
{
	if (root == NULL){
		Node *node = malloc(sizeof(Node));
		if (node == NULL) return NULL;
		node->data = val;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
	else{
		if (val < root->data){
			root->left = insert(root->left, val);	
		}
		else if (val > root->data){
			root->right = insert(root->right, val);
		}
	}
	return root;
}

Node* find(Node *root, int value)
{
	if (root == NULL) return NULL;
	if (root->data == value) return root;
	else if (value < root->data){
		return find(root->left, value);
	}
	else(value > root->data){
		return find(root->right, value);
	}
}
void free_tree(Node *root)
{
	if (root == NULL) return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}



