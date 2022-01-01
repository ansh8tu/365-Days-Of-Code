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
    int maxCoins(vector<int>& nums) {
        int out = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));

        for(int g=0; g<dp.size(); g++){
            for(int i=0, j=g; j<dp.size(); i++, j++){
                int max = INT32_MIN;
                for(int k=i; k<=j; k++){
                    int left;
                    int right;
                    int valLeft = (i == 0? 1: nums[i-1])*nums[k]*(j == nums.size() -1? 1: nums[j+1]);

                    if(k == i){
                        left = 0;
                    }else{
                        left = dp[i][k-1];
                    }

                    if(k == j){
                        right = 0;
                    }else{
                        right = dp[k+1][j];
                    }

                    int total = left + valLeft + right;

                    if(total > max){
                        max = total;
                    }
                }

                dp[i][j] = max;
            }
        }
        return dp[0][dp.size() - 1];
    }
};

int main(){
    vi nums = {3, 1, 5, 8};
    Solution s;
    int out = s.maxCoins(nums);
    cout<<out<<endl;
}