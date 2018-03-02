/*
* Start from second element, keep swapping it back till a smaller element is reached. *
* The process is repeated for the remaining elements as well to sort the entire array *
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

int main()
{
    //input
    int n;
    cin>>n;
    int arr[n];
    f(q, 0, n)
        cin>>arr[q];

    //insertion sort
    f(q, 1, n){
        //key stores the element whose position is currently being changed
        int key = arr[q], index = q-1;
        //push the previous element ahead if it is smaller than key
        while(arr[index]>key && index>-1){
            arr[index+1] = arr[index];
            index--;
        }
        //index stores the element which was smaller than key (-1 if no element is smaller)
        //since item at index+1 is also present at index+2, this does not lead to loss of element
        arr[index+1] = key;
    }

    //output
    f(q, 0, n)
        cout<<arr[q]<<" ";
    cout<<endl;
}

