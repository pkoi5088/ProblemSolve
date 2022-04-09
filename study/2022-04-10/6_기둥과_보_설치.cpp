#include <string>
#include <vector>
#define MAX 101

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/60061
*/

//0 기둥, 1 보
bool arr[MAX][MAX][2]={false,};

//arr[x][y][a]가 현재 유효한가?
bool check(int x,int y,int a,int n){
    //범위밖이거나 구조물이 없으면 유효(무시가능)
    if(x<0||x>n||y<0||y>n) return true;
    if(arr[x][y][a]==false) return true;
    
    //보
    if(a){
        if(arr[x][y-1][0]||arr[x+1][y-1][0]||(x>0&&arr[x-1][y][1]&&x<=n&&arr[x+1][y][1])){
            return true;
        }
    }
    //기둥
    else{
        if(y==0||(x>0&&arr[x-1][y][1])||arr[x][y][1]||arr[x][y-1][0]){
            return true;
        }
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(vector<int> order:build_frame){
        int x=order[0],y=order[1],a=order[2],b=order[3];
        
        //설치
        if(b){
            arr[x][y][a]=true;
            if(!check(x,y,a,n)){
                arr[x][y][a]=false;
            }
        }
        //삭제
        else{
            //보
            if(a){
                arr[x][y][a]=false;
                if(!(check(x-1,y,1,n)&&check(x+1,y,1,n)&&check(x,y,0,n)&&check(x+1,y,0,n))){
                    arr[x][y][a]=true;
                }
            }
            //기둥
            else{
                arr[x][y][a]=false;
                if(!(check(x,y+1,0,n)&&check(x-1,y+1,1,n)&&check(x,y+1,1,n))){
                    arr[x][y][a]=true;
                }
            }
        }
    }
    
    for(int x=0;x<=n;++x){
        for(int y=0;y<=n;++y){
            for(int i=0;i<2;++i){
                if(arr[x][y][i]){
                    answer.push_back({x,y,i});
                }
            }
        }
    }
    return answer;
}