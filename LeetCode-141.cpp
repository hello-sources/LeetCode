/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    if (head == NULL) return false;
	while(p->next != NULL && q->next != NULL){
		if(p->next == q->next->next){
			return true;
		}
		p = p->next; q = q->next->next;
        if(p == NULL||q == NULL){
            return false;
        }
	}
	return false;
}
