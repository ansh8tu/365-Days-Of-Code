#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int oldBoughtStatePrice = -prices[0];
        int oldSoldStatePrice = 0;
        int oldCooldownStatePrice = 0;

        for(int i=1; i<prices.size(); i++){
            int newBoughtStatePrice = 0;
            int newSoldStatePrice = 0;
            int newCooldownStatePrice = 0;

            if(oldCooldownStatePrice - prices[i] > oldBoughtStatePrice){
                newBoughtStatePrice = oldCooldownStatePrice - prices[i];
            }else{
                newBoughtStatePrice = oldBoughtStatePrice;
            }

            if(oldBoughtStatePrice + prices[i] > oldSoldStatePrice){
                newSoldStatePrice = oldBoughtStatePrice + prices[i];
            }else{
                newSoldStatePrice = oldSoldStatePrice;
            }

            if(oldSoldStatePrice > oldCooldownStatePrice){
                newCooldownStatePrice = oldSoldStatePrice;
            }else{
                newCooldownStatePrice = oldCooldownStatePrice;
            }

            oldBoughtStatePrice = newBoughtStatePrice;
            oldSoldStatePrice = newSoldStatePrice;
            oldCooldownStatePrice = newCooldownStatePrice;

        }

        return oldSoldStatePrice;
    }
};

int main(){
    Solution s;
    vector<int> prices = {1,2,3,0,2};
    cout << s.maxProfit(prices) << endl;
}