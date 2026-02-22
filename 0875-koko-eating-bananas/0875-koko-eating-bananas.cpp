class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // piles 크기보다 h가 같거나 더 큼. 가장 큰 값을 처리하면 h시간만큼 걸림
        int left = 1, right = 0;

        for(int & pile : piles)
        {
            right = max(right, pile);
        }

        int k = 0;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            unsigned int time = 0;
            for(int& pile : piles)
            {
                time += pile/mid;
                if(pile%mid != 0) time++;
            }

            if(time > h)
            {
                left = mid + 1;
            }
            else
            {
                k = mid;
                right = mid-1;
            }
            cout << left << " , "<< right << ", " << k <<"\n";
        }

        return k;
    }
};