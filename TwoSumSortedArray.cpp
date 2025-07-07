/* TwoSum sorted array
   Time Complexity: O(n) */

#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target)
{
    int n=arr.size();
    int i=0, j=n-1, current sum;
    vector<int> vec(2);
    while (i<j)
    {
        current_sum = arr[i] + arr[j];
	if (current_sum < target)
	    i++;
	else if (current_sum > target)
	    j--;
	else
	{
	    vec.push_back(i);
	    vec.push_back(j);
	    break;
	}
    }
    return vec;
}
