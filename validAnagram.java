// Time Complexity: O(n)

class Solution
{
    public boolean isAnagram(String str1, String str2)
    {
        if (str1.length() != str2.length())
            return false;
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
      
        // Create a HashMap to store frequency counts of characters in str1
        HashMap<Character, Integer> map = new HashMap<>();
      
        // Count occurrences of each character in str1
        for (int i=0; i<str1.length(); i++)
        {
            char c = str1.charAt(i);
            if (map.containsKey(c))
                map.put(c, map.get(c) + 1);
            else
                map.put(c, 1);
        }
      
        // Subtract the count for each character in str2
        for (int j=0; j<str2.length(); j++)
        {
            char d = str2.charAt(j);
            // If the character is not in the map, str2 has an extra character, ie not an anagram
            if (!(map.containsKey(d)))
                return false;
            map.put(d, map.get(d) - 1);
            // If count goes below 0, str2 has more of this particularcharacter, ie not an anagram
            if (map.get(d) < 0)
                return false;
        }

        return true;
    }
}
