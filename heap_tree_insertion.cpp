#include<iostream>
using namespace std;
#define max 100
void heapify(int a[],int n,int i){
    int parent=(i-1)/2;
    if(parent>=0){
        if(a[i]>a[parent]){
           swap(a[i],a[parent]);
           heapify(a,n,parent);
        }
    }
}
void insert(int a[],int n,int value){
    n=n+1;
    a[n-1]=value;
    heapify(a,n,n-1);
}
void printarray(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main(){
    int a[]={10,5,3,2,4};
    int n=sizeof(a)/sizeof(int);
    int value=15;
    insert(a,n,value);
    printarray(a,n+1);
}


/*#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    // Get the parent index of a node
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Heapify Up operation to maintain the max heap property after insertion
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

public:
    // Function to insert a new element into the heap
    void insert(int value) {
        heap.push_back(value); // Inserting the new element at the end
        int index = heap.size() - 1;
        heapifyUp(index); // Restore heap property upwards
    }

    // Function to print the elements of the heap
    void printHeap() {
        std::cout << "Max Heap: ";
        for (int i = 0; i < heap.size(); ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;
    
    // Insert elements into the heap
    maxHeap.insert(12);
    maxHeap.insert(7);
    maxHeap.insert(6);
    maxHeap.insert(10);
    maxHeap.insert(8);
    maxHeap.insert(20);

    maxHeap.printHeap(); // Print the heap after insertions

    return 0;
}
*/