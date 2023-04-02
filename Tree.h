#include <iostream>
#pragma once
template <class T>
class Tree {

private:
	T** list;			///Lista de adiacenta pentru fiecare nod
	int num_of_nods;	///cate noduri am in arbore
	int list_count[256];	///cati vecini are fiecare nod -> imi crapa daca o fac cu * ...incerc mai tarziu
public:
	Tree():num_of_nods(0), list(nullptr), list_count() {};
	~Tree() {
		for (int i = 0; i < num_of_nods; i++)
			delete[]list[i];
		delete[]list;
	}
	void add_node(T parent_node, T child) {

		if (num_of_nods == 0)
		{
			list = new T*[1];
			list[0] = new T[2];
			list[child] = new T[1];
			

			list[0][0] = parent_node;
			list[0][1] = child;
			list[child][0] = child;
			list_count[0] = 2;
			list_count[child] = 1;
			
			num_of_nods = 2;
		}
		else 
		{
			T** copy = list;
			list = new T *[num_of_nods + 1];	///am mai bagat un nod nou la sf
			for (int i = 0; i < num_of_nods; i++)
			{
				if (i == parent_node)	list[i] = new T[list_count[i] + 1];	///am mai bagat un loc in plus pt LAD
				else					list[i] = new T[list_count[i]];


				for (int j = 0; j < list_count[i]; j++)
					list[i][j] = copy[i][j];

			}
			list_count[parent_node]++;			
			list_count[child] = 1;
			list[child] = new T[2];	///aloc si pt noul nod memorie
			list[child][0] = child;
			list[child][1] = 0;
			list[parent_node][list_count[parent_node] - 1] = child;

			num_of_nods++;
			//std::cout << "num of nod:" << num_of_nods << std::endl;
		}

	}
	T get_node(T child) {

		for (int i = 0; i < num_of_nods; i++)
			for (int j = 0; j < list_count[i]; i++)
				if (list[i][j] == child)
					return i;
		return 0;
	}
	void delete_node(T node) {

		//T** copy = list;
		//list = new T *[num_of_nods - 1];

		for (int i = 0; i < node; i++)
		{
			for(int j = 1 ; j < list_count[i]; j++)
				if (j == node)
				{
					for (int k = j; k < list_count[i] - 1; k++)
						list[i][k] = list[i][k + 1];
					list_count[i]--;
				}
		}
		for (int i = node; i < num_of_nods - 1; i++)
		{
			list[i] = new T[list_count[i + 1]];
			for (int j = 0; j < list_count[i + 1]; j++)
				list[i][j] = list[i + 1][j];

			list_count[i] = list_count[i + 1];
		}
		num_of_nods--;
	}
	void count() {
		for(int i = 0 ; i < num_of_nods; i++)
			std::cout<<list[i][0]<<" has "<<list_count[i] - 1 <<" children\n";
	}
	void sort(T node, bool* (callback)(T,T))
	{
		for(int i = 1; i < list_count[node] - 1; i++)
			for(int j = i + 1; j < list_count[node]; j++)
				if (callback == nullptr)
				{
					if (list[node][i] < list[node][j])
						swap(list[node][i], list[node][j]);
				}
				else
				{
					if(callback(list[node][i], list[node][j]))
						swap(list[node][i], list[node][j]);
				}
	}
	void Print_Nodes() {

		for (int i = 0; i < num_of_nods; i++)
		{
			std::cout << "Nodul " << list[i][0] << " are urm fii: ";
			if(list_count[i]!=NULL)
				//for (int j = 1; j < list_count[i]; j++) -> ONLY FOR QUICK DEBUG
				for (int j = 1; j < list_count[i]; j++)
					std::cout << list[i][j] << ' ';
			std::cout << '\n';
		}
		
	}
	//TO - DO//
	// find method - > nu inteleg ce face ???
	//functia de insert e same cu add node -> nu vad diferenta intre ele....
};