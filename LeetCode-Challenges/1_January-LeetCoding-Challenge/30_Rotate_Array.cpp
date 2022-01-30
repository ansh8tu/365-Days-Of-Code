#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//APPROACH 1: TC: O(n) & SC: O(n)
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            int index = (i% nums.size()) + k;
            if((index >= nums.size())){
                temp[index%nums.size()] = nums[i];
            }else{
                temp[index] = nums[i];
            }
        }
        nums = temp;
    }
};
*/

//Step1: Reverse the complete array
//Strp2: Reverse the first k elements 
//Step3: Reverse the elements starting from k+1 index to end.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution sol;
    sol.rotate(nums, k);

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}