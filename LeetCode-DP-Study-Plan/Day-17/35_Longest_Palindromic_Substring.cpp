#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0; 
        int end = 0;
        
        for(int i=0; i<s.length(); i++){
            int lenOne = expandAroundCenter(s, i, i);
            int lenTwo = expandAroundCenter(s, i, i+1);
            
            int len = max(lenOne, lenTwo);
            
            if(len > end - start){
                start = i - (len -1) / 2;
                end = i + len / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    int expandAroundCenter(string &s, int l, int r){
        while(l >=0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        
        return r-l-1;
    }
};

/*
class Solution {
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.length() -1;

        while(start <= end){
            if(s[start] == s[end]){
                start++;
                end--;
            }else{
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s) {
        unordered_set<string> setz;
        int maxSize = 0;
        int count = s.length();
        string res = "";

        if(s.length() == 1){
            return s;
        }

        for(int i=0; i<s.length(); i++){
            for(int j=1; j<=count; j++){
                string currStr = s.substr(i, j);
                if(isPalindrome(currStr)){
                    setz.insert(currStr);
                }
            }
            count--;
        }

        for(auto str : setz){
            int currLen = str.length();
            if(currLen > maxSize){
                res = str;
                maxSize = currLen;
            }
        }
        return res;
    }
};

*/

int main(){
    string s = "b";
    Solution sol;
    string res = sol.longestPalindrome(s);
    cout << res <<endl;
}