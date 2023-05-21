#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_NMQ = 50005;

using namespace std;

int main()
{
    fio;
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<pair<int, int>> block(MAX_NMQ, {-1, -1}), sheet(MAX_NMQ, {-1, -1}), question(MAX_NMQ, {-1, -1});
        vector<pair<int, pair<int, int>>> block_and_sheet;
        ordered_set<pair<int, int>> ordered_set;
        
        for(int i = 0; i < n; i++)
        {
            cin >> block[i].first >> block[i].second;
            block_and_sheet.push_back({0, {block[i].first, block[i].second}});
        }
        for(int i = 0; i < m; i++)
        {
            cin >> sheet[i].first >> sheet[i].second;
            block_and_sheet.push_back({1, {sheet[i].first, sheet[i].second}});
        }
            
        sort(block_and_sheet.begin(), block_and_sheet.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
        {
            if(a.second.second == b.second.second)
                return a.first < b.first;
            else
                return a.second.second < b.second.second;
        });
        
        vector<int> count(m + 1, 0);
        int block_sheet_size = block_and_sheet.size();
        for(int i = block_sheet_size - 1; i >= 0; i--)
        {
            if(block_and_sheet[i].first == 1)
                ordered_set.insert({block_and_sheet[i].second.first, i});
            else
            {
                int cnt = ordered_set.size() - ordered_set.order_of_key({block_and_sheet[i].second.first, -1});
                count[cnt]++;
            }
        }
        
        vector<int> prefix_sum(m + 1, 0);
        prefix_sum[0] = count[0];
        for(int i = 1; i <= m; i++)
            prefix_sum[i] = prefix_sum[i - 1] + count[i];
        for(int i = 0; i < q; i++)
        {
            int q1, q2;
            cin >> q1 >> q2;
            cout << prefix_sum[q2] - prefix_sum[q1] + count[q1] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
