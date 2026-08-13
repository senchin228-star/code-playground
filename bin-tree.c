#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

Node* insert(Node *root, int val)
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
	else{
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
void print_in_order(Node *root)
{
    if (root == NULL) return;

    print_in_order(root->left);
    printf("%d ", root->data);
    print_in_order(root->right);
}
int get_height(Node *root){
    if (root == NULL) return 0;
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

Node *get_min(Node *root)
{
    if (root == NULL) return NULL;
    Node *tmp = root;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

Node *get_max(Node *root)
{
    if (root == NULL) return NULL;
    Node *tmp = root;
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp;
}

Node* delete_node(Node* root, int val)
{
    if (root == NULL) return NULL;

    if (root->data == val){
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if (root->left != NULL && root->right != NULL){
            Node *min_node = get_min(root->right);

            root->data = min_node->data;

            root->right = delete_node(root->right, min_node->data);
        }
        else{
            if (root->left == NULL) {
                Node *tmp = root->right;
                free(root);
                return tmp;
            } else if (root->right == NULL) {
                Node *tmp = root->left;
                free(root);
                return tmp;
            }
        }
    }
    else{
        if (val < root->data){
           root->left = delete_node(root->left, val);
        }
        else{
            root->right = delete_node(root->right, val);
        }
    }
    return root;
}

