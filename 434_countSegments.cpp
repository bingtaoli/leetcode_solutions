class Solution {
public:
    int countSegments(string s) 
    {
        vector<char> word;
        int i(0);
        int count(0);
        while ( i < s.size() )
        {
            if (s[i] != ' ')
            {
                word.push_back(s[i]);
            }
            else
            {
                if (word.size() > 0)
                {
                    count++;
                    word.clear();
                }
            }
            i++;
        }
        if (word.size())
        {
            count++;
        }
        return count;
    }
};
