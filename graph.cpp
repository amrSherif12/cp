// In a complete graph (clique) with V vertices, the number of edges E must be exactly: V * (V - 1) / 2


// when making an edge struct for weighted graph u can define an opperator to be able to use the struct in pq
struct Edge {
    int u, v, c;

    bool operator>(const Edge &other) const {
        return c > other.c;
    }
};


// function for getting 2nd MST

int mst(int n, map<int, vii> &adj, int bu, int bv, vector<Edge> &edges, bool sve) {
    int tot = 0;
    vb vis(n + 1, false);
    int edg = 0;
    priority_queue<Edge, vector<Edge>, greater<> > pq;
    pq.emplace(-1, 1, 0);
    while (!pq.empty()) {
        auto [u, v, c] = pq.top();
        pq.pop();
        if (vis[v]) continue;
        vis[v] = true;
        tot += c;
        edg++;
        if (sve && u != -1) edges.emplace_back(u, v, c);
        for (auto [nc, na]: adj[v]) {
            if ((v == bu && na == bv) || (na == bu && v == bv)) continue;
            if (!vis[na]) {
                pq.emplace(v, na, nc);
            }
        }
    }
    return edg == n ? tot : INT_MAX;
}
