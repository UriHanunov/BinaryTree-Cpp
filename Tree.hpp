#include <iostream>
using namespace std;

namespace ariel
{
	class Tree
	{
		struct node
		{
			int value;
			node *left;
			node *right;
			node *parent;
		};

		public:
			Tree();
			~Tree();

			void insert(int key);
			void remove(int key);
			int size();
			bool contains(int key);
			int root();
			int parent(int key);
			int left(int key);
			int right(int key);
			void print();
			node *search(int key);
			void destroy_tree();

		private:
			node *root2;
			void destroy_tree(node *leaf);
			int size(node *leaf);
			node *search(int key, node *leaf);
			void insert(int key, node *leaf);
			void inorder_print(node *leaf);

	};
	
};
