/* reference: https://github.com/baactree/Algorithm/blob/master/Stl/set.cpp */
#include <iostream>

using namespace std;

template <class T>
class set {
public:
	struct Node {
		int priority;
		T val;
		struct Node *left;
		struct Node *right;

		Node(T v) {
			val = v;
			right = left = NULL;
		}

	};

	Node *root;
	set() {
		root = NULL;
	}
	Node* insert(Node *r, Node *n) {
		if (r == NULL)
			r = n;
		else {
			if (n->val > r->val)
				r->right = insert(r->right, n);
			else if (n->val < r->val)
				r->left = insert(r->left, n);
		}
		return r;
	}
	void insert(T v) {
		root = insert(root, new Node(v));
	}

	bool find(Node* r, T v) {
		if (r == NULL)
			return false;
		else {
			if (r->val == v)
				return true;
			else if (r->val > v)
				return find(r->left, v);
			else
				return find(r->right, v);
		}
	}
	bool find(T v) {
		return find(root, v);
	}
	Node* merge(Node* a, Node* b) {
		if (a == NULL)
			return b;
		if (b == NULL)
			return a;
		if (a->val < b->val)
			a->right = merge(a->right, b);
		else
			a->left = merge(a->left, b);
		return a;
	}
	Node* remove(Node* r, T v) {
		if (r->val == v) {
			Node* ret = merge(r->left, r->right);
			delete(r);
			return ret;
		}
		else if (r->val > v)
			remove(r->left, v);
		else
			remove(r->right, v);
		return r;
	}
	void remove(T v) {
		root = remove(root, v);
	}
};
int main()
{
	set<int> s;
	s.insert(1);
	cout << s.find(1) << endl;
	cout << s.find(2) << endl;
	s.insert(3);
	cout << s.find(2) << endl;
	cout << s.find(3) << endl;
	s.insert(2);
	cout << s.find(1) << endl;
	cout << s.find(2) << endl;
	s.remove(1);
	cout << s.find(1) << endl;
	cout << s.find(3) << endl;
	return 0;
}