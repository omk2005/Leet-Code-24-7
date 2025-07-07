/* Substring needle in a haystack
   Returns the index of the first occurrence of needle in haystack,
   or –1 if needle is not part of haystack.
   
   BRUTE FORCE
   Worst time Complexity: O(n^2) */

#include <vector>
using namespace std;

int subStr(string haystack, string needle) //return the index where substring starts
{
    // if needle is empty, return 0 (first index match)
    if (needle.empty())
	return 0;

    if (needle.size() > haystack.size())
	return -1;

    // Loop through haystack
    // go up to haystack.size() - needle.size() because needle must fit within haystack
    for (int i = 0; i <= haystack.size() - needle.size(); i++)
    {
        bool match = true;   // assume a match is possible at index i

        // Loop through needle
	// compare each character of needle with haystack starting from i
        for (int j = 0; j < needle.size(); j++)
        {
            // if characters don't match, set match to false and break out of inner loop
            if (haystack[i + j] != needle[j])
            {
                match = false;
                break; // no need to check further if one character mismatches
            }
        }

        // If the whole needle matched, return the starting index i
        if (match)
            return i;
    }

    // If no match is found after scanning the whole haystack, return -1
    return -1;
}
