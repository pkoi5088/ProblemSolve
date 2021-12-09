#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/84512
*/

int solution(string word) {
    int answer = 0;
    string list="AEIOU";
    for(int idx=0;idx<word.size();++idx){
        int letter,childnodes;
        for(letter=0;letter<5&&list[letter]!=word[idx];++letter);
        childnodes=(pow(5,4-idx+1)-1)/4*letter;
        answer+=childnodes+1;
    }
    return answer;
}