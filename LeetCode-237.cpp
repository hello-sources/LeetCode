
//传入的是要删除的节点，当前节点的值可以覆写
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;//待删除节点的值被覆盖为后一个节点的值
    node->next = node->next->next;//直接删除下一个节点
}
