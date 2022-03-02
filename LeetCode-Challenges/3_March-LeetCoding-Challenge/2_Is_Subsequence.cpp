#include<iostream>
using namespace std;

//tLen = n
//TC: O(n) SC: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0){
            return true;
        }
        
        int tracker = 0;
        for(int i=0; i<t.length(); i++){
            if(t[i] == s[tracker]){
                tracker++;
            }
            if(tracker >= s.length()){
                return true;
            }
        }
        
        return false;
    }
};

//sLen = m  tLen = n
//TC:O(mn) SC: O(1)
/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int setPos = 0;
        int sLen = s.length();
        for(int i=0; i<s.length(); i++){
            for(int j=setPos; j<t.length(); j++){
                if(s[i] == t[j]){
                    setPos = j+1;
                    sLen--;
                    break;
                }
            }
        }
        return sLen == 0;
    }
};
*/

int main(){
    Solution sol;
    cout<<sol.isSubsequence("abc", "ahbfc");
}