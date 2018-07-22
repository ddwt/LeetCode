/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    struct ListNode *temp1, *temp2;
    temp1 = headA;
    temp2 = headB;
    int len1 = 1, len2 = 1;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
        len1++;
    }
    while (temp2->next != NULL) {
        temp2 = temp2->next;
        len2++;
    }
    temp1 = headA;
    temp2 = headB;
    if (len1 > len2) {
        int ind = len1 - len2;
        while (ind--) {
            temp1 = temp1->next;
        }
    } else {
        int ind = len2 - len1;
        while (ind--) {
            temp2 = temp2->next;
        }
    }
    while (temp1 != temp2 && temp1 != NULL && temp2 != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 == temp2)
        return temp1;
    else
        return NULL;
}
//Âú·Ö´úÂë
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int numA=0, numB=0, diff;
    struct ListNode *p = headA;
    struct ListNode *q = headB;
    while(p){
        numA++;
        p=p->next;
    }

    while(q){
        numB++;
        q=q->next;
    }
    p=headA;
    q=headB;
    if(numB>numA){
        diff = numB - numA;
        for(int i = 0; i < diff; i++){
            q=q->next;
        }
    } else {
        diff = numA - numB;
        for(int i = 0; i < diff; i++){
            p=p->next;
        }
    }
    while(p){
        if(p==q)
            return p;
        p=p->next;
        q=q->next;
    }
    return NULL;
}
