/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Lucas Faletra
OS: Linux(Ubuntu)
Text editor: Emacs
Hours to complete assignment: 3 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
I displayed the planets Mercury, Venus, Earth, and Mars, along with the sun
by using the x and y coordinates given in the planets.txt file. I also displayed
a space background image for one point of extra credit. I used smart pointers
to hold each Body object.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Vectors were essential for this assignment. One of the only ways to hold an
arbitrary number of smart pointers associated with body objects is to place them
into a vector. Also the assignment instructions said to use a vector for holding
the objects. Strings were also useful for me. I used strings to parse the information
contained in the planets.txt file and store that information as numberic values.
Smart pointers were also central to this assignment. I never knew about smart pointers
before this assignment, but they are actually very useful.



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
I first scaled down the radius to a reasonable size, by taking the fractional
part of the string containing the radius measurement as a substring and multiplying
it by 200. I used this as an initial coordinate to base the locations of each planet
off of. I stored the xvelocity, yvelocity, and mass as strings. I did not need to use
them for this assignment since the planets all remain in static positions. The coordinates
for each planet are stored in a sf::Vector2f which becomes the coordinates for the sprite
of each planet. The Body class has two seperate contructors. In both cases, a radius of the
universe must be provided because the x and y coordinates rely on the location of the universe's
origin. The origin of the univers is stored in a private data member called U_center.

I redefined the draw function from sf::Drawable to draw the private sprite member of each
object:
void Body::Draw(sf::RenderTarget target, sf::RenderStates states)
{
    target.draw(this->sprite);
}

I also used smart pointers in my main file to store each object. I compiled
with C++14 to so I could use make_unique. Below is the code that stores the smart pointers in a vector:

vector<unique_ptr<Body>> pointers;
for(i = 0; i < num_planets; i++)
      pointers.push_back(make_unique<Body>(radius))
for(i = 0; i < num_planets; i++)
      cin >> (*(pointers.at(i)));

the code above take the number of planets from planets.txt and creates a unique_ptr associated with an initialized Body object.
A second loop reads all information from one line into each Body object using the overloaded >> operator.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I had to search online for information about smart pointers. I have never used
them before. 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had a little bit of trouble taking the large numbers from the planets.txt file
and scaling them. There wasnt a good way for storing them immediately as numbers,
so I had to figure out how to parse the strings.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
My makefile uses C++14 to compile because make_unique is not in C++11 or any
other version before C++14.
