/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *temp;
    temp = head;
    while (temp->next != NULL) {
        if (temp->next->val == temp->val) {
            struct ListNode *del;
            del = temp->next;
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
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head || !head->next){
        return head;
    }
    struct ListNode *cur = head, *nex = head->next;

    while(nex){
        if(cur->val == nex->val){
            cur->next = nex->next;
            free(nex);
            nex = cur -> next;
        }else{
            cur = cur -> next;
            nex = nex -> next;
        }
    }
    return head;
}
