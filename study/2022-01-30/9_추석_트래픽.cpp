#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/17676
*/

int solution(vector<string> lines) {
    vector<pair<int,int>> v;
    int answer = 0;
    for(int i=0;i<lines.size();++i){
        lines[i].pop_back();
        string h,m,s,ms,tmp;
        int second;
        h=lines[i].substr(11,2);
        m=lines[i].substr(14,2);
        s=lines[i].substr(17,2);
        ms=lines[i].substr(20,3);
        tmp=lines[i].substr(24,5);
        second=stoi(h)*3600+stoi(m)*60+stoi(s);
        second=second*1000+stoi(ms);
        //second는 끝나는시간
        v.push_back({second-stof(tmp)*1000+1,second});
    }
    for(int i=0;i<lines.size();++i){
        int cutline=v[i].second+1000;
        int count=0;
        for(int j=i;j<lines.size();++j){
            if(v[j].first<cutline)   count+=1;
        }
        answer=max(answer,count);
    }
    return answer;
}