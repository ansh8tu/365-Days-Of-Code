#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int lengthOfStr = instructions.length();
        int northMovement = 0;
        int westMovement = 0;
        char currDir = 'N';
        char initialDir = 'N';
        char finalDir = 'N';
        bool finalSol;

        for(int i=0; i<lengthOfStr; i++){
            //movement
            if(instructions[i] == 'G'){
                if(currDir == 'N'){
                    northMovement++;
                }else if(currDir == 'E'){
                    westMovement--;
                }else if(currDir == 'W'){
                    westMovement++;
                }else{
                    northMovement--;
                } 
            }

            //direction in left
            if(instructions[i] == 'L'){
                if(currDir == 'N'){
                    currDir = 'W';
                }else if(currDir == 'E'){
                    currDir = 'N';
                }else if(currDir == 'W'){
                    currDir = 'S';
                }else{
                    currDir = 'E';
                }   
            }

            //direction in right
            if(instructions[i] == 'R'){
                if(currDir == 'N'){
                    currDir = 'E';
                }else if(currDir == 'E'){
                    currDir = 'S';
                }else if(currDir == 'W'){
                    currDir = 'N';
                }else{
                    currDir = 'W';
                }   
            }

            finalDir = currDir;
        }

        if(northMovement == 0 && westMovement == 0){
            finalSol = true;
        }else if (initialDir != finalDir){
            finalSol = true;
        }else{
            finalSol = false;
        }

        return finalSol;
    }
};

int main(){
    string instructions = "GL";
    Solution s;
    cout << s.isRobotBounded(instructions) << endl;
}