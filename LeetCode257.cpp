
//求解路径个数
int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;//树为空则路劲为0
    if (root->left == NULL && root->right == NULL) return 1;//只有一个节点返回1
    return getPathCnt(root->left) + getPathCnt(root->right);//返回到左右子树路径之和
}

//按照输出要求返回答案
int getResult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if (root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    //判断往后移动多少，使用sprintf把当前节点的值打印到字符串中去
    buff[len] = 0;//对应buff里面位置值设置为0
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buff);//当前节点没有子节点时候就把对应buff里面的字符串拷贝到ret中
        return 1;
    }
    len += sprintf(buff + len, "->");//打印箭头到buff字符串中
    int cnt = getResult(root->left, len, k, ret, buff);//对应层数从当前开始，返回值也记录下来
    cnt += getResult(root->right, len, k + cnt, ret, buff);//对应从上面的cnt记录得到的层数开始
    return cnt;
}


char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt =getPathCnt(root);
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);
    int max_len = 1024;
    char *buff = (char *)malloc(sizeof(char) * max_len);
    getResult(root, 0, 0, ret, buff);
    *returnSize = pathCnt;
    return ret;
}
