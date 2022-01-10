#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int waterStored = 0;
        
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], height[i-1]);
        }
        
        for(int i= n- 2; i>=0; i--){
            right[i] = max(right[i+ 1], height[i+1]);
        }
        
        for(int i=0; i<n; i++){
            int level = min(left[i], right[i]);
            if(level > height[i]){
                waterStored +=  level - height[i];
            }     
        }
        
        return waterStored;
    }
};

int main(){
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;
}