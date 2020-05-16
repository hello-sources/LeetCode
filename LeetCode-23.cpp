/*************************************************************************
    > File Name: LeetCode-23.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sat 16 May 2020 06:56:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    typedef pair<int, ListNode *> PIL;
    typedef pair<int, PIL> PIP;
    set<PIP> s; 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL) continue;
            s.insert(PIP(lists[i]->val, PIL(i, lists[i])));
            lists[i] = lists[i]->next;
        }
        ListNode ret, *p = &ret;
        ret.next = NULL;
        while (s.size()) {
            PIP temp = *s.begin();
            s.erase(s.begin());
            p->next = temp.second.second;
            p = p->next;
            int i = temp.second.first;
            if (lists[i] == NULL) continue;
            s.insert(PIP(lists[i]->val, PIL(i, lists[i])));
            lists[i] = lists[i]->next;
        }
        return ret.next;
    }
};
