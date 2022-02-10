#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        for(int i=0; i<nums.size(); i++){
            for(int j = i+1; j<=nums.size(); j++){
                int sum = 0;
                for(int l = i; l<j; l++){
                    sum += nums[l]; 
                }
                if(sum == k){
                    res++;
                }
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mapzy;
        int count = 0;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            if(sum == k){
                count++;
            }

            if(mapzy.find(sum - k) != mapzy.end()){
                count += mapzy[sum -k];
            }

            mapzy[sum]++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << sol.subarraySum(nums, k) << endl;
}
