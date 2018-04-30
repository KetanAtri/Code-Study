// question link - http://www.spoj.com/problems/HORRIBLE/
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

//segment tree is used to answer the range sum queries
struct SegmentTree
{
    //st is the values stored in the segment tree (sums of ranges)
    //lazy is used for lazy propagation of range update
    //n is the number of elements
    vector<ll> st, lazy;
    ll n;
    //an empty segment tree is created to store the range sum queries from 0 to a
    SegmentTree(ll a)
    {
        n = a;
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    //function to get the index of the left and right child of a given element
    ll left(ll a) { return a<<1; }
    ll right(ll a) { return (a<<1)+1; }

    //function to update the given range with the given value using lazy propagation
    void updateRange(ll index, ll start, ll end_, ll a, ll b, ll value)
    {
        //if the current node has pending updates
        if(lazy[index]!=0){
            //update the node
            st[index] += ((end_-start)+1)*lazy[index];
            //if the node has children, propagate the lazy updation to the children
            if(start!=end_){
                lazy[left(index)] += lazy[index];
                lazy[right(index)] += lazy[index];
            }
            lazy[index] = 0;
        }
        //if range of current node is outside the given range exit
        if(start>b || end_<a) return;
        //if the range of the current node is inside the given range
        if(start>=a && end_<=b){
            //update the node
            st[index] += ((end_-start)+1) * value;
            //if the node has children propagate the updation
            //to the lazy node of the children
            if(start!=end_){
                lazy[left(index)] += value;
                lazy[right(index)] += value;
            }
            return;
        }
        //if the given range lies inside the range of the current node
        ll mid = (start+end_)/2;
        //updateRange is called on children
        updateRange(left(index), start, mid, a, b, value);
        updateRange(right(index), mid+1, end_, a, b, value);
        //current node is updated with values obtained from children
        st[index] = st[left(index)] + st[right(index)];
    }
    //wrapper function to aid in function call inside main
    void updateRange(ll start, ll end_, ll value) { updateRange(1, 0, n-1, start, end_, value); }

    //function to answer the range sum queries
    ll sumRange(ll index, ll start, ll end_, ll a, ll b)
    {
        //if updation of the current node is pending
        //update the current node and propagate the updation to the children
        if(lazy[index]!=0){
            st[index] += ((end_-start)+1)*lazy[index];
            if(start!=end_){
                lazy[left(index)] += lazy[index];
                lazy[right(index)] += lazy[index];
            }
            lazy[index] = 0;
        }
        //if given range is outside current range
        if(start>b || end_<a) return 0;
        //if current range is inside given range
        if(start>=a && end_<=b) return st[index];
        //if given range is inside current range
        ll mid = (start+end_)/2;
        return sumRange(left(index), start, mid, a, b)+sumRange(right(index), mid+1, end_, a, b);
    }
    //wrapper function
    ll sumRange(ll start, ll end_) { return sumRange(1, 0, n-1, start, end_); }
};

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n, c;
        cin>>n>>c;
        //create a segment tree
        SegmentTree my_tree(n);
        ll command, start, end_;
        ll value;
        f(q, 0, c){
            cin>>command>>start>>end_;
            start--; end_--;
            //updation query
            if(command==0){
                cin>>value;
                my_tree.updateRange(start, end_, value);
            }
            //range sum query
            else{
                cout<<my_tree.sumRange(start, end_)<<endl;
            }
        }
    }
}

