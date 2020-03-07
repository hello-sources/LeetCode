

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) return true;//都空则相等
    if ( q == NULL || p == NULL) return  false;//有一空则不相等
    if (q->val - p->val) return false;//根节点不相等则不相等
    return isSameTree(p->left,q->left) && isSameTree(q->right, p->right);//递归调用函数，比较左右子树
}
