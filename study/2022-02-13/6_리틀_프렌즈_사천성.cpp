#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/1836
*/

//board에서 v[idx]를 지울수 있는가?
bool check(int idx,vector<string>& board,vector<pair<int,int>>* v,int& total,int* visit){
    int i;
    int x1=v[idx][0].first,y1=v[idx][0].second;    
    int x2=v[idx][1].first,y2=v[idx][1].second;
    string t;
    while(x1!=x2){
        t.push_back(board[x1][y1]);
        if(x1>x2) x1-=1;
        else x1+=1;
    }
    while(y1!=y2){
        t.push_back(board[x1][y1]);
        if(y1>y2) y1-=1;
        else y1+=1;
    }
    for(i=1;i<t.size();++i){
        if(t[i]!='.') break;
    }
    if(i==t.size()) return true;
    
    x1=v[idx][0].first,y1=v[idx][0].second;
    x2=v[idx][1].first,y2=v[idx][1].second;
    t="";
    while(y1!=y2){
        t.push_back(board[x1][y1]);
        if(y1>y2) y1-=1;
        else y1+=1;
    }
    while(x1!=x2){
        t.push_back(board[x1][y1]);
        if(x1>x2) x1-=1;
        else x1+=1;
    }
    for(i=1;i<t.size();++i){
        if(t[i]!='.') return false;
    }
    return true;
}

void dfs(vector<string>& board,string& answer,string& tmp,vector<pair<int,int>>* v,int& total,int* visit){
    if(!answer.empty()) return;
    if(total==0){
        if(answer.empty()) answer=tmp;
    }else{
        for(int now=0;now<26;++now){
            //now를 지울 수 있는가?
            if(visit[now]==1&&check(now,board,v,total,visit)){
                total-=1;
                //지우고
                board[v[now][0].first][v[now][0].second]='.';
                board[v[now][1].first][v[now][1].second]='.';
                visit[now]=0;
                tmp.push_back(now+'A');
                dfs(board,answer,tmp,v,total,visit);
            }
        }
    }
}

string solution(int m, int n, vector<string> board) {
    vector<pair<int,int>> v[26];
    int total=0,visit[26]={0,};
    string answer = "",tmp="";
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(board[i][j]!='.'&&board[i][j]!='*'){
                v[board[i][j]-'A'].push_back({i,j});
                visit[board[i][j]-'A']=1;
            }
        }
    }
    for(int i=0;i<26;++i){
        if(v[i].size()!=0) total+=1;
    }
    dfs(board,answer,tmp,v,total,visit);
    if(answer.empty()) return "IMPOSSIBLE";
    return answer;
}