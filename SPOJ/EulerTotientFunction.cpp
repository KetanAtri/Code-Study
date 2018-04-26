// question link - http://www.spoj.com/problems/ETF/
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

//function to find the prime factors of a given number
//this uses the division method runs in O(sqrt(n))
void find_prime_fac(mii &prime_fac, int n)
{
    while(n%2==0){
        prime_fac[2]++;
        n/=2;
    }
    for(int q=3; q<=sqrt(n); q+=2)
        while(n%q==0){
            prime_fac[q]++;
            n/=q;
        }
    if(n>2)
        prime_fac[n]++;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        mii prime_fac;
        int n;
        cin>>n;
        find_prime_fac(prime_fac, n);
        double ans = double(n);
        //the answer is found using the euler product formula
        for(mii::iterator iter=prime_fac.begin(); iter!=prime_fac.end(); iter++)
            ans = ans * (1-(1/double(iter->first)));
        cout<<ans<<endl;
    }
}

