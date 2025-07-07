/* Reverse Words in a String II
   reverse it word by word without using a separate data structure
   Time Complexity: O(n) 
   Space Complexity: O(1) */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseRange(vector<char>&, int, int);

void reverse(vector<char>& s)
{
    int n = s.size();

    // Step 1: Reverse the entire string
    reverseRange(s, 0, n);

    // Step 2: Reverse each word
    int i=0;  // start index of current word
    for (int j=0; j<=n; j++)
    {
        if (j==n || s[j]==' ')   // Last word (no space at the end)
	{
            reverseRange(s, i, j);   // Reverse the word from i to j-1
            i = j+1;  // move to the start of the next word
        }
    }
}

void reverseRange(vector<char>& str1, int begin, int end)
{
    // Reverses the characters in the range [begin, end)
    while (begin < end-1)
    {
	char temp = str1[begin]; 
	str1[begin] = str1[end-1]; 
	str1[end-1] = temp;
	begin++;
	end--;
    }
}
