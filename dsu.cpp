struct DSU {
    vector<int> parent;
    vector<int> sz; // size of the component
    int num_components;

    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1); // Initially, every group has 1 element
        num_components = n;
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    // Find with Path Compression: O(alpha(N))
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    // Union by Size: O(alpha(N))
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            // Always attach the smaller tree to the larger one
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            num_components--;
            return true; // Successfully merged
        }
        return false; // Already in the same group
    }

    // Check if connected
    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    // Get size of the component containing i
    int size(int i) {
        return sz[find(i)];
    }
};
