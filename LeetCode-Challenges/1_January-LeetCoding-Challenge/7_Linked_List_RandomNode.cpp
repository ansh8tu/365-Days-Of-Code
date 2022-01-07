#include<iostream>
#include<vector>
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
    ListNode* headOrg;
    int lengthOfList = 0;

    Solution(ListNode* head) {
        headOrg = head;
        ListNode* temp = headOrg;
        while(temp){
            lengthOfList++;
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int randomIndex = rand()%lengthOfList;
        ListNode* temp = headOrg;
        for(int i=0; i<randomIndex; i++){
            temp = temp->next;
        }

        return temp->val;
    }
};

int main(){
    ListNode* head = new ListNode();
    ListNode* firstNode = new ListNode(1);
    ListNode* secondNode = new ListNode(2);
    ListNode* thirdNode = new ListNode(3);

    head->next = firstNode;
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = NULL;

    
    Solution* s = new Solution(head);
    cout << s->getRandom() << endl;
}