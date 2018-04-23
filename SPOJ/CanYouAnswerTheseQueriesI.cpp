// question link - http://www.spoj.com/problems/GSS1/
#include <bits/stdc++.h>
using namespace std;

#define f(q, a, b) for(int q = int(a); q<int(b); q++)
#define fb(q, a, b) for(int q = int(a); q>int(b); q--)
#define pb(v, x) v.push_back(x)
#define A first
#define B second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef map<int, int> mii;

//ifstream in("input");
//ofstream out("output");

// read string with spaces, string is a char array here
// scanf ("%[^\n]%*c", string)
#define sz 50007
vi given;
int n;

//Segment trees are used to answer the range queries
//the information stored for each range in Segment Tree includes:
//total - the sum of all the elements in the range
//prefix - the highest possible sum starting from the left edge of the range
//suffix - the highest possible sum starting from the right edge of the range
//best - the best sum possible in the entire range
struct SegmentTree { int total, prefix, suffix, best; };
SegmentTree tree[sz*4];

//function to combine the solutions of the left and right subtree
SegmentTree combine(SegmentTree left, SegmentTree right)
{
    SegmentTree ret;
    //total is calculated from left and right trees total
    ret.total = left.total + right.total;
    //prefix - max of(prefix of left, total of left + prefix of right)
    ret.prefix = max(left.prefix, left.total + right.prefix);
    //same logic as prefix
    ret.suffix = max(right.suffix, right.total + left.suffix);
    //best is either the best of left, right or combined (suffix of left + prefix of right)
    ret.best = max(left.suffix + right.prefix, max(left.best, right.best));
    return ret;
}

//function to build the tree
void build(int p, int a, int b)
{
    //edge case, everything is equal to the element at that index
    if(a==b)
        tree[p].best = tree[p].prefix = tree[p].suffix = tree[p].total = given[a];
    else{
        //construction from left and right subtree using the above function
        int l = p<<1;
        int r = (p<<1)+1;
        int mid = (a+b)/2;
        build(l, a, mid);
        build(r, mid+1, b);
        tree[p] = combine(tree[l], tree[r]);
    }
}

//function to answer the queries
SegmentTree query(int p, int a, int b, int x, int y)
{
    //if the current range is same as queried range
    if(a==x && b==y) return tree[p];
    int l = p<<1;
    int r = (p<<1)+1;
    int mid = (a+b)/2;
    //if the queries range is in the left half of current range
    if(y<=mid) return query(l, a, mid, x, y);
    //opposite of above condition
    if(x>mid) return query(r, mid+1, b, x, y);
    //the queried range is somewhere between the current range
    else return combine(query(l, a, mid, x, mid), query(r, mid+1, b, mid+1, y));
}

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    cin>>n;
    pb(given, -1);
    f(q, 0, n){
        int x;
        cin>>x;
        pb(given, x);
    }
    build(1, 1, n);
    int m;
    cin>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        cout<<query(1, 1, n, a, b).best<<endl;
    }
}

