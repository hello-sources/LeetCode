
//code 1
int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL) return true;
    int l = getDepth(root->left), r = getDepth(root->right);
    if (abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

// code2
//速度提升
int Depth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = Depth(root->left), r = Depth(root->right);
    if (l == -2 || r == -2 || abs(l - r) > 1) return -2; 
    //至多为-2,这样使得高度差绝对值不小于1
    return (l > r ? l : r) + 1; 
}

bool isBalanced(struct TreeNode* root) {
    return Depth(root) >= 0;
}
