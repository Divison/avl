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
		Node* q = p->GetLeft();
		p->SetLeft( q->GetRight());
		q->SetRight(p);
		fixheight(p);
		fixheight(q);
		return q;
	}

	Node* rotateleft(Node* q) // левый поворот вокруг q
	{
		Node* p = q->GetRight();
		q->SetRight( p->GetLeft());
		p->SetLeft(q);
		fixheight(q);
		fixheight(p);
		cout << endl;
	//	preorder(p);

		return p;
	
	}

	Node* balance(Node* p) // балансировка узла p
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->GetRight()) < 0)
				p->SetRight(rotateright(p->GetRight()));
		//	cout << "----" << endl;
		//	preorder(p); cout << endl;
		p = rotateleft(p);
		//	cout << " --" << endl;
			
		//	preorder(p);
		//	cout << endl << "  -- " << endl;
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->GetLeft()) > 0)
				p->SetLeft( rotateleft(p->GetLeft()));
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}

};




template <class mySort>
class cTree : public Node<mySort> {
public:

	cTree(mySort &key) : Node(key) {};
	//////////////
	void print_preorder();
	/////////////


	void operator()( mySort &k) 
	{	
		Node* root = Get();
	root=insert(root, k);
	cout << "koreshok" << endl;
	preorder(root);
	cout << "----";

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