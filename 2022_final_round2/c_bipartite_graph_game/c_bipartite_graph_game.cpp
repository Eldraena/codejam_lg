#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
typedef long long ll;

int main()
{
    fio;
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> v, _v, w, _w;
        vector<pair<int, int>> edge;
        vector<int> minv, minw;
        
        for(int i = 0; i <= n; i++)
            v.push_back(0);        
        for(int i = 0; i <= m; i++)
            w.push_back(0);
        
        edge.assign(k + 5, pair{-1, -1});       
        for(int i = 1; i <= k; i++)
        {
            cin >> edge[i].first >> edge[i].second;
            v[edge[i].first]++;
            w[edge[i].second]++;
        }
        
        pair<ll, ll> max_score = {0, 0};
        _v = v, _w = w;
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        
        minv.assign(n + 5, n);
        minw.assign(m + 5, m);
        for(int i = 1; i <= n; i++)
        {
            max_score.first += i * v[i];
            if(minv[v[i]] > i)
                minv[v[i]] = i;
        }
        for(int i = 1; i <= m; i++)
        {
            max_score.first += i * w[i];
            if(minw[w[i]] > i)
                minw[w[i]] = i;            
        }
        for(int i = 1; i <= k; i++)
        {
            int num_edge_v =  _v[edge[i].first];
            int num_edge_w =  _w[edge[i].second];
            int tmp = max_score.first - minv[num_edge_v] - minw[num_edge_w];
            if(tmp > max_score.second)
                max_score.second = tmp;
        }          
        cout << max_score.first << " " << max_score.second << endl;
    }
  
    return 0;
}
