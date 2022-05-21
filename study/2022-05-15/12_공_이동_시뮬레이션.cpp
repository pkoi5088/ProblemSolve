#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/87391
*/

void queryLeft(int n,int m,long long dx,pair<long long,long long>& left,pair<long long,long long>& right){
    right.second+=dx;
    if(left.second!=0) left.second+=dx;
}

void queryRight(int n,int m,long long dx,pair<long long,long long>& left,pair<long long,long long>& right){
    left.second-=dx;
    if(right.second!=m-1) right.second-=dx;
}

void queryUp(int n,int m,long long dx,pair<long long,long long>& left,pair<long long,long long>& right){
    right.first+=dx;
    if(left.first!=0) left.first+=dx;
}

void queryDown(int n,int m,long long dx,pair<long long,long long>& left,pair<long long,long long>& right){
    left.first-=dx;
    if(right.first!=n-1) right.first-=dx;
}

bool check(int n,int m,pair<long long,long long>& left,pair<long long,long long>& right){
    if(left.first<0||left.first>=n||left.second<0||left.second>=m){
        if(right.first<0||right.first>=n||right.second<0||right.second>=m){
            return false;
        }
    }
    return true;
}

void correction(int n,int m,pair<long long,long long>& left,pair<long long,long long>& right){
    if(left.first<0) left.first=0;
    else if(left.first>=n) left.first=n-1;
    
    if(left.second<0) left.second=0;
    else if(left.second>=m) left.second=m-1;
    
    if(right.first<0) right.first=0;
    else if(right.first>=n) right.first=n-1;
    
    if(right.second<0) right.second=0;
    else if(right.second>=m) right.second=m-1;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    pair<long long,long long> left={x,y},right={x,y};
    for(int i=queries.size()-1;i>=0;--i){
        switch(queries[i][0]){
            //왼
            case 0:
                queryLeft(n,m,queries[i][1],left,right);
                break;
                
            //오
            case 1:
                queryRight(n,m,queries[i][1],left,right);
                break;
                
            //위
            case 2:
                queryUp(n,m,queries[i][1],left,right);
                break;
                
            //아래
            case 3:
                queryDown(n,m,queries[i][1],left,right);
                break;
        }
        
        if(check(n,m,left,right)==false){
            return 0;
        }
        correction(n,m,left,right);
    }
    answer=(right.first-left.first+1)*(right.second-left.second+1);
    return answer;
}