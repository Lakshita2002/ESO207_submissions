// recursive code
#include <iostream>
using namespace std;

// defining our functions
long long int A(long long int n);
long long int B(long long int n);
long long int C(long long int n);

// recursive relation for A(n)
long long int A(long long int n){
    
    // base case
    if(n==0){
        return 1;
    }
    else{
        return B(n-1)+C(n-1);
    }
}

// recursive relation for B(n)
long long int B(long long int n){
    
    // base case
    if(n==0){
        return 0;
    }
    else{
        return C(n-1)+A(n-1);
    }
}

// recursive relation for C(n)
long long int C(long long int n){
    
    // base case
    if(n==0){
        return 0;
    }
    else{
        return A(n-1)+B(n-1);
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    long long int n;
    cin >> n;
    cout << A(n);
    return 0;
}