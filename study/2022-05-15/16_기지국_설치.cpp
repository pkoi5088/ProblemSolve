#include <iostream>
#include <vector>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12979
*/

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<int> sector;
    int last=1;
    for(int i=0;i<stations.size();++i){
        int start=stations[i]-w;
        if(last<start){
            sector.push_back(start-last);
        }
        last=stations[i]+w+1;
    }
    if(last<=n){
        sector.push_back(n-last+1);
    }
    
    for(int i=0;i<sector.size();++i){
        answer+=sector[i]/(2*w+1)+!!(sector[i]%(2*w+1));
    }
    return answer;
}