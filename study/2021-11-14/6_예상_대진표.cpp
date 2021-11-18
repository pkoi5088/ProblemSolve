#include <iostream>

using namespace std;

int log2(int n){
    int ret=0;
    while(n!=1){
        ret+=1;
        n/=2;
    }
    return ret;
}

int solution(int n, int a, int b)
{
    if(a>b) swap(a,b);
    int start=1,end=n,answer=0;
    while(true){
        if(a<start&&start<=b){
            return log2(n)-answer+1;
        }
        int mid=(start+end)/2;
        if(b<=mid) end=mid;
        else start=mid+1;
        answer+=1;
    }
}