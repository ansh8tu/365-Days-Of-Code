#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Step 1: i'll convert all the odd numnbers to even numbers so that my number of operation which were initially 2 now gets reduced to 1;
//Step 2: get the max and the min number from the nums array so that you can calculate the initial value for the deviation
//Step 3: so in the priority queue get the max element everytime untill its even once it becomes odd then get out of the loop and simply sub the max and min val calculated in 
// the process and return it

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pqz;
        int maxVal = INT_MIN;
        int minVal = INT_MAX;

        //1
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                pqz.push(nums[i]);
            }else{
                nums[i] *= 2;
                pqz.push(nums[i]);
            }

            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }

        //2
        int deviation = maxVal - minVal;

        //3
        while(pqz.top() % 2 == 0){
            int currTop = pqz.top();
            pqz.pop();
            deviation = min(deviation, currTop - minVal);
            currTop /= 2;
            pqz.push(currTop);
            minVal = min(minVal, currTop);
        }

        deviation = min(deviation, pqz.top() - minVal);
        return deviation;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << sol.minimumDeviation(nums) << endl;
}