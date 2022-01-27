#include<iostream>
#include<vector>
using namespace std;

int main(){
    int numOfVertices, numOfEdges;
    cout<< "Input the number of Vertices & Edges: ";
    cin>>numOfVertices >> numOfEdges;

    vector<int> adjacencyList[10];

    for(int i=0; i<numOfEdges; i++){
        int edgeFrom, edgeTo;
        cin>>edgeFrom>>edgeTo;

        adjacencyList[edgeFrom].push_back(edgeTo);

        //comment this line out if you are making a directed graph
        adjacencyList[edgeTo].push_back(edgeFrom);
    }

    for(int i=1; i<=numOfVertices; i++){
        cout<< i << "-> ";
        for(int j=0; j<adjacencyList[i].size(); j++){
            cout<< adjacencyList[i][j] << " ";
        }
        cout<<endl;
    }
}