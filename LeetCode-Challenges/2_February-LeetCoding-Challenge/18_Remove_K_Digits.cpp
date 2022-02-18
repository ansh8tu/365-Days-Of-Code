#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stackzy;
        int n = num.size();

        for(int i=0; i<num.length(); i++){
            while(!stackzy.empty() && k>0 && num[i] < stackzy.top()){
                stackzy.pop();
                k--;
            }
            if(!stackzy.empty() || num[i] != '0'){
                stackzy.push(num[i]);
            }
        }

        while(!stackzy.empty() && k--){
            stackzy.pop();
        }

        if(stackzy.empty()){
            return "0";
        }

        while(!stackzy.empty()){
            num[n - 1] = stackzy.top();
            stackzy.pop();
            n--;
        }

        return num.substr(n);
    }
};

int main(){
    string num = "1433219";
    int k = 3;
    Solution sol;
    cout << sol.removeKdigits(num, k) << endl;
}