#include <vector>
#include <iostream>
using namespace std;

long long int cc = 0;
long long int n; // vertices

vector<vector<long long int>> adM; 

vector<bool> vis;
vector<long long int> tin, low, bridge;
long long int t;

void normDFS(long long int vertices, long long int p = -1){

    vis[vertices] = true;
    tin[vertices] = low[vertices] = t++;

    for (long long int outG:adM[vertices]) {
        if(outG == p){
            continue;
        }
        if(vis[outG]){
            low[vertices] = min(low[vertices], tin[outG]);
        }else{
            normDFS(outG, vertices);
            low[vertices] = min(low[vertices], low[outG]);

            if (low[outG] > tin[vertices]){
                bridge.push_back(vertices); 
                bridge.push_back(outG);
            }

        }
    }
}

void optDFS(long long int curr){

    vis[curr] = true; 
    cc = cc+1; 

    for(long long int j=0; j<adM[curr].size(); j++){
        if(adM[curr][j] != -1 and vis[adM[curr][j]] == false){
            optDFS( adM[curr][j]);
        }        
    }

    return; 
}

void find_bridges() {

    t = 0;

    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);

    for (long long int i=0; i<n; ++i) {
        if(!vis[i]){
            normDFS(i);
        }           
    }
}

int main(){

    long long int vertices, edges; 
    cin >> vertices >> edges;

    n = vertices; 

    for(long long int i=0; i<vertices; i++){
        adM.push_back(vector<long long int>());
    }
    for(long long int i=0; i<edges; i++){

        long long int inC, outG; 
        cin >> inC >> outG; 

        inC--; 
        outG--; 

        adM[inC].push_back(outG); 
        adM[outG].push_back(inC);
    }

    find_bridges();

    for(long long int i=0; i<bridge.size(); i=i+2){

        for(long long int j=0; j<adM[bridge[i]].size(); j++){
            if(adM[bridge[i]][j] == bridge[i+1]){
                adM[bridge[i]][j] = -1; 
            } 
        }

        for(long long int j = 0 ; j < adM[bridge[i+1]].size() ; j++){
            if(adM[bridge[i+1]][j] == bridge[i]){
                adM[bridge[i+1]][j] = -1; 
            } 
        } 
    }

    for(long long int i=0; i<vis.size(); i++){
        vis[i] = false;
    }

    long long int A = 0; 

    for(long long int i=0; i<n; i++){
        if(!vis[i]){ 
            optDFS(i); 
            A = A + (cc*(cc-1));
            cc = 0;
        }
    }
    cout << A << endl ;
    return 0;
}
