#include <string>
#include <vector>
#include <algorithm>
#define MAX 360001

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/72414
*/

int arr[MAX]={0,};

int stringToInt(string s){
    int ret=0;
    ret+=(s[0]-'0')*10*60*60;
    ret+=(s[1]-'0')*60*60;
    ret+=(s[3]-'0')*10*60;
    ret+=(s[4]-'0')*60;
    ret+=(s[6]-'0')*10;
    ret+=(s[7]-'0');
    return ret;
}

string intToString(int i){
    string ret;
    ret.push_back(i%10+'0');
    i/=10;
    ret.push_back(i%6+'0');
    i/=6;
    ret.push_back(':');
    ret.push_back(i%10+'0');
    i/=10;
    ret.push_back(i%6+'0');
    i/=6;
    ret.push_back(':');
    ret.push_back(i%10+'0');
    i/=10;
    ret.push_back(i%10+'0');
    reverse(ret.begin(),ret.end());
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for(string s:logs){
        int start=stringToInt(s.substr(0,8));
        int end=stringToInt(s.substr(9,8));
        for(int i=start;i<end;++i)
            arr[i]+=1;
    }
    
    int idx=0,left=0,right=stringToInt(adv_time);
    long long tmp=0,maxRet=0;
    for(int i=0;i<right;++i){
        tmp+=arr[i];
    }
    maxRet=tmp;
    while(right<stringToInt(play_time)){
        tmp+=arr[right++];
        tmp-=arr[left++];
        if(tmp>maxRet){
            idx=left;
            maxRet=tmp;
        }
    }
    answer=intToString(idx);
    return answer;
}