#include <iostream>
#include <vector>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12978
*/

int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<int>> graph;
    graph.resize(N);
    for(int i=0;i<N;++i){
        graph[i].resize(N,-1);
        graph[i][i]=0;
    }
    int answer = 0;
    for(int i=0;i<road.size();++i){
        int a=road[i][0],b=road[i][1],c=road[i][2];
        if(graph[a-1][b-1]==-1)
            graph[a-1][b-1]=c;
        else
            graph[a-1][b-1]=min(graph[a-1][b-1],c);
        if(graph[b-1][a-1]==-1)
            graph[b-1][a-1]=c;
        else
            graph[b-1][a-1]=min(graph[b-1][a-1],c);
    }
    
    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(graph[i][k]==-1||graph[k][j]==-1||i==k||k==j) continue;
                if(graph[i][j]==-1)
                    graph[i][j]=graph[i][k]+graph[k][j];
                else
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    
    for(int i=0;i<N;++i){
        if(graph[0][i]<=K&&graph[0][i]!=-1)
            answer+=1;
    }
    return answer;
}