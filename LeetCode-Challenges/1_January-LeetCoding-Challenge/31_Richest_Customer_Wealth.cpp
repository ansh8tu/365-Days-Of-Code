#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(int i=0; i<accounts.size(); i++){
            int dumz = 0;
            for(int j=0; j<accounts[i].size(); j++){
                dumz += accounts[i][j];
            }
            res = max(res, dumz);
        }
        return res;
    }
};

int main(){
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
    Solution sol;
    cout << sol.maximumWealth(accounts) << endl;
}