#include <vector>

#define f(q, a, b) for(int q=int(a); q!=int(b); q++)

typedef std::vector<int> vi;

class UFDS
{
    vi parent, rank;
    public:
    UFDS(int N)
    {
        rank.assign(N, 0);
        parent.assign(N, 0);
        f(q, 0, N) parent[q] = q;
    }
    int findSet(int x) { return parent[x]==x? x: (parent[x] = findSet(parent[x])); }
    bool isSameSet(int x, int y) { return findSet(x)==findSet(y); }
    void unionSet(int x, int y)
    {
        if(!isSameSet(x, y)){
            int a = findSet(x);
            int b = findSet(y);
            if(rank[a]>rank[b]) parent[b] = a;
            else{
                parent[a] = b;
                if(rank[a]==rank[b]) rank[b]++;
            }
        }
    }
}


