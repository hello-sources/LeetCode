
bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) return false;//空树就表示错误
    if (root->left == NULL && root->right == NULL) return sum - root->val == 0;//结束条件表示左右子树都为空，返回根节点与sum的值的比较
    return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));//左右子树都不同时为空，那么就递归查找相应的val是否等与sum值
}
