// binarytree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "tree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 8;
	int j = 35;
	int k = 7;
	int q = 25;
	int w = 4;
	int e = 14;
	int r = 12;
	int t = 13;
	int d = 15;
	cTree<int> tree(i);
	//tree(q); cout << endl;
	//tree.print_preorder();
	tree(w); cout << endl;
	tree.print_preorder();
	tree(e); cout << endl;
	tree.print_preorder();
	tree(r); cout << endl;
	tree.print_preorder();
	tree(d); cout << endl;
	tree.print_preorder();
	tree(q); cout << endl;
	tree.print_preorder();
	tree(j); cout << endl;
	tree.print_preorder();
	tree.Delete(e); cout << endl;
	tree.print_preorder();
	tree.Find(4);
	
/*tree(j); cout << endl;
	tree.print_preorder();*/
		
	
	
	_getch();
	return 0;
}

