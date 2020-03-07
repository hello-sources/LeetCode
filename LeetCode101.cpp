
bool is_check(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val - q->val) return false;//比较两颗子树的根节点大小是否相等
    return is_check(p->left, q->right) && is_check(p->right, q->left);//比较两颗子树的左右子树是否相等
}


bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;//空树本身就是对称的
    return is_check(root->left, root->right);
}
