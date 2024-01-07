struct fenwick
{
    int n;
    vector<int> fn;

    void init(int n)
    {
        this->n = n + 1;
        fn.resize(this->n, 0);
    }

    void update(int index, int value)
    {
        index++;
        while (index < n)
        {
            //sum [0-index]
            fn[index] += value;
            //min [0-index]
            //fn[index] = min(fn[index], value);
            //max [0-index]
            //fn[index] = max(fn[index], value);
            index += (index & (-index));
        }
    }

    int query(int index)
    {
        index++;
        int ans = 0;
        while(index)
        {
            //sum [0-index]
            ans += fn[index];
            //min [0-index]
            //ans = min(ans, fn[index]);
            //max [0-index]
            //ans = max(ans, fn[index]);
            index -= (index & (-index));
        }
        return ans;
    }

    int sum(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};
