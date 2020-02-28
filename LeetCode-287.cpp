
int findDuplicate(int* nums, int numsSize){
    //首先先以数组下标映射规则，就是通过当前下标对应的值作为另外元素的下标
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while (p != q);//这一个while循环是为了找出对应是否存在重复数，也是通过链表判断是否有环来做的
    q = nums[0];
    while (p != q) {//确定有重复数之后，使两个指针移动速度一样
        p = nums[p];
        q = nums[q];
    }//直到找到相等的数为止
    return p;
}
