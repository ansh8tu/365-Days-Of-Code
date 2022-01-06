#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        int maxSoFar = nums[0];
        int currSoFar = nums[0];
            
        for(int i=1; i<nums.size(); i++){
            currSoFar = max(nums[i], nums[i] + currSoFar);
            maxSoFar = max(currSoFar, maxSoFar);
        }
        
        return maxSoFar;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1};
    cout << s.maxSubArray(nums) << endl;
}