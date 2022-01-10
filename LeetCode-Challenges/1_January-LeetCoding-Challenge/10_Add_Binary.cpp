#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int lenOfA = a.length() - 1;
        int lenOfB = b.length() - 1;
        string finalRes;
        int carry = 0;

        while(lenOfA >= 0 || lenOfB>=0 || carry){
            if(lenOfA >=0){
                carry += a[lenOfA] - '0';
                lenOfA--;
            }

            if(lenOfB >= 0){
                carry += b[lenOfB] - '0';
                lenOfB--;
            }

            finalRes += (carry%2 + '0');
            carry /= 2;

        }

        reverse(finalRes.begin(), finalRes.end());
        return finalRes;
    }
};

int main(){
    string a = "11";
    string b = "1";
    Solution s;
    cout<< s.addBinary(a, b) <<endl;
}