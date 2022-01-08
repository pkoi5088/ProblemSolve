#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12911
*/

int solution(int n) {
    for(int i=0,count=0;;++i,n/=2){
        if((n&3)==1){
            n+=1;
            n<<=i;
            n+=(1<<count)-1;
            return n;
        }
        count+=n%2;
    }
}