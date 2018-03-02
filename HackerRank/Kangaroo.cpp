//question link https://www.hackerrank.com/challenges/kangaroo/problem

#include <bits/stdc++.h>
using namespace std;

#define f(q, a, b) for(int q = int(a); q<int(b); q++)
#define fb(q, a, b) for(int q = int(a); q>int(b); q--)
#define pb(v, x) v.push_back(x)
#define A first
#define B second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//ifstream in("input");
//ofstream out("output");

//a and c belong to jump and location of the earlier kangaroo respectively
string find_ans(int a, int b, int c, int d)
{
    //same starting location and same speed case
    if(a==b && c==d)
        return "YES";
    //if the speed is less then earlier kangaroo can never catch up
    if(a<=b)
        return "NO";
    double dist = d-c;
    double speed = a-b;
    double time = dist/speed;
    //time here will measure the jumps, if fractional then meeting is not possible
    if(int(time)==time)
        return "YES";
    return "NO";
}

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    pii k1, k2;
    cin>>k1.A>>k1.B>>k2.A>>k2.B;
    string ans = "";
    if(k1.A < k2.A)
        ans = find_ans(k1.B, k2.B, k1.A, k2.A);
    else
        ans = find_ans(k2.B, k1.B, k2.A, k1.A);
    cout<<ans<<endl;
}

