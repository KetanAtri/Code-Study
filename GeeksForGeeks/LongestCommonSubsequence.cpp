// question link - https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
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

string s1, s2;
int memory[110][110];

//a DP based solution
int LCS(int a, int b)
{
    //if the solution has been computed
    if(memory[a][b]!=-1) return memory[a][b];
    //if the last elements are same then LCS(a, b) = 1 + LCS(a-1, b-1)
    if(s1[a-1]==s2[b-1]) memory[a][b] = 1 + LCS(a-1, b-1);
    //if last elements are not same LCS(a, b) = max(LCS(a-1, b), LCS(a, b-1))
    else memory[a][b] = max(LCS(a-1, b), LCS(a, b-1));
    return memory[a][b];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        //filling the memory
        f(q, 0, 110)
            f(w, 0, 110){
                //this is the trivial case the LCS
                // for an empty string and any sting is of 0 length
                if(q==0 || w==0) memory[q][w] = 0;
                //the non calculated values are sotred as -1
                else memory[q][w] = -1;
            }
        int n, m;
        cin>>n>>m>>s1>>s2;
        cout<<LCS(n, m)<<endl;
    }
}

