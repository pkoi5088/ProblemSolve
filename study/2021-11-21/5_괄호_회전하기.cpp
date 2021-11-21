#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/76502
*/

int dp[1000][1000];

bool isOpen(char c){
    return c=='('||c=='{'||c=='[';
}

bool isClose(char c){
    return c==')'||c=='}'||c==']';
}

bool isSame(char a,char b){
    return (a=='('&&b==')')||(a=='{'&&b=='}')||(a=='['&&b==']');
}

//s[start:end]가 올바른 문자열인가?
bool getDP(string& s,int start,int end){
    if(start>=end) return false;
    if(dp[start][end]!=-1) return dp[start][end];
    
    //기저사례
    if(isClose(s[start])||isOpen(s[end]))
        return dp[start][end]=0;
    if(isSame(s[start],s[end])&&start+1==end)
        return dp[start][end]=1;
        
    if(isSame(s[start],s[end])&&getDP(s,start+1,end-1))
        return dp[start][end]=1;
    for(int i=start+1;i<end;++i){
        if(getDP(s,start,i)&&getDP(s,i+1,end))
            return dp[start][end]=1;
    }
    return dp[start][end]=0;
}

bool isCorrect(string& s){
    memset(dp,-1,sizeof(dp));
    return getDP(s,0,s.size()-1);
}

int solution(string s) {
    int answer=0;
    for(int i=0;i<s.size()-1;++i){
        if(isCorrect(s))
            answer+=1;
        char tmp=s[0];
        s.erase(0,1);
        s.push_back(tmp);
    }
    return answer;
}