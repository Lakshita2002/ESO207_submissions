#include <iostream>
using namespace std;
typedef long long ll;

struct data{
    ll val;
    ll pos;
};

// merge and count inversion
void MCInversion(data A[], ll start, ll mid, ll end, data  C[], ll count[], ll K){

    ll i = start;
    ll j = mid+1;
    ll r = 0;
    ll m = mid+1;

    while(i<=mid and j<=end){
        if(A[i].val > A[j].val){
            while((A[i].val<=K*A[m].val) and (m<=end)){
                m++;
            }
            count[A[i].pos]+=end-m+1;                
            C[r] = A[i];
            r++;
            i++;
        }
        else{
            C[r] = A[j];
            r++;
            j++;
        }
    }
    while(i<=mid){
        C[r] = A[i];
        r++;
        i++;
    }
    while(j<=end){
        C[r] = A[j];
        r++; 
        j++;
    }
    return;
}

// sort and count inversion
void SCInversion(data A[], ll start, ll end, ll count[], ll K){
    if(start==end){
        return;
    }
    else{
        SCInversion(A, start, (start+end)/2, count, K);
        SCInversion(A, ((start+end)/2)+1, end, count, K);
        data C[end-start+1];
        MCInversion(A, start, (start+end)/2, end, C, count, K);
        
        for(ll i=0; i<=end-start; i++){
            A[start+i] = C[i];
        }
        return;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    ll N; 
    cin >> N;
    ll K; 
    cin >> K;
    
    data A[N];
    for(ll i=0; i<N; i++){
        cin >> A[i].val;
        A[i].pos = i;
    }
    
    ll count[N] = {0};
    
    SCInversion(A, 0, N-1, count, K);
    
    for(ll i=0; i<N ; i++){
        cout << count[i] << " ";
    }
       
    
    return 0;
}