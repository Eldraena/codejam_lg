#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
typedef long long ll;
 
int main() 
{
    fio;

    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        ll k; cin >> k;			
        vector<int> a(n, 0), b(n, 0);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
	 
        map<int, int> m;
        for(int i = 0; i < n; i++)
            m[a[i] - b[i]]++;

        vector<pair<int, int>> frq;
        for(auto p: m)
            frq.pb({p.first, p.second});
	 
		vector<int> prefix_sum(frq.size(), 0);
		prefix_sum[0] = frq[0].second;
		for(int i = 1; i < frq.size(); i++)
			prefix_sum[i] = prefix_sum[i - 1] + frq[i].second;
	 
        int l, r;
        l = 0, r = frq.back().first - frq.front().first;
		int j;
		while(l < r) 
		{
			ll cnt = 0;
			int mid = l + (r - l) / 2;
			j = 0;
			for(int i = 0; i < frq.size(); i++) 
			{
				cnt += frq[i].second * (frq[i].second - 1) / 2;
				if(cnt > k) break;
				
				while(j < frq.size() && frq[j].first - frq[i].first <= mid) 
					j++;				
				if(j >= frq.size() || frq[j].first - frq[i].first > mid)
					j--;
				
				cnt += (prefix_sum[j] - prefix_sum[i]) * frq[i].second;				
				if(cnt > k) break;
			}
			 
			if (cnt < k) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
	 
		ll cnt = 0;
		j = 0;
		for(int i = 0; i < frq.size(); i++) {
			cnt += frq[i].second * (frq[i].second - 1) / 2;
			if(cnt > k) break;
			
			while(j < frq.size() && frq[j].first - frq[i].first <= l) 
				j++;
			if(j >= frq.size() || frq[j].first - frq[i].first > l)
				j--;
			
			cnt += (prefix_sum[j] - prefix_sum[i]) * frq[i].second;
			if(cnt > k) break;
		}
	 
		int ans = -1;
		if(cnt == k) ans = l;
		cout << ans << '\n';
    }
  
    return 0;
}
