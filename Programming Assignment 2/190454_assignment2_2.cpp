#include <iostream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long int N;
    cin >> N;
    
    long long int A[N];
    long long int K[N];
    
    for(long long int i=0; i<N; i++){
        cin >> A[i];
    }
    
    // for(long long int i=0; i<N; i++){
    //     cout << A[i] << " ";
    // }
    
    for(long long int i=0; i<N; i++){
        K[i] = 0;
    }
    
    for(long long int index=0; index<N; index++){
        long long int ans = 0;
        for(long long int j=index; j>0; j--){
            
            if(A[j-1]<=A[index]){
                ans++;
            }
            else{
                break;
            }
        }
        
        K[index] = ans;
    }
    
    for(long long int i=0; i<N; i++){
        cout << K[i] << " ";
    }
    
    return 0;
}