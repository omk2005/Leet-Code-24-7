#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.size();
    int i=0, j=n-1;	//two iterators starting from the beginning and the end
    while (i<j)
    {
	// handle non alphanumeric cases
	while ((i<j) && (s[i]<97 || s[i]>122) && (s[i]<65 || s[i]>90) && (s[i]<48 || s[i]>57))
	    i++;
	while ((i<j) && (s[j]<97 || s[j]>122) && (s[j]<65 || s[j]>90) && (s[j]<48 || s[j]>57))
	    j--;

	// convert a character to lowercase if they are alphabets
	char a = s[i], b = s[j];
	if (a>='A' && a<='Z')
	    a += 32;
	if (b>='A' && b<='Z')
	    b += 32;
        if (a!=b)
	    return false;

	i++;
	j--;
    }
    return true;
}
