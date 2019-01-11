#include <iostream>
using namespace std;

template <class T>
class priority {
public:
	struct Node {
		T val;
		Node *l;
		Node * r;

		Node(T v) {
			val = v;
			l = NULL;
			r = NULL;
		}
	};
	Node *root;
	priority() {
		root = NULL;
	}

	Node* pop(Node* r) {
		if (r == NULL) {
			return NULL;
		}

		Node* ret = merge(r->l, r->r);
		delete(r);
		return ret;
	}

	T pop() {
		root = pop(root);
		return root->val;
	}

	T peek() {
		return root->val;
	}
	Node* merge(Node* a, Node* b) {
		if (a == NULL) {
			return b;
		}
		if (b == NULL) {
			return a;
		}

		if (a->val > b->val) {
			if (a->l == NULL) {
				a->l = b;
			}
			else if (a->r == NULL) {
				a->r = b;
			}
			else {
				a->r = merge(a->r, b);
			}
			return a;
		}
		else {
			if (b->l == NULL) {
				b->l = a;
			}
			else if (b->r == NULL) {
				b->r = a;
			}
			else {
				b->r = merge(b->r, a);
			}
			return b;
		}
	}
	void push(T v) {
		root = merge(root, new Node(v));
	}
};

int main()
{
	priority<int> p = priority<int>();
	p.push(1);
	cout << p.peek() << endl;
	p.push(3);
	cout << p.peek() << endl;
	p.push(2);
	cout << p.peek() << endl;
	cout << p.pop() << endl;
	p.push(4);
	cout << p.peek() << endl;
	cout << p.pop() << endl;
	cout << p.pop() << endl;
	return 0;
}