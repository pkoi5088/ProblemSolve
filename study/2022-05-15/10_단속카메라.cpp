#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42884
*/

bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second<p2.second;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int,int>> v;
    for(vector<int> t:routes){
        v.push_back({t[0],t[1]});
    }
    sort(v.begin(),v.end(),cmp);
    
    int idx=0,N=routes.size();
    while(idx<N){
        answer+=1;
        int cut=v[idx].second;
        int next=idx;
        while(next<N&&v[next].first<=cut){
            next+=1;
        }
        idx=next;
    }
    return answer;
}