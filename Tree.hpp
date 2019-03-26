#include <iostream>

namespace ariel
{
	class Tree
	{
	public:
		void insert(int i);
		void remove(int i);
		int size();
		bool contains(int i);
		int root();
		int parent(int i);
		int left(int i);
		int right(int i);
		void print();
	};
	
};
