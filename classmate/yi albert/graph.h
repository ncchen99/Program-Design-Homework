#ifndef GRAPH_H
#define GRAPH_H

/* Do not modify any code in this file */

#include<string>
#include<vector>
#include<unordered_map>
#include<limits>
using namespace std;

/* An Edge struct contains informations about a directed connection between two users  */
struct Edge {
	Edge(int from_node, int to_node, double influence) :
		from_node{ from_node }, to_node{ to_node }, influence{ influence }{}
	int from_node; // Describe which user this Edge directs from
	int to_node; // Describe which user this Edge directs to
	double influence; // Describe the influence weight from user from_node to user to_node
};
/* An Node struct contains information about a user */
struct Node {
	Node(int node, double threshold) :
		node{ node }, threshold{ threshold }{}
	int node; // Describe which user this Node belongs to
	double threshold; // Describe the threshold influence that will activate this user
	vector<Edge*> in_edges; // Contain Edge pointers which direct to this user
	vector<Edge*> out_edges; // Contain Edge pointers which this user directs to
};
/*
You can initiate struct just like a variable,
and access the members in a struct with "." operator,
or access by "->" operator if it is a struct pointer.

E.g.

 Edge edge = { 1, 2, 0.7 };
 edge.threshold; // 0.7

 Edge *edge_pointer = &edge;
 edge_pointer->threshold; // 0.7

*/

/* DirectedGraph class contains all information about the network */
class DirectedGraph {
private:
	int number_of_nodes; // Record number of total users in this network
	int number_of_edges; // Record number of total connections between users in this network
	unordered_map<int, Node*> nodeMap; // Map the user to its Node, which contains information about the user
public:
	// Class construster, initialize the default value for number_of_nodes and number_of_edges
	DirectedGraph(void) {
		number_of_nodes = 0;
		number_of_edges = 0;
	}
	// Return number of total users in this network
	int getNodeNumber(void) {
		return number_of_nodes;
	}
	// Return number of total connections between users in this network
	int getEdgeNumber(void) {
		return number_of_edges;
	}
	// Insert a new Node into this network with given user and its threshold value
	void addNode(int node, double threshold = 0) {
		// If the given user does not exist in this network, then create a new user with given value
		if (!isNodeExist(node)) {
			Node* newNode = new Node(node, threshold);
			nodeMap[node] = newNode;
			number_of_nodes++;
		}
		// If the given user already exists in this network, then update its threshold with given value
		else
			setNode(node, threshold);
	}
	// Update a user's threshold with given value
	void setNode(int node, double threshold = 0) {
		// If the given user does not exist in this network, then create a new user with given value
		if (!isNodeExist(node))
			addNode(node, threshold);
		// If the given user already exists in this network, then update its threshold with given value
		else {
			Node* node_ptr = nodeMap[node];
			node_ptr->node = node;
			node_ptr->threshold = threshold;
		}
	}
	// Insert a new Edge into this network with two given users and influence weight
	void addEdge(int from_node, int to_node, double influence) {
		// Check if the from user exists in this network, if not, then create user from_node
		if (!isNodeExist(from_node))
			addNode(from_node);
		// Check if the to user exists in this network, if not, then create user to_node
		if (!isNodeExist(to_node))
			addNode(to_node);

		// Create an edge pointer and push it into from_node user's out_edge vector
		Edge* newEdge_1 = new Edge(from_node, to_node, influence);
		nodeMap[from_node]->out_edges.push_back(newEdge_1);

		// Create an edge pointer and push it into to_node user's in_edge vector
		Edge* newEdge_2 = new Edge(from_node, to_node, influence);
		nodeMap[to_node]->in_edges.push_back(newEdge_2);

		number_of_edges++;
	}
	// Update an edge with two given users and influence weight
	void setEdge(int from_node, int to_node, double influence) {
		// If the given edge does not exist in this network, then insert it to the network with given values
		if (!isEdgeExist(from_node, to_node))
			addEdge(from_node, to_node, influence);
		else
			// If the given edge exists in this network, then update its influence weight with given value
			for (auto edge : nodeMap[from_node]->out_edges)
				if (edge->to_node == to_node) {
					edge->influence = influence;
					break;
				}
	}
	// Delete a user from the network
	void deleteNode(int node) {
		if (isNodeExist(node)) {
			// Delete all connections direct to this given user
			for (auto from_node : getNodeInNeighbors(node))
				deleteEdge(from_node, node);
			// Delete all connections this given user directs to
			for (auto to_node : getNodeOutNeighbors(node))
				deleteEdge(node, to_node);

			// Erase the Node in the map belongs to this given user
			nodeMap.erase(node);
			number_of_nodes--;
		}
	}
	// Delete a connection between two given users in this network
	void deleteEdge(int from_node, int to_node) {
		if (isEdgeExist(from_node, to_node)) {
			// Delete the Edge pointer in from_node user's out_edges which store this given Edge
			for (vector<Edge*>::iterator it = nodeMap[from_node]->out_edges.begin(); it != nodeMap[from_node]->out_edges.end(); it++)
				if ((*it)->to_node == to_node) {
					nodeMap[from_node]->out_edges.erase(it);
					break;
				}
			// Delete the Edge pointer in to_node user's in_edges which store this given Edge
			for (vector<Edge*>::iterator it = nodeMap[to_node]->in_edges.begin(); it != nodeMap[to_node]->in_edges.end(); it++)
				if ((*it)->from_node == from_node) {
					nodeMap[to_node]->in_edges.erase(it);
					break;
				}
			number_of_edges--;
		}
	}
	// Check if a given user exists in this network
	bool isNodeExist(int node) {
		return nodeMap.find(node) != nodeMap.end();
	}
	// Check if a given directed connection exists between two users in this network
	bool isEdgeExist(int from_node, int to_node) {
		if (isNodeExist(from_node) && isNodeExist(to_node)) {
			for (auto edge : nodeMap[from_node]->out_edges)
				if (edge->to_node == to_node)
					return true;
			return false;
		}
		else
			return false;
	}
	// Get a given user's threshold weight
	double getNodeThreshold(int node) {
		if (isNodeExist(node))
			return nodeMap[node]->threshold;
		else {
			string errorMessage = "node " + to_string(node) + " doesn't exist!";
			cerr << errorMessage;
			double max = numeric_limits<double>::infinity();
			return max;
		}
	}
	// Get the influence weight from user from_node to user to_node
	double getEdgeInfluence(int from_node, int to_node) {
		if (isEdgeExist(from_node, to_node)) {
			for (auto edge : nodeMap[from_node]->out_edges)
				if (edge->to_node == to_node)
					return edge->influence;
			return double(0);
		}
		else {
			string errorMessage = "edge(" + to_string(from_node) + "," + to_string(to_node) + ") doesn't exist!";
			cerr << errorMessage;
			return double(0);
		}
	}
	// Get the users which have a connection directs to this given user
	vector<int> getNodeInNeighbors(int node) {
		vector<int> vec_to_return;
		if (isNodeExist(node)) {
			for (auto edge : nodeMap[node]->in_edges)
				vec_to_return.push_back(edge->from_node);
			return vec_to_return;
		}
		else {
			string errorMessage = "node " + to_string(node) + " doesn't exist!";
			cerr << errorMessage;
			return vec_to_return;
		}
	}
	// Get the users which this given user has a connection directs to
	vector<int> getNodeOutNeighbors(int node) {
		vector<int> vec_to_return;
		if (isNodeExist(node)) {
			for (auto edge : nodeMap[node]->out_edges)
				vec_to_return.push_back(edge->to_node);
			return vec_to_return;
		}
		else {
			string errorMessage = "node " + to_string(node) + " doesn't exist!";
			cerr << errorMessage;
			return vec_to_return;
		}
	}
	// Get all users in this network
	vector<int> getAllNodes(void) {
		vector<int> nodeVector;
		for (auto node : nodeMap)
			nodeVector.push_back(node.first);
		return nodeVector;
	}
	// Get all connections between users in this network
	vector<pair<int, int>> getAllEdges(void) {
		vector<pair<int, int>> edgeVector;
		for (auto node : nodeMap)
			for (auto edge : node.second->out_edges)
				edgeVector.push_back(make_pair(edge->from_node, edge->to_node));
		return edgeVector;
	}
	// Class deconstructor
	~DirectedGraph() {

	}
};
/*
 You can initiate DirectedGraph class just like a variable,
 and access the member functions in a class with "." operator,
 or access by "->" operator if it is a class pointer.

 E.g.
 DirectedGraph G = DirectedGraph();
 G.addEdge(1, 2, 0.7);
 G.getEdgeThreshold(1, 2); // 0.7

 DirectedGraph *G_pointer = &G;
 G_pointer->getEdgeThreshold(1, 2); // 0.7

*/
#endif