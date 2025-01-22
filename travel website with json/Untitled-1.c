#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive Inorder Traversal
void inorderRecursive(struct Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}

// Recursive Preorder Traversal
void preorderRecursive(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

// Recursive Postorder Traversal
void postorderRecursive(struct Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}

// Non-recursive Inorder Traversal
void inorderNonRecursive(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// Non-recursive Preorder Traversal
void preorderNonRecursive(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right) stack[++top] = curr->right;
        if (curr->left) stack[++top] = curr->left;
    }
}

// Non-recursive Postorder Traversal
void postorderNonRecursive(struct Node* root) {
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;
    if (root == NULL) return;

    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left) stack1[++top1] = curr->left;
        if (curr->right) stack1[++top1] = curr->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Mirror Image of the tree
struct Node* mirror(struct Node* root) {
    if (root == NULL) return NULL;

    struct Node* temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);

    return root;
}

// Count the number of nodes in the tree
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Menu-driven function
void menu() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int choice;
    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Recursive Inorder Traversal\n");
        printf("2. Recursive Preorder Traversal\n");
        printf("3. Recursive Postorder Traversal\n");
        printf("4. Non-recursive Inorder Traversal\n");
        printf("5. Non-recursive Preorder Traversal\n");
        printf("6. Non-recursive Postorder Traversal\n");
        printf("7. Mirror Image of Tree\n");
        printf("8. Count Nodes in Tree\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Recursive Inorder Traversal: ");
                inorderRecursive(root);
                break;
            case 2:
                printf("Recursive Preorder Traversal: ");
                preorderRecursive(root);
                break;
            case 3:
                printf("Recursive Postorder Traversal: ");
                postorderRecursive(root);
                break;
            case 4:
                printf("Non-recursive Inorder Traversal: ");
                inorderNonRecursive(root);
                break;
            case 5:
                printf("Non-recursive Preorder Traversal: ");
                preorderNonRecursive(root);
                break;
            case 6:
                printf("Non-recursive Postorder Traversal: ");
                postorderNonRecursive(root);
                break;
            case 7:
                root = mirror(root);
                printf("Tree mirrored. Now the Inorder Traversal is: ");
                inorderRecursive(root);
                break;
            case 8:
                printf("Number of nodes in the tree: %d", countNodes(root));
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
        printf("\n");
    }
}

int main() {
    menu();
    return 0;
}