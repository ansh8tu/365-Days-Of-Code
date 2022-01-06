#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int finalDestination = 0;
    
        for(int i=0; i<trips.size(); i++){
            if(trips[i][2] > finalDestination){
                finalDestination = trips[i][2];
            }
        }
        
        vector<int> sol(finalDestination + 1, 0);
        
        for(int i=0; i<trips.size(); i++){
            if(trips[i][0] > capacity){
                return false;
            }
            sol[trips[i][1]] += trips[i][0];
            sol[trips[i][2]] -= trips[i][0];
        }

        for(int i = 1; i<=finalDestination; i++){
            sol[i] +=sol[i-1];

            if(sol[i] > capacity){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<vector<int>> trips = {{2,1,5}, {3,3,7}};
    int capacity = 4;
    cout << s.carPooling(trips, capacity) << endl;
}
