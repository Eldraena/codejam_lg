#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)

int main()
{
    fio;
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        
        vector<int> pic(n + 1, 0);
        vector<vector<int>> rub(n + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++)
        {
            int scr, l, r;
            cin >> scr >> l >> r;
            rub[l][r] += scr;
        }
        
        for(int i = 1; i <= n; i++)
            pic[i] = i;
            
        int mscr = -1, cnt = 0;
        do 
        {
            int scr = 0;
            for(int i = 1; i < n; i++)
            {
                for(int j = i + 1; j <= n; j++)
                {
                    int l, r;
                    l = pic[i], r = pic[j];
                    scr += rub[l][r];
                }
            }
            
            if(mscr < scr)
            {
                mscr = scr;
                cnt = 1;
            }
            else if(mscr == scr)
                cnt++;
        } while(next_permutation(pic.begin() + 1, pic.end()));
        
        cout << mscr << " " << cnt << endl;
    }
    
    return 0;
}
