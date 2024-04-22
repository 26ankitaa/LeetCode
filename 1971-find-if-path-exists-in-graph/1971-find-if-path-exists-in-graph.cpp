using vvI = vector<vector<int>>;
using graph = unordered_map<int, unordered_set<int>>;
class Solution {
	graph g;
	unordered_set<int> visited;
	int dest;
public:
	void add_node(int src, int dst) {
		auto it = g.find(src);
		if (it != g.end()) {
			auto& itr = it->second;
			itr.insert(dst);
		}
		else {
			unordered_set<int> us;
			us.insert(dst);
			g[src] = us;
		}
	}
	void create_graph(vvI& edges) {
		for (auto& i : edges) {
			add_node(i[0], i[1]);
			add_node(i[1], i[0]);
		}
	}
	bool find(int source) {
		auto it = g.find(source);
		if (it != g.end()) {
			for (auto& i : it->second) {
				if (visited.find(i) == visited.end()) {
					// if dest is any of neighbour
					if (i == dest)
						return true;

					// jump to unvisited neighbour
					visited.insert(i);
					if (find(i))
						return true;
				}
			}
		}
		return false;
	}
	bool validPath(int n, vvI& edges, int source, int destination) {
        if (edges.empty())
            return true;
		dest = destination;
		create_graph(edges);
		
		auto it = g.find(source);
		if (it == g.end())
			return false;

		return find(source);
	}
};