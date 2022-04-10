#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42892
*/

struct Node{
    int x,y,idx;
    Node(int ix,int iy,int id){
        x=ix;y=iy;idx=id;
    }
};

bool cmp(const Node& n1,const Node& n2){
    return n1.x<n2.x;
}

//y값이 가장 높은 idx
int findHighLevel(int left,int right, vector<Node>& v){
    int ret=left;
    for(int i=left;i<=right;++i){
        if(v[ret].y<v[i].y){
            ret=i;
        }
    }
    return ret;
}

void f(int left,int right,vector<Node>& v,vector<vector<int>>& answer){
    if(left>right) return;

    int idx=findHighLevel(left,right,v);
    answer[0].push_back(v[idx].idx);
    f(left,idx-1,v,answer);
    f(idx+1,right,v,answer);
    answer[1].push_back(v[idx].idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<Node> v;
    for(int i=1;i<nodeinfo.size()+1;++i){
        v.push_back(Node(nodeinfo[i-1][0],nodeinfo[i-1][1],i));
    }
    sort(v.begin(),v.end(),cmp);
    f(0,v.size()-1,v,answer);
    return answer;
}