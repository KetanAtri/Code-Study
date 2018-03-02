/*
* Divide and conquer strategy is used, divide the array into two equal halves till single *
* element is reached. Merge these divisions while keeping ordering under consideration.   *
*/
#include <bits/stdc++.h>
using namespace std;

#define f(q, a, b) for(int q = int(a); q<int(b); q++)
#define fb(q, a, b) for(int q = int(a); q>int(b); q--)
#define pb(v, x) v.push_back(x)

typedef long long ll;
typedef unsigned long long ull;

//ifstream in("input");
//ofstream out("output");

void merge_(int* arr, int a, int b, int c, int d)
{
    //creating two arrays to represent the two halves being merged
    int left[(b-a)+1], right[(d-c)+1], left_index = 0, right_index = 0;
    f(q, a, b+1)
        left[left_index++] = arr[q];
    f(q, c, d+1)
        right[right_index++] = arr[q];
    int left_size = left_index, right_size = right_index, index = a;

    //merging the two arrays, till one is exhausted
    left_index = right_index = 0;
    while(left_index!=left_size && right_index!=right_size){
        if(left[left_index] <= right[right_index])
            arr[index++] = left[left_index++];
        else
            arr[index++] = right[right_index++];
    }

    //filling the remaining elements; taken from non-exhausted half
    if(left_index!=left_size){
        f(q, left_index, left_size)
            arr[index++] = left[q];
    }
    if(right_index!=right_size){
        f(q, right_index, right_size)
            arr[index++] = right[q];
    }
}

void mergeSort(int* arr, int a, int b)
{
    //termination condition, when single element is remaining
    if(a!=b){
        int mid = (a+b)/2;
        mergeSort(arr, a, mid);
        mergeSort(arr, mid+1, b);
        merge_(arr, a, mid, mid+1, b);
    }
}

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    //input
    int n;
    cin>>n;
    int arr[n];
    f(q, 0, n)
        cin>>arr[q];

    mergeSort(arr, 0, n-1);

    //output
    f(q, 0, n)
        cout<<arr[q]<<" ";
    cout<<endl;
}

