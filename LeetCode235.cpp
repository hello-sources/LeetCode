
//code 1
//主要是按照二叉排序树的性质来判断，对于p, q就三种位置，一个是在根节点左边，一个是在根节点右边，一个是分别在根节点两边
struct TreeNode *__lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (root->val == p->val) return p;
    if (root->val == q->val) return q;
    if (root->val > p->val && q->val > root->val) return root;
   //这是处理根节点在p,q 两侧的情况下
    if (p->val > root->val) return __lowestCommonAncestor(root->right, p, q);//根节点右子树
    return __lowestCommonAncestor(root->left, p, q);//根节点左子树
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (p->val == q->val) return p;
    if (p->val > q->val) {
        struct TreeNode *temp = p;
        p = q;
        q = temp;
    }//当前p是较小编号
    return __lowestCommonAncestor(root, p, q);
}

//code 2
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p ,q);
    if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    return root;
}
