#include <string>
#include <vector>

using namespace std;

vector<bool> check;

/*
    https://www.acmicpc.net/problem/4256
*/

//k: 현재 피로도, idx: 방문한 던전, count: 던전개수
void dfs(int idx,int count,vector<vector<int>>& dungeons,int k,int& ret){
    if(idx!=-1){
        ret=max(ret,count);
    }
    for(int next=0;next<dungeons.size();++next){
        if(check[next]==false&&dungeons[next][0]<=k){
            check[next]=true;
            dfs(next,count+1,dungeons,k-dungeons[next][1],ret);
            check[next]=false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0,N=dungeons.size();
    check.resize(N,false);
    dfs(-1,0,dungeons,k,answer);
    return answer;
}