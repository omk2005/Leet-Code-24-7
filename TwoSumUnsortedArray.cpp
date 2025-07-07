/* TwoSum unordered array
   Time Complexity: O(n) */

#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target)
{
    unordered_map<int, int> m1;
    vector<int> vec;
    for (int i=0; i<arr.size(); i++)
    {
        int b = target - arr[i];
        if (m1.find(b) != m1.end())
	{
	    vec.push_back(m1[b]);
            vec.push_back(i);
	    break
        }
        m1[arr[i]] = i;
    }
    return vec;
}
