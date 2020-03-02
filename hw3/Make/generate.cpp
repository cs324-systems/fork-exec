
#include <iostream>
#include "graph.h"
#include "dot.h"

using namespace std;


// ******************   Main   ************************


int main(int argc, char *argv[]) {

  srand(time(NULL));

  if (argc > 2) {

    int n = atoi(argv[1]);
    Graph g(n, 0.1);

    cout << "Number of nodes: " << g.get_nodes() << endl;
    cout << "Number of edges: " << g.get_edges() << endl;
    Dot d;
    d.save_graph(g, argv[2]);
  }
  else {
    cout << "Requires two parameters." << endl;
    cout << "Example: " << endl;
    cout << "   ./graph 100 filename.dot" << endl;
  }

}
