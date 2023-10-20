#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl '\n'

using namespace std;

class Trie {
private:
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;

        TrieNode() {
            children.resize(10, nullptr);
            isEnd = false;
        }
    };

    TrieNode* root;

    bool checkNode(TrieNode* node) const {
        // 현재 노드가 단어의 끝이고, 자식 노드가 있다면 접두사
        if (node->isEnd) {
            for (auto& child : node->children) {
                if (child) return true;
            }
        }

        // 자식 노드들에 대해 재귀적으로 검사
        for (auto& child : node->children) {
            if (child && checkNode(child)) return true;
        }
        return false;
    }

    void freeNode(TrieNode* node) {
        for (auto& child : node->children) {
            if (child) freeNode(child);
        }
        delete node;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - '0';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - '0';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool isAnyNodePrefixOfAnother() {
        return checkNode(root);
    }

    ~Trie() {
        freeNode(root);
    }
};

void solve() {
    Trie trie;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string t;
        cin >> t;
        trie.insert(t);
    }
    if (trie.isAnyNodePrefixOfAnother()) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--)
        solve();
	return 0;
}