/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    if (head->next->next == NULL) {
        head->next->next= head;
        head = head->next;
        head->next->next = NULL;
        return head;
    }
    struct ListNode *temp = head->next;
    head->next = temp->next;
    temp->next = head;
    head = temp;
    struct ListNode *p1, *p2;
    p1 = head->next;
    p2 = p1->next;
    while (p2->next != NULL) {
        p1->next = p2->next;
        p2->next = p1->next->next;
        p1->next->next = p2;
        p1 = p2;
        if (p2->next != NULL)
            p2 = p2->next;
    }
    return head;
}

//Âú·Ö´úÂë
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    struct ListNode* n = head;
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    while(n) {
        if(n->next) {
            newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = n->val;
            newNode->next = n->next->next;
            n->val = n->next->val;
            n->next = newNode;
            n = newNode->next;
        }
        else break;
    }

    return head;
}
