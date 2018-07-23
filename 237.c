/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if (node == NULL || node->next == NULL) return ;
    struct ListNode *ret;
    ret = node->next;
    node->val = node->next->val;
    node->next = ret->next;
    free(ret);
}
//Âú·Ö´úÂë
void deleteNode(struct ListNode* node) {
        *node=*node->next;


}
