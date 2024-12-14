#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }
    bool isRight = isSameTree(p->right, q->left);
    bool isLeft = isSameTree(p->left, q->right);
    return isRight && isLeft;
}


bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;  
    }
    return isSameTree(root->left, root->right);
}


struct TreeNode* newNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(2);
    root1->left->left = newNode(3);
    root1->left->right = newNode(4);
    root1->right->left = newNode(4);
    root1->right->right = newNode(3);

    
    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->left = newNode(5);
    root2->right->right = newNode(3);

    
    if (isSymmetric(root1))
    {
        printf("The tree is symmetric.\n");
    }
    else
    {
        printf("The tree is not symmetric.\n");
    }

    if (isSymmetric(root2))
    {
        printf("The tree is symmetric.\n");
    }
    else
    {
        printf("The tree is not symmetric.\n");
    }

   
    free(root1->left->left);
    free(root1->left->right);
    free(root1->right->left);
    free(root1->right->right);
    free(root1->left);
    free(root1->right);
    free(root1);

    free(root2->left->left);
    free(root2->right->right);
    free(root2->left);
    free(root2->right);
    free(root2);

    return 0;
}
