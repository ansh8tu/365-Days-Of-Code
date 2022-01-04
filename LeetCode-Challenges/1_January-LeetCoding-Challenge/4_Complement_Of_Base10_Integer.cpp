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
    int bitwiseComplement(int n) {
        int res = 0;
        int pow = 1;

        if(n == 0){
            return 1;
        }

        while(n > 0){
            res += pow * (n % 2 == 0 ? 1 : 0);
            pow = pow * 2;
            n = n/2;
        }

        return res;
    }
};

int main(){
    Solution s;
    cout<< s.bitwiseComplement(5) <<endl;
}