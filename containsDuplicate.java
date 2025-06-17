// Time Complexity: O(n)

class Solution
{
  public boolean containsDuplicate(int[] arr)
  {
    HashSet<Integer> h1 = new HashSet<>();
    for (int x : arr)          // O(n)
    {
      if (h1.contains(x))      // O(1)
        return true;
      h1.add(x);
    }
    return false;
  }
}
