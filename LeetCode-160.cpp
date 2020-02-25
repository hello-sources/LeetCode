/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//code 1
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    int len_a =0, len_b =0;
    while(a) {
        if (a->next) {
            a = a->next;
        } else {
            break;
        }
        len_a++;
        }
    while(b) {
        if (b->next) {
            b = b->next;
        } else {
            break;
        }
        len_b++;
    }
    a = headA;
    b = headB;
    if (len_a > len_b) {
        int len = len_a - len_b;
        while(len--) {
            a = a->next;
        }
    } else {
        int len = len_b - len_a;
        while(len--) {
            b = b->next;
        } 
    }
    while (a && b) {
        if(a == b){
          return a;
            break;
        }
        a = a->next;
        b = b->next;
    }
    return NULL;
}


//code 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int  cntA = 0, cntB = 0;
    struct ListNode *p = headA, *q = headB;
    while (p) cntA++, p = p->next;
    while (q) cntB++, q = q->next;
    int m = cntA - cntB;
    p = headA, q = headB;
    if (m > 0) {
        while (m--) p = p->next;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
    } else {
        while (m++) q = q->next;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
    }
    return p;
}
