#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// BRUTE FORCE APPROACH
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;

        for(int i=0; i<heights.size(); i++){
            int leftLimit = -1;
            int rightLimit = heights.size();

            //for left part 
            for(int j=i; j>=0; j--){
                if(heights[j] < heights[i]){
                    leftLimit = j;
                    break;
                }
            }

            //for right part
            for(int j=i; j<heights.size(); j++){
                if(heights[j] < heights[i]){
                    rightLimit = j;
                    break;
                }
            }
            
            int area = (rightLimit - leftLimit - 1)*heights[i];
            res = max(res, area);

            leftLimit = 0;
            rightLimit = heights.size() - 1;
            area = 0;
        }
        return res;

    }
};
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> stackzy;

        for(int i=0; i<=heights.size(); i++){
            while(!(stackzy.empty()) && (i == heights.size() || heights[stackzy.top()] >= heights[i])){
                int height = heights[stackzy.top()];
                stackzy.pop();
                int width = 0;

                if(stackzy.empty()){
                    width = i;
                }else{
                    width = i - stackzy.top() - 1;
                }
                res = max(res, height*width);
            }
            stackzy.push(i);
        }
        return res;
    }
};


int main(){
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution sol;
    cout << sol.largestRectangleArea(heights) << endl;
}