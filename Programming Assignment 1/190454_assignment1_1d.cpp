// matrix exponentiation code
#include <iostream>
using namespace std;
#define K 1000000007
// equation for matrix exponentiation
/*    
|A(n)| = |0 1 1 |^n |1|
|B(n)| = |1 0 1 |   |0|
|C(n)| = |1 1 0 |   |0|
*/

// function to multiply two matrices
void multiply(long long int a[3][3], long long int b[3][3]){

    // a spare matrix to to store the multiplications
    long long int mul[3][3];

    for(long long int i=0; i<3; i++){
        for(long long int j=0; j<3; j++){
            mul[i][j] = 0;
            for(long long int k = 0; k < 3; k++)
                mul[i][j] = ((mul[i][j]%K) + ((a[i][k]%K) * (b[k][j]%K))%K)%K;
        }
    }

    // copying the spare matrix into matrix a
    for (long long int i=0; i<3; i++){
        for (long long int j=0; j<3; j++){
            a[i][j] = mul[i][j]; 
        }
    }
}

// function to calculate matrix A raised to the power n
long long int power(long long int A[3][3], long long int n){

    long long int M[3][3] = {{0,1,1}, {1,0,1}, {1,1,0}};

    // base case for matrix powered to 1
    if (n==1){
        return 0;
    }

    // inplace updation of matrix A to A raised to (n/2)
    power(A, n/2);

    // multiplying A raised to (n/2) with itself 
    multiply(A, A);

    // if n is odd, multiply the above result with the initial A matrix (here, M)
    if (n%2 != 0){
        multiply(A, M);
    }

    // returning the first element (as we are multiplying with the vector [1 0 0])
    return A[0][0];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    long long int n;
    cin >> n;
    long long int F[3][3] = {{0,1,1}, {1,0,1}, {1,1,0}} ;
    cout << power(F, n);
    return 0;
}