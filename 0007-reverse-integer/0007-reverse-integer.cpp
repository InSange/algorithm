class Solution {
public:
    int reverse(int x) {
        string stringNum = to_string(x);
        
        std::reverse(stringNum.begin(), stringNum.end());

        try {
            x = (x < 0 ? stoi(stringNum) * -1 : stoi(stringNum));
        } catch (const std::out_of_range& e) {
            return 0;
        }
        
        return x;
    }
};