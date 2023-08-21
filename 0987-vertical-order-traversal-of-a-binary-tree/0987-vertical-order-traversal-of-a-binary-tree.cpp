class Solution {
public:
    
	Solution() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	}
	
    void preOrder(TreeNode * root, int level, int horiDist, map<int, vector<pair<int, int>>>& _map) {
        if(root == nullptr) return;
        _map[horiDist].push_back({level, root->val});
        preOrder(root->left, level + 1, horiDist - 1, _map);
        preOrder(root->right, level + 1, horiDist + 1, _map);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> _map;
        preOrder(root, 0, 0, _map);
        vector<vector<int>> vertTraversal;
        for(auto &entry : _map) {
            sort(entry.second.begin(), entry.second.end());
            vector<int> vertical;
            for(auto &_pair : entry.second) {
                vertical.push_back(_pair.second);
            }
            vertTraversal.push_back(vertical);
        }
        
        return vertTraversal;
    }
};