#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// try not to change it
template <class T>
struct Vertex
{
	T label; // unique int/string for a vertex
	vector<T> adj_list;
	int indegree;												   // Part 2: number of nodes pointing in
	int top_num;												   // Part 2: topological sorting number
	Vertex() {}													   // default constructor
	Vertex(T l) : label(l), adj_list(), indegree(0), top_num(0) {} // Part 1
};

// optional, but probably helpful (comment it out if not used)
template <class T>
ostream &operator<<(ostream &o, Vertex<T> v)
{
	o << v.label << " :";
	for (const auto &adj : v.adj_list)
	{
		o << ' ' << adj;
	}
	return o;
};

template <class T>
class Graph
{
private:
	// c++ STL hash table
	unordered_map<T, Vertex<T>> node_set;
	bool indegrees_computed, has_cycles, top_sort_done; // optional
														// Use other data fields if needed

public:
	Graph() : node_set(), indegrees_computed(false),
			  has_cycles(false), top_sort_done(false){};
	~Graph(){}; // No modification needed to destructor.

	// build a graph - refer the instructions PDF for more information.
	void buildGraph(istream &input)
	{
		std::string line;
		while (getline(input, line))
		{
			std::istringstream iss(line);

			T label;
			iss >> label;
			Vertex<T> new_vertex(label);

			T adj_label;
			while (iss >> adj_label)
			{
				new_vertex.adj_list.push_back(adj_label);
			}
			node_set.insert({label, new_vertex});
		}

	} // Part 1

	// display the graph into ostream
	// refer the instructions PDF for more information.
	void displayGraph(ostream &o)
	{
		for (auto &node : node_set)
		{
			o << node.first << ": ";
			for (T i : node.second.adj_list)
			{
				o << i << " ";
			}
			o << endl;
		}
	} // Part 1

	// return the vertex at label, else throw any exception
	//  refer the instructions PDF for more information.
	Vertex<T> at(T label)
	{
		if (node_set.contains(label))
		{
			return node_set[label];
		}
		throw invalid_argument("label not found");
	} // Part 1

	// return the graph size (number of verticies)
	int size()
	{
		return node_set.size();
	} // Part 1

	// topological sort
	// return true if successful, false on failure (cycle)
	bool topological_sort()
	{
		return true;
	}; // Part 2

	// find indegree
	void compute_indegree() {
		// YOUR CODE IS HERE
	}; // Part 2

	// print topological sort into ostream
	// if addNewline is true insert newline into stream
	void print_top_sort(ostream &o, bool addNewline = true)
	{
		if (!top_sort_done && !topological_sort())
		{
			throw invalid_argument("Graph has cycle(s)"
								   " and cannot be sorted topologically");
		}

		vector<T> vec(this->size());
		for (const auto &vertex : node_set)
		{
			vec.at(vertex.second.top_num - 1) = vertex.second.label;
		}

		for (const auto &label : vec)
		{
			o << label << ' ';
		}

		if (addNewline)
		{
			o << '\n';
		}
	}; // Part 2
};

#endif
