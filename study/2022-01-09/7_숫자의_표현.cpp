#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12924
*/

int solution(int n) {
    int answer = 0,start=1,end=1,t=1;
    while(start<=n){
        if(t==n){
            answer+=1;
            end+=1;
            t+=end;
        }else if(t<n){
            end+=1;
            t+=end;
        }else{
            t-=start;
            start+=1;
        }
    }
    return answer;
}