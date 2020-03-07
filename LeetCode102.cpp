
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int getDepth(struct TreeNode *root) {//记录树的深度
    if (root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1; //左右子树分别记录深度，取较大者加上根节点就是这颗二叉树的深度
}

//传出参数cnt，k记录的是层数，每一次都增加1
void getCnt(struct TreeNode *root, int k, int *cnt) {//记录每一层节点个数
    if (root == NULL) return ;
    cnt[k] += 1;
    getCnt(root->left, k + 1, cnt);//通过递归调用，来记录左子树第k+1层元素个数
    getCnt(root->right, k + 1, cnt);//同上，但是要注意的是两个递归调用改变的是同一个数组，就是记录层节点的数
    return ;
}

//cnt与ret都是传出参数，该函数的目的就是得到树每一层的值，k就是层数
void getResult(struct TreeNode *root, int k, int *cnt, int **ret) {
    if (root == NULL) return ;
    ret[k][cnt[k]++] = root->val;//把对应根节点的值放到二维数组对应位置上，其中k（代表层数）在递归调用中是一直变化的，对应二维数组位置也是一直变化的
    getResult(root->left, k+ 1, cnt, ret);//层数变化，每一层向右展开，递归取出左子树值
    getResult(root->right, k + 1, cnt, ret);//递归取出右子树值
    return ;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = getDepth(root);//存储数的深度
    int **ret = (int **)malloc(sizeof(int *) * depth);//动态开辟一个二维数组，大小为上一步得到的深度
    int *cnt = (int *)calloc(depth, sizeof(int));//cnt是为了初始化二维数组的第二个维度，calloc为的就是清零操作，malloc开辟出来的空间没有值，就是NULL
    getCnt(root, 0, cnt);//每一个cnt记录的是每一层节点个数
    for (int i = 0; i < depth; i++) {
        ret[i]  = (int *)malloc(sizeof(int) *cnt[i]);
        cnt[i] = 0;//每使用一次层节点个数之后清零，方便下一次使用不用malloc
    }
    getResult(root, 0, cnt, ret);//往二维数组存储值，就是真正实现树的层次存储
    *returnSize = depth;
    *returnColumnSizes = cnt;
    return ret;
}
