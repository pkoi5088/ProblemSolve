#include <string>
#include <vector>
#define MAX 60001

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12900
*/

int solution(int n) {
    int answer = 0;
    int arr[MAX];
    arr[0]=arr[1]=1;
    for(int i=2;i<=n;++i){
        arr[i]=(arr[i-2]+arr[i-1])%1000000007;
    }
    answer=arr[n];
    return answer;
}