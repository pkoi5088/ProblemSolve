#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/68646
*/

int solution(vector<int> a) {
    vector<int> left(a.size(),0),right(a.size(),0);
    int answer = 0,N=a.size();
    
    left[0]=a[0];
    for(int i=1;i<a.size();++i)
        left[i]=min(left[i-1],a[i]);
    
    right[N-1]=a[N-1];
    for(int i=N-2;i>=0;--i)
        right[i]=min(right[i+1],a[i]);
    
    for(int i=0;i<N;++i){
        if(i==0||i==N-1)
            answer+=1;
        else if(a[i]<left[i-1]||a[i]<right[i+1])
            answer+=1;
    }
    return answer;
}