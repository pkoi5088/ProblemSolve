#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 20000

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/49189
*/

int solution(int n, vector<vector<int>> edge) {
    int answer = 0,maxValue=-1,dist[MAX];
    vector<int> graph[MAX];
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<edge.size();++i){
        graph[edge[i][0]-1].push_back(edge[i][1]-1);
        graph[edge[i][1]-1].push_back(edge[i][0]-1);
    }

    queue<int> q;
    q.push(0);
    dist[0]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<graph[now].size();++i){
            int next=graph[now][i];
            if(dist[next]!=-1) continue;
            q.push(next);
            dist[next]=dist[now]+1;
        }
    }
    
    for(int i=0;i<n;++i){
        if(maxValue<dist[i]){
            answer=1;
            maxValue=dist[i];
        }else if(maxValue==dist[i]){
            answer++;
        }
    }
    return answer;
}