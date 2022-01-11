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
    int helpMe(TreeNode* root, int ans){
        if(root == NULL){
            return 0;
        }
        ans = ans*2 + root->val;

        if(root->left == NULL && root->right == NULL){
            return ans;
        }

        return helpMe(root->left, ans) + helpMe(root->right, ans);
    }

    int sumRootToLeaf(TreeNode* root) {
        return helpMe(root, 0);
    }
};

int main(){
    TreeNode* root = NULL;
    TreeNode* firstNode = new TreeNode(1);
    TreeNode* secondNode = new TreeNode(0);
    TreeNode* thirdNode = new TreeNode(1);
    TreeNode* fourthNode = new TreeNode(0);
    TreeNode* fifthNode = new TreeNode(1);
    TreeNode* sixthNode = new TreeNode(0);
    TreeNode* seventhNode = new TreeNode(1);

    root = firstNode;
    firstNode->left = secondNode;
    firstNode->right = thirdNode;

    secondNode->left = fourthNode;
    secondNode->right = fifthNode;

    thirdNode->left = sixthNode;
    thirdNode->right = seventhNode;

    Solution s;
    cout<<s.sumRootToLeaf(root)<<endl;

}