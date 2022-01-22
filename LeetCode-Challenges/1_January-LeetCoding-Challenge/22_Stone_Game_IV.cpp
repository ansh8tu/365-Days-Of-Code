#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
#include<math.h>
using namespace std;

class Solution {
public:  
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        dp[0] = false;
        dp[1] = true;
        
        for(int i = 2; i<dp.size(); i++){
            for(int j = 1; j*j <=i; j++){
                if(dp[i - j*j] == false){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[dp.size() - 1]; 
    }
};

int main(){
    Solution sol;
    cout << sol.winnerSquareGame(5) << endl;
}