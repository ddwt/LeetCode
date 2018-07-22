/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) return false;
    struct ListNode *temp, *temp2;
    temp = head;
    temp2 = head->next->next;
    while(temp2 != temp && temp2 != NULL && temp != NULL) {
        temp = temp->next;
        if (temp2->next != NULL)
            temp2 = temp2->next->next;
        else
            return false;
    }
    if (temp2 == temp)
        return true;
    else
        return false;
}
//Âú·Ö´úÂë
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast=head, *slow=head;
    while( slow && fast && fast->next ){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}
