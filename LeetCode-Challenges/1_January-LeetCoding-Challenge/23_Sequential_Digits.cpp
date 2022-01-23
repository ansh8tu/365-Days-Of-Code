#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for(int i=1; i<=9; i++){
            int sum = 0;
            for(int j = i; j<=9; j++){
                sum = sum*10 + j;
                if(sum >= low && sum <= high){
                    res.push_back(sum);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution sol;
    int low = 100;
    int high = 300;
    vector<int> res = sol.sequentialDigits(low, high);

    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
}