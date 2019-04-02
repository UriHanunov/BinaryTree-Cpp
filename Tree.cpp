/**
* this code based on https://gist.github.com/toboqus/def6a6915e4abd66e922 and https://gist.github.com/mopkaloppt/ebc5180d7b5fb01a20c8
* @author Uri Hanunov
*/

#include "Tree.hpp"
using namespace std;
using namespace ariel;

ariel::Tree::Tree()
{
	root2 = NULL;
	size_ = 0;
}

ariel::Tree::~Tree()
{
	destroy_tree();
}

void ariel::Tree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void ariel::Tree::insert(int key, node *leaf)
{
	if (key == leaf->value)
	{
		throw "ERROR: this number is already in the tree";
	}
	else if (key < leaf->value)
	{
		if (leaf->left != NULL)
		{
			insert(key, leaf->left);
		}
		else
		{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			leaf->left->parent = leaf;
			size_++;
		}
	}
	else if (key > leaf->value)
	{
		if (leaf->right != NULL)
		{
			insert(key, leaf->right);
		}
		else
		{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
			leaf->right->parent = leaf;
			size_++;
		}
	}
}

void ariel::Tree::insert(int key)
{
	if (root2 != NULL)
	{
		insert(key, root2);
	}
	else
	{
		root2 = new node;
		root2->value = key;
		root2->left = NULL;
		root2->right = NULL;
		root2->parent = NULL;
		size_++;
	}
}

Tree::node *ariel::Tree::search(int key, node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->value)
		{
			return leaf;
		}
		else if (key < leaf->value)
		{
			return search(key, leaf->left);
		}
		else
		{
			return search(key, leaf->right);
		}
	}
	else
	{
		return NULL;
	}
}

Tree::node *ariel::Tree::search(int key)
{
	return search(key, root2);
}


bool ariel::Tree::contains(int key)
{
	Tree::node *temp = search(key);
	if (temp == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Tree::destroy_tree()
{
	destroy_tree(root2);
}



void ariel::Tree::remove(node*& root2, int key)
{

	// find target node to delete
	node* target = search(key);
	if (!target) return;

	// find parent of target
	node* parent = target->parent;

	// case 1: target is a leaf
	if (target->left == NULL && target->right == NULL) {
		// set parent's child pointer
		if (parent != NULL) {
			if (parent->left == target)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root2 = NULL;

		// free target
		delete target;
		return;
	}

	// case 2: target has two children
	else if (target->left != NULL && target->right != NULL) {
		/**
		 * THIS SECTION NEEDS TO BE IMPLEMENTED ********************
		 *
		 * Add the missing lines here to make the function complete. (Hint: To
		 * remain a valid binary tree, you must replace 'target' with either
		 * its predecessor or its successor. To make the lab more easy to test,
		 * PLEASE USE THE PREDECESSOR.)
		 */

		 // Find predecessor
		node* predec_node = target->left;

		while (predec_node->right != NULL) {
			predec_node = predec_node->right;
		}

		target->value = predec_node->value;
		remove(target->left, predec_node->value);

		return;

	}

	// case 3: target has only left child
	else if (target->left != NULL) {
		// set parent's child pointer
		if (parent != NULL) {
			if (parent->left == target)
				parent->left = target->left;
			else
				parent->right = target->left;
		}
		else
			root2 = target->left;

		// free target
		delete target;
		return;
	}

	// case 4: target has only right child
	else {
		// set parent's child pointer
		if (parent != NULL) {
			if (parent->left == target)
				parent->left = target->right;
			else
				parent->right = target->right;
		}
		else
			root2 = target->right;

		// free target
		delete target;
		return;
	}
}
void ariel::Tree::remove(int key)
{
	remove(root2, key);
	/**bool temp = contains(key);
	if (temp == false)
	{
		throw "ERROR: the number is not in the tree";
	}
	else
	{
		Tree::node *temp = search(key);
		temp->parent->left = temp->left;
		temp->parent->right = temp->right;
		if (temp->left != NULL)
		{
			temp->left->parent = temp->parent;
		}
		if (temp->right != NULL)
		{
			temp->right->parent = temp->parent;
		}
		delete temp;
	}*/
}

int ariel::Tree::size(node *leaf) /////check why 2
{
	return Tree::size_;
}

int ariel::Tree::size()
{
	return size(root2);
}


int ariel::Tree::root()
{
	if (root2 != NULL)
	{
		return root2->value;
	}
	else
	{
		throw "ERROR: there is no root to the tree";
	}
}


int ariel::Tree::parent(int i)
{
	Tree::node *temp = search(i);
	if (temp != NULL)
	{
		return temp->parent->value;
	}
	else
	{
		throw "ERROR: this number is no in the tree";
	}
}


int ariel::Tree::left(int i)
{
	Tree::node *temp = Tree::search(i);
	if (temp != NULL)
	{
		if (temp->left != NULL)
		{
			return temp->left->value;
		}
		else
		{
			throw "ERROR: to this number there is not a left son";
		}
	}
	else
	{
		throw "ERROR: this number is no in the tree";
	}
}


int ariel::Tree::right(int i)
{
	Tree::node *temp = search(i);
	if (temp != NULL)
	{
		if (temp->right != NULL)
		{
			return temp->right->value;
		}
		else
		{
			throw "ERROR: to this number there is not a right son";
		}
	}
	else
	{
		throw "ERROR: this number is no in the tree";
	}
}


void ariel::Tree::inorder_print(node *leaf)
{
	if (leaf != NULL)
	{
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}


void ariel::Tree::print() //print inorder
{
	inorder_print(root2);
	cout << "\n";
}
