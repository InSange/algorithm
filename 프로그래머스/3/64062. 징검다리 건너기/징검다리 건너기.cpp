#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
    int value;
    int index;
};

// 부모 노드를 찾는 함수 (경로 압축 적용)
int findParent(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent, parent[x]);
}

// 두 집합을 합치는 함수 (구멍 크기 갱신 포함)
void unionSets(vector<int>& parent, vector<int>& size, int a, int b) {
    int rootA = findParent(parent, a);
    int rootB = findParent(parent, b);

    if (rootA != rootB) {
        // b를 a에 붙임 (순서는 상관없으나 크기 관리를 위해 통일)
        parent[rootB] = rootA;
        size[rootA] += size[rootB]; // a의 그룹 크기에 b의 그룹 크기를 더함
    }
}

bool compareNodes(const Node& a, const Node& b) {
    return a.value < b.value;
}

int solution(vector<int> stones, int k) {
    int n = stones.size();
    
    // Union-Find용 배열 초기화
    vector<int> parent(n);
    vector<int> size(n, 1); // 각 돌은 처음에 크기 1짜리 구멍
    vector<bool> visited(n, false); // 해당 돌이 0이 되었는지 체크
    vector<Node> nodes(n);

    // 1. 돌들을 값 기준으로 정렬하기 위해 저장
    for (int i = 0; i < n; i++) {
        parent[i] = i; // 자기 자신이 부모
        nodes[i] = {stones[i], i};
    }
    sort(nodes.begin(), nodes.end(), compareNodes);

    // 2. 값이 작은 돌부터 차례대로 제거 (0으로 만들기)
    for (int i = 0; i < n; i++) {
        int idx = nodes[i].index;
        int val = nodes[i].value;

        visited[idx] = true; // 현재 돌 제거 처리

        // 왼쪽 돌이 이미 제거된 상태라면 합침
        if (idx - 1 >= 0 && visited[idx - 1]) {
            unionSets(parent, size, idx - 1, idx);
        }
        // 오른쪽 돌이 이미 제거된 상태라면 합침
        if (idx + 1 < n && visited[idx + 1]) {
            unionSets(parent, size, idx, idx + 1);
        }

        // 합친 후, 현재 그룹(구멍)의 크기가 k 이상인지 확인
        int root = findParent(parent, idx);
        if (size[root] >= k) {
            return val;
        }
    }
    return 0;
}