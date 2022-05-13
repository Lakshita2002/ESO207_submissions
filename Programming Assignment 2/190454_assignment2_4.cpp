#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N, M;
    cin >> N >> M;
    
    int A[N];
   
    
    for(long long int i=0; i<N; i++){
        long long int n;
        cin >> n;
        A[i]=n;
    }
    int arr[N];
    int tracker =0;
    for(long long int i=0;i<N;i++){
        if(A[i]==0){
            arr[tracker]=i;
            tracker++;
        }
    }
    
    int ans = 100008;
    
    for(int i=0; i+M < tracker; i++){
        int start = i;
        int end = i+M;
        int dist = -500;
        while(start <= end){
            int mid = start + (end-start)/2;
            int distLeft = arr[mid]-arr[i];
            int distright = arr[i+M]-arr[mid];
            dist = max(distLeft,distright);
        
            if(mid+1<=end && arr[mid+1]-arr[i]<dist){
                start = mid+1;
            }
            else if(mid-1>=start && arr[i+M]-arr[mid-1]<dist){
                end = mid-1;
            }
            else{
                break;
            }
        }
        ans = min(ans, dist);
    }
    
    cout<< ans <<endl;
    
    return 0;
}