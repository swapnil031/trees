#include<iostream>
using namespace std;
void heapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest])
        largest=l;
    if(r<n && a[r]>a[largest])
        largest=r;
    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void delete1(int a[],int n){
    a[0]=a[n-1];
    n=n-1;
    heapify(a,n,0);
}
void printarray(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main(){
    int a[]={10,5,3,2,4};
    int n=sizeof(a)/sizeof(int);
    delete1(a,n);
    printarray(a,n-1);
}