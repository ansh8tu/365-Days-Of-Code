#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int signVal = 1;
        int res = 0;

        // 1. Read in and ignore any leading whitespace.
        while(i<s.length()){
            if(s[i] == ' '){
                i++;
            }else{
                break;
            } 
        }

        //1 a) If no digits were read, then the integer is 0
        if(i == s.length()){
            return 0;
        }

        // 2. Check if the next character (if not already at the end of the string) is '-' or '+'.
        //    Read this character in if it is either. This determines if the final result is negative or positive respectively.
        //    Assume the result is positive if neither is present.
        if(i == s.length() -1 && (s[i] <= '0' || s[i] >= '9')){
            return 0;
        }else{
            if(s[i] == '-'){
                signVal = -1;
                i++;
            }else if(s[i] == '+'){
                signVal = 1;
                i++;
            }
        }
        
        // 3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
        while(i<s.length() && (s[i] >= '0' && s[i] <= '9')){

            
            if(res > (INT_MAX / 10) || (res == (INT_MAX / 10) && (s[i] - '0') > 7)){
                return (signVal == -1) ? INT_MIN : INT_MAX;
            }

            // 4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32).
            //    If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
            res = res*10 + (s[i] - '0');
            i++;
        }

        return signVal*res;
    }
};

int main(){
    Solution sol;
    string s = "   -32";
    cout << sol.myAtoi(s) << endl;
}