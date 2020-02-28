//code 1
struct ListNode* reverseList(struct ListNode* head){
    if (!head) return head;
    struct ListNode *p = head->next, *q;
    head->next = NULL;
    while (p) {
        q = p->next;
        p->next = head;
        head = p;
        p = q;
    }
    return head;
}//正常的链表反转


//code 2
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode ret, *p, *q;//ret就是虚拟头，p指向第一个节点，q指向第二个节点
    if (head == NULL) return head;
    ret.next = NULL;//首先虚拟头指空
    p = head;
    while (p) {//p一直沿着原来的链表进行向后走
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;//注意返回值是虚拟头节点的下一个节点
}
