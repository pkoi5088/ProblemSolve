#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/70129
*/

vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(s!="1"){
        answer[0]+=1;
        int count=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='0')
                count+=1;
        }
        answer[1]+=count;
        count=s.size()-count;
        s.clear();
        while(count!=0){
            s.push_back(count%2+'0');
            count/=2;
        }
    }
    return answer;
}