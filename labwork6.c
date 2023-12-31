#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define COUNT 3

//The backbone structure of the binary tree
struct Node {
    int data;
    struct Node *left, *right;
};

//Function to create a new node/branch in the tree
struct Node* newNode(int data)
{
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//Function to find the maximum between 2 ints
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

//Easy: Create a function to calculate the height of a binary tree.
int height(struct Node* root) 
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

//"Base"/Mandatory task to display the tree
//Helper function to print spaces
void printSpaces(int n) 
{
    for (int i = 0; i < n; i++)
        printf(" ");
}
//Helper function to calculate the width of a number
int numWidth(int num) 
{
    int width = 0;
    do {
        width++;
        num /= 10;
    } while (num != 0);
    return width;
}
// Function to print the binary tree
void printBinaryTree(struct Node* root) 
{
    if (root == NULL)
        return;

    int treeHeight = height(root);

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    int front = 0, rear = 0;

    queue[rear++] = root;
    int totalSpaces = COUNT * pow(2, treeHeight);
    int spacesBetweenNodes = totalSpaces/2;
    int spacesFromLeft = totalSpaces/2;
    for (int i = 0; i < treeHeight; i++) {
        int nodesAtLevel = pow(2, i);
        spacesFromLeft = (totalSpaces - spacesBetweenNodes*(nodesAtLevel - 1))/2;

        for (int j = 0; j < nodesAtLevel; j++) 
        {
            struct Node* node = queue[front++];

            if (node == NULL) 
            {
                printSpaces(spacesBetweenNodes);
                if (j == 0)
                    printSpaces(spacesFromLeft);
                queue[rear++] = NULL;
                queue[rear++] = NULL;
            } 
            else 
            {
                int nodeWidth = numWidth(node->data);
                if (j == 0)
                    printSpaces(spacesFromLeft);
                printf("%d", node->data);
                printSpaces(spacesBetweenNodes - nodeWidth);
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            }
        }
        spacesBetweenNodes = spacesFromLeft;
        printf("\n");
    }

    free(queue);
}

/*void print2DUtil(struct Node* root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;
 
    print2DUtil(root->right, space);
 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    print2DUtil(root->left, space);
}*/

//Function to insert a value into the tree
struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

//Easy: Create a function to count the number of leaf nodes in the binary tree.
int countLeafNodes(struct Node* root) 
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

//Medium: Create a function to find the lowest common ancestor (LCA) of two nodes with given values in a binary tree.
struct Node* findLCA(struct Node* root, int n1, int n2) 
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    if (leftLCA != NULL) 
        return leftLCA;
    else
        return rightLCA;
}

/*
//Medium: Create a function to delete a node with a given value from the binary search tree. Ensure that the tree remains a valid binary search tree after the deletion.
struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        free(root);
        return NULL;
    }

    return root;
}*/

//Medium: Create a function to delete a node with a given value from the binary search tree. Ensure that the tree remains a valid binary search tree after the deletion.
struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL)
        return root;

    // Recursive deletion based on key
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* successor = root->right;
        while (successor->left != NULL)
            successor = successor->left;

        root->data = successor->data;

        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}


//Medium: Create a function to check if the binary tree is balanced.
int isBalanced(struct Node* root) 
{
    if (root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (abs(leftHeight - rightHeight) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    struct Node* root = NULL;
    int inputValue;

    printf("Enter values to insert into the binary tree (enter a character to stop):\n");

    while (scanf("%d", &inputValue) == 1)
    {
        root = insert(root, inputValue);
    }

    printf("\nBinary Tree:\n");
    printBinaryTree(root);

    //E1
    printf("\nThe height of the given tree is %d.\n", height(root) - 1);
    //E2
    printf("\nThe tree has %d leaf nodes.\n", countLeafNodes(root));

    //M1
    int value1, value2;
    while (getchar() != '\n'); // Consume the newline character left in the buffer (I can only assume what this means. I copied it and the code worked because of it)
    printf("\nEnter the first value to find the Lowest Common Ancestor: ");
    scanf("%d", &value1);
    while (getchar() != '\n'); // Consume the newline character left in the buffer (I can only assume what this means. I copied it and the code worked because of it)
    printf("Enter the second value: ");
    scanf("%d", &value2);
    struct Node* lca = findLCA(root, value1, value2);
    if (lca != NULL)
        printf("Lowest Common Ancestor of %d and %d is %d.\n", value1, value2, lca->data);
    else
        printf("Lowest Common Ancestor of %d and %d was not found.\n");

    //M2
    int delete;
    printf("\nEnter the value you wish to delete: ");
    scanf("%d", &delete);
    root = deleteNode(root, delete);
    printf("\nBinary Tree after deletion:\n");
    printBinaryTree(root);

    //M3
    if (isBalanced(root))
        printf("\nThe binary tree is balanced.\n");
    else
        printf("\nThe binary tree is not balanced.\n");

    return 0;
}
