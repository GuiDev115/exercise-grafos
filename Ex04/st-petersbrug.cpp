#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int pCommunity, shipEdges, minFriends; 
  int u, v;

  cin >> pCommunity >> shipEdges >> minFriends;
  
  while (cin) {
    
    vector<int>* adj = new vector<int>[pCommunity+1];
    int* degree =  new int[pCommunity + 1];
    
    for(int i = 1; i <= pCommunity; i++) {
      degree[i] = 0;
    }

    for (int i = 0; i < shipEdges; i++) {
      cin >> u >> v; 

      if (find(adj[u].begin(), adj[u].end(), v) != adj[u].end())
        continue;


      adj[v].push_back(u); 
      adj[u].push_back(v); 
      

      degree[u]++;
      degree[v]++;
    }

    priority_queue<pair<int, int>> PQ;
    for (int i = 1; i <= pCommunity; i++) {
      if (degree[i] < minFriends) {
        PQ.push({ degree[i], i });
      }
    }

    while (!PQ.empty()) {

      int aux = PQ.top().second;
      PQ.pop();

      for (auto it = adj[aux].begin(); it != adj[aux].end(); it++) {
        if (--degree[*it] == minFriends-1) {
          PQ.push({ degree[*it], *it });
        }
      }
    }

    bool first = true;
    for (int i = 1; i <= pCommunity; i++) {
      if (degree[i] >= minFriends) {
        if (!first) {
          cout << " ";
        }
        first = false;
        cout << i;
        
      }
    }

    if (first) 
      cout << 0;

    cout << endl;

    cin >> pCommunity >> shipEdges >> minFriends; 
  }
  
  return 0;
}