#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0,idx=0,nowWeight=0;
    //first: weight, second: insertTime
    queue<pair<int,int>> q;
    while(!q.empty()||idx<truck_weights.size()){
        //q에서 빼고
        while(!q.empty()&&answer-q.front().second>=bridge_length){
            nowWeight-=q.front().first;
            q.pop();
        }
        
        //q에 넣는다
        if(idx<truck_weights.size()&&nowWeight+truck_weights[idx]<=weight&&q.size()<bridge_length){
            nowWeight+=truck_weights[idx];
            q.push({truck_weights[idx],answer});
            idx+=1;
        }
        answer+=1;
    }
    return answer;
}