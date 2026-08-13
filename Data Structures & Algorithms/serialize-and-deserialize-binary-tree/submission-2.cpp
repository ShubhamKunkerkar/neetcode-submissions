/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "[]";
        string out = "[";
        queue<TreeNode*> q;
        q.push(root);
        bool trig = true;
        while(trig){
            int size = q.size();
            trig = false;
            for(int i = 0; i < size; i++){
                if(q.front() == nullptr){
                    out += "null,";
                    q.pop();
                    continue;
                }else{
                    out += to_string(q.front()->val) + ',';
                }
                q.push(q.front()->left);
                q.push(q.front()->right);
                if(q.front()->left != nullptr || q.front()->right != nullptr)
                    trig = true;
                q.pop();
            }
        }
        out[out.size()-1] = ']';
        cout << out << endl;
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> s;
        TreeNode* root = nullptr;
        TreeNode* curr;
        vector<int> tree;
        int i = 1;
        while (i < data.size() - 1) {
            int j = i;
            string num = "";
            while (data[j] != ',' && j < data.size() - 1) {
                num += data[j];
                j++;
            }
            i = j + 1;
            if (num == "null") {
                tree.push_back(-1001);
            } else
                tree.push_back(stoi(num));
        }
        int j = 0;
        int consumed = 0;
        for (int i = 0; i < tree.size(); i++) {
            if (i == 0) {
                root = new TreeNode(tree[i]);
                curr = root;
                s.push_back(curr);
                continue;
            }
            if(consumed == 0){
                if(tree[i] != -1001){
                    curr->left = new TreeNode(tree[i]);
                    s.push_back(curr->left);
                }
                consumed++;
            } else if(consumed == 1){
                if(tree[i] != -1001){
                    curr->right = new TreeNode(tree[i]);
                    s.push_back(curr->right);
                }
                consumed++;
            } else{
                j++;
                i--;
                consumed = 0;
                curr = s[j];
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));