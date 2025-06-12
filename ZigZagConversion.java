class Solution
{
    public String convert(String s, int numRows)
    {
        if (s == null || s.length() <= 1 || numRows == 1 || numRows >= s.length())
            return s;
      
        int len = s.length();
        int rowCount = Math.min(numRows, len);
        StringBuilder[] rows = new StringBuilder[rowCount];
      
        for (int i = 0; i < rowCount; i++)
            rows[i] = new StringBuilder();

        int curRow = 0;
        boolean goingDown = false;

        for (char c : s.toCharArray())
        {
            rows[curRow].append(c);
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        // Slight optimization: reserve initial capacity for result
        StringBuilder result = new StringBuilder(len);
        for (StringBuilder row : rows)
            result.append(row);

        return result.toString();
    }
}
