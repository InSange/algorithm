#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, x;

priority_queue<int> val;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    while(N--)
    {
        cin >> x;
        if(x == 0)
        {
            if(val.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << val.top() << "\n";
                val.pop();
            }
        }
        else
        {
            val.push(x);
        }
    }
    
    return 0;
}