#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42584
*/

vector<int> solution(vector<int> prices) {
    prices.push_back(-1);
    int N=prices.size(),time;
    vector<int> answer(N-1);
    //first:price, second:idx
    stack<pair<int,int>> s;
    for(time=0;time<N;++time){
        if(s.empty()){
            s.push({prices[time],time});
        }else{
            while(!s.empty()&&s.top().first>prices[time]){
                answer[s.top().second]=time-s.top().second-(time==N-1?1:0);
                s.pop();
            }
            s.push({prices[time],time});
        }
    }
    return answer;
}