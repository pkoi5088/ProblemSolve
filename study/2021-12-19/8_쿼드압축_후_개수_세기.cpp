#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/68936
*/

bool check(vector<vector<int>>& arr,int x,int y,int size){
    for(int i=x;i<x+size;++i){
        for(int j=y;j<y+size;++j){
            if(arr[x][y]!=arr[i][j])
                return false;
        }
    }
    return true;
}

//ans1: 0개수, ans2: 1개수
void searchQuad(vector<vector<int>>& arr,int x,int y,int size,int& ans1,int& ans2){
    if(check(arr,x,y,size)){
        if(arr[x][y]==0){
            ans1+=1;
        }else{
            ans2+=1;
        }
    }else{
        searchQuad(arr,x,y,size/2,ans1,ans2);
        searchQuad(arr,x+size/2,y,size/2,ans1,ans2);
        searchQuad(arr,x,y+size/2,size/2,ans1,ans2);
        searchQuad(arr,x+size/2,y+size/2,size/2,ans1,ans2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    searchQuad(arr,0,0,arr.size(),answer[0],answer[1]);
    return answer;
}