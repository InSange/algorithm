#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, greater<int>> pq;
    
    cin >> N;

    while(N--)
    {
        int num;
        cin >> num;

        if(num == 0)
        {
            if(pq.empty()) cout << 0 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }
    
    return 0;
}