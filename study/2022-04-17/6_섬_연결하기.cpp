#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/42861
*/

struct Node{
    int from,to,cost;
    Node(int f,int t,int c){
        from=f,to=t,cost=c;
    }
};

struct cmp{
    bool operator()(Node n1,Node n2){
        return n1.cost>n2.cost;
    }
};

vector<int> parent;

int Find(int x){
    if(x==parent[x]) return x;
    return parent[x]=Find(parent[x]);
}

void Union(int a,int b){
    parent[Find(a)]=parent[Find(b)];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<Node,vector<Node>,cmp> pq;
    parent.resize(n);
    for(int i=0;i<n;++i){
        parent[i]=i;
    }
    for(vector<int>& v:costs)
        pq.push(Node(v[0],v[1],v[2]));
    
    while(!pq.empty()){
        int from=pq.top().from,to=pq.top().to,cost=pq.top().cost;
        pq.pop();
        if(Find(from)==Find(to)) continue;
        answer+=cost;
        Union(from,to);
    }
    return answer;
}