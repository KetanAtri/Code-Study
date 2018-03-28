//question link http://www.spoj.com/problems/INVCNT/
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

ll counter = 0;

void merger(int* arr, int a, int b, int c, int d)
{
    int left[(b-a)+1], right[(d-c)+1];
    int left_index = 0, right_index = 0;
    f(q, a, b+1)
        left[left_index++] = arr[q];
    f(q, c, d+1)
        right[right_index++] = arr[q];

    int left_size = left_index, right_size = right_index;
    int counter2 = 0;
    left_index = right_index = 0;
    int index = a;

    while(left_index!=left_size && right_index!=right_size){
        if(left[left_index] <= right[right_index])
            arr[index++] = left[left_index++];
        else{
            //this modification on merge sort algorithm counts the inversions
            //if an element is picked from right half, the remaining left half elements are
            //added to the number of inversions
            counter+=(left_size-left_index);
            arr[index++] = right[right_index++];
        }
    }
    if(left_index!=left_size){
        f(q, left_index, left_size)
            arr[index++] = left[q];
    }
    if(right_index!=right_size){
        f(q, right_index, right_size)
            arr[index++] = right[q];
    }

}

void countInversion(int* arr, int start, int end_)
{
    if(start<end_){
        int mid = (start+end_)/2;
        countInversion(arr, start, mid);
        countInversion(arr, mid+1, end_);
        merger(arr, start, mid, mid+1, end_);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        f(q, 0, n) cin>>arr[q];
        countInversion(arr, 0, n-1);
        cout<<counter<<endl;
        counter = 0;
    }
}

