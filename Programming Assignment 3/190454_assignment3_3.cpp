#include <iostream>
using namespace std;

void heapify(long long int arr[], long long int n, long long int i){
    
    long long int largest = i; 
    long long int leftChild = 2*i + 1; 
    long long int rightChild = 2*i + 2; 
 
    // left child is larger than root
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;
 
    // right child is larger than largest so far
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;
 
    // largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


void buildHeap(long long int arr[], long long int n){
    
    long long int startId = (n / 2) - 1;
    for (long long int i = startId; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void deleteRoot(long long int arr[], long long int& n){
    
    long long int lastElement = arr[n - 1];
 
    arr[0] = lastElement;
    n = n - 1;
    buildHeap(arr, n);
}

void insert(long long int x, long long int arr[], long long int& curLen){
    
    long long int i = curLen;
    arr[i] = x;
    curLen++;
    while(i>0 && arr[i]>arr[(i-1)/2]){
        // swap
        long long int temp = arr[i];
        arr[i] = arr[(i-1)/2];
        arr[(i-1)/2] = temp;
        
        i = (i-1)/2;
    }
}

long long int minEl(long long int heap[], long long int n){
    
    long long int ans = heap[n/2];
 
    for (long long int i = 1 + n/2; i<n; ++i)
        ans = min(ans, heap[i]);
 
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long int q;
    cin >> q;
    
    long long int curLen = 0;
    
    long long int arr[q];
    buildHeap(arr, curLen);
    
    for(long long int i=0; i<q; i++){
        long long int op;
        cin >> op;
        
        if(op == 1){
            // inserting an element in the maxheap
            long long int el;
            cin >> el;
            
            insert(el, arr, curLen);
        }
        else if(op == 2){
            // deleting the most expensive element in the maxheap
            if(curLen != 0){
                deleteRoot(arr, curLen);
            }
        }
        else if(op == 3){
            // reporting the difference between the maximum and the minimum element in the maxheap
            if(curLen == 0){
                cout << -1 << endl;
            }
            else{
                cout << arr[0]-minEl(arr, curLen) << endl;
            }
            
        }
    }
    
    return 0;
}