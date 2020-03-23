class Solution {
public:
    vector<int> constructRectangle(int area) 
    {
        int length = area/2;
        vector<int> result;
        result.push_back(area);
        result.push_back(1);
        int lastDiff(area-1);
        while (length > 0)
        {
            int width = area/length;
            if (width > length)
            {
                break;
            }
            int diff = length - width;
            if ( width * length == area && lastDiff > diff)
            {
                lastDiff = diff;
                result.clear();
                result.push_back(length);
                result.push_back(width);
            }
            length--;
        }
        return result;
    }
};
