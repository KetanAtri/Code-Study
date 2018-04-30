#include <vector>

using std::vector;

inline int left(int i) { return i<<1; }
inline int right(int i) { return (i<<1)+1; }

class SegmentTree
{
    vector<int> st, A, lazy;
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
    void rangeUpdate(int index, int start, int end_, int a, int b, int value)
    {
        if(lazy[index]){
            st[index] += ((end_-start)+1)*value;
            if(start!=end_){
                lazy[left(index)] += lazy[index];
                lazy[right(index)] += lazy[index];
            }
            lazy[index] = 0;
        }
        if(start>b || end_<a) return;
        if(start>=a && end_<=b){
            st[index]+=((end_-start)+1)*value;
            if(start!=end_){
                lazy[left(index)]+=value;
                lazy[right(index)]+=value;
            }
            return;
        }
        int mid = (start+end_)/2;
        rangeUpdate(left(index), start, mid, a, b, value);
        rangeUpdate(right(index), mid+1, end_, a, b, value);
        st[index] = st[left(index)] + st[right(index)];
    }
    int rangeSum(int index, int start, int end_, int a, int b)
    {
        if(lazy[index]){
            st[index] += ((end_-start)+1)*lazy[index];
            if(start!=end_){
                lazy[left(index)] += lazy[index];
                lazy[right(index)] += lazy[index];
            }
            lazy[index] = 0;
        }
        if(start>b || end_<a) return 0;
        if(start>=a && end_<=b) return st[index];
        int mid = (start+end_)/2;
        return rangeSum(left(index), start, mid, a, b) + rangeSum(right(index), mid+1, end_, a, b);
    }
    public:
    SegmentTree(vector<int> &given)
    {
        n = given.size();
        A = given;
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int rangeSum(int a, int b) { return rangeSum(1, 0, n-1, a, b); }
    void rangeUpdate(int a, int b, int value){ return rangeUpdate(1, 0, n-1, a, b, value); }
};
