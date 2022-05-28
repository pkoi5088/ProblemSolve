#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12927
*/

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<long long> pq;
    for(int i=0;i<works.size();++i)
        pq.push(works[i]);
    
    while(n--){
        long long M=pq.top();
        pq.pop();
        pq.push(M-1);
    }
    
    while(!pq.empty()){
        if(pq.top()>=0){
            answer+=pq.top()*pq.top();
        }
        pq.pop();
    }
    return answer;
}