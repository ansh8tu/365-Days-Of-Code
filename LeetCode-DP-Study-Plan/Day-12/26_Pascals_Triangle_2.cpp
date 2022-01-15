#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        
        for(int i=0; i<=rowIndex; i++){
            vector<int> dumz(i+1, 1);
            for(int j = 1; j<i; j++){
                dumz[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(dumz);
        }
        
        return res[rowIndex];
    }
};

int main(){
    vector<int> sol;
    Solution s;
    sol = s.getRow(5);
}