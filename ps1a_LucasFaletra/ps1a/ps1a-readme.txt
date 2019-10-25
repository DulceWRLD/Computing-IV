/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt
 **********************************************************************/

Name: Lucas Faletra
Hours to complete assignment: 3
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was to create a functional linear feedback shift register given a series of bits and an integer for the tap position. The second part of the assignment was to perform unit tests on the linear feedback shift register after finishing the implementation. I became familiar with the boost unit testing framework while completing this assignment. I also accomplished compiling all files into a single executable file using my own makefile.

I stored the register bits as a string and used string member functions to acces bits. Then I converted the individual extracted characters to integers by subtracting 48 to get the value of the integer being represented and storing the result in integer variables. I did this because this was the easiest way I could think of accomplishing the task.

The index of the tap is obtained by subtracting the initial tap value from the initial seed length, and then subtracting 1.

I also gave the LFSR class a size data member to access for bounds checks, but it is not necessary because each member function could just use seed.length(). I just thought a size data member would make my code easier to read.


/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
None

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I encountered a problem with using the boost library when I tried to compile. I received probably 100 errors about classes from boost not being referenced properly. I googled the problem and realized I needed to add the line -lboost_unit_test_framework to my makefile when compiling the final executable. All my problems were fixed. I did not notice that the end of the assignment saysto link the assignment with the unit_test_framework library. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 This was an interesting assignment. The most difficult problems were solving the errors with boost mentioned above and learning the syntax of the boost unit testing framework.
