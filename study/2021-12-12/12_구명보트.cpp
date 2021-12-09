#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42885
*/

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    int answer = 0,end=people.size()-1,start;
    for(start=0;start<=end;end-=1,answer+=1){
        if(people[start]+people[end]<=limit){
            start+=1;
        }
    }
    return answer;
}