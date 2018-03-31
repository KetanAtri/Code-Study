//question link - http://www.spoj.com/problems/EDIST/
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

//DP solution
//bottom-up construction
int findAns(string &s1, string &s2)
{
    int m = s1.size(), n = s2.size();
    int dp[m+1][n+1];
    f(q, 0, m+1)
        f(w, 0, n+1){
            //if the first string is empty
            //the answer is the length of the second string
            if(q==0)
                dp[q][w] = w;
            //if the second string is empty
            //the anser is the length of the first string
            else if(w==0)
                dp[q][w] = q;
            //if the last elements are the same
            //the answer is the same as construction of penultimate letters
            else if(s1[q-1]==s2[w-1])
                dp[q][w] = dp[q-1][w-1];
            //otherwise chose the option with minimum cost
            //dp[q][w-1] - Insertion
            //dp[q-1][w] - Deletion
            //dp[q-1][w-1] - Replacement
            else
                dp[q][w] = 1 + min(dp[q][w-1], min(dp[q-1][w], dp[q-1][w-1]));
        }
    return dp[m][n];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        cout<<findAns(s1, s2)<<endl;
    }
}

