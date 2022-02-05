#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listSize = lists.size();
        if(listSize == 0){
            return NULL;
        }

        vector<pair<int, ListNode*>> res;

        for(int i=0; i<listSize; i++){
            ListNode* curr = lists[i];
            while(curr!=NULL){
                res.push_back({curr->val, curr});
                curr = curr->next;
            }
        }

        if(res.size() == 0){
            return NULL;
        }

        sort(res.begin(), res.end());

        for(int i =0; i<res.size() -1; i++){
            res[i].second->next = res[i+1].second;
        }

        res[res.size() -1].second->next = NULL;

        return res[0].second;
    }
};
 
int main(){
    return 0;
}