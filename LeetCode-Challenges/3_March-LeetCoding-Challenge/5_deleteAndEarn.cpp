#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> getMaxPoints(vector<int> &nums){
        unordered_map<int, int> mapzy;
        for(int i=0; i<nums.size(); i++){
            if(mapzy.find(nums[i]) != mapzy.end()){
                mapzy[nums[i]] += nums[i];
            }else{
                mapzy.insert({nums[i], nums[i]});
            }
        }
        return mapzy;
    }
    
    int getMaxElement(vector<int> & nums){
        int res = nums[0];
        for(int i=0; i<nums.size(); i++){
            res = max(res, nums[i]);
        }
        return res;
    }

    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> currPoints = getMaxPoints(nums);
        int maxEl = getMaxElement(nums);
        
        vector<int> dp(maxEl + 1, 0);
        dp[0] = 0; 
        dp[1] = currPoints[1];
        
        for(int i=2; i<dp.size(); i++){
            dp[i] = max(currPoints[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[dp.size()-1];

    }   
    
};

int main(){
    Solution sol;
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    cout<< sol.deleteAndEarn(nums) << endl;
}