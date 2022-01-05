#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<math.h>
#include<stack>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;
typedef stack<int> st;
typedef queue<int> que;
typedef priority_queue<int> pq;


#define LOOP(i, a, b) for(int i = a; i<b; i++) 
#define ITLOOP(it, a, b) for(auto it=a; it!=b; it++)
#define F first
#define S second
#define PB push_back
#define MP make_pair

class Solution {
public:
    bool checkPalindrome(string s){
        int leftChar = 0;
        int rightChar = s.size() -1;

        while(leftChar <= rightChar){
            if(s[leftChar] != s[rightChar]){
                return false;
            }else{
                leftChar++;
                rightChar--;
            }
            
        }
        return true;
    }

    void backtrackingSol(vector<vector<string>>& finalRes, vector<string>& tempRes, int startPos, string &s){
       if(startPos == s.size()){
           finalRes.push_back(tempRes);
       }else{
           string pal = "";
           for(int i= startPos; i<s.size(); i++){
               pal += s[i];
               if(checkPalindrome(pal)){
                   tempRes.push_back(pal);
                   backtrackingSol(finalRes, tempRes, i+1, s);
                   tempRes.pop_back();
               }
           }
       }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> finalRes;
        vector<string> tempRes;
        backtrackingSol(finalRes, tempRes, 0, s);
        return finalRes;
    }
    
};

int main(){
    string s = "aab";
    vector<vector<string>> res;
    Solution sol;
    res = sol.partition(s);

    LOOP(i, 0, res.size()){
        LOOP(j, 0, res[i].size()){
            cout<<res[i][j]<<", ";
        }
        cout<<endl;
    }
}