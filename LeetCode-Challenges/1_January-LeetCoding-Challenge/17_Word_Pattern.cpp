#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        unordered_map<char, string> mapzy;
        unordered_map<string, bool> checkMeFirst;

        string currStr = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                str.push_back(currStr);
                currStr = "";
            }else{
                currStr += s[i];
            }
        }
        str.push_back(currStr);

        if(pattern.length() != str.size()){
            return false;
        }

        for(int i=0; i<str.size(); i++){
            if(mapzy.find(pattern[i]) != mapzy.end()){
                if(mapzy[pattern[i]] != str[i]){
                    return false;
                }
            }else{
                if(checkMeFirst[str[i]] == 0){
                    mapzy.insert({pattern[i], str[i]});
                    checkMeFirst[str[i]] = 1;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    string pattern = "abba";
    string s = "dog dog dog dog";
    Solution sol;
    cout << sol.wordPattern(pattern, s);
}