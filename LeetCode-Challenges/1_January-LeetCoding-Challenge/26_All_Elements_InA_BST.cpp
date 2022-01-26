#include<iostream>
#include<vector>
#include<algorithm>
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
    void inOrderTraversal(TreeNode* root, vector<int> &dumz){
        if(root == NULL){
            return;
        }
        inOrderTraversal(root->left, dumz);
        dumz.push_back(root->val);
        inOrderTraversal(root->right, dumz);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> resOne;
        vector<int> resTwo;
        inOrderTraversal(root1, resOne);
        inOrderTraversal(root2, resTwo);
        
        int resTwoSize = resTwo.size();

        while(resTwoSize){
            resOne.push_back(resTwo[resTwoSize -1]);
            resTwoSize--;
        }

        sort(resOne.begin(), resOne.end());
        return resOne; 
    }
};

int main(){
    TreeNode* root1 = new TreeNode(0);
    TreeNode* leftNodeOne = new TreeNode(1);
    TreeNode* rightNodeOne = new TreeNode(4);

    root1->left = leftNodeOne;
    root1->right = rightNodeOne;

    TreeNode* root2 = new TreeNode(1);
    TreeNode* leftNodeTwo = new TreeNode(0);
    TreeNode* rightNodeTwo = new TreeNode(3);

    root2->left = leftNodeTwo;
    root2->right = rightNodeTwo;

    Solution sol;
    vector<int> res = sol.getAllElements(root1, root2);;
    
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}