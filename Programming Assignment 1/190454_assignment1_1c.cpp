// iterative code
#include <iostream>
using namespace std;
#define M 1000000007

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n;
    cin >> n;
    // we are building upon the recursive relations to get these equations
    // a = b+c
    // b = c+a
    // c = a+b
    // with the initial values starting like this
    long long int a = 1;
    long long int b = 0;
    long long int c = 0;

    for(long long int i=0; i<n; i++){
        long long int temp_a = ((b%M)+(c%M))%M;
        long long int temp_b = ((a%M)+(c%M))%M;
        long long int temp_c = ((a%M)+(b%M))%M;
        a = temp_a;
        b = temp_b;
        c = temp_c;
    }
    
    cout << a ;
    
    return 0;
}