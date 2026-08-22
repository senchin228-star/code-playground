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
void callback_int_print_negative(int data, void *userdata)
{
	if (data < 0) printf("%d\n", data);
}
void callback_int_print_positive(int data, void *userdata)
{
	if (data >= 0) printf("%d\n", data);
}
void callback_int_print(int data, void *userdata)
{
    printf("%d\n", data);
}

void callback_int_sum(int data,void *userdata)
{
    int *sum = (int*)userdata;
    *sum +=data;
}
void callback_int_max(int data,void *userdata)
{
    int *cur = (int*)userdata;
    if (data > *cur) *cur = data; 
}

void int_bin_tree_traverse(Node *root, void (*callback)(int data, void *userdata), void *userdata)
{
    if (root == NULL) return;

    int_bin_tree_traverse(root->left, callback, userdata);
    callback(root->data, userdata);
    int_bin_tree_traverse(root->right, callback, userdata);
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

int main()
{
    Node root;

    insert(&root, 10);
    insert(&root, 15);
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 42);
    int_bin_tree_traverse(&root, callback_int_print, NULL);
    int sum = 0;
    int_bin_tree_traverse(&root, callback_int_sum, &sum);
    printf("SUM: %d\n", sum);
    int max = -999;
    int_bin_tree_traverse(&root, callback_int_max, &max);
    printf("MAX: %d\n", max);
    return 0;
}


