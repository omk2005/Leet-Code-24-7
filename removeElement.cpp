// Time complexity: O(n)
// Space complexity: O(1)

int removeElement(vector<int>& arr, int val)
{
    int i = 0;
    for (int j = 0; j < arr.size(); ++j)
    {
        if (arr[j] != val)
            arr[i++] = arr[j];
    }
    return i;
}
