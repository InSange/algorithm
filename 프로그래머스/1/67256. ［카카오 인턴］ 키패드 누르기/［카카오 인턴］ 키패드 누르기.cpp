#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left = {3, 0};
    pair<int, int> right = {3, 2};
    
    for(auto i : numbers)
    {
        if(i == 1) left = {0, 0}, answer += 'L'; 
        else if(i == 4) left = {1, 0}, answer += 'L';
        else if(i == 7) left = {2, 0}, answer += 'L';
        else if(i == 3) right = {0, 2}, answer += 'R';
        else if(i == 6) right = {1, 2}, answer += 'R';
        else if(i == 9) right = {2, 2}, answer += 'R';
        else if(i == 2)
        {
            int Len_l = (left.first == 0 ? 0 : left.first) + (left.second == 1 ? 0 : 1);
            int Len_r = (right.first == 0 ? 0 : right.first) + (right.second == 1 ? 0 : 1);
            if(Len_l < Len_r) left = {0, 1}, answer += 'L';
            else if(Len_r < Len_l) right = {0, 1}, answer += 'R';
            else
            {
                if(hand == "right") right = {0, 1}, answer += 'R';
                else left = {0, 1}, answer += 'L';
            }
        }
        else if(i == 5) // 1,1
        {
            int Len_l = (left.first == 1 ? 0 : abs(left.first-1)) + (left.second == 1 ? 0 : 1);
            int Len_r = (right.first == 1 ? 0 : abs(right.first-1)) + (right.second == 1 ? 0 : 1);
            if(Len_l < Len_r) left = {1, 1}, answer += 'L';
            else if(Len_r < Len_l) right = {1, 1}, answer += 'R';
            else
            {
                if(hand == "right") right = {1, 1}, answer += 'R';
                else left = {1, 1}, answer += 'L';
            }
        }
        else if(i == 8)
        {
            int Len_l = (left.first == 2 ? 0 : abs(left.first-2)) + (left.second == 1 ? 0 : 1);
            int Len_r = (right.first == 2 ? 0 : abs(right.first-2)) + (right.second == 1 ? 0 : 1);
            if(Len_l < Len_r) left = {2, 1}, answer += 'L';
            else if(Len_r < Len_l) right = {2, 1}, answer += 'R';
            else
            {
                if(hand == "right") right = {2, 1}, answer += 'R';
                else left = {2, 1}, answer += 'L';
            }
        }
        else if(i == 0)
        {
            int Len_l = (left.first == 3 ? 0 : abs(left.first-3)) + (left.second == 1 ? 0 : 1);
            int Len_r = (right.first == 3 ? 0 : abs(right.first-3)) + (right.second == 1 ? 0 : 1);
            if(Len_l < Len_r) left = {3, 1}, answer += 'L';
            else if(Len_r < Len_l) right = {3, 1}, answer += 'R';
            else
            {
                if(hand == "right") right = {3, 1}, answer += 'R';
                else left = {3, 1}, answer += 'L';
            }
        }
    }
    
    return answer;
}