#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/70130
*/

int max(int a,int b){
    return a<b?b:a;
}

int solution(vector<int> a) {
    vector<int> numCheck(a.size(),0);
    int answer=0;
    for(int i=0;i<a.size();++i){
        numCheck[a[i]]+=1;
    }
    
    for(int num=0;num<a.size();++num){
        if(answer>=numCheck[num]*2) continue;
        
        //num을 센터로 세팅
        vector<int> v;
        for(int i=0;i<a.size();++i){
            if(v.size()%2==0) v.push_back(a[i]);
            else if(v.back()!=num&&a[i]==num) v.push_back(a[i]);
            else if(v.back()==num&&a[i]!=num) v.push_back(a[i]);
        }
        answer=max(answer,v.size()-v.size()%2);
    }
    return answer;
}