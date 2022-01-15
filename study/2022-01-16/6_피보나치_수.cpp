#include <string>
#include <vector>
#define MOD 1234567

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12945
*/

int solution(int n) {
    int answer = 0;
    int a=0,b=1;
    if(n<=1)
        return n;
    n-=1;
    while(n--){
        answer=(a+b)%MOD;
        a=b;
        b=answer;
    }
    return answer;
}