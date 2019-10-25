/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name:Lucas Faletra

Hours to complete assignment: 7



/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
 In this assignment, I first created a matrix from a vector of vectors. The dimensions were MxN where M corresponds to the second string and N corresponds to the first string. I then created the final row and the final collumn using the
 information given in the assignment. Each element of the last collumn at index j is 2 * (N - j) and each element in the final row at i is 2 * (M - i).
Using those values as a base, I filled the rest of the matrix with the proper values. Finally, using the algorithm described in the assignment, I iterated through the matrix to find the optimal allignment, appending the result of each step to the final string to be output to the command line.


/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: atattat
       tattata

Expected output: t - 2
	 	 a a 0
		 t t 0
		 t a 1
		 a t 1
		 t t 0
		 a a 0
		 - t 0

What happened:   t - 2
	 	 a a 0
		 t t 0
		 t a 1
		 a t 1
		 t t 0
		 a a 0
		 - t 0


		



/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2 GB to 16 GB.
 **********************************************************************/
8 GB


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 8
b = 2
largest N = roughly 31,500

Filling the entire matrix requires N^2 space if M and N are equal. Traversing
through the matrix also requires reading and storing results for the final string

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
 *  Answer yes, no, I didn't try, I tried and failed, or I used a 
 *  different tool.
 *
 *  If yes, paste in the ms_print top chart of memory use over time,
 *  and also indicate which file your code was solving.
 * 
 *  Explain if necessary.
/**********************************************************************
Yes

Here is the chart for ecoli20000.txt:

    GB
3.933^                              ######################################### 
     |                              #                                         
     |                              #                                         
     |                              #                                         
     |                              #                                         
     |                              #                                         
     |                              #                                         
     |                             :#                                         
     |                            @@#                                         
     |                          @@@@#                                         
     |                       @@@@@@@#                                         
     |                     @@@@@@@@@#                                         
     |                   @@@@@@@@@@@#                                         
     |                 @@@@@@@@@@@@@#                                        :
     |              :@@@@@@@@@@@@@@@#                                        :
:





/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       118             0.081781            63.22
ecoli5000.txt       160             0.304056            252.2
ecoli7000.txt       194             0.571946            406.4
ecoli10000.txt      223             1.11973             984
ecoli20000.txt      3135            4.55704             3.933
ecoli28284.txt      8335            8.74898             6436

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 4
b = 2 
largest N = 440,000,000

using the data from the sample cases, time quadruples each time
M doubles. There are 86,400 seconds each day. 7.730 times 11000 is very close to this, therefore the largest N should be close to (20,000 * 2) * 11,000 which is 440,000,000

/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where (describe a method or provide a lines numbers)
 **********************************************************************/
no



**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
none


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I was getting segmentation faults because I was accessing the wrong indexes of
my vectors. I also started out allocating all the memory for this assingment
dynamically but there were too many problems so I rewrote the entire thing.
The description of the assignment was also very confusing.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
I have not used valgrind in a while. I was not aware you can view the memory
used by a program like this.
