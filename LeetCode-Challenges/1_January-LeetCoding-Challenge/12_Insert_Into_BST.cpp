#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;

        if(root == NULL){
            return new TreeNode(val);
        }

        while(true){
            if(val >= temp->val){
                if(temp->right!=NULL){
                    temp = temp->right;
                }else{
                    temp->right = new TreeNode(val);
                    break;
                }
            }else{
                if(temp->left!=NULL){
                    temp= temp->left;
                }else{
                    temp->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

int main(){
    TreeNode* root = NULL;
    TreeNode* firstNode = new TreeNode(4);
    TreeNode* secondNode = new TreeNode(2);
    TreeNode* thirdNode = new TreeNode(7);
    TreeNode* fourthNode = new TreeNode(1);
    TreeNode* fifthNode = new TreeNode(3);

    root = firstNode;
    firstNode->left = secondNode;
    firstNode->right = thirdNode;

    secondNode->left = fourthNode;
    secondNode->right = fifthNode;

    Solution s;
    s.insertIntoBST(root, 5);

}