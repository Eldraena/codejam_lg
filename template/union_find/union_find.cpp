int dsu_find(vector<int>& parent, int k)
{
    int p = parent[k];
    while(p != parent[p])
    {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

bool dsu_union(int k1, int k2, vector<int>& parent, vector<int>& rank)
{
    int p1 = dsu_find(parent, k1), p2 = dsu_find(parent, k2);
    if(p1 == p2) return false;

    if(rank[p1] > rank[p2])
    {
        parent[p2] = p1;
        rank[p1] += rank[p2];
    }
    else
    {
        parent[p1] = p2;
        rank[p2] += rank[p1];
    }

    return true;
}
