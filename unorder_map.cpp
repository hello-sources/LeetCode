/*************************************************************************
    > File Name: unorder_map.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 07:32:04 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;


int main() {
	//unordered_map<>      //底层数据结构是哈希表
	//map<>     //底层实现方式是红黑树  
	unordered_map<double, int> h;
	h[2.3] = 123;
	h[345.6] = 123456;


	return 0;
}
