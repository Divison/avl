// binarytree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "tree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 8;
	int j = 15;
	int k = 7;
	int q = 9;
	int w = 10;
	int e = 14;
	int r = 12;
	int t = 13;
	cTree<int> tree(i);
	tree(r); cout << endl;
	tree.print_preorder();
	tree(k); cout << endl;
	tree.print_preorder();
	tree(t); cout << endl;
	tree.print_preorder();
	tree(e); cout << endl;
	tree.print_preorder();
tree(j); cout << endl;
	tree.print_preorder();
		
	
	
	_getch();
	return 0;
}

