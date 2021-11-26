#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/4256
*/

int N;
vector<int> preorder,inorder;

int getIdx(int start,int end,int number){
	int ret;
	for(ret=start;ret<=end&&inorder[ret]!=number;++ret);
	return ret;
}

void f(int preStart,int preEnd,int inStart,int inEnd){
	if(preStart>preEnd||inStart>inEnd) return;

	int root=preorder[preStart],idx;
	idx=getIdx(inStart,inEnd,root);
	//개수 idx-inStart
	f(preStart+1,preStart+idx-inStart,inStart,idx-1);
	f(preStart+idx-inStart+1,preEnd,idx+1,inEnd);
	cout<<root<<' ';
}

void solve() {
    cin>>N;
	preorder.resize(N);
	inorder.resize(N);
	for(int i=0;i<N;++i)
		cin>>preorder[i];
	for(int i=0;i<N;++i)
		cin>>inorder[i];
	
	f(0,N-1,0,N-1);
	cout<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}