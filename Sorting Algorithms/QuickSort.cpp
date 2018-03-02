/*
* Choose a pivot element, order the element around it. Repeat the procedure *
* on either sides of the pivot element to sort the entire array             *
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

int pivot_(int* arr, int low, int high)
{
    //first element is chosen as pivot
    int ele = arr[low], last_index = high-1, q = low+1;
    //q is the element which is one ahead of pivot
    //last_index is the last element (not swapped)
    while(q<=last_index){
        //if current element is smaller, bring pivot to the front
        if(arr[q]<=ele){
            swap(arr[q], arr[q-1]);
            q++;
        }
        //if present element is bigger, swap it with the last element
        else swap(arr[q], arr[last_index--]);
    }
    //return the pivot location
    return last_index;
}

void quickSort(int* arr, int low, int high)
{
    if(low<high){
        //get the pivot location
        int pivot = pivot_(arr, low, high);
        //apply recursion on the two halves created by pivot
        quickSort(arr, low, pivot);
        quickSort(arr, pivot+1, high);
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

    //processing
    quickSort(arr, 0, n);

    //output
    f(q, 0, n)
        cout<<arr[q]<<" ";
    cout<<endl;
}
