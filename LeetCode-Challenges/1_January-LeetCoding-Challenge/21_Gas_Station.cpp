#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
#include<math.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startingIndex = 0;
        int totalDiff = 0;
        int currDiff = 0;
        
        
        for(int i=0; i<gas.size(); i++){
            totalDiff += (gas[i] - cost[i]);
            currDiff += (gas[i] - cost[i]);
            if(currDiff < 0){
                currDiff = 0;
                startingIndex = i + 1;
            }
        }
        
        return totalDiff < 0 ? -1: startingIndex;
    }
};

int main(){
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << sol.canCompleteCircuit(gas, cost) <<endl;
}