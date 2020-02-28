//code 1
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p = head;
    if (p == NULL) return head;
    p->next = removeElements(p->next, val);//递归调用函数实现相应值的删除
    return (p->val == val)? p->next : p;
}


//code 2
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *p, *q;//类似的定义两个指针
    ret.next = head;
    p = &ret;//第一个指针p从链表头进行向后遍历
    while (p && p->next) {
        if (p->next->val == val) {//如果p节点对应下一个节点值就是我们要找的，指向删除操作
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;//否则就把当前节点p向后移动，也是避免出现连续的数相同
        }
    }
    return ret.next;
}
