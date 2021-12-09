#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/17680
*/

bool cmp(pair<string,int> p1,pair<string,int>p2){
    return p1.second>p2.second;
}

int solution(int cacheSize, vector<string> cities) {
    set<string> cache;
    vector<pair<string,int>> v;
    int answer = 0;
    for(string& s:cities){
        for(int i=0;i<s.size();++i){
            if(s[i]<='Z') s[i]-='A'-'a';
        }
        if(cache.find(s)==cache.end()){
            //miss
            answer+=5;
            if(cacheSize!=0){
                if(cache.size()>=cacheSize){
                    cache.erase(v.back().first);
                    v.pop_back();
                }
                cache.insert(s);
                v.push_back({s,answer});
            }
        }else{
            //hit
            answer+=1;
            int idx=0;
            for(;idx<v.size()&&v[idx].first!=s;++idx);
            v[idx].second=answer;
        }
        sort(v.begin(),v.end(),cmp);
    }
    return answer;
}