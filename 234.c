/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->next = NULL;
    ret->val = 0;
    struct ListNode *temp = head;
    int len = 1, flag = 0;
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }
    //printf("%d\n", len);
    if (len % 2 != 0) {
        len = len / 2;
    } else {
        len = len / 2 - 1;
        flag = 1;
    }
    if (len == 0) return head->val == head->next->val;
    temp = head->next;
    while (len--) {
        head->next = ret->next;
        ret->next = head;
        head = temp;
        temp = temp->next;
    }
    if (flag == 1) {
        head->next = ret->next;
        ret->next = head;
    }
    head = ret->next;
    //printf("%d\n", temp->val);
    //printf("%d\n", head->val);
    //printf("%d\n", ret->val);
    //if (ret->next == NULL) printf("NULL");
    while (temp != NULL) {
        if (temp->val == head->val) {
            temp = temp->next;
            head = head->next;
        } else {
            return false;
        }
    }
    return true;
}
//Âú·Ö´úÂë
bool isPalindrome(struct ListNode* head) {
    struct ListNode *p = head;
    if(head == NULL)return true;
    if(head -> next == NULL)return true;
    if(head -> next -> next == NULL){
        if(head -> val == head -> next -> val )return true;
        else
            return false;
    }

    int n = 0, i;

    while(p != NULL){
        p = p -> next;
        n ++;
    }
    int data[n];
    p = head;

    for(i = 0; i < n; i ++){
        data[i] = p -> val;
        p = p -> next;
    }

    for(i = 0; i < n/2; i ++){
        if(data[i] != data[n - i - 1])return false;
    }

    return true;
}
