/*************************************************************************
    > File Name: sort.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 07:27:54 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int a[10] = {2, 3, 4, 5, 1, 9, 10, 6};
	sort(a, a + 8, cmp);
	for (int i = 0; i < 8; i++) {
		cout << a[i] << endl;
	}

	return 0;
}
