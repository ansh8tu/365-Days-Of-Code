#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> res;

        for(auto num : nums){
            res[num]++;
        }

        for(auto itr : res){
            if(k == 0){
                if(itr.second > 1){
                    count++;
                }
            }
            else if(res.find(itr.first + k) != res.end()){
                count ++;
            }
        }

        return count;
    }
};

int main(){
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    Solution sol;
    cout << sol.findPairs(nums, k) << endl;
}