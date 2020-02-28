//求出这个数字下一个数
int get_next(int n) {
    int temp = 0;
    while (n) {
        temp += (n % 10) * (n % 10);//进行相应的运算
        n /= 10;
    }
    return temp;
}

bool isHappy(int n){
    int p = n, q = n;
    //q是快指针,p是慢指针，类似于链表判断有环无环的结果
    while (q != 1) {
        p = get_next(p);//慢指针正常走一步
        q = get_next(get_next(q));//快指针后移两步
        if (p == q) break;//如果成环就推出循环
    }
    return q == 1;//最终判断是否为1，不成环则成一
}
