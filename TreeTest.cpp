/**
 * Tests for the exercise on binary trees.
 * @author Uri Hanunov
 */

#include <iostream>
#include "badkan.hpp"
#include "Tree.hpp"
using std::cout, std::endl;
using namespace ariel;

int main()
{
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree; 
  mytree.insert(10);
  mytree.insert(3);
  mytree.insert(6);
  mytree.insert(2);
  mytree.insert(15);
  mytree.insert(12);
  mytree.insert(13);
  mytree.insert(8);
  mytree.insert(18);



  badkan::TestCase tc("Binary tree");
  tc
	  .CHECK_EQUAL(emptytree.size(), 0)
	  .CHECK_OK(emptytree.insert(5))
	  .CHECK_EQUAL(emptytree.size(), 1)
	  .CHECK_EQUAL(emptytree.contains(5), true)
	  .CHECK_OK(emptytree.remove(5))
	  .CHECK_EQUAL(emptytree.contains(5), false)
	  .CHECK_THROWS(emptytree.remove(5))
	  .CHECK_EQUAL(emptytree.size(), 0)

	  .CHECK_EQUAL(threetree.size(), 3)
	  .CHECK_EQUAL(threetree.root(), 5)
	  .CHECK_EQUAL(threetree.parent(3), 5)
	  .CHECK_EQUAL(threetree.parent(7), 5)
	  .CHECK_EQUAL(threetree.left(5), 3)
	  .CHECK_EQUAL(threetree.right(5), 7)
	  .CHECK_THROWS(threetree.insert(3))
	  .CHECK_THROWS(threetree.left(6))
	  .CHECK_OK(threetree.print())
	  .print()

	  .CHECK_EQUAL(mytree.size(), 9)
	  .CHECK_EQUAL(mytree.root(), 10)
	  .CHECK_EQUAL(mytree.parent(12), 15)
	  .CHECK_EQUAL(mytree.parent(2), 3)
	  .CHECK_EQUAL(mytree.parent(6), 3)
	  .CHECK_EQUAL(mytree.left(10), 3)
	  .CHECK_EQUAL(mytree.right(10), 15)
	  .CHECK_THROWS(mytree.insert(6))
	  .CHECK_THROWS(mytree.left(4))
	  .CHECK_THROWS(mytree.remove(7))
	  .CHECK_EQUAL(mytree.contains(12), true)
	  .CHECK_EQUAL(mytree.contains(4), false)
	  .CHECK_OK(mytree.remove(3))
	  .CHECK_EQUAL(mytree.size(), 8)
	  .CHECK_EQUAL(mytree.root(), 10)
	  .CHECK_EQUAL(mytree.parent(6), 10)
	  .CHECK_EQUAL(mytree.left(10), 6)
	  .CHECK_EQUAL(mytree.contains(3), false)
	  .CHECK_THROWS(mytree.remove(3))

	  .CHECK_OK(mytree.print());
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}