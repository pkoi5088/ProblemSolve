#include <string>
#include <vector>
#define MOD 1234567

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12914
*/

long long solution(int n) {
    long long answer = 0;
    vector<int> arr(n+1,0);
    arr[0]=arr[1]=1;
    for(int i=2;i<=n;++i){
        arr[i]=(arr[i-1]+arr[i-2])%MOD;
    }
    answer=arr[n];
    return answer;
}