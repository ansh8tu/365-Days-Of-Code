#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowPtr = 2;

        if(nums.size() < 3){
            return nums.size();
        }

        for(int fastPtr = slowPtr; fastPtr<nums.size(); fastPtr++){
            if(nums[fastPtr] != nums[slowPtr - 2]){
                nums[slowPtr++] = nums[fastPtr];
            }
        }

        return slowPtr;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4, 5, 6, 6, 6, 6, 6};
    cout<< sol.removeDuplicates(nums);
}