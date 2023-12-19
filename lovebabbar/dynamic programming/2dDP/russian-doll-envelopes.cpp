class Solution
{
private:
    static int compare(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
        {
            return a[0] < b[0];
        }
        else
        {
            return a[1] > b[1];
        }
    }

    int solveOptimal(vector<int> &a)
    {
        if (a.size() == 0)
        {
            return 0;
        }

        vector<int> ans;
        int n = a.size();
        ans.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {

        sort(envelopes.begin(), envelopes.end(), compare);
        int n = envelopes.size();
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back(envelopes[i][1]);
            cout << envelopes[i][1];
        }
        return solveOptimal(arr);
    }
};