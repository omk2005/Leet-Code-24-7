/* Reverse Words in a String I
   reverse it word by word, i.e. if s = "the sky is blue", return "blue is sky the"
   Time Complexity: O(n) 
   Space Complexity: O(n) */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reverse(string);

int main()
{
    string str1 = "blue is sky the";
    cout<<reverse(str1)<<endl;  //the sky is blue
    return 0;
}

string reverse(string s)
{
    vector<string> vec;
    
    string x;
    for (char c : s)
    {
        if (c == ' ')
        {
            if (!x.empty())
                vec.push_back(x);
            x = "";
            continue;
        }
        x += c;
    }
    // in case the last word is not followed by a space
    if (!x.empty())
        vec.push_back(x);

    string rev = "";
    for (int i = vec.size()-1; i>=0; i--)
    {
        rev += vec[i];
        if (i != 0)
            rev += " ";
    }
    return rev;
};
