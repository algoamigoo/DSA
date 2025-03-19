
vi parent, dsuRank, sizee;

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

void Union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;

    if (dsuRank[px] < dsuRank[py]) swap(px, py);
    parent[py] = px;
    sizee[px] += sizee[py];
    if (dsuRank[px] == dsuRank[py]) dsuRank[px]++;
}

in main function
parent.resize(n + 1);
    dsuRank.resize(n + 1, 0);
    sizee.resize(n + 1, 1); 

    fo(i, n + 1) parent[i] = i;
