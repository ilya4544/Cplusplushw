#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <functional>
#include <stack>
#include <vector>

template<typename NodePayload>
class Graph {
public:
    typedef unsigned NodeHandle; // Unique ID for each node.
    typedef std::pair<NodeHandle, NodeHandle> EdgeHandle; // Pair of NodeHandle
    typedef std::function<void(NodeHandle const &)> NodeVisitor; // Custom function for node.
    typedef std::function<void(EdgeHandle const &)> EdgeVisitor; // Custom function for edge.

    Graph() = default; // Default constructor.
    ~Graph() = default; // Default destructor.
    void loadFromFile(std::string const & filename); // Load graph from file with specified filename.
    void saveToFile(std::string const & filename); // Save graph in file with specified filename.
    NodeHandle addNode(); // Add new node to graph. Return handle its node.
    void addEdge(NodeHandle const & a, NodeHandle const & b); // Add new edge to graph.
    void forEachNode(std::function<void(NodeHandle const &)> const & visitor) const; // Run custom function for each node.
    size_t getNodesCount() const; // Return count of nodes.
    void forEachEdge(EdgeVisitor const & visitor); // Run custom function for each edge.
    NodeHandle move(NodeHandle const & origin, EdgeHandle const & edge); // Move from selected node in selected direction edge. Return ending node.
    NodePayload & operator[](NodeHandle const & node); // Return payload of selected node.
    void dfs(NodeHandle const & startNode, NodeHandle const & endNode, NodeVisitor const & discoverNode); // Run dfs from startNode to endNode and for each visited node runs function discoverNode
private:
    std::vector<NodePayload> nodePayloads;
    std::vector<std::vector<NodeHandle> > graph;
};

template <typename NodePayload>
void Graph<NodePayload>::loadFromFile(std::string const & filename) {
    std::ifstream in;
    in.open(filename);
    if (in.is_open()) {
        int n, m;
        in >> n >> m;
        for (int i = 0; i < n; i++) {
            NodePayload payload;
            in >> payload;
            NodeHandle h = addNode();
            nodePayloads[h] = payload;
        }
        for (int i = 0; i < m; i++) {
            NodeHandle a, b;
            in >> a >> b;
            addEdge(a, b);
        }
        in.close();
    }
}

template <typename NodePayload>
void Graph<NodePayload>::saveToFile(std::string const & filename) {
    std::ofstream out(filename);
    int m = 0;
    for (size_t i = 0; i < graph.size(); i++)
        m += graph[i].size();
    out << graph.size() << " " << m << std::endl;
    for (size_t i = 0; i < graph.size(); i++) {
        out << nodePayloads[i] << " ";
    }
    out << std::endl;
    for (size_t i = 0; i < graph.size(); i++)
        for (size_t j = 0; j < graph[i].size(); j++)
            out << i << " " << graph[i][j] << std::endl;
    out.close();
}


template <typename NodePayload>
typename Graph<NodePayload>::NodeHandle Graph<NodePayload>::addNode() {
    graph.resize(graph.size() + 1);
    nodePayloads.resize(nodePayloads.size() + 1);
    return graph.size() - 1;
}

template <typename NodePayload>
void Graph<NodePayload>::addEdge(NodeHandle const & a, NodeHandle const & b) {
    graph[a].push_back(b);
}

template <typename NodePayload>
size_t Graph<NodePayload>::getNodesCount() const {
    return graph.size();
}

template <typename NodePayload>
NodePayload & Graph<NodePayload>::operator[](NodeHandle const & node) {
    NodePayload & a = nodePayloads[node];
    return a;
}

template <typename NodePayload>
void Graph<NodePayload>::forEachEdge(EdgeVisitor const & visitor) {
    for (size_t i = 0; i < graph.size(); i++)
        for (size_t j = 0; j < graph[i].size(); j++) {
            EdgeHandle edgeHandle = std::make_pair(i, graph[i][j]);
            visitor(edgeHandle);
        }
}

template <typename NodePayload>
typename Graph<NodePayload>::NodeHandle Graph<NodePayload>::move(NodeHandle const & origin, EdgeHandle const & edge) {
    return (origin == edge.first) ? edge.second : edge.first;
}

template <typename NodePayload>
void Graph<NodePayload>::forEachNode(std::function<void(NodeHandle const &)> const & visitor) const {
    for (size_t i = 0; i < graph.size(); i++)
        visitor(i);
}

template <typename NodePayload>
void Graph<NodePayload>::dfs(NodeHandle const & startNode, NodeHandle const & endNode, NodeVisitor const & discoverNode) {
    std::stack<NodeHandle> s;
    std::vector<char> used(graph.size(), false);
    s.push(startNode);
    used[startNode] = true;
    while (!s.empty()) {
        NodeHandle v = s.top();
        s.pop();
        discoverNode(v);
        if (v == endNode)
            break;
        for (size_t i = 0; i < graph[v].size(); i++) {
            if (!used[graph[v][i]]) {
                s.push(graph[v][i]);
                used[graph[v][i]] = true;
            }
        }
    }
}

#endif //GRAPH_H