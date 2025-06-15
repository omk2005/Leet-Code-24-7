public class Solution
{
    void Rotate(int[][] arr)
    {
        int L = arr.length;
        for (int i=0; i<L; i++)
        {
            for (int j=0; j<i; j++)
            {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
        for (int k=0; k<L; k++)
            Reverse(0, L-1, arr[k]);
    }
    
    void Reverse(i, j, int[] a)
    {
        while (i<j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++; j--;
        }
    }
}
