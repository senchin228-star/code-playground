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
int main(void) { /* TEST */
    Node *root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("In-order traversal: ");
    print_in_order(root);
    printf("\n");

    printf("Tree height: %d\n", get_height(root));

    Node *min_node = get_min(root);
    Node *max_node = get_max(root);
    if (min_node) printf("Min value: %d\n", min_node->data);
    if (max_node) printf("Max value: %d\n", max_node->data);

    int target = 40;
    Node *found = find(root, target);
    if (found) {
        printf("Value %d found in tree!\n", target);
    } else {
        printf("Value %d not found.\n", target);
    }

    free_tree(root);
    root = NULL;

    return 0;
}

