#include "map.h"
using namespace MAP;

pair<int, pair<int, int>>> MAP::node;     //<index, x, y>
vector<vector<int> MAP::adj_list;       //adjacency_list

void MAP::buildNode(){
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    YAML::Node pathConfig = YAML::Load(file);
    for (auto nodeElement : pathConfig) {
        auto node = nodeElement["node"];
        int index = node[0].as<int>();
        int x = node[1].as<int>();
        int y = node[2].as<int>();
        node.push_back(make_pair(index, make_pair(x, y)));
    }
}
void MAP::buildEdge(){

}