// O(n) algorithm
#include <iostream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    long long int n;
    cin >> n;

    long long int arr[n];

    for(long long int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    // declaring current max and global max
    long long int max_c, max_g;
    max_c = max_g = arr[0];

    for(long long int i=1; i<n; i++){
        // calculating max sum of the subarray till the ith position
        max_c = max(arr[i], max_c+arr[i]);
        // updating the current max
        if (max_c>max_g){
            max_g = max_c;
        }
    }

    cout << max_g;
    
    return 0;
}
