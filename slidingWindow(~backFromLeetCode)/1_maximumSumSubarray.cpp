#include<iostream>
#include<vector>
using namespace std;

int maximumSubarraySum(vector<int> &nums, int k){
    int start = 0;
    int currSum = 0;
    int maxSum = 0;
    int numsSize = nums.size();

    for(int end = 0; end < numsSize; end++){
        currSum += nums[end];

        while(start <= end && (end - start + 1) > k){
            currSum -= nums[start];
            start++;
        }

        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main(){
    vector<int> nums = {100, 200, 300, 400};
    int k = 2;

    int res = maximumSubarraySum(nums, k);
    cout << res << endl;
}