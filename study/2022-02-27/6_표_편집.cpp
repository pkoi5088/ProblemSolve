#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/81303
*/

struct Node {
    int number;
    Node* prev;
    Node* next;
    Node(int num) :number(num), prev(NULL), next(NULL) {};
};

string solution(int n, int k, vector<string> cmd) {
    vector<Node*> v(n), log;
    for (int i = 0; i < n; ++i) {
        v[i] = new Node(i);
    }
    for (int i = 0; i < n; ++i) {
        if (i != 0) v[i]->prev = v[i - 1];
        if (i != n - 1) v[i]->next = v[i + 1];
    }

    for (string s : cmd) {
        if (s[0] == 'D' || s[0] == 'U') {
            int x = stoi(s.substr(2));
            if (s[0] == 'D') while (v[k]->next != nullptr && x--) k = v[k]->next->number;
            else while (v[k]->prev != nullptr && x--) k = v[k]->prev->number;
        }
        else if (s[0] == 'C') {
            log.push_back(v[k]);
            //마지막행이 아닌 경우
            if (v[k]->next != nullptr) {
                //제일 앞 삭제
                if (v[k]->prev != nullptr) {
                    v[k]->prev->next = v[k]->next;
                }
                v[k]->next->prev = v[k]->prev;
                k = v[k]->next->number;
            }
            //마지막 행인경우
            else {
                v[k]->prev->next = v[k]->next;
                k = v[k]->prev->number;
            }
        }
        else if (s[0] == 'Z') {
            if (log.empty()) continue;
            Node* tmp = log.back();
            if (tmp->prev != nullptr)
                tmp->prev->next = tmp;
            if (tmp->next != nullptr)
                tmp->next->prev = tmp;
            log.pop_back();
        }
    }

    string answer(n, 'X');
    while (v[k]->prev != nullptr)
        k = v[k]->prev->number;
    while (v[k]->next != nullptr) {
        answer[k] = 'O';
        k = v[k]->next->number;
    }
    answer[k] = 'O';
    return answer;
}