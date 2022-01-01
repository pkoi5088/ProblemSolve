#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/17687
*/

void next(vector<int>& now,int n){
    now[0]+=1;
    for(int i=0;i<now.size();++i){
        if(now[i]>=n){
            now[i]=0;
            if(i==now.size()-1){
                now.push_back(1);
                return;
            }
            now[i+1]+=1;
        }
    }
}

string solution(int n, int t, int m, int p) {
    p-=1;
    string answer = "";
    vector<int> now;
    now.push_back(0);
    int idx=0;
    while(answer.size()!=t){
        if(p==0){
            if(now[idx]>=10){
                answer.push_back(now[idx]-10+'A');
            }else{
                answer.push_back(now[idx]+'0');
            }
            p=m;
        }
        p-=1;
        idx-=1;
        if(idx<0){
            next(now,n);
            idx=now.size()-1;
        }
    }
    return answer;
}