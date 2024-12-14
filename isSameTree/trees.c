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
    bool isRight = isSameTree(p->right, q->right);
    bool isLeft = isSameTree(p->left, q->left);
    return isRight && isLeft;
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
    root1->right = newNode(3);
    
    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    
    if (isSameTree(root1, root2))
    {
        printf("The trees are the same.\n");
    }
    else
    {
        printf("The trees are not the same.\n");
    }

   
    free(root1->left);
    free(root1->right);
    free(root1);
    free(root2->left);
    free(root2->right);
    free(root2);

    return 0;
}
