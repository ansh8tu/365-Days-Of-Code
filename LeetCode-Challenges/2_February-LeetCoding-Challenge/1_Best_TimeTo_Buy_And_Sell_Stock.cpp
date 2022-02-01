#include<iostream>
#include<vector>
using namespace std;

//TC: O(n^2) SC: O(1)
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;

        for(int i=0 ;i<prices.size(); i++){
            for(int j=i+1; j<prices.size(); j++){
                res = max(res, prices[j] - prices[i]);
            }
        }

        return res;
    }
};
*/

//TC: O(n) SC: O(n)
//BONUS: It'll give max profit for each day if you change it a bit!
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        vector<int> maxVal(prices.size(), INT_MIN);
        vector<int> minVal(prices.size(), INT_MAX);

        if(prices.size() == 1){
            return 0;
        }

        minVal[0] = prices[0];

        for(int i=1; i<prices.size(); i++){
            minVal[i] = min(minVal[i-1], prices[i]);
        }

        maxVal[prices.size() -1] = prices[prices.size() -1];

        for(int i=prices.size() -2; i>=0; i--){
            maxVal[i] = max(maxVal[i+1], prices[i]);
        }

        for(int i=0; i<prices.size(); i++){
            res = max(res, maxVal[i] - minVal[i]);
        }

        return res;
        
    }
};
*/

//TC: O(n) SC: O(1)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
}