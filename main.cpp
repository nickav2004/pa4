// main function

#include <iostream>
#include <cstdlib>

#include "graph.h"

using namespace std;

int main(int argc, const char *argv[])
{
  if (argc != 2)
  {
    cout << "usage: " << argv[0] << " input filename\n";
    exit(1);
  }

  string input_name = argv[1];
  ifstream input(input_name);
  if (!input)
  {
    cout << "Wrong or nonexisting input file\n";
    exit(1);
  }

  Graph<string> graph;

  // Part 1
  graph.buildGraph(input);
  if (graph.size() < 20)
  {
    cout << "Display graph:\n";
    graph.displayGraph(cout);
  }
  cout << " finsihed part 1" << endl;

  // Part 2 starts here
  graph.compute_indegree();          // Part 2
  bool b = graph.topological_sort(); // Part 2
  if (b)
  {
    if (graph.size() < 20)
    {
      cout << "\nTopological sort:\n";
      graph.print_top_sort(cout);
    }
  }
  else
  {
    cout << "Cycle Detected - no toplogical sort.\n";
  }

  return 0;
}
