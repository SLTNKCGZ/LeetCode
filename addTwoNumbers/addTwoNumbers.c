#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void createNode(struct ListNode **node);
struct ListNode* reverseTheList(struct ListNode *head);
void printList(struct ListNode *head);

void printList(struct ListNode *head){
    struct ListNode *temp=head;
    
    while(temp!=NULL){
        printf("%d--",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *temp1 = l1;
    struct ListNode *temp2 = l2;
    
    struct ListNode *sumNode = NULL;
    struct ListNode *sumTemp = NULL;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL) {
        int sum = carry;
        carry = 0;
        if (temp1 != NULL) {
            sum += temp1->val;
            temp1 = temp1->next;
        }
        if (temp2 != NULL) {
            sum += temp2->val;
            temp2 = temp2->next;
        }
        if (sum >= 10) {
            carry = sum / 10;
            sum = sum % 10;
        }
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sum;
        newNode->next = NULL;
        if (sumNode == NULL) {
            sumNode = newNode;
            sumTemp = sumNode;
        } else {
            sumTemp->next = newNode;  
            sumTemp = newNode; 
        }
        
    }
    
    if (carry != 0) {
        struct ListNode *carryNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        carryNode->val = carry;
        carryNode->next = NULL;
        sumTemp->next = carryNode;
    }

    return reverseTheList(sumNode);
}



struct ListNode* reverseTheList(struct ListNode *head) {
    struct ListNode *previous = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;

    if(head==NULL || head->next==NULL){
        return head;
    }
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
void addNode(struct ListNode ** head,int data){
    struct ListNode  *new=(struct ListNode  *)malloc(sizeof(struct ListNode));
    new->val=data;
    new->next=NULL;
    struct ListNode  *temp=*head;
    if(*head==NULL){
        *head=new;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }
    
}

int main() {
    // İlk bağlı listeyi oluşturuyoruz
    struct ListNode *l1=NULL;
    addNode(&l1,2);
    addNode(&l1,4);
    addNode(&l1,3);

    struct ListNode *l2=NULL;
    addNode(&l2,5);
    addNode(&l2,6);
    addNode(&l2,4);
    printf("L1 list: ");
    printList(l1);
    printf("L2 list: ");
    printList(l2);
    
    struct ListNode *sum = addTwoNumbers(l1, l2);

    printf("Sum list: ");
    if(sum != NULL) {
        printList(sum);
    }
    printf("\n");

    return 0;
}
