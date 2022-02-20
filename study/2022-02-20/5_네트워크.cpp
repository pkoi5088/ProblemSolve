#include <string>
#include <vector>
#include <queue>
#define MAX 200

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/43162
*/

bool check[MAX]={false,};

void visit(int idx,vector<vector<int>>& computers){
    queue<int> q;
    q.push(idx);
    check[idx]=true;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int next=0;next<computers[now].size();++next){
            if(computers[now][next]==1&&check[next]==false){
                q.push(next);
                check[next]=true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;++i){
        if(check[i]==false){
            answer+=1;
            visit(i,computers);
        }
    }
    return answer;
}