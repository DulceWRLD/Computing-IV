/**********************************************************************
 *  readme.txt template                                                   
 *  Guitar Hero: GuitarString implementation and SFML audio output 
 **********************************************************************/

Name: Lucas Faletra
CS Login: lfaletra


Hours to complete assignment : 10 

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed all parts of the assignment. My program reads in keyboard input correctly by only playing notes when a key in the given string for the assignment ispressed. All 37 keys have associated notes at different frequencies.


/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 *  If you completed the AutoGuitar, what does it play?
 **********************************************************************/
I tried to distort the audio produced from the guitar string slightly to almost mimic a piano. The first few notes clearly sound different than a standard acoustic guitar because of this modification. All I needed to do was make a minor change to how the samples are stored.

/**********************************************************************
 *  Does your GuitarString implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes. I compiled my guitar string with the given unit tests. It passed all tests. I included a GStest executable
which has already been compiled. Run the GStest executable file to observe that all tests are passed. Also, if the executable is removed, it will need to be recompiled manually becuase I did not include lines in my makefile to build the GStest executable. The GStest.cpp file is included here if you would like to do this. Also do not forget to link sfml-audio and sfml-system if you decide to rebuild the GStest executable.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
none


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
My guitar string was storing vectors of samples correctly, but the sound buffer
and sound were either not being stored correctly or going out of scope before they could be played, causing no sound to play. So I instead created the sound buffers in my main file and created the sound each time a valid key is pressed.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
IMPORTANT:
When testing/grading this assignment, do not hold down a key. Holding down
a key will cause the sound associated with that key to play from the start
until the key is released. This will sound like white noise but it is not white
noise. The program only checks if a key is pressed. So please, do not deduct
points for holding down individual keys. The assignment was to create notes for
individual keys, and this program does exactly that.
