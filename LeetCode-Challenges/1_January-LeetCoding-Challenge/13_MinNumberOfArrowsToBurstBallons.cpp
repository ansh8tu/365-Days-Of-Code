#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),  [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];});
        int res = 1;
        int endVal = points[0][1];

        for(int i=1; i<points.size(); i++){
            if(points[i][0] > endVal){
                res++;
                endVal = points[i][1];
            }
        }
        return res;
    }
};

//{ {1, 6}, {2, 8}, {7, 12}, {10, 16}}
int main(){
    Solution s;
    vector<vector<int>> points = { {1, 3}, {2, 6}, {2, 5}, {10, 16}};
    cout << s.findMinArrowShots(points) << endl;
}

