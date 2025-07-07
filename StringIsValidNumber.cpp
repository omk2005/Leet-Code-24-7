/* Valid number (check if a given string is number
   "0", "0.1" return true. "Abc" -> false
    Time complexity: O(n)
    Space complexity: O(1) */

#include <iostream>
#include <climits>
using std::cout, std::endl, std::string;

bool isValidNum(string);

int main()
{
    cout<<isValidNum("  25")<<endl;
    cout<<isValidNum(" -0.1  ")<<endl;
    cout<<isValidNum("00.2")<<endl;
    cout<<isValidNum("2.2.5.5")<<endl;
    return 0;
}

bool isValidNum(string str1)
{
    int i = 0, n = str1.size();
    
    //loop until you run into a non-whitespace character
    while (i<n && str1[i]==' ')
    {
        i++;
    }
    
    if (i==n) //no digits
        return false;
    if (str1[i]=='+' || str1[i]=='-')
        i++;
    
    bool digit_seen = false; // merely "+" or "-" is not numeric
    int decimal_count = 0;
    int trail_space = 1;

    while (i<n)
    {
        char a = str1[i];
        int digit = a - '0';
        if (digit>=0 && digit<=9)
        {
            digit_seen = true;
            if (trail_space == 1)  //there are no spaces in between
            {
                i++;
                continue;
            }
            return false;  //for example, "1 1" is not numerical
        }
        if (a == '.')
        {
            if (decimal_count == 0)
            {
                decimal_count += 1;
                i++;
                continue;
            }
            return false;
        }
        if (a == ' ')
        {
            trail_space = 0;
            i++;
            continue;
        }
        return false; //str1[i] neither numeric, decimal, space
    }
    return digit_seen;
}
