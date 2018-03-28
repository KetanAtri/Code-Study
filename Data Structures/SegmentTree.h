#include <vector>

using std::vector;

inline int left(int i) { return i<<1; }
inline int right(int i) { return (i<<1)+1; }

class SegmentTree
{
    vector<int> st, A;
    int n;
    void build(int p, int L, int R)
    {
        if(L==R)
            st[p] = A[L];
        else{
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            int a = st[left(p)], b = st[right(p)];
            st[p] = a+b;
        }
    }
    int rsq(int p, int a, int b, int L, int R)
    {
        if(L>b || R<a) return -1;
        if(L>=a && R<=b) return st[p];
        int p1 = rsq(left(p), a, b, L, (L+R)/2);
        int p2 = rsq(right(p), a, b, (L+R)/2+1, R);
        if(p1==-1) return p2;
        if(p2==-1) return p1;
        return p1+p2;
    }
    public:
    SegmentTree(vector<int> &given)
    {
        n = given.size();
        A = given;
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int rsq(int x, int y) { return rsq(1, x, y, 0, n-1); }
};
