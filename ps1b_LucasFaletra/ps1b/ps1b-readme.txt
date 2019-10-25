/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Lucas Faletra
OS: Linux(Ubuntu)
Machine (e.g., Dell Latitude, MacBook Pro): Virtual Box
Text editor: Emacs
Hours to complete assignment: 2 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The purpose of this assignment was to use a Linear feedback shift register to encrypt a given image. I was able to use the LFSR class I had defined in the previous assignment to accomplish this using my LFSR.generate() function to produce a number unique to the chosen initial seed and tap position. I then performed an XOR operation with this integer and the rgb values of each pixel in the source image to produce a pixel which is either encrypted or decrypted depending on the original image.




/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
none

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had trouble thinking of how to implement a method which could both encrypt and decrypt an image, but I solved this after thinking about the assignment and some trial and error. Also the discussions in class about the assignment helped me visualize this.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Overall an interesting assignment. I never knew an LFSR could be used for encryption like this.
