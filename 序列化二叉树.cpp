
#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
	string serialize(TreeNode* root) {
		string result;
		queue<TreeNode*> record;
		record.emplace(root);
		while (!record.empty()) {
			size_t size = record.size();
			while (size--) {
				auto node = record.front();
				if (node == nullptr) {
					result.append("null,");
				}
				else {
					result.append(to_string(node->val)).push_back(',');
					record.emplace(node->left);
					record.emplace(node->right);
				}
				record.pop();
			}
		}
		return result;
	}

	vector<string> split(const string& str) {
		vector<string> result;
		size_t begin = 0;
		size_t end = 0;
		while (1) {
			end = str.find(',', begin);
			if (end == string::npos) {
				break;
			}
			result.emplace_back(str.substr(begin, end - begin));
			begin = end + 1;
		}
		return result;
	}
	TreeNode* deserialize(string data) {
		vector<string> nodes = split(data);
		if (nodes.empty() || nodes[0] == "null") {
			return nullptr;
		}
		queue<TreeNode*> record;
		TreeNode* node = new TreeNode(stoi(nodes.front()));
		record.emplace(node);
		for (int i = 0; i < nodes.size() - 1;) {
			if (nodes[++i] != "null") {
				record.front()->left = new TreeNode(stoi(nodes[i]));
				record.emplace(record.front()->left);
			}
			if (nodes[++i] != "null") {
				record.front()->right = new TreeNode(stoi(nodes[i]));
				record.emplace(record.front()->right);
			}
			record.pop();
		}
		return node;
	}

#include <unordered_map>
	class Solution {
	public:
		vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
			vector<TreeNode*> vT;
			if (root == nullptr)
				return vT;
			unordered_map<string, int> mymap;
			Get(vT, root, mymap);
			return vT;

		}
		string Get(vector<TreeNode*>& vT, TreeNode* root, unordered_map<string, int>& mymap)
		{
			if (root == nullptr)
				return "#";
			string str;
			 str = to_string(root->val) + Get(vT, root->left, mymap) + Get(vT, root->right, mymap);
			if (mymap[str] == 1)
				vT.push_back(root);
			mymap[str]++;
			return str;
		}
	};
int main()
{

	Solution s;

	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(11);

	root->right->left = new TreeNode(1);
	root->left ->left = new TreeNode(11);
	s.findDuplicateSubtrees(root);

	//s.findDuplicateSubtrees();
	//vector<string> result;
	//size_t begin = 0;
	//size_t end = 0;
	//string str = "123,314134,3112";
	//while (1) {
	//	end = str.find(',', begin);
	//	if (end == string::npos) {
	//		break;
	//	}
	//	result.emplace_back(str.substr(begin, end - begin));
	//	begin = end + 1;
	//}
	//TreeNode* root = new TreeNode(1);
	//root->left = new TreeNode(2);
	//root->right = new TreeNode(3);

	//root->right->left = new TreeNode(4);
	//root->right->right = new TreeNode(5);
	//string str = serialize(root);
	//deserialize(str);


	system("pause");
}