#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }else if(nums.size() == 1){
            return nums[0];
        }else{
            vector<int> dp(20002);
            vector<int> numCount(20002);
            int maxEl = *max_element(nums.begin(), nums.end());
        
            for(auto i : nums){
                numCount[i]++;
            }

            dp[1] = numCount[1];
            dp[2] = max(dp[1], (2 * numCount[2]));

            for(int i=3; i<=maxEl; i++){
                dp[i] = max(dp[i-2] + numCount[i] * i, dp[i-1]);
            }

            return dp[maxEl];
        }
    }
};

int main(){
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    Solution s;
    cout << s.deleteAndEarn(nums) << endl;
}