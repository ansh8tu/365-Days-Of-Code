#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int sum = 0;

        if(nums.size() <=2){
            return 0;
        }else if(nums.size() == 3){
            if((2*nums[1]) == (nums[0] + nums[2])){
                return 1;
            }else{
                return 0;
            }
        }else{
            if((2*nums[1]) == (nums[0] + nums[2])){
                dp[2] = 1;
            }else{
                dp[2] = 0;
            }
            sum+=dp[2];

            for(int i=3; i<dp.size(); i++){
                if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])){
                    dp[i] = dp[i-1] + 1;
                }
                sum += dp[i];
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout<< s.numberOfArithmeticSlices(nums) << endl;
}