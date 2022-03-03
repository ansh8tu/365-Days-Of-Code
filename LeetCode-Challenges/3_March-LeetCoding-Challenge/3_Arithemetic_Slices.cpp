#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int res = 0;
        if(nums.size() <= 2){
            return 0;
        }else if(nums.size() == 3){
            return (2*nums[1] == nums[0] + nums[2]) ? 1 : 0;
        }else{
            dp[2] = ((2*nums[1]) == (nums[0] + nums[2])) ? 1 : 0;
            res += dp[2];
            
            for(int i=3; i<nums.size(); i++){
                if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])){
                    dp[i] = dp[i-1] + 1;
                }
                res += dp[i];
            }
        }
        
        return res;
    }
};
/*
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int res = 0;
        if(nums.size() <= 2){
            return 0;
        }else if(nums.size() == 3){
            return (2*nums[1] == nums[0] + nums[2]) ? 1 : 0;
        }else{
            dp[2] = ((2*nums[1]) == (nums[0] + nums[2])) ? 1 : 0;
            res += dp[2];
            
            for(int i=3; i<nums.size(); i++){
                if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])){
                    dp[i] = dp[i-1] + 1;
                }
                res += dp[i];
            }
        }
        
        return res;
    }
};
*/

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 7, 9};
    int res = s.numberOfArithmeticSlices(nums);
    cout << res << endl;

   
}