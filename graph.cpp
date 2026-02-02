// In a complete graph (clique) with V vertices, the number of edges E must be exactly: V * (V - 1) / 2


// when making an edge struct for weighted graph u can define an opperator to be able to use the struct in pq
struct Edge {
    int u, v, c;

    bool operator>(const Edge &other) const {
        return c > other.c;
    }
};
