#include<iostream>
#include<vector>
using namespace std;

//TC:O(n) SC:O(1)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i= 0; i<=n; i++){
            if(i%2 == 0){
                res[i] = res[i/2];
            }else{
                res[i] = res[i/2] + 1;
            }
        }

        return res;
    }
};


//TC:O(nlog(n)) SC: O(1)
/*
class Solution {
public:
    int numOfOnes(int num){
        int count = 0;
        while(num != 0){
            if(num%2 == 1){
                count++;
            }
            num = num/2;
        }
        return count;
    }
    
    
    vector<int> countBits(int n) {
        vector<int> res;
        
        for(int i=0; i<=n; i++){
            res.push_back(numOfOnes(i));
        }
        
        return res;
    }
};
*/

int main(){
    Solution sol;
    vector<int> res = sol.countBits(10);
    for(int i=0; i<res.size(); i++){
        cout<<i<<" : "<<res[i]<<endl;
    }
}