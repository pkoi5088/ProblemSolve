#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/12953
*/

int gcd(int a,int b){
    while(b!=0){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}

int lcm(int a,int b){
    int tmp=gcd(a,b);
    return a*b/tmp;
}

int solution(vector<int> arr) {
    if(arr.size()==1) return arr[0];
    int answer = lcm(arr[0],arr[1]);
    for(int i=2;i<arr.size();++i){
        answer=lcm(answer,arr[i]);
    }
    return answer;
}