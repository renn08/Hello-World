#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};//this ; is easy to be omitted

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    /*思路：
    int i, n1, n2 = 0;
    l1->val += l2->val;
    l1->next->val = l1->val / 10;
    l1->val = l1->val % 10;
    
    l1->next->val += l2->next->val;
    l1->next->next->val = l1->next->val / 10;
    l1->next->val = l1->next->val % 10;

    ...
    */
    /*大致代码，但对一长一短情况实现不清晰
    int i = 0;
    struct ListNode *p = l1; 
    struct ListNode *q = l2;
    while (i < 100){
        // p -> val = p ? p -> val : 0;
        // q -> val = q ? q -> val : 0;
        p -> val += q -> val;
        p -> next -> val = p -> val / 10;
        p -> val = p -> val % 10;
        p = p -> next;
        q = q -> next;
        i++;
    }*/
    /*难点在于解决 runtime error: member access within null pointer of type 'struct ListNode' [solution.c]*/
    int sum, n1, n2;
    int carry = 0;
    struct ListNode *head = NULL, *tail = NULL;//从空指针开始扩增 双指针超强 注意declare时每个值都要写，类型可以合并写
    while (l1 || l2){
        /*将一数字被另一数字超出的部分令为0*/
        n1 = l1 ? l1->val : 0;
        n2 = l2 ? l2->val : 0;

        sum = (n1 + n2 + carry) % 10;
        carry = (n1 + n2 + carry) / 10;
        if (!head){
            head = tail = (struct ListNode *)malloc(sizeof(struct ListNode));
            head -> val = sum;
            tail -> next = NULL; 
        }
        else{
            tail -> next = (struct ListNode *)malloc(sizeof(struct ListNode)); //malloc分配连续内存不会重叠
            tail -> next -> val = sum;
            tail = tail -> next;
            tail -> next = NULL; //确保安全结束
        }
        /*向后移动*/
        if (l1){
            l1 = l1 -> next;//不会越界因为任何一个val!=0的l1都会有next(最后一个有可能会变成NULL)
        }
        if (l2){
            l2 = l2 -> next;
        }  
    }
    /*还有多一位（只出现于两数字同长度）*/
    if (carry > 0){
        tail -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
        tail -> next -> val = carry;
        tail = tail -> next;
        tail -> next = NULL;
    }
    return head;
}

int main(){
    struct ListNode l1[100] = {{7, l1 + 1}, {8, l1 + 2}, {9, }};
    struct ListNode l2[100] = {{4, l2 + 1}, {5, l2 + 2}, {1, }};
    struct ListNode *sum = addTwoNumbers(l1, l2);
    struct ListNode *p = sum;
    while (p){
        printf("%d ", p -> val);
        if(p){
            p = p -> next;
        }
    }
    free(sum);
    return 0;
}