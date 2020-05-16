/*************************************************************************
    > File Name: set.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 06:12:25 PM CST
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;

set<int> s;//默认从小到大排序，当作小顶堆

int main() {
	//s.insert();
	//s.begin();//二叉排序树中最左边的节点，
	//s.end();//二叉排序树中，前一位是集合最后一位
	//s.erase();//红黑树删除操作
	s.insert(2);
	s.insert(1);
	s.insert(3);
	cout << *(s.begin()) << endl;
	s.erase(s.begin());
	cout << *(s.begin()) << endl;
	return 0;
}
