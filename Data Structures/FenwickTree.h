#include <vector>

using std::vector;

inline int LSOne(int i) { return (i & (-i)); }

struct FenwickTree
{
    vector<int> ft;
    FenwickTree(int n) { ft.assign(n+1, 0); }
    int rsq(int a)
    {
        int sum = 0;
        for(; a; a-=LSOne(a)) sum+=ft[a];
        return sum;
    }
    int update(int index, int val)
    {
        for(; index<ft.size(); index+=LSOne(index))
            ft[index]+=val;
    }
    int rsq(int a, int b)
    {
        return rsq(b) - rsq(a-1);
    }
};
