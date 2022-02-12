#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
/*
    https://programmers.co.kr/learn/courses/30/lessons/42627
*/

struct cmp {
    bool operator()(vector<int>& v1, vector<int>& v2) {
        return v1[1]>v2[1];
    }
};
 
int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    int answer=0,time=0;
    sort(jobs.begin(),jobs.end());
    
    int i=0;
    while (i<jobs.size()||!pq.empty()) {
        //pq에 현재 들어갈수 있는 작업들을 넣기
        while(i<jobs.size()&&jobs[i][0]<=time) {
            pq.push(jobs[i]);
            i+=1;
        }
        
        //하나의 작업을 수행
        if (!pq.empty()) {
            //끝나는 시간
            time+=pq.top()[1];
            //반환시간
            answer+=time-pq.top()[0];
            pq.pop();
        }
        else{
            //작업이 없으면 다음시작시간까지 대기
            time=jobs[i][0];
        }
    }
    return answer/jobs.size();
}