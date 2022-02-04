#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mapzy;
        mapzy[0] = -1;
        int res = 0; 
        int sum = 0;


        for(int i=0; i<nums.size(); i++){
            sum += (nums[i] == 0) ? -1 : 1;
            
            if(mapzy.find(sum) != mapzy.end()){
                res = max(res, i - mapzy[sum]);
            }else{
                mapzy[sum] = i;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {0, 1, 0, 1};
    Solution s;
    cout << s.findMaxLength(nums) << endl;
}