/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) return head;
    while (head->val == val && head->next != NULL) {
        head = head->next;
    }
    if (head->val == val && head->next == NULL) return NULL;
    struct ListNode *temp;
    temp = head;
    while (temp->next != NULL) {
        if (temp->next->val == val) {
            struct ListNode *del = temp->next;
            temp->next = del->next;
            free(del);
            del = NULL;
        } else {
            temp = temp->next;
        }
    }
    return head;
}
//Âú·Ö´úÂë
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode temp;
    struct ListNode *p, *q;

    if(head == NULL)
        return NULL;

    temp.next = head;
    p = &temp;
    while(p->next != NULL) {
        if(p->next->val == val) {
            q = p->next;
            p->next = p->next->next;
            free(q);
        } else {
            p = p->next;
        }
    }


    return temp.next;
}
