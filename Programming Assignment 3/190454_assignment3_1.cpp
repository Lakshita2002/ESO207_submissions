#include <vector>
#include <iostream>
using namespace std;
#define INT_MAX 2147483647
long long int front = 0 ; 

// implementing queues using arrays
vector<long long int> queue1;
vector<long long int> queue2;

int main(){

    long long int n, m;
    cin >> n >> m;

    // all cells initialised with infinity
    vector<vector<long long int>> v (n, vector<long long int> (m, INT_MAX));
    // all cells initialised with false
    vector<vector<bool>> visited (n, vector<bool> (m, false));

    long long int shops;
    cin >> shops;

    long long int X_s, Y_s, cost;
    for(int i=0; i<shops; i++){
        // loc plus cost
        cin >> X_s >> Y_s >> cost;
        v[X_s-1][Y_s-1] = min(cost, v[X_s-1][Y_s-1]);
    }

    long long int k;
    cin >> k;
    long long int X_start, Y_start;

    for(int i=0; i<k; i++){
        cin >> X_start >> Y_start;
        queue1.push_back(X_start - 1); 
        queue2.push_back(Y_start - 1);

        // mark the starting cell as true
        visited[X_start-1][Y_start-1] = true;
    }

    // queries
    long long int t_c;
    cin >> t_c;
    vector<long long int> dist(t_c,0);
    long long int d = n+m;
    for(long long int i=0; i<t_c; i++){
        cin >> dist[i];
        d = max(d, dist[i]);
    }

    vector<long long int> t_r(d+1, INT_MAX);
    long long int distance = 0;
    
    
    while(queue1.size() - front != 0){
        long long int minimum = INT_MAX;
        long long int curS = queue1.size() - front;

        while(curS--){

            long long int x = queue1[front]; 
            long long int y = queue2[front];

            minimum = min(minimum, v[x][y]);
            front++; 

            if(x-1 >= 0 and visited[x-1][y] == false){
                queue1.push_back(x-1); 
                queue2.push_back(y); 
                visited[x-1][y]=true;
            }

            if(y-1 >= 0 and visited[x][y-1] == false){
                queue1.push_back(x); 
                queue2.push_back(y-1);
                visited[x][y-1] = true;
            }

            if(x+1 < n and visited[x+1][y] == false){
                queue1.push_back(x+1); 
                queue2.push_back(y);
                visited[x+1][y] = true;
            }

            if(y+1 < m and visited[x][y+1] == false){
                queue1.push_back(x); 
                queue2.push_back(y+1);
                visited[x][y+1] = true;
            }
        }

        t_r[distance] = minimum;
        distance++;
    }

    vector<long long int> ans(d+1, INT_MAX);
    ans[0] = t_r[0];
    for(long long int i=1; i<d+1; i++){
        ans[i] = min(t_r[i], ans[i-1]); 
    }

    for(long long int i=0; i<t_c; i++){
        if(ans[dist[i]] == INT_MAX){
            cout << "-1 ";
        }
        else{
            cout << ans[dist[i]] << " ";
        }
    } 

   return 0;
}