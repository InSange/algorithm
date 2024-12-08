class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = -1;
        
        int searchSize = searchWord.size();
        int sentenceSize = sentence.size();
        
        int n = 1;
        
        for(int i = 0; i <= sentenceSize - searchSize; ++i)
        {
            string s = sentence.substr(i, searchSize);
            
            if(s == searchWord)
            {
                ans = n;
                break;
            }
            else
            {
                while(i < sentenceSize && sentence[i] != ' ')
                {
                    ++i;
                }
                n++;
            }
        }
        
        return ans;
    }
};