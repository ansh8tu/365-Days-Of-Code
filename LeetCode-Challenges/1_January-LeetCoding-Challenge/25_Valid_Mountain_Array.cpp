#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3){
            return false;
        }
        
        int maxElement = 0;
        int indexOfMaxElement = 0;
        
        //result : maxElement = 5, indexOfMaxElement = 4
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > maxElement){
                maxElement = arr[i];
                indexOfMaxElement = i;
            }
        }
        
        bool checkOne = true;
        bool checkTwo = true;
        
        if(arr[0] >= maxElement){
          checkOne = false;
        }
        
        //result: 
        for(int i=1;i<=indexOfMaxElement; i++){
            if((i != indexOfMaxElement) && (arr[i] >= maxElement || arr[i] <= arr[i-1])){
                checkOne = false;
            }
            if(arr[indexOfMaxElement] <= arr[indexOfMaxElement - 1]){
                checkOne = false;
            }
        }

        if(indexOfMaxElement == arr.size() - 1){
            return false;
        }else{
            for(int i = indexOfMaxElement + 1; i<arr.size(); i++){
                if(arr[i] >= maxElement || (arr[i] >= arr[i-1])){
                    checkTwo = false;
                }
            }
        }
        
        return checkOne && checkTwo;
    }
};

int main(){
    Solution s;
    vector<int> arr = {0, 2, 3, 4, 5, 2, 3, 0};
    cout << s.validMountainArray(arr) << endl;
}