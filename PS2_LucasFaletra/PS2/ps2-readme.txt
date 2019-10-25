/**********************************************************************
 *  ps2-readme template                                                   
 *  Recursive Graphics (Pythagoras tree)                       
 **********************************************************************/

Your name: Lucas Faletra

Hours to complete assignment: 7 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was to draw a pythagoreas tree by making a class whch can recursively
draw itself to the screen. The dimensions and depth of recursion are determined by
the two parameters the user enters. The first parameter from the user determines the length
of the sides of the base square, and window has a width of 6 times this length and a height
of 4 times the length of the side of the base square. The user also enters a second parameter
which determines the depth of recursion(how many times the tree will branch out). I implemented
this by creating a Ptree class with two ConvexShape objects from the SFML library. One object is
a square and the other is a triangle. Using the public member functions I created, I can use the
x and y coordinates of the current square and triangle to determine the coordinates of the next
square and triangle. Once the program gets the coordinates of the next two shapes, a new Ptree is
created using the second constructor. The depth of recursion also decrements each time a
new Ptree is created. As the depth decrements, all objects are drawn recursively until the depth reaches 0.

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
One key algorithm that I used during this assignment was the preorder traversal of a binary search tree.
My draw function is very similar to this algorithm since it first evaluates and draws the current
Ptree, then procedes to the left, then to the right after finishing the left in a recursive pattern.
A data structure which was very helpful in this assignment was a vector. Since coordinates are stored
in vectors, the easiest way for me to store multiple coordinates was to create a vector containing
the sf::Vector2f type.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
I added color to my tree for extra credit by setting the fill color of
the triangle and square of each Ptree object
On lines 34, and 103 in the Ptree.cpp file, there are lines that set the color
of the objects.

I used the setFillColor member function for the ConvexShape class like this:

this->base.setFillColor(sf::Color::Green);

Since this line is in the constructor, each time a new object is made, the square is automatically colored green.


 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
In this assignment I learned how to recursively create shapes using the SFML
library. I also learned about fractals and how to use them to create interesting
objects. Another thing I learned in this assignment was that certain algorithms
are easily transferable to many different kinds of projects, as was the case of
using a tree traversal algorithm in my draw function.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I had to read a lot of the documentation on the ConvexShape object in SFML,
but other than the SFML documentation, I had no help from anyone else.


/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
I encountered a problem where my program would have a segmentation fault.
Apparently it was because I forgot to call setPointCount on the ConvexShape
objects in my Ptree class and a segmentation fault occurs if you try to set
the coordinates of points without giving the object a point count. I also
spent a lot of time trying to come up with formulas that could calculate
the coordinates of both the left and right squares, but after a lot of trial
and error and thinking about the problem for a couple days, I created four
formulas that work for any recursion depth, given a base square and base triangle.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
This assignment was difficult, but very fun and interesting. I really do
enjoy solving puzzles like this.
