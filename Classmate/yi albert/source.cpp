#include <iostream> 
#include <fstream>
#include <iomanip>
#include "graph.h"
#include "LT.h"
#include "your_algorithm.h"
#define seedNumber 20// Set the number of initial active users in the network
using namespace std;

DirectedGraph loadGraph(string);
double activeRate(DirectedGraph&);

const string test_file = "./test_data/"; // Test data file directory path

int main() {
	DirectedGraph G = loadGraph(test_file);
	double active_rate_of_my_algorithm = activeRate(G);
	cout << "Active Rate: " << setprecision(2) << fixed << active_rate_of_my_algorithm << " %" << endl;
	system("pause");
	return 0;
}

/* 
 Load network from given data directory
 which contains two files:
 "node.txt" and "edge.txt"
 and return the loaded network
 */
DirectedGraph loadGraph(string dataFileDirectory) {
	DirectedGraph G = DirectedGraph();

	string node_file_path = dataFileDirectory + "node.txt";

	ifstream f1(node_file_path);
	string line;
	f1 >> line;
	while (f1 >> line) {
		int node = stoi(line);
		f1 >> line;
		double threshold = stod(line);
		G.addNode(node, threshold);
	}
	f1.close();

	string edge_file_path = dataFileDirectory + "edge.txt";

	ifstream f2(edge_file_path);
	f2 >> line;
	while (f2 >> line) {
		int from_node = stoi(line);
		f2 >> line;
		int to_node = stoi(line);
		f2 >> line;
		double influence = stod(line);
		G.addEdge(from_node, to_node, influence);
	}
	f2.close();

	return G;
}

/* 
 Run diffusion in given DirectedGraph G with initial active users
 selected by included seedSelection algorithm and return active rate
*/
double activeRate(DirectedGraph& G) {
	DirectedGraph G1 = loadGraph(test_file);
	unordered_set<int> seeds = seedSelection(G1, seedNumber);

	if (seeds.size() != seedNumber) {
		cerr << "Seed set size invalid";
		exit(EXIT_FAILURE);
	}

	vector<int> actived_nodes = diffuse_all(&G, seeds);
	double active_rate = double(actived_nodes.size()) * 100 / double(G.getNodeNumber());

	return active_rate;
}