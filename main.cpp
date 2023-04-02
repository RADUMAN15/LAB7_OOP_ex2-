#include <iostream>
#include "Tree.h"

int main()
{
	Tree <int>copac;
	copac.add_node(0, 1);
	copac.add_node(0, 2);
	copac.add_node(1, 3);
	copac.add_node(2, 4);
	copac.add_node(3, 5);
	copac.add_node(3, 6);
	copac.add_node(5, 7);
	copac.add_node(5, 8);
	copac.Print_Nodes();
	std::cout << '\n';
	copac.delete_node(1);
	//copac.delete_node(2);
	copac.Print_Nodes();
	std::cout << '\n';
	copac.count();
	std::cout << "Tatal nodului 4 este: " << copac.get_node(4) << '\n';
}