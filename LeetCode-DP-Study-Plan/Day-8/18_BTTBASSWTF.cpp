#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int oldBoughtStatePrice = -prices[0];
        int oldSoldStatePrice = 0;

        for(int i=1; i<prices.size(); i++){
            int newBoughtStatePrice = 0;
            int newSoldStatePrice = 0;

            if(oldSoldStatePrice - prices[i] > oldBoughtStatePrice){
                newBoughtStatePrice = oldSoldStatePrice - prices[i];
            }else{
                newBoughtStatePrice = oldBoughtStatePrice;
            }

            if(oldBoughtStatePrice + prices[i] - fee > oldSoldStatePrice){
                newSoldStatePrice = oldBoughtStatePrice + prices[i] - fee;
            }else{
                newSoldStatePrice = oldSoldStatePrice;
            }

            oldBoughtStatePrice = newBoughtStatePrice;
            oldSoldStatePrice = newSoldStatePrice;
        }

        return oldSoldStatePrice;
    }
};

int main(){
    Solution s;
    vector<int> prices = {1,3,2,8,4,9};
    cout << s.maxProfit(prices, 2) << endl;
}
