#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int midZeros = -1;
        int prefixZeros = -1;
        int suffixZeros = -1;
        int zeros = 0;
        int numOfFlowersToPlotInPrefix = 0;
        int numOfFlowersToPlotInMiddleRegion = 0;
        int numOfFlowersToPlotInSuffix = 0;
        bool res = false;
        bool onePresent = false;

        if(n == 0){
            return true;
        }

        if(flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1){
            return true;
        }

        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i] == 0){
                zeros++;
            }else{
                if(prefixZeros == -1){
                    prefixZeros = zeros;
                }else{
                    midZeros = zeros;
                    if(midZeros > 2 && midZeros % 2 == 0){
                        numOfFlowersToPlotInMiddleRegion += ((midZeros / 2) - 1); 
                    }else if(midZeros > 2 && midZeros % 2 != 0) {
                        numOfFlowersToPlotInMiddleRegion += (midZeros / 2); 
                    }
                }
                zeros = 0;
                onePresent = true;
            }
        }
        suffixZeros = zeros;
        numOfFlowersToPlotInPrefix = (prefixZeros > 0) ? (prefixZeros / 2) : 0;

        if(onePresent == true){
            numOfFlowersToPlotInSuffix = suffixZeros / 2;
        }else{
            if(suffixZeros % 2 == 0){
               numOfFlowersToPlotInSuffix = suffixZeros / 2; 
            }else{
                numOfFlowersToPlotInSuffix = (suffixZeros / 2) + 1;
            }
        }
        
        int totalFlowersToPlot = numOfFlowersToPlotInPrefix + numOfFlowersToPlotInMiddleRegion + numOfFlowersToPlotInSuffix;

        if(totalFlowersToPlot >= n){
            res = true;
        }else{
            res = false;
        }
        
        return res;
    }
};

int main(){
    Solution s;
    vector<int> flowerbed = {0, 0, 0, 0, 0};
    int n = 2;
    cout << s.canPlaceFlowers(flowerbed, n) << endl;
}