#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {     
        int begZeros = -1;
        int maxZerosInMid = -1;
        int endZeros = -1;
        int dummyZeros = 0;

        for(int i=0; i<seats.size(); i++){
            if(seats[i] == 0){
                dummyZeros++;
            }else{
                if(begZeros == -1){
                    begZeros = dummyZeros;
                }else{
                    maxZerosInMid = max(maxZerosInMid, dummyZeros);
                }
                dummyZeros = 0;
            }
        }
        endZeros = dummyZeros;
        int res = max(max(begZeros, endZeros), ((maxZerosInMid+1)/2));
        return res;
    }
};

int main(){
    Solution s;
    vector<int> seats = {1,0,0,0,1,0,1};
    cout << s.maxDistToClosest(seats) << endl;
}