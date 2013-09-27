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
        
		vector<UndirectedGraphNode*> copiedNodes(100, nullptr);

		return cloneGraph(node, copiedNodes);
    }

private:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, 
			vector<UndirectedGraphNode*> &copiedNodes) {

		if (node == NULL)
			return NULL;

		if (copiedNodes.size() <= node->label)
			copiedNodes.resize((node->label+1)*2, nullptr);

		UndirectedGraphNode *cur = new UndirectedGraphNode(node->label);
		copiedNodes[cur->label] = cur;
		for (int i=0; i<node->neighbors.size(); i++) {
			int curLabel = node->neighbors[i]->label;
			if (curLabel<copiedNodes.size() && copiedNodes[curLabel]) {
				cur->neighbors.push_back(copiedNodes[curLabel]);
			} else {
				cur->neighbors.push_back(cloneGraph(node->neighbors[i]));
			}
		}

		return cur;
	}
};
