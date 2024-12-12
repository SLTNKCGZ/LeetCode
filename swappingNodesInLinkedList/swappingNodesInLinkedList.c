#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}node; 

struct ListNode* swapNodes(struct ListNode* head, int k);
void printList(node *head);


struct ListNode* swapNodes(struct ListNode* head, int k) {
    
    node *temp=head;
    int count=0;
    while(temp!=NULL){
        
        count++;
        temp=temp->next;
    }
    
    temp=head;
    int n1=0;
    int n2=0;
    for(int i=1;i<count+1;i++){
        
        if(i==k){
            n1=temp->val;
            
        }
        else if(i==count-k+1){
            n2=temp->val;
            
        }
        temp=temp->next;
    }
    
    temp=head;
    for(int i=1;i<count+1;i++){
        
            
        if(i==k){
            temp->val=n2;
            
        }
        else if(i==count-k+1){
            temp->val=n1;
            
        }
        temp=temp->next;
    }
    
    return head;
}
void printList(node *head){
    node *temp=head;
    
    while(temp!=NULL){
        printf("%d",temp->val);
        if(temp->next!=NULL){
            printf("--");
        }
        temp=temp->next;
    }
}
int main(){

    node *head = (node*)malloc(sizeof(node));
    head->val = 1;
    head->next = (node*)malloc(sizeof(node));
    head->next->val = 2;
    head->next->next = (node*)malloc(sizeof(node));
    head->next->next->val = 3;
    head->next->next->next = (node*)malloc(sizeof(node));
    head->next->next->next->val = 4;
    head->next->next->next->next = (node*)malloc(sizeof(node));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;
    printf("original list:");
    printList(head);
    head=swapNodes(head,2);
    printf("\nswapped list:");
    printList(head);
    return 0;
}