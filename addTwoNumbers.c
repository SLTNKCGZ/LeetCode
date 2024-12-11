#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *sum = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tempSum = sum;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum1 = carry;  // Carry'yi ekliyoruz

        if (l1 != NULL) {
            sum1 += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum1 += l2->val;
            l2 = l2->next;
        }

        carry = sum1 / 10;  // Taşıma değeri
        sum1 = sum1 % 10;   // Kalan değer

        sum->val = sum1;    // Şimdiki düğümdeki değeri atama

        if (l1 != NULL || l2 != NULL || carry != 0) {
            sum->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            sum = sum->next;
        }
    }

    sum->next = NULL;  // Son düğümde next NULL olmalı
    return tempSum;
}

int main() {
    // İlk bağlı listeyi oluşturuyoruz
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    // İkinci bağlı listeyi oluşturuyoruz
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    // Toplama işlemi
    struct ListNode *sum = addTwoNumbers(l1, l2);

    // Toplam sonucu yazdırma
    while (sum != NULL) {
        printf("%d ", sum->val);
        sum = sum->next;
    }
    printf("\n");

    return 0;
}
