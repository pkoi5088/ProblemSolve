#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/43238
*/

bool check(int n,vector<int> times,long long time){
    long long ret=0;
    for(int i=0;i<times.size();++i){
        ret+=time/times[i];
    }
    return ret<n;
}

long long solution(int n, vector<int> times) {
    long long answer = 0,start=1,end=1000000000000000000,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(check(n,times,mid)){
            start=mid+1;
        }else{
            answer=mid;
            end=mid-1;
        }
    }
    return answer;
}