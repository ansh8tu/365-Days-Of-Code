#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int res = 0;
        if(arr.size() == 1){
            return 0;
        }
        unordered_map<int, vector<int>> mapzy;

        for(int i=0; i<arr.size(); i++){
            mapzy[arr[i]].push_back(i);
        }

        //implementin' bfs now
        queue<int> que;
        que.push(0);

        while(!que.empty()){
            res++;
            int currQueSize = que.size();

            for(int i=0; i<currQueSize; i++){
                int j = que.front();
                que.pop();

                if(j+1 < arr.size() && (mapzy.find(arr[j+1]) != mapzy.end())){
                    if(j+1 == arr.size() -1){
                        return res;
                    }
                    que.push(j+1);
                }

                if(j-1>=0 && (mapzy.find(arr[j-1]) != mapzy.end())){
                    que.push(j-1);
                }

                if(mapzy.find(arr[j]) != mapzy.end()){
                    for(auto it: mapzy[arr[j]]){
                        if(it != j){
                            if(it == arr.size()-1){
                                return res;
                            } 
                            que.push(it);
                        }
                    }
                }
                mapzy.erase(arr[j]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout<< s.minJumps(arr) << endl;
}