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
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> sol(n+1, 0);
        for(auto &a : trust){
            sol[a[0]]--;
            sol[a[1]]++;
        }

        for(int i=1; i<=n; i++){
            if(sol[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};

int main(){
    Solution s;
    vvi trust = {{1, 3}, {2, 3}, {3, 1}};
    int res = s.findJudge(3, trust);
    cout<<res<<endl;
}