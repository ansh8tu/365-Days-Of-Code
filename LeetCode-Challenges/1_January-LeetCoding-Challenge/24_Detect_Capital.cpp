#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool caseOne = true;
        bool caseTwo = true;
        bool caseThree = true;
        
        for(int i=0; i<word.length(); i++){
            if(!(word[i] >= 65 && word[i] <= 90)){
                caseOne = false;
            }

            if(!(word[i] >= 97 && word[i] <= 122)){
                caseTwo = false;
            }

            if(!(word[0] >= 65 && word[0] <=90)){
                caseThree = false;
            }

            if(!(word[i] >= 97 && word[i] <= 122) && (i!=0)){
                caseThree = false;
            }
        }
        
        return caseOne || caseTwo || caseThree;
    }
};

int main(){
    Solution sol;
    cout << sol.detectCapitalUse("Leetcode")<< endl;
}