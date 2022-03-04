#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double> (101, 0.0));
        dp[0][0] = poured; 

        for(int i=0; i<query_row; i++){
            for(int j=0; j<=i; j++){
                double supply = (dp[i][j] - 1)/2.0; 
                if(supply > 0){
                    dp[i+1][j] += supply;
                    dp[i+1][j+1] += supply;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};

int main(){
    Solution sol;
    int poured = 2;
    int query_row = 1;
    int query_glass = 1;

    double res = sol.champagneTower(poured, query_row, query_glass);
    cout << res << endl;
}