//question link https://www.hackerrank.com/challenges/between-two-sets/problem
#include <bits/stdc++.h>
using namespace std;

//make sure to use this template

#define f(q, a, b) for(int q = int(a); q<int(b); q++)
#define fb(q, a, b) for(int q = int(a); q>int(b); q--)
#define pb(v, x) v.push_back(x)
#define A first
#define B second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

//ifstream in("input");
//ofstream out("output");

//finding the gcd between two numbers
//using Euclid's algorithm
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

//finding the gcd of array of elements
int GCDarray(vi arr)
{
    int n = arr.size();
    int gcd_ = arr[0];
    //find gcd between consecutive elements
    f(q, 1, n)
        gcd_ = gcd_<=arr[q]? gcd(gcd_, arr[q]): gcd(arr[q], gcd_);
    return gcd_;
}

//finding the LCM of two numbers
int LCM(int a, int b)
{
    int num = a*b;
    int den = a<=b? gcd(a, b): gcd(b, a);
    return num/den;
}

//finding the LCM of an array of elements
int LCMarray(vi arr)
{
    int ans = arr[0];
    int n = arr.size();
    //find LCM between consecutive elements
    f(q, 1, n)
        ans = LCM(ans, arr[q]);
    return ans;
}

/*
* the x value can only exist between the range LCM(arr1) and GCD(arr2) *
* so we find the two values, then we check how many multiples of       *
* LCM(arr1) are factors of GCD(arr2), since the constraints are small  *
* this logic can be implemented using brute force                      *
*/
int getTotalX(vi a, vi b)
{
    int ans = 0;
    int start = LCMarray(a);
    //start_copy is for generating multiples of start
    int end_ = GCDarray(b), start_copy = start;
    while(start<=end_){
        if(end_%start==0)
            ans++;
        //go to next multiple of start
        start+=start_copy;
    }
    return ans;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
