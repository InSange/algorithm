#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, ans, maxAns, minAns;
vector<int> nums;
vector<int> ops;

void FIND(int sum, int curSize)
{
    if(curSize == N)
    {
        maxAns = max(maxAns, sum);
        minAns = min(minAns, sum);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        if(ops[i] == 0) continue;

        ops[i]--;
        if(i == 0)
        {
            FIND(sum + nums[curSize], curSize + 1);
        }
        else if(i == 1)
        {
            FIND(sum - nums[curSize], curSize + 1);
        }
        else if(i == 2)
        {
            FIND(sum * nums[curSize], curSize + 1);
        }
        else if(i == 3)
        {
            FIND(sum / nums[curSize], curSize + 1);
        }
        ops[i]++;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    nums.assign(N, 0);
    ops.assign(4, 0);

    for(int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    for(int i = 0; i < 4; i++)
    {
        cin >> ops[i];
    }

    maxAns = INT_MAX*(-1);
    minAns = INT_MAX;

    FIND(nums[0], 1);

    cout << maxAns << "\n" << minAns;
    
    return 0;
}