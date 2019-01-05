#include <iostream>

using namespace std;

typedef struct Node {
	int value;
	struct Node *link;
}Node;


Node* insert(Node *p, int value) {
	if (p == NULL) {
		p = (Node*)malloc(sizeof(Node));
		p->value = value;
		p->link = NULL;
		return p;
	}
	else {
		Node *q = p;

		while (q->link)
			q = q->link;

		Node *r = (Node*)malloc(sizeof(Node));
		q->link = r;
		r->value = value;
		r->link = NULL;
		return p;
	}
}

void list(Node *p) {
	if (p == NULL)
		cout << "Empty" << endl;
	else {
		do {
			cout << p->value << " ";
		} while (p = p->link);
		cout << endl;
	}
}

Node* remove(Node *p, int value) {
	if (p == NULL)
		cout << "Empty" << endl;
	else {
		Node *q = p;
		if (p->value == value) {
			q = p->link;
			free(p);
			return q;
		}
		else {
			Node *r;
			do {

				if (q->link == NULL) {
					cout << "Input coorect value" << endl;
					return p;
				}

				r = q->link;
				if (r->value == value) {
					if (r->link != NULL)
						q->link = r->link;
					else
						q->link = NULL;
					free(r);
					return p;
				}

			} while (q = q->link);
		}
	}
}

int count(Node *p) {
	if (p == NULL)
		return 0;
	int c = 1;
	for (; p->link; c++, p = p->link);
	return c;
}

int main()
{
	Node* head = NULL;
	list(head);
	head = insert(head, 1);
	list(head);
	head = insert(head, 2);
	head = insert(head, 3);
	list(head);
	head = remove(head, 4);
	list(head);
	cout << count(head) << endl;
	return 0;
}