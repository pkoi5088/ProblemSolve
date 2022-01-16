#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12949
*/

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int N=arr1.size(),M=arr2[0].size(),C=arr1[0].size();
    answer.resize(N);
    for(int i=0;i<N;++i)
        answer[i].resize(M);
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            int tmp=0;
            for(int k=0;k<C;++k){
                tmp+=arr1[i][k]*arr2[k][j];
            }
            answer[i][j]=tmp;
        }
    }
    return answer;
}