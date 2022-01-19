#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        ListNode* temp = head;

        while(fastPtr->next && fastPtr->next->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if(slowPtr == fastPtr){
                while(slowPtr != temp){
                    temp = temp->next;
                    slowPtr = slowPtr->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};

void printList(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
        cout<< temp->val <<"->";
        temp = temp->next;
    } 
    cout<<"NULL"<<endl;  
}

int main(){
    ListNode* head = NULL;
    ListNode* firstNode = new ListNode(3);
    ListNode* secondNode = new ListNode(2);
    ListNode* thirdNode = new ListNode(0);
    ListNode* fourthNode = new ListNode(-4);

    head = firstNode;
    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = secondNode;
    
    Solution s;
    ListNode* res = s.detectCycle(head);
    cout<< res->val << endl;

}