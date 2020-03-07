
int minDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right  == NULL) return  1;
    if (root->left == NULL || root->right == NULL) {
        return minDepth(root->left ? root->left : root->right) + 1;
    }
    return fmin(minDepth(root->right), minDepth(root->left)) + 1;
}
//fmin也是比较两个参数的大小
