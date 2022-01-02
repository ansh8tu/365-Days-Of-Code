#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;
typedef stack<int> st;
typedef queue<int> que;
typedef priority_queue<int> pq;


#define LOOP(i, a, b) for(int i = a; i<b; i++) 
#define ITLOOP(it, a, b) for(auto it=a; it!=b; it++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(38, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i = 3; i<=n; i++){
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        
        return dp[n];
    }
};

int main(){
    Solution s;
    cout<< s.tribonacci(5)<< endl;
}
