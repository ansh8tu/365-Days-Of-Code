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
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        dp[cost.size() - 1] = cost[cost.size() - 1];

        for(int i=cost.size()-2; i>=0; i--){
            dp[i] = min(dp[i+1], dp[i+2]) + cost[i];
        }
        return min(dp[0], dp[1]);
    }
};

int main(){
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution s;
    cout << s.minCostClimbingStairs(cost)<< endl;
}