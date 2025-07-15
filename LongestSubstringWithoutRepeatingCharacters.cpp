/* Length of Longest Substring Without Repeating Characters
   Time Complexity: O(n) */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<bool> exist(256, false); // ASCII character tracking
    int i = 0, maxLen = 0;

    for (int j = 0; j < s.length(); j++)
    {
        // If s[j] already exists in the current window
        while (exist[s[j]])
        {
            exist[s[i]] = false;  // Remove s[i] from window
            i++;                  // Move left pointer forward
        }
        exist[s[j]] = true;       // Add s[j] to window
        if (maxLen < j-i+1)
            maxLen = j-i+1;  // Update max length if needed
    }
    return maxLen;
}

int main()
{
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
