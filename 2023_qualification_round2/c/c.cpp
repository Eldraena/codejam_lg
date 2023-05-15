#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)

const int MAX_NMQ = 100001;

struct segment_tree
{
    vector<int> dt;
    vector<int> tree;
    
    void init()
    {
        dt.assign(MAX_NMQ, 0);
        tree.assign(MAX_NMQ * 4, 0);
    }
    
    void update(int w, int val)
    {
        int start = 1;
        int end = dt.size() - 1;
        int idx = 1;
        
        while(true)
        {
            int mid = (start + end) / 2;
            tree[idx] += val;
            
            if(start == end)
                break;
            
            if (w <= mid)
            {
                idx = 2 * idx;
                end = mid;
            }
            else
            {
                idx = 2 * idx + 1;
                start = mid + 1;                
            }
        }
    }
    
    int query(int w)
    {
        int result = 0;
        int start = 1;
        int end = dt.size() - 1;
        int idx = 1;
        
        while(true)
        {
            int mid = (start + end) / 2;
 
            if(start == end)
                break;
 
            if (w <= mid)
            {
                idx = 2 * idx;
                end = mid;
            }
            else
            {
                result += tree[2 * idx];
                idx = 2 * idx + 1;
                start = mid + 1;
            }
        }
 
        return tree[1] - result;
    }
};

int main()
{
    fio;
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        
        vector<pair<int, pair<int, int>>> block_and_sheet;
        vector<pair<int,int>> question(q);
        segment_tree segtree;
        for(int i = 0; i < n; i++)
        {
            pair<int, int> tmp_block;
            cin >> tmp_block.first >> tmp_block.second;
            block_and_sheet.push_back({0, tmp_block});
        }
        
        segtree.init();
        for(int i = 0; i < m; i++)
        {
            pair<int, int> tmp_sheet;
            cin >> tmp_sheet.first >> tmp_sheet.second;
            block_and_sheet.push_back({1, tmp_sheet});
            segtree.dt[tmp_sheet.first]++;
            segtree.update(tmp_sheet.first, 1);
        }
        
        sort(block_and_sheet.begin(), block_and_sheet.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
        {
            if(a.second.second != b.second.second)
                return a.second.second < b. second.second;
            else
                return a.first < b.first;
        });
        
        vector<int> cover(m + 1, 0);
        for(auto x: block_and_sheet)
        {
            if(x.first == 0)
            {
                int num_sheet = segtree.query(x.second.first);
                cover[num_sheet]++;
            }
            else
                segtree.update(x.second.first, -1);
        }

        vector<int> prefix_sum(m + 1, 0);
        prefix_sum[0] = cover[0];
        for(int i = 1; i <= m; i++)
            prefix_sum[i] = prefix_sum[i - 1] + cover[i];
           
        for(int i = 0; i < q; i++)
        {
            int l, u;
            cin >> l >> u;
            cout << prefix_sum[u] - prefix_sum[l] + cover[l] << " ";
        }
        cout << endl;
    }
    return 0;
}
