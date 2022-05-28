#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12907
*/

int solution(int n, vector<int> money) {
    vector<int> arr(n+1,0);
    arr[0]=1;
    int answer = 0;
    
    for(int i=0;i<money.size();++i){
        for(int j=money[i];j<=n;++j){
            if(j-money[i]>=0){
                arr[j]+=arr[j-money[i]];
                arr[j]%=MOD;
            }
        }
    }
    answer=arr[n];
    return answer;
}