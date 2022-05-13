#include <iostream>
using namespace std;

void merge(long long int array[], long long int left, long long int mid, long long int right){
    
    long long int subArr1 = mid-left+1;
    long long int subArr2 = right-mid;
  
    long long int *lArr = new long long int[subArr1];
    long long int *rArr = new long long int[subArr2];
  
    for (long long int i=0; i<subArr1; i++){
        lArr[i] = array[left+i];
    }
    
    for (long long int j=0; j<subArr2; j++){
        rArr[j] = array[mid+1+j];
    }
        
    long long int iSubArr1 = 0;
    long long int iSubArr2 = 0;
    long long int iMergedArr = left; 

    while (iSubArr1<subArr1 and iSubArr2<subArr2) {
        if(lArr[iSubArr1]<=rArr[iSubArr2]) {
            array[iMergedArr] = lArr[iSubArr1];
            iSubArr1++;
        }
        else{
            array[iMergedArr] = rArr[iSubArr2];
            iSubArr2++;
        }
        iMergedArr++;
    }
    
    while (iSubArr1<subArr1) {
        array[iMergedArr] = lArr[iSubArr1];
        iSubArr1++;
        iMergedArr++;
    }
    
    while (iSubArr2<subArr2) {
        array[iMergedArr] = rArr[iSubArr2];
        iSubArr2++;
        iMergedArr++;
    }
}
  
void mergeSort(long long int array[], long long int begin, long long int end){
    
    if (begin>=end){
        return; 
    }
  
    long long int mid = begin + (end-begin)/2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long int N;
    cin >> N;
    long long int v[N];
    for(long long int i=0; i<N; i++){
        long long int a;
        cin >> a;
        v[i] = a;
    }
    
    long long int visited[N];
    long long int index = N/2-1;
    
    mergeSort(v, 0, N-1);
    long long int count = 0;
    
    for(long long int i=N-1; i>0; i--){
        if(visited[i]!=-1){
            for(long long int j=index; j>=0; j--){
                if(v[j]<=v[i]/2){
                    visited[j] = -1;
                    index = j-1;
                    count++; 
                    break; 
                }
            }
        }
    }
    
    long long int ans = N-count;
    cout << ans;
    
    return 0;
}