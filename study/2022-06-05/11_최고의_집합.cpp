#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12938
*/

vector<int> solution(int n, int s) {
    if(s/n==0){
        return {-1};
    }
    vector<int> answer(n,s/n);
    for(int i=0;i<s%n;++i){
        answer[answer.size()-1-i]+=1;
    }
    return answer;
}