#include<iostream>
#include<unordered_map>
using namespace std;

//TC: O(3n) ~ O(n) SC: O(n)
/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mapzy;
        
        for(int i=0; i<t.length(); i++){
            if(mapzy.find(t[i]) != mapzy.end()){
                mapzy[t[i]]++;
            }
            mapzy.insert({t[i], 1});
        }
        
        for(int i=0; i<s.length(); i++){
            if(mapzy.find(s[i]) != mapzy.end()){
                mapzy[s[i]]--;
            }
        }
        
        for(auto itr: mapzy){
            if(itr.second == 1){
                return itr.first;
            }
        }
        
        return 'a';
    }
};
*/

//TC: O(n) SC: O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int diff = 0;
        for(int i=0; i<s.length(); i++){
            diff += t[i];
            diff -= s[i];
        }
        diff += t[t.length() -1];
        return diff;
    }
};

int main(){
    string s ="abcd";
    string t = "abcde";
    Solution sol;
    cout << sol.findTheDifference(s, t) << endl;
}