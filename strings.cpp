// suffix array and lcp

struct Suffix {
    int index;
    int rank[2];
};

bool compare(const Suffix &a, const Suffix &b) {
    if (a.rank[0] == b.rank[0]) return a.rank[1] < b.rank[1];
    return a.rank[0] < b.rank[0];
}

struct SuffixArrayResult {
    vector<int> sa;
    vector<int> lcp;
};

SuffixArrayResult buildSA(string s) {
    int n = s.length();
    vector<Suffix> suffixes(n);

    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = s[i];
        suffixes[i].rank[1] = (i + 1 < n) ? s[i + 1] : -1;
    }

    sort(suffixes.begin(), suffixes.end(), compare);

    vector<int> ind(n);
    for (int k = 4; k < 2 * n; k *= 2) {
        int rank = 0;
        int prev_rank0 = suffixes[0].rank[0];
        suffixes[0].rank[0] = 0;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prev_rank0 && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank0 = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
        for (int i = 0; i < n; i++) {
            int next_index = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (next_index < n) ? suffixes[ind[next_index]].rank[0] : -1;
        }
        sort(suffixes.begin(), suffixes.end(), compare);
    }

    vector<int> sa(n);
    for (int i = 0; i < n; i++) sa[i] = suffixes[i].index;

    vector<int> lcp(n, 0);
    vector<int> invSA(n, 0);
    for (int i = 0; i < n; i++) invSA[sa[i]] = i;

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (invSA[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[invSA[i] + 1]; 
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[invSA[i] + 1] = k;
        if (k > 0) k--;
    }

    return {sa, lcp};
}
