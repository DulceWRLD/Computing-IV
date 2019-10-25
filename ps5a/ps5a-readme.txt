/**********************************************************************
 *  readme.txt template                                                   
 *  Guitar Hero: RingBuffer implementation with unit tests and exceptions
 **********************************************************************/

Name: Lucas Faletra



Hours to complete assignment: 1 hour

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was to implement an API for the guitar hero project with some
basic member functions. The assignment also consisted of using the BOOST unit
testing framework to test the functionality of the member functions and
exceptions created specifically for these member functions. The assignment also
required using cpplint to ensure code followed google's style guide for writing
clean, readable code.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Vectors are one way to accomplish this assignment but basic c-style arrays
could also be used and might be more efficient in some cases. Classes and data
encapsulation were also necessary for this assingment in order to create
the RingBuffer API successfully.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
I created the 6 functions and constructor listed as requirements for this assignment.

The RingBuffer constructor takes an integer parameter and stores it in the
RingBuffer private data member named capacity.

int RingBuffer::size() is a basic accessor function which returns the size private data member.

bool RingBuffer::isEmpty() uses a ternary operator to compare size with 0.
If the size is 0, it returns true. Otherwise it returns false.

bool RingBuffer::isFull() uses a ternary operator to compare size with capacity.
If size is equal to capacity, it returns true. Otherwise the function returns false.

void RingBuffer::enqueue(int16_t x) takes a 16 bit integer as a parameter and
calls push_back on the class's vector (buffer) which contains 16 bit integers.
This appends the parameter passed to the vector. enqueue also has an exception
which checks whether or not the buffer is full.

int16_t RingBuffer::dequeue() stores the first element of the buffer in a temporary variable, then erases that element from the vector. dequeue has an exceptionwhich checks if the buffer is empty before attempting to store an element.

int16_t RingBuffer::peek() returns the first element of the buffer, but does not delete it like enqueue does.


I also created boost test cases for each function, including the constructor. These test cases also test whether exceptions are thrown in the correct cases.


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed the whole assignment.




/**********************************************************************
 *  Does your RingBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes. I ran the executable and checked that my test cases made sense. The RingBuffer class passed each test case.

/**********************************************************************
 *  Explain the time and space performance of your RB implementation
**********************************************************************/
time and space performance of this API should be linear. Since the vector
only needs to push back values, adding items with enqueue should be linear in time and space. Calling dequeue should also be a linear operation since every
time the first element is removed, all other elements in the vector must be
shifted to the left.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
none


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had to look up the library to include for std::invalid_argument and std::runtime_error because I forgot the name of it.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

