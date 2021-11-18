#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool check[256]={false,};
int row,col;

bool checkMinimality(vector<int>& answer,int now){
    for(int i=0;i<answer.size();++i){
        if((now&answer[i])==answer[i]) return false;
    }
    return true;
}

bool checkUniqueness(vector<vector<string>>& relation,int now){
    vector<string> v;
    for(int i=0;i<row;++i){
        string tmp="";
        for(int j=0;j<col;++j){
            if(now&(1<<j)){
                tmp+=relation[i][j];
            }
        }
        for(int j=0;j<v.size();++j){
            if(tmp==v[j]) return false;
        }
        v.push_back(tmp);
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    row=relation.size(),col=relation[0].size();
    queue<int> q;
    q.push(0);
    check[0]=true;
    
    //answer: 후보키 모음
    vector<int> answer;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        
        //now가 최소성이 보장 되는가?
        if(!checkMinimality(answer,now)) continue;
        
        //now가 유일성이 보장 되는가?
        if(checkUniqueness(relation,now)) answer.push_back(now);
        
        //next
        for(int i=0;i<col;++i){
            if(now^(1<<i)){
                int next=now|(1<<i);
                if(check[next]) continue;
                q.push(next);
                check[next]=true;
            }
        }
    }    
    return answer.size();
}