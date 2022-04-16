#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/76503
*/

vector<long long> arr;
vector<vector<int>> graph;

void dfs(int idx,int parent,long long& answer){
    //리프노드일때
    if(graph[idx].size()==1&&graph[idx][0]==parent){
        return;
    }
    
    for(int i=0;i<graph[idx].size();++i){
        int next=graph[idx][i];
        if(next==parent) continue;
        dfs(next,idx,answer);
        arr[idx]+=arr[next];
        answer+=abs(arr[next]);
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -2;
    arr.resize(a.size());
    graph.resize(a.size());
    for(int i=0;i<a.size();++i){
        arr[i]=a[i];
    }
    for(int i=0;i<edges.size();++i){
        int from=edges[i][0],to=edges[i][1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    answer=0;
    dfs(0,-1,answer);
    if(arr[0]!=0) answer=-1;
    return answer;
}