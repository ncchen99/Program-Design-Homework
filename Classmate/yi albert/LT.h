#ifndef LT_H
#define LT_H

/* Do not modify any code in this file */

#include<unordered_set>
#include"graph.h"

// Get sum of influence from active user which has a directed connection to this given user
double influence_sum(DirectedGraph* G, int targetNode, const vector<int>& activeInNeighbors) {
	double influence_sum = 0;
	for (auto inNeighbor : activeInNeighbors)
		influence_sum += G->getEdgeInfluence(inNeighbor, targetNode);
	return influence_sum;
}
// Get all active users in the network after one round of propagation with given initial active users
vector<int> diffuse_one_round(DirectedGraph* G, const unordered_set<int>& seeds) {
	unordered_set<int> activated_nodes;
	for (auto seed : seeds) {
		for (auto neighbor : G->getNodeOutNeighbors(seed)) {
			if (seeds.find(neighbor) != seeds.end() || activated_nodes.find(neighbor) != activated_nodes.end())
				continue;
			vector<int> active_Neighbors;
			for (auto in_Neighbor : G->getNodeInNeighbors(neighbor))
				if (seeds.find(in_Neighbor) != seeds.end())
					active_Neighbors.push_back(in_Neighbor);
			if (influence_sum(G, neighbor, active_Neighbors) >= G->getNodeThreshold(neighbor))
				activated_nodes.insert(neighbor);
		}
	}
	vector<int> vecToReturn(activated_nodes.begin(), activated_nodes.end());
	return vector<int>(activated_nodes.begin(), activated_nodes.end());
}
// Get all active users in the network when propagation ends, with given initial active users
vector<int> diffuse_all(DirectedGraph* G, const unordered_set<int> seeds) {
	unordered_set<int> seed_set_in_function;
	seed_set_in_function.insert(seeds.begin(), seeds.end());
	while (true) {
		vector<int> new_actived_nodes = diffuse_one_round(G, seed_set_in_function);
		if (new_actived_nodes.empty())
			return vector<int>(seed_set_in_function.begin(), seed_set_in_function.end());
		else
			seed_set_in_function.insert(new_actived_nodes.begin(), new_actived_nodes.end());
	}
}
// Get all active users in the network after k rounds of propagation with given initial active users
vector<int> diffuse_k_rounds(DirectedGraph* G, const unordered_set<int> seeds, int rounds = 0) {
	unordered_set<int> seed_set_in_function;
	seed_set_in_function.insert(seeds.begin(), seeds.end());
	while (rounds-- > 0) {
		vector<int> new_actived_nodes = diffuse_one_round(G, seed_set_in_function);
		if (!new_actived_nodes.empty())
			seed_set_in_function.insert(new_actived_nodes.begin(), new_actived_nodes.end());
	}
	return vector<int>(seed_set_in_function.begin(), seed_set_in_function.end());
}
#endif