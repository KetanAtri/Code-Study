// question link - http://www.spoj.com/problems/AIBOHP/
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

//s1 is the given string, s2 is the reverse
string s1, s2;
int memory[6110][6110];

//function to find length of LCS using DP
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
        //initializing memory
        f(q, 0, 6110)
            f(w, 0, 6110){
                //this is the trivial case the LCS
                // for an empty string and any sting is of 0 length
                if(q==0 || w==0) memory[q][w] = 0;
                //the non calculated values are sotred as -1
                else memory[q][w] = -1;
            }
        cin>>s1;
        s2 = s1;
        reverse(s2.begin(), s2.end());
        //val is the length of LCS of given string and its reverse
        int val = LCS(s1.size(), s1.size());
        //the difference in the length and length
        //of LCS is the number of characters that need to be added
        cout<<s1.size() - val<<endl;
    }
}

