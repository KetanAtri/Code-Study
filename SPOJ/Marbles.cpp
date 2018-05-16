//question link - http://www.spoj.com/problems/SBANK/
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

ll nCr(int n, int r)
{
    ll ans = 1;
    if(r>n/2) r = n-r;
    f(q, 0, r){
        ans*=n;
        ans/=q+1;
        n--;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        //we have n-r free positions and r different coloured balls
        //the formula for filling 's' free positions with 'r' distinguish items the formula is r+s-1 C s
        //applying this with n-r as 's' and r as 'r' and simplifying we get n-1 C r-1
        cout<<nCr(n-1, r-1)<<endl;//, memory)<<endl;
    }
}

