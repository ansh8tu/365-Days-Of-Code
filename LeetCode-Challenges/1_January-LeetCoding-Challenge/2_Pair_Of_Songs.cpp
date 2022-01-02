#include<bits/stdc++.h>
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

//TLE - NA
/*
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        for(int i=0; i<time.size(); i++){
            for(int j = i+1; j<time.size(); j++){
                if((time[i] + time[j])% 60 == 0){
                    count++;
                }
            }
        }

        return count;
    }
};
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> dumz(60, 0);
        for(int i=0; i<time.size(); i++){
            int dumVal = time[i] % 60;
            if(dumVal == 0){
                count += dumz[0];
            }else{
                count += dumz[60 - dumVal];
            }
            dumz[dumVal]++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vi time = {30, 20, 150, 100, 40};
    int out = s.numPairsDivisibleBy60(time);
    cout<<out<<endl;
}