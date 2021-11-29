#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2263
*/

vector<int> inorder,postorder;
int n;

int getIdx(int start,int end,int number){
    int ret=start;
    for(;ret<=end&&inorder[ret]!=number;++ret);
    return ret;
}

void f(int inStart,int inEnd,int postStart,int postEnd){
    if(inStart>inEnd||postStart>postEnd) return;
    int root=postorder[postEnd],idx=getIdx(inStart,inEnd,root);
    cout<<root<<' ';
    f(inStart,idx-1,postStart,postStart+idx-inStart-1);
    f(idx+1,inEnd,postStart+idx-inStart,postEnd-1);
}

void solve() {
    cin>>n;
    inorder.resize(n);
    postorder.resize(n);
    for(int i=0;i<n;++i)
        cin>>inorder[i];
    for(int i=0;i<n;++i)
        cin>>postorder[i];
    f(0,n-1,0,n-1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}