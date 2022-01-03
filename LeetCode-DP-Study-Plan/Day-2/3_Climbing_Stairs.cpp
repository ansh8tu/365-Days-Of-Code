#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<stack>

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
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[dp.size()-1] = 1;

        for(int i = dp.size() - 2; i>=0; i--){
            if(i == dp.size()-2){
                dp[i] = dp[i+1];
            }else{
                dp[i] = dp[i+1] + dp[i+2];
            }
        }

        return dp[0];
    }
};

int main(){
    Solution s;
    cout<< s.climbStairs(5) <<endl;
}