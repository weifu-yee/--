#ifndef _MAP_H_
#define _MAP_H_

#include <stdc++/bits>

#define filePath "test123.yaml"

namespace MAP{
    extern pair<int, pair<int, int>>> node;    //<index, x, y>
    extern vector<vector<int> adj_list;     //adjacency_list
    void buildNode();
    void buildEdge();
}

#endif