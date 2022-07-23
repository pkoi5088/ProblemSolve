#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
    https://school.programmers.co.kr/learn/courses/30/lessons/42891
*/

struct cmp{
  bool operator()(pair<long long,long long> p1,pair<long long,long long> p2){
      if(p1.first==p2.first)
          return p1.second>p2.second;
    return p1.first>p2.first;
  }  
};

bool compare(pair<long long,long long> p1,pair<long long,long long> p2){
    return p1.second<p2.second;
}

int solution(vector<int> food_times, long long k) {
    long long answer = 0,N=food_times.size();
    //-1 출력
    for(int& i:food_times){
        answer+=(long long)i;
    }
    if(answer<=k){
        return -1;
    }
    
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,cmp> pq;
    for(int i=0;i<N;++i){
        pq.push({food_times[i],i});
    }
    
    int idx=0;
    //여태 먹은 양
    long long food=0;
    while(true){
        if(k-(pq.top().first-food)*(long long)pq.size()<=0){
            int idx=k%pq.size();
            vector<pair<long long,long long>> v;
            while(!pq.empty()){
                v.push_back(pq.top());
                pq.pop();
            }
            sort(v.begin(),v.end(),compare);
            return v[idx].second+1;
        }else{
            k-=(pq.top().first-food)*(long long)pq.size();
           food= pq.top().first;
            idx=pq.top().second;
            pq.pop();
        }
    }
}