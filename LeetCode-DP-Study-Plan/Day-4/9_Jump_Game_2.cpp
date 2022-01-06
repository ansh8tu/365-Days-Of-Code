#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int currReach = 0;
        int maxReach = 0;
        int jumps = 0;

        for(int i=0; i<nums.size() - 1; i++){
            if(i + nums[i] > maxReach){
                maxReach = i + nums[i];
            }

            if(i == currReach){
                jumps++;
                currReach = maxReach;
            }
        }

        return jumps;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 3, 3, 1, 1, 4};
    cout<< s.jump(nums) << endl;
}