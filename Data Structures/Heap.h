#include <vector>
#include <stdio.h>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

inline int left(int i) { return i<<1; }
inline int right(int i) { return (i<<1)+1; }
inline int parent(int i) { return (i>>1); }

struct Heap
{
    vector<int> heap;
    int heap_size;
    Heap(int a)
    {
        heap_size = 0;
        heap.assign(a+1, -INT_MAX);
    }
    Heap(vector<int> &A)
    {
        heap.assign(A.size()+1, 0);
        heap_size = A.size();
        for(int q=0; q!=A.size(); q++)
            heap[q+1] = A[q];
        for(int q=heap.size()/2; q!=0; q--)
            max_heapify(q);
    }
    void display()
    {
        for(int q=1; q!=heap_size+1; q++) cout<<heap[q]<<" ";
        cout<<endl;
    }
    void max_heapify(int el)
    {
        int l = left(el), r = right(el);
        int largest = el;
        if(l<=heap_size && heap[l]>heap[largest]) largest = l;
        if(r<=heap_size && heap[r]>heap[largest]) largest = r;
        if(largest!=el){
            swap(heap[largest], heap[el]);
            max_heapify(largest);
        }
    }
    int extractMax()
    {
        int ret = heap[1];
        heap[1] = heap[heap_size];
        heap_size--;
        max_heapify(1);
        return ret;
    }
    void updateKey(int index, int value)
    {
        heap[index] = value;
        while(index>1 && heap[parent(index)]<heap[index]){
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    void insertVal(int value)
    {
        heap_size++;
        heap[heap_size] = -INT_MAX;
        updateKey(heap_size, value);
    }
    void deleteKey(int index)
    {
        heap[index] = heap[heap_size];
        heap[heap_size] = -INT_MAX;
        heap_size--;
    }
};


