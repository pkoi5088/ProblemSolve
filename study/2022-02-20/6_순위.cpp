#include <string>
#include <vector>
#define MAX 100

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/49191
*/

int solution(int n, vector<vector<int>> results) {
    bool graph[MAX][MAX] ={false,};
    for(int i=0;i<results.size();++i){
        graph[results[i][0]-1][results[i][1]-1]=true;
    }
    
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j||i==k||j==k||graph[i][k]==false||graph[k][j]==false||graph[i][j]) continue;
                graph[i][j]=true;
            }
        }
    }
    
    int ret=0;
    for(int i=0;i<n;++i){
        int j;
        for(j=0;j<n;++j){
            if(i==j) continue;
            if(graph[i][j]==false&&graph[j][i]==false) break;
        }
        if(j==n) ret+=1;
    }
    return ret;
}