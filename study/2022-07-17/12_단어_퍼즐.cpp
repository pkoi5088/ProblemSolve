#include <iostream>
#include <string>
#include <vector>
#define INF 3000000
#define MAX 20000

using namespace std;

int min(int a,int b){
    if(a==-1) return b;
    if(b==-1) return a;
    return a<b?a:b;
}

//dp[i]: t[i:]에서 만들수있는 단어조각의 최소값
int dp[MAX];

void init(){
    for(int i=0;i<MAX;++i){
        dp[i]=INF;
    }
}

bool check(int idx,string t,string p){
    for(int i=0;i<p.size();++i){
        if(idx+i>=t.size()||p[i]!=t[idx+i]) return false;
    }
    return true;
}

int getDP(int idx,vector<string>& strs, string& t){
    if(idx>=t.size()) return 0;
    int& ret=dp[idx];
    if(ret!=INF) return ret;
    
    ret=-1;
    for(int i=0;i<strs.size();++i){
        if(check(idx,t,strs[i])){
            int tmp=getDP(idx+strs[i].size(),strs,t);
            if(tmp!=-1){
                ret=min(ret,tmp+1);
            }
        }
    }
    return ret;
}

int solution(vector<string> strs, string t)
{
    init();
    int answer = getDP(0,strs,t);
    
    

    return answer;
}