/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		if (node == NULL)
			return NULL;

		queue<UndirectedGraphNode*> nodeQueue;
		unordered_map<int, UndirectedGraphNode*> copiedNodes;
		copiedNodes[node->label] = new UndirectedGraphNode(node->label);
		nodeQueue.push(node);

		while (!nodeQueue.empty()) {
			UndirectedGraphNode *top = nodeQueue.front();
			UndirectedGraphNode *copied = copiedNodes[top->label];
			nodeQueue.pop();

			for (int i=0; i<top->neighbors.size(); i++) {
				UndirectedGraphNode *cur = top->neighbors[i];
				if (copiedNodes.count(cur->label) == 0) {
					nodeQueue.push(cur);
					copiedNodes[cur->label] = new UndirectedGraphNode(cur->label);
				}

				copied->neighbors.push_back(copiedNodes[cur->label]);
			}
		}

		return copiedNodes[node->label];
    }
};
