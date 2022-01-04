#include<iostream>
#include<vector>
using namespace std;

class Solution { 
public:
    int robFake(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
          
        for(int i=2; i<nums.size(); i++){
            if(dp[i-2] + nums[i] > dp[i-1]){
                dp[i] = dp[i-2] + nums[i];
            }else{
                dp[i] = dp[i-1];
            }
        }
        
        return dp[dp.size() - 1];
    }
   
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }else if(nums.size() == 1){
            return nums[0];
        }else if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        
        vector<int> vOne(nums.begin(), nums.end()-1);
        vector<int> vTwo(nums.begin()+1, nums.end());
        return max(robFake(vOne), robFake(vTwo));

    }
};

int main(){
    vector<int> nums = {1, 2, 1, 1};
    Solution s;
    cout << s.rob(nums) << endl;
}