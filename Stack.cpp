#include <iostream>
using namespace std;

template <class T>
class stack {
public:
	struct Node {
		T val;
		Node *prev;

		Node(T v, Node* p) {
			val = v;
			prev = p;
		}
	};

	int sz;
	Node *root;
	stack() {
		root = NULL;
		sz = 0;
	}
	int size() {
		return sz;
	}
	Node *push(Node* r, T v) {
		Node* ret = new Node(v, r);
		return ret;
	}
	void push(T v) {
		root = push(root, v);
		sz++;
	}
	T top() {
		return root->val;
	}
	Node* pop(Node* r) {
		if (r == NULL) {
			return NULL;
		}

		Node *ret = r->prev;
		delete(r);
		return ret;
	}
	T pop() {
		if (root == NULL) {
			return NULL;
		}
		T v = root->val;
		root = pop(root);
		sz--;
		return v;
	}


};

int main() {
	stack<int> s = stack<int>();
	cout << s.size() << endl;
	s.push(2);
	cout << s.top() << endl;
	s.push(5);
	cout << s.top() << endl;
	cout << s.size() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;
}