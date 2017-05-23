#include "stdafx.h"

template <class mySort>
class Node{
	mySort key;
	int height;
	Node *left;
	Node *right;



public:


	Node(mySort key) : key(key), left(nullptr), right(nullptr), height(1)
	{
	};
	~Node() {

	}

	
	void SetLeft(Node *ptr){
		left = ptr;
	}

	void SetRight(Node *ptr){
		right = ptr;
	}

	void Setkey(mySort ptr){
		key = ptr;
	}
	void Setheight(int h){
		height = h;
	}

	int Getheight(Node *p){
		if (p == NULL) return 0;
		else return p->height;
	}


	mySort Getkey(){
		return key;
	}

	Node *GetLeft(){
		return left;
	}

	Node *GetRight(){
		return right;
	}

	Node *Get(){

		return this;
	}
	void preorder(Node<mySort>* p)
	{

		if (p->Getkey() != NULL)
		{
			cout << " " << p->Getkey() << " ";
			if (p->GetLeft() != NULL){
				preorder(p->GetLeft());
			}
			if (p->GetRight() != NULL){
				preorder(p->GetRight());
			}
		}
		else return;
	}

	int bfactor(Node* p)
	{
		return Getheight(p->GetRight()) - Getheight(p->GetLeft());
	}

	void fixheight(Node* p)
	{
		int hl = Getheight(p->GetLeft());
		int hr = Getheight(p->GetRight());
		p->Setheight((hl>hr ? hl : hr) + 1);
	}

	Node* rotateright(Node* p) // правый поворот вокруг p
	{
		Node* q = new Node(p->Getkey());
		q->SetRight(p->GetRight());
		p->SetRight(q);
		q->Setheight(Getheight(p));
		q->SetLeft(p->GetLeft()->GetRight());

		p->Setkey(p->GetLeft()->Getkey());
		p->Setheight(Getheight(p->GetLeft()));

		p->SetLeft(p->GetLeft()->GetLeft());
		fixheight(p);

		fixheight(q);
		return p;
	}

	Node* rotateleft(Node* q) // левый поворот вокруг q
	{
	
		

		Node* p = new Node(q->Getkey());
		p->SetLeft(q->GetLeft());
		q->SetLeft(p);
		p->Setheight(Getheight(q));
		p->SetRight(q->GetRight()->GetLeft());

		q->Setkey(q->GetRight()->Getkey());
		q->Setheight(Getheight(q->GetRight()));
	
		q->SetRight(q->GetRight()->GetRight());
				
		fixheight(q);
		
		fixheight(p);
		cout << endl;
		return q;
	
	
	}

	Node* balance(Node* p) // балансировка узла p
	{
		fixheight(p);
		
		if (bfactor(p) == 2)
		{
			cout <<
				"balanc\n";
			if (bfactor(p->GetRight()) < 0)
				p->SetRight(rotateright(p->GetRight()));
	
		 rotateleft(p);
		return p;
		
		}
		if (bfactor(p) == -2)
		{
			cout <<
				"balanc\n";
			if (bfactor(p->GetLeft()) > 0)
				p->SetLeft( rotateleft(p->GetLeft()));
			rotateright(p);
			return p;
		}
		return p; // балансировка не нужна
	}

	Node* findmin(Node* p) // поиск узла с минимальным ключом в дереве p 
	{
		return p->GetLeft() ? findmin(p->GetLeft()) : p;
	}

	Node* removemin(Node* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->GetLeft() == 0)
			return p->GetRight();
		p->SetLeft( removemin(p->GetLeft()));
		return balance(p);
	}

	Node* remove(Node* p, mySort &k) // удаление ключа k из дерева p
	{
		if (!p) return 0;
		if (k < p->Getkey())
			p->SetLeft( remove(p->GetLeft(), k));
		else if (k > p->Getkey())
			p->SetRight(remove(p->GetRight(), k));
		else //  k == p->key 
		{
			Node* q = p->GetLeft();
			Node* r = p->GetRight();
			delete p;
			if (!r) return q;
			Node* min = findmin(r);
			min->SetRight(removemin(r));
			min->SetLeft(q);
			return balance(min);
		}
		return balance(p);
	}

	Node* elFind(Node* n, mySort value) {
		if (n == NULL || n->Getkey() == value) {
			if (n == NULL) return 0;
			cout << endl << "element   " << n->Getkey() << endl;
			return n;

		}
		else if (value < n->Getkey()) {
			return elFind(n->GetLeft(), value);
		}
		else if (value > n->Getkey()) {
			return elFind(n->GetRight(), value);
		}
		
	}
};




template <class mySort>
class cTree : public Node<mySort> {
public:

	cTree(mySort &key) : Node(key) {};
	//////////////////////
	void print_preorder();
	void Find(mySort);
	void Delete(mySort&);
	/////////////////////


	void operator()( mySort &k) 
	{	
		Node* root = Get();
		insert(root, k);
		

	}

	Node* insert(Node* p, mySort &k) // вставка ключа k в дерево с корнем p
	{
		if (!p) return new Node(k);
		if (k < p->Getkey())
			p->SetLeft(insert(p->GetLeft(), k));

		else
			p->SetRight(insert(p->GetRight(), k));
		p = balance(p);
		return p;
	}

};


template <class mySort>
void cTree<mySort>::print_preorder()
{
	Node* _root = Get();

	preorder(_root);
};

template <class mySort>
void cTree<mySort>::Delete(mySort &k)
{
	Node* _root = Get();

	remove(_root,k);
};

template <class mySort>
void cTree<mySort>::Find(mySort k)
{
	Node* _root = Get();

	elFind(_root, k);
};