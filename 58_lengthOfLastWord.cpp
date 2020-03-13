class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int lastWordLen = 0;
        const int len = s.size();
        int result(0);
        for (int i = 0; i < len; i++)
        {
            while (i < len && s[i] == ' ')
            {
                i++;
            }
            lastWordLen = 0;
            while (i < len && s[i] != ' ')
            {
                lastWordLen++;
                i++;
            }
            if (lastWordLen)
            {
                result = lastWordLen;
            }
        }
        return result;
    }
};
