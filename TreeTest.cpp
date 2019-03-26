/**
 * Tests for the exercise on binary trees.
 * @author Uri Hanunov
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
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
  ariel::Tree mytree2;
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
	  .CHECK_EQUAL(mytree.left(6), 2)
	  .CHECK_EQUAL(mytree.right(6), 8)
	  .CHECK_EQUAL(mytree.contains(11), false)
	  .CHECK_THROWS(mytree.left(12))
	  .CHECK_OK(mytree.insert(11))
	  .CHECK_EQUAL(mytree.contains(11), true)
	  .CHECK_EQUAL(mytree.parent(11), 12)
	  .CHECK_EQUAL(mytree.contains(20), false)
	  .CHECK_THROWS(mytree.right(20))
	  .CHECK_OK(mytree.insert(20))
	  .CHECK_EQUAL(mytree.contains(20), true)
	  .CHECK_OK(mytree.right(18))
	  .CHECK_EQUAL(mytree.right(18), 20)
	  .CHECK_THROWS(mytree.left(18))
	  .CHECK_EQUAL(mytree.size(), 10)
	  .CHECK_OK(mytree.print())
	  .print();

  srand((int)time(0));
  for (int i = 0; i < 100; i++)
  {
	  int temp = (rand() % 100) + 1;
	  tc.CHECK_EQUAL(mytree2.contains(temp), false);
	  if (mytree2.contains(temp) == false)
	  {
		  mytree2.insert(temp);
	  }
	  tc.CHECK_EQUAL(mytree2.contains(temp), true);
  }
  for (int i = 0; i < 100; i++)
  {
	  int temp = (rand() % 100) + 1;
	  if (mytree2.contains(temp) == true)
	  {
		  mytree2.remove(temp);
	  }
	  tc.CHECK_EQUAL(mytree2.contains(temp), false);
  }
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
