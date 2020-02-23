#include <iostream>
using namespace std;

/*
https://leetcode-cn.com/problems/find-k-closest-elements/

我们可以使用二分查找来找到最接近x的元素索引index，然后让left=index-k，right=index+k，然后迭代。
时间复杂度：O(logn+k)  logn是二分查找，O(k)是迭代时间
空间复杂度: O(k) 
*/

class Solution {
public:
    int binarySearch(const vector<int> &arr, int value)
    {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (value == arr[middle])
            {
                return middle;
            }
            else if (value > arr[middle])
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        //left和right哪个和value更接近
        int absLeft = abs(value-arr[left]);
        int absRight = abs(value-arr[right]);
        if (absLeft < absRight)
        {
            return left;
        }
        return right;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<int> result;
        int len = arr.size();
        if (x <= arr[0])
        {
            result.assign(arr.begin(), arr.begin()+k);
            return result;
        }
        if (x >= arr[len-1])
        {
            result.assign(arr.end()-k, arr.end());
            return result;
        }
        int index = binarySearch(arr, x);  //最接近x的位置
        cout << index << endl;
        int left = index - k;
        int right = index + k;
        while (left < 0)
        {
            left++;
        }
        while (right >= len)
        {
            right--;
        }
        cout << left << right << endl; 
        while (right - left > k-1)
        {
            int absLeft = abs(x-arr[left]);
            int absRight = abs(x-arr[right]);
            if (absLeft < absRight)
            {
                right--;
            }
            else if (absLeft > absRight)
            {
                left++;
            }
            else 
            {
                if (arr[left] == arr[right])
                {
                    right--;
                }
                else if (arr[left] < arr[right])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        cout << left << right << endl; 
        result.assign(arr.begin()+left, arr.begin()+right+1);
        return result;
    }
};
