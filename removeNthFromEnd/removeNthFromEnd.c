#include <stdio.h>
#include <stdlib.h>
  
typedef struct ListNode {
    int val;
    struct ListNode *next;
}node;
 
node* removeNthFromEnd(node* head, int n) {
    int i;
    node *temp = head;
    node *prev = NULL;

    // Eğer sadece bir düğüm varsa ve silinecek düğüm bu ise
    if (n == 1 && head->next == NULL) {
        free(head);
        return NULL;
    }

    // Eğer n 1 ise, baştaki düğümü sil
    if (n == 1) {
        node *toDelete = head;
        head = head->next;
        free(toDelete);
        return head;
    }

    // temp'i sondan n'inci düğüme getir
    for (i = 1; i < n - 1; i++) {
        if (temp == NULL || temp->next == NULL) return head; // Liste biterse
        temp = temp->next;
    }

    // temp'in sonrasındaki düğümü sil
    node *toDelete = temp->next;
    if (toDelete != NULL) {
        temp->next = toDelete->next;
        free(toDelete);
    }
    //head=reverseTheList(head);
    return head;
}

node* reverseTheList(node* head) {
    node* previous = NULL;
    node* current = head;
    node* next = NULL;
    
    while (current != NULL) {
        next = current->next; // Bir sonraki düğümü kaydet
        current->next = previous; // Şu anki düğümün yönünü ters çevir
        previous = current; // Bir sonraki adım için 'previous' ve 'current' güncellenir
        current = next;
    }
    
    return previous;
    
}
void addNode(node** head,int data){
    node *new=(node *)malloc(sizeof(node));
    new->val=data;
    new->next=NULL;
    node *temp=*head;
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
void printList(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d--",temp->val);
        temp=temp->next;
    }
    
}
int main(){
    node *head=NULL;
    addNode(&head,5);
    addNode(&head,4);
    addNode(&head,3);
    
    head=reverseTheList(head);
    head=removeNthFromEnd(head,1);
    printList(reverseTheList(head));
}