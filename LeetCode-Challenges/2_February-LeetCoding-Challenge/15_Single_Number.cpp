#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            res = nums[i] ^ res;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3, 4, 4};
    cout << sol.singleNumber(nums) << endl;
}