/* It mimics the atoi() behavior:
	Converts a string like " -42" into integer -42.
	Stops at the first non-digit.
	Handles leading whitespace and signs.
	Detects overflow:
		If the number goes beyond Integer.MAX_VALUE (2^31 - 1)
		or below Integer.MIN_VALUE (-2^31),
		it returns the appropriate bound.
   Time complexity: O(n)
   Space complexity: O(1) */

#include <iostream>
#include <climits>
using std::cout, std::string;

int myAtoi(string);

int main()
{
    cout<<myAtoi("  -35 Vance");
    return 0;
}

int myAtoi(string str1)
{
    int i = 0, n = str1.size();
    
    //loop until you run into a non-whitespace character
    while (i<n && str1[i]==' ')
    {
        i++;
    }
    
    int sign = 1;
    if (i < n)  //we can only continue if there are characters left
    {
        if (str1[i] == '+')
            i++;
        else if (str1[i] == '-')
        {
            sign = -1;
            i++;
        }
    }
    
    int num = 0, maxDiv = INT_MAX/10;
    while (i<n)
    {
        int digit = str1[i] - '0';
        if (digit<0 || digit>9)
            break;
        // prevent overflow before it occurs, by checking:
        if ((num > maxDiv) || ((num == maxDiv) && (digit > 8)))
        {
            if (sign == 1)
                return INT_MAX;
            return INT_MIN;
        }
        num = num*10 + digit;
        i+=1;
    }
    return sign * num;
}
	
