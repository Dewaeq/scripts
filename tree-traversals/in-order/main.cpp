#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = right = NULL;
	}
};


class Solution {
  public:
	vector<int> inOrder(Node *root) {
		vector<int> result(0);
		traverse(root, result);
		return result;
	}

	void traverse(Node *node, vector<int> &values) {
		if (node->left == NULL && node->right == NULL) {
			values.push_back(node->data);
			return;
		}
		if (node->left != NULL) {
			traverse(node->left, values);
		}
		values.push_back(node->data);
		if (node->right != NULL) {
			traverse(node->right, values);
		}
	}
};

Node *buildTree() {
	Node *root = new Node(10);
	Node *a = new Node(40);
	Node *b = new Node(60);
	Node *c = new Node(20);
	c->left = a;
	c->right = b;


	Node *d = new Node(50);
	Node *e = new Node(30);
	e->left = d;

	root->left = c;
	root->right = e;

	return root;
}

int main() {

	Node *root = buildTree();

	Solution ob;
	vector<int> res = ob.inOrder(root);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}
