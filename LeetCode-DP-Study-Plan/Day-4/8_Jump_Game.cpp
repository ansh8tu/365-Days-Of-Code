#include<iostream>
#include<vector>
using namespace std;

/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);

        if(nums.size() == 0){
            return false;
        }else if(nums.size() == 1){
            return true;
        }else{
            dp[dp.size() - 1] = true;
            for(int i = dp.size() - 2; i>=0; i--){
                if(dp[i + nums[i]] == true){
                    dp[i] = true;
                }else{
                    dp[i] == false;
                }
            }
        }

        return dp[0];
    }
};
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lPos = nums.size() - 1;
        if(nums.size() == 0){
            return true;
        }else if(nums.size() == 1){
            return true;
        }else{
            for(int i = nums.size() - 1; i>=0; i--){
                if(i + nums[i] >= lPos){
                    lPos = i;
                }
            }
        }

        return lPos == 0;
    }
};

int main(){
    vector<int> nums = {3, 2, 1, 0, 4};
    Solution s;
    cout<<s.canJump(nums)<<endl;
}