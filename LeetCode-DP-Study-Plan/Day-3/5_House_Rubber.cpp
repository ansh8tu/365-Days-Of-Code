#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if(nums.size() == 1){
            return nums[0];
        }else{
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            for(int i=2; i<nums.size(); i++){
                if(dp[i-2] + nums[i] > dp[i-1]){
                    dp[i] = dp[i-2] + nums[i];
                }else{
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[dp.size() - 1];
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 1};
    Solution s;
    cout<< s.rob(nums) << endl;
}
