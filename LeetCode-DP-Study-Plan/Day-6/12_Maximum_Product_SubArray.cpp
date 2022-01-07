#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int finalSol = nums[0];
        int minProduct = finalSol;
        int maxProduct = finalSol;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] < 0){
                swap(minProduct, maxProduct);
            }

            minProduct = min(nums[i], nums[i]*minProduct);
            maxProduct = max(nums[i], nums[i]*maxProduct);
            finalSol = max(finalSol, maxProduct);
        }

        return finalSol;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 3, -1, 4, 0, -2};
    cout << s.maxProduct(nums) << endl;
}