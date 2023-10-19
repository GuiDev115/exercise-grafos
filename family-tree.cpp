#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct NoArvore
{
  string name;
  unsigned id;
  NoArvore *leftChild;
  NoArvore *rightChild;
};

#define TRUE 1
#define FALSE 0
#define MAX_NODES 302

char visitado[MAX_NODES];
int adj[MAX_NODES][MAX_NODES];

unsigned nodeCounter;
unsigned numNodes, numEdges;

void DFS(const unsigned vertex)
{

  unsigned i;
  visitado[vertex] = TRUE;
  for (i = 1; i <= numNodes; ++i)
    if (adj[vertex][i])
      if (!visitado[i])
        DFS(i);
}

NoArvore *insert(NoArvore *root, const string &str)
{

  if (!root){

    root = new NoArvore;
    root->leftChild = root->rightChild = nullptr;
    root->name = str;
    root->id = ++nodeCounter;
  }

  else if (root->name > str)
    root->leftChild = insert(root->leftChild, str);

  else if (root->name < str)
    root->rightChild = insert(root->rightChild, str);

  return root;
}

int findId(NoArvore *root, const string &str){

  if (!root)
    return -1;

  if (root->name > str)
    return findId(root->leftChild, str);
  else if (root->name < str)
    return findId(root->rightChild, str);
  else
    return root->id;
}

int main(int argc, char **argv)
{

  int u, v, i, j;
  NoArvore *tree = nullptr;
  string name1, name2, connection;

  cin >> numNodes >> numEdges;
  int tmp = numEdges;
  while (tmp--){

    cin >> name1 >> connection >> name2;
    tree = insert(tree, name1);
    tree = insert(tree, name2);

    u = findId(tree, name1);
    v = findId(tree, name2);

    adj[u][v] = adj[v][u] = 1;
  }

  int ans = 0;

  for (i = 1; i <= numNodes; ++i)
    if (!visitado[i])
      ans++, DFS(i);

  cout << ans << endl;

  return 0;
}
