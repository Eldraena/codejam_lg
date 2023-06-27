#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define ll long long

struct node
{
    int id;
    int val;
    int parent;
    vector<int> children;
    vector<ll> max_sum;
    
    node(int _val, int _parent, vector<int> _children, vector<ll> _max_sum)
    {
        val = _val;
        parent = _parent;
        children = _children;
        max_sum = _max_sum;
    }
    
    void show()
    {
        cout << "********" << endl;
        cout << "This is the data of node " << id << "\n";
        cout << "val: "  << val << "\n";
        cout << "parent: " << parent << "\n";
        cout << "children: ";
        for(int i = 0; i < children.size(); i++)
        {
            cout << children[i] << " ";
        }
        cout << "\n";
        cout << "max_sum: " << max_sum[0] << " " << max_sum[1] << "\n";
        cout << "********" << endl;
    }
};

vector<node> tree;

void init(int n)
{
  tree.clear();
  tree.assign(n + 5, {0, -1, {}, {0LL, 0LL}});
}

void find_subset(int u)
{
    if(tree[u].children.size() == 0)
    {
        tree[u].max_sum[0] = 0LL;
        tree[u].max_sum[1] = tree[u].val;
        return;
    }
    
    tree[u].max_sum[1] = tree[u].val;
    for(int i = 0; i < tree[u].children.size(); i++)
    {
        find_subset(tree[u].children[i]);
        tree[u].max_sum[1] += tree[tree[u].children[i]].max_sum[0];
    }
    
    tree[u].max_sum[0] = -10e13;
    for (int i = 0; i < (1 << tree[u].children.size()); i++) 
    {
        ll tmp_max = 0;
        for(int j = 0; j < tree[u].children.size(); j++) 
        {
            if(i != 0)
            {
                int idx = (i >> j) & 1;
                tmp_max += tree[tree[u].children[j]].max_sum[idx];
            }
        }
        
        if(i != 0 && tree[u].max_sum[0] < tmp_max)
        {
            tree[u].max_sum[0] = tmp_max;
        }
    }
}

int main()
{
    fio;
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        init(n);
        
        for(int i = 1; i <= n; i++)
        {
            cin >> tree[i].val;
            tree[i].id = i;
        }
        
        int root = 1;
        for(int i = 1; i <= n; i++)
        {
            cin >> tree[i].parent;
            tree[tree[i].parent].children.push_back(i);
            if(tree[i].parent == 0)
            {
                root = i;
            }
        }

        find_subset(root); 
/*        
        for(int i = 1; i <= n; i++)
        {
            tree[i].show();
        }
*/
        cout << max(tree[root].max_sum[0], tree[root].max_sum[1]) << "\n";
    }

    return 0;
}
