/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *new_head = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_head->next = NULL;
    struct ListNode *temp = head->next;
    while (temp != NULL) {
        head->next = new_head->next;
        new_head->next = head;
        head = temp;
        temp = temp->next;
    }
    head->next = new_head->next;
    new_head->next = head;
    return new_head->next;
}
//Âú·Ö´úÂë
struct ListNode*  reverse(struct ListNode* prev,struct ListNode *after)
{
    if(!after)
        return NULL;

    struct ListNode *ret= reverse(after,after->next);

    after->next=prev;
    prev->next=NULL;
    if(!ret)
        return after;

    return ret;

}

struct ListNode* reverseList(struct ListNode* head) {

    //struct ListNode **temp=(struct ListNode **)malloc(sizeof(struct ListNode *));
    if(!head)

        return NULL;

    if(head->next==NULL)
        return head;

    return reverse(head,head->next);
    //return *temp;
}
