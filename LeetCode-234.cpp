
//得到链表长度
int get_len(struct ListNode *head) {
    int n = 0;
    while (head) n += 1, head = head->next;//逗号运算符在计数加一是时候，对应指针向下移动
    return n;
}

//链表部分反转，头插法，采用虚拟头节点
struct ListNode* reverse(struct ListNode *head, int n) {
    struct ListNode ret, *p = head, *q;
    while (n--) p = p->next;//把指针移到当前节点位置，便于向下进行反转操作
    ret.next = NULL;//头插法
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
} 

bool isPalindrome(struct ListNode* head){
    int len = get_len(head);//获取链表长度
    struct ListNode *p = head, *q = reverse(head, (len + 1) / 2);//把链表一分为二，q为中间开始向后
    //通过下半段反转的链表，向下与上半段进行比较
    while (q) {
        if (p->val - q->val) return false;//如果对应节点的值不相等就返回false
        p = p->next;//对应链表向后走
        q = q->next;//另一半的链表继续向后走
    }
    return true;
}
