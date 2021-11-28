#ifndef YOUR_ALGORITHM_H
#define YOUR_ALGORITHM_H

#include "LT.h"
#include "graph.h"

using namespace std;

unordered_set<int> seedSelection(DirectedGraph G, unsigned int numberOfSeeds) {
    unordered_set<int> seeds;
    /* Put selected users into unordered_set seeds */
    /* Implement your seed selection algorithm below */
    vector<int> N = G.getAllNodes();
    // bool isEdgeExist(int, int);
    int count;
    int k = 0;
    int kk = 0;
    int a;

    int gnn = int(G.getNodeNumber());
    int gen = int(G.getEdgeNumber());

    for (int i = 0; i < gen; i++) {
        count = 0;
        for (int j = 0; j < gnn; j++) {
            if (G.isEdgeExist(i, j) == true) {
                count++;
            }
        }
        printf("count : %d", count);
        while (k < numberOfSeeds) {
            if (count > 200) {
                seeds.insert(N[i]);
                k++;
                kk++;
                cout << ">200:" << kk;
            }
            for (a = 200; a >= 0; a--) {
                if (a == count) {
                    seeds.insert(N[i]);
                    k++;
                }
            }
        }

        //seeds.insert(N[i]);
    }

    return seeds;
}
#endif