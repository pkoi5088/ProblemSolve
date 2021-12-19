#include <iostream>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12980
*/

int solution(int n)
{
    int ans = 0;
    while(n!=0){
        if(n%2)
            ans+=1;
        n/=2;
    }
    return ans;
}