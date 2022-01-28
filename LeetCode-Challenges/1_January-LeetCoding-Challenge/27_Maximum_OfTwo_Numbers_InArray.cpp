#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=0, mask=0;
        unordered_set<int> setz;

        for(int i=31;i>=0;i--){
            mask|=(1<<i);
            int temp=res|(1<<i);

            for (int j = 0; j < nums.size(); j++) {
                int num = nums[j] & mask;
                if (setz.find(temp ^ num)!=setz.end()) {
                    res = temp;
                    break;
                }
                setz.insert(num);
            }
            
            setz.clear();
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << sol.findMaximumXOR(nums) << endl;
}