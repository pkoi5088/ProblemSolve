#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12924
*/

int getSum(int n){
    return n*(n+1)/2;
}

int getSectionSum(int s,int e){
    return getSum(e)-getSum(s-1);
}

int solution(int n) {
    int answer = 0,start=1,end=1;
    while(start<=n){
        int t=getSectionSum(start,end);
        if(t==n){
            answer+=1;
            end+=1;
        }else if(t<n){
            end+=1;
        }else{
            start+=1;
        }
    }
    return answer;
}