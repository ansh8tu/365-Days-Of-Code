#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hashMapOne(26, 0);
        vector<int> hashMapTwo(26, 0);
        int leftPtr = 0;
        int rightPtr = 0;

        if(s1.length() > s2.length()){
            return false;
        }

        while(rightPtr < s1.length()){
            hashMapOne[s1[rightPtr] - 'a']++;
            hashMapTwo[s2[rightPtr] - 'a']++;
            rightPtr++;
        }
        rightPtr--;

        while(rightPtr < s2.length()){
            if(hashMapOne == hashMapTwo){
                return true;
            }
            rightPtr++;

            if(rightPtr != s2.length()){
                hashMapTwo[s2[rightPtr] - 'a']++;
            }
            hashMapTwo[s2[leftPtr] - 'a']--;
            leftPtr++;
        }
        return false;

    }
};

int main(){
    string s2 = "eidbaooo";
    string s1 = "ab";
    Solution sol;
    cout << sol.checkInclusion(s1, s2) << endl;
}