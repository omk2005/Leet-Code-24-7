class Solution {
public:
    vector<int> twoSum(vector<int>& num, int tar)
    {
        vector<int>v(2);
        unordered_map<int, int> m;
        for (int a=0; a<num.size(); a++)
        {
            m[num[a]] = a;
        }
        for (int i=0; i<num.size(); i++)
        {
            if (m[tar-num[i]] && i!=m[tar-num[i]])
            {
                v[0]=i, v[1]=m[tar-num[i]];
                break;
            }
        }
        return v;
    }
};
