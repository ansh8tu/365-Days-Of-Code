#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for(int i=0; i<=s.size(); ++i){
            for(int j=0; j<i; ++j){
                if(dp[j]){
                    if(find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

int main(){
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    cout << sol.wordBreak(s, wordDict) << endl;
}