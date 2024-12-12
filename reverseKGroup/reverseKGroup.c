#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} node;
void printList(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->val);
        if (temp->next != NULL)
        {
            printf("--");
        }
        temp = temp->next;
    }
    printf("\n");
}
int reversePart(node *previous, node *current, int k)
{
    printf("reversePartta\n");
    node *preTemp = previous;
    node *curTemp = current;
    node *next = NULL;
    node *temp = current;
    int count = 0;
    while (curTemp != NULL)
    {
        count++;
        curTemp = curTemp->next;
    }
    curTemp=current;
    if (count >= k)
    {
        printf("kontrol\n");
        int i = 0;
        while (curTemp != NULL && i < k)
        {
            //printf("%d\n",i);
            next = curTemp->next;
            curTemp->next = preTemp;
            preTemp = curTemp;
            curTemp = next;
            i++;
        }
        printf("pretemp:%d\n",preTemp->val);
        printf("curtemp:%d\n",curTemp->val);
        printf("current:%d\n",current->val);
        //printf("previous:%d\n",previous->val);
        printf("temp:%d\n",temp->val);
        printList(preTemp);
        temp->next = curTemp;
        previous = temp;
        printf("previous:%d\n",previous->val);
        printList(previous);
        printf("curtemp:%d\n",curTemp->val);
        printList(curTemp);
        current = curTemp;
        printf("current:%d\n",current->val);
        printList(current);
    }
    else {
        return 0;
    }
    return 1;
}
struct ListNode *reverseKGroup(struct ListNode *head, int k)
{

    node *current = head;
    node *previous = NULL;
    while (1)
    {
        printf("not null\n");
        if(reversePart(previous, current, k)!=1){
            break;
        }
        
    }

    return head;
}

int main()
{

    node *head = (node *)malloc(sizeof(node));
    head->val = 1;
    head->next = (node *)malloc(sizeof(node));
    head->next->val = 2;
    head->next->next = (node *)malloc(sizeof(node));
    head->next->next->val = 3;
    head->next->next->next = (node *)malloc(sizeof(node));
    head->next->next->next->val = 4;
    head->next->next->next->next = (node *)malloc(sizeof(node));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;
    printf("original list:");
    printList(head);
    reverseKGroup(head, 2);
    printf("\nreversed list:");
    printList(head);
    return 0;
}
