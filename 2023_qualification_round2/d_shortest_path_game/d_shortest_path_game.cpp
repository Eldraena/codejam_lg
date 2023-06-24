#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
const ll INF = 10e9 + 7;

vector<vector<ll>> dist;

void init(int N)
{
    dist.assign(N + 5, vector<ll>(N + 5, INF));
    
    for(int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;  
    }
}

ll floyd_warshall(int N)
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = i + 1; j <= N; j++)
            {
                if(dist[i][k] == INF || dist[k][j] == INF)
                {
                    continue;
                }
                
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][j];
                }
            }
        }
    }
    
    ll sum = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = i + 1; j <= N; j++)
        {
            if(dist[i][j] != INF)
            {
                sum += dist[i][j];
            }
        }
    }
    
    return sum;
}

ll update(int v1, int v2, int d, int N)
{
    ll res = 0;
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = i + 1; j <= N; j++)
        {
            ll new_dist, new_dist1, new_dist2;

            if(dist[i][v1] != INF && dist[v2][j] != INF)
            {
                new_dist1 = dist[i][v1] + d + dist[v2][j];
                
                if(dist[i][j] > new_dist1)
                {
                    dist[i][j] = new_dist1;
                    dist[j][i] = dist[i][j];
                }
            }
            
            if(dist[i][v2] != INF && dist[v1][j] != INF)
            {
                new_dist2 = dist[i][v2] + d + dist[v1][j];
                
                if(dist[i][j] > new_dist2)
                {
                    dist[i][j] = new_dist2;
                    dist[j][i] = dist[i][j];
                }
            }
            
            if(dist[i][j] != INF)
            {
                res += dist[i][j];
            }
            
        }
    }
    
    return res;
}

int main()
{
    fio;
    
    int T;
    cin >> T;
    
    for(int tc = 0; tc < T; tc++)
    {
        int N, M, Q;
        cin >> N >> M >> Q;
        
        init(N);
        
        for(int i = 0; i < M; i++)
        {
            int v1, v2;
            ll d;
            cin >> v1 >> v2 >> d;
            if(d < dist[v1][v2])
            {
                dist[v1][v2] = d;
                dist[v2][v1] = d;
            }
        }
        
        ll first_sum = floyd_warshall(N);
        stack<ll> st;
        stack<vector<vector<ll>>> st_dist;

        st.push(first_sum);
        st_dist.push(dist);
        
        for(int u = 0; u < Q; u++)
        {
            int q;
            cin >> q;
            if(q == 1)
            {
                cout << st.top() << " ";
            }
            else if(q == 2)
            {
                int v1, v2;
                ll d;
                cin >> v1 >> v2 >> d;
                
                ll new_sum = st.top();
                vector<vector<ll>> tmp = st_dist.top();
                
                for(int i = 1; i <= N; i++)
                {
                    for(int j = 1; j <= N; j++)
                    {
                        dist[i][j] = tmp[i][j];
                    }
                }
                
                if(d < dist[v1][v2])
                {
                    new_sum = update(v1, v2, d, N);
                }
                
                st.push(new_sum);
                st_dist.push(dist);
            }
            else if(q == 3)
            {
                if(st.size() > 1)
                {
                    st.pop();
                    st_dist.pop();
                }
            } 
        }
        
        cout << "\n"; 
    }

    return 0;
}
