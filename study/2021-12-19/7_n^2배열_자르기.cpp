#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/87390
*/

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(;left<=right;++left){
        int i=(int)(left/(long long)n)+1;
        int j=(int)(left%(long long)n)+1;
        answer.push_back(max(i,j));
    }
    return answer;
}