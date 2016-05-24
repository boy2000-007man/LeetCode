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
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> um;
        queue<UndirectedGraphNode **> q;
        if (node)
            q.push(&node);
        for ( ; !q.empty(); q.pop()) {
            auto &po = *q.front(),
                 &pn = um[po];
            if (!pn) {
                pn = new UndirectedGraphNode(po->label);
                for (auto &p: pn->neighbors = po->neighbors)
                    q.push(&p);
            }
            po = pn;
        }
        return node;
    }
};