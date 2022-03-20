#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/72413
*/

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<int>> graph(n,vector<int>());
    for(int i=0;i<n;++i){
        graph[i].resize(n,-1);
        graph[i][i]=0;
    }
    for(int i=0;i<fares.size();++i){
        int start=fares[i][0]-1,end=fares[i][1]-1,money=fares[i][2];
        graph[start][end]=money;
        graph[end][start]=money;
    }
    
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(graph[i][k]==-1||graph[k][j]==-1) continue;
                if(graph[i][j]==-1||graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    answer=graph[s-1][a-1]+graph[s-1][b-1];
    for(int i=0;i<n;++i){
        if(graph[s-1][i]==-1||graph[i][a-1]==-1||graph[i][b-1]==-1) continue;
        answer=min(answer,graph[s-1][i]+graph[i][a-1]+graph[i][b-1]);
    }
    return answer;
}