/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//code 1
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    for(int i = 0; i < n; i++){
        p = p->next;
    }
    if(p == NULL){
        head = head->next;
        return head;
    }
    for( ;p->next != NULL ; p = p->next){
        q = q->next; 
    }
    p = q->next;
    q->next = q->next->next;
    free(p);
    return head;
}

//code 2
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct  ListNode ret, *p, *q;//设置一个虚拟头节点ret,以及两个指针
    ret.next = head;
    p = q = &ret;//p初始化为首地址,p从虚拟头节点往后走
    while (n--) q = q->next;
    q = q->next;//当前q 走到当前位置前一个节点
    while (q) {
        p = p->next;
        q = q->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
}
