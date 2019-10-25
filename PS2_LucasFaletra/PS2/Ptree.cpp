#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Ptree.hpp"
using namespace std;

//this function is for accessing the points of the triangle
//I used this to get a parameter for initializing a new Ptree object
vector<sf::Vector2f> Ptree::getTriangle() const{
  vector<sf::Vector2f> temp;
  temp.push_back(this->triangle.getPoint(0));
  temp.push_back(this->triangle.getPoint(1));
  temp.push_back(this->triangle.getPoint(2));
  return temp;
}


//initial constructor. Sets the length of the base square and
//the points of both the first square and first triangle based on 2 parameters
Ptree::Ptree(double L, int N)
{ 

    this->start = L;
    this->depth = N;

    this->base.setPointCount(4); //set the coordinates of the base square
    this->base.setPoint(0, sf::Vector2f(3 * L - (L/2.0), 4 * L));//
    this->base.setPoint(1, sf::Vector2f(3 * L + (L/2.0), 4 * L)); 
    this->base.setPoint(2, sf::Vector2f(3 * L + (L/2.0), (4 * L) - L));
    this->base.setPoint(3, sf::Vector2f(3 * L - (L/2.0), (4 * L) - L));//
    
    this->base.setFillColor(sf::Color::Green);
    
    this->triangle.setPointCount(3);//set coordinates of first triangle
    sf::Vector2f p0 = this->base.getPoint(3);
    sf::Vector2f p1 = this->base.getPoint(2);
    sf::Vector2f p2;
    p2.x = (3 * L)/1.0;
    p2.y = (4 * L) - (L * 1.5);


    this->triangle.setPoint(0, p0);
    this->triangle.setPoint(1, p1);
    this->triangle.setPoint(2, p2); 


    this->points.push_back(triangle.getPoint(0));
    this->points.push_back(triangle.getPoint(1));
    this->points.push_back(triangle.getPoint(2));

    this->triangle.setFillColor(sf::Color::White);
}

/**************************************************
This is a second constructor I use for creating new objects based on the
initial Ptree object created from user input. The constructor uses a vector of three points from the previous object's triangle to create a new square, sets
a new recursion depth, and uses lr_val to determine whether the new square will
be oriented to the left or right.
****************************************************/
Ptree::Ptree(vector<sf::Vector2f> previous, int N, char lr_val){
 vector<sf::Vector2f> points;
 
 points.reserve(3);
 sf::Vector2f p3;

 this->depth = N;
 this->base.setPointCount(4);
 this->triangle.setPointCount(3);
if(lr_val == 'l')
  {
    this->base.setPoint(0, previous.at(0));
    this->base.setPoint(1, previous.at(2));

    this->base.setPoint(2, this->calculate_l_points(previous).at(0));
    this->base.setPoint(3, this->calculate_l_points(previous).at(1));
    this->triangle.setPoint(0, this->base.getPoint(3));
    this->triangle.setPoint(1, this->base.getPoint(2));

    p3.x = this->base.getPoint(3).x + ((this->base.getPoint(2).x -  this->base.getPoint(0).x) * 0.5);
    p3.y = this->base.getPoint(2).y + ((this->base.getPoint(3).y - this->base.getPoint(1).y) * 0.5);
    this->triangle.setPoint(2, p3);
  }

 
 else
   {
     this->base.setPoint(0, previous.at(2));
     this->base.setPoint(1, previous.at(1));

     this->base.setPoint(2, this->calculate_r_points(previous).at(0));
     this->base.setPoint(3, this->calculate_r_points(previous).at(1));

     this->triangle.setPoint(0, this->base.getPoint(3));
     this->triangle.setPoint(1, this->base.getPoint(2));

     p3.x = this->base.getPoint(3).x - ((this->base.getPoint(0).x - this->base.getPoint(2).x) * 0.5);
     p3.y = this->base.getPoint(2).y - ((this->base.getPoint(1).y - this->base.getPoint(3).y) * 0.5);
     this->triangle.setPoint(2, p3);
   }

 this->base.setFillColor(sf::Color::Green);
}

/****************************************************
This member function is used in the second constructor mentioned above. It
takes the vector of 3 coordinates passed to the constructor and
calculates the coordinates of the next left-oriented square
**************************************************/
vector<sf::Vector2f> Ptree::calculate_l_points(vector<sf::Vector2f> previous) const
{
  sf::Vector2f p2;
  sf::Vector2f p3;
  vector<sf::Vector2f> ret_points;
  ret_points.clear();
  ret_points.reserve(2);
  p2.x = previous.at(2).x + (previous.at(2).x - previous.at(1).x);
  p2.y = previous.at(2).y + (previous.at(2).y - previous.at(1).y);

  p3.x = previous.at(0).x + (previous.at(2).x - previous.at(1).x);
  p3.y = previous.at(0).y + (previous.at(2).y - previous.at(1).y);
  ret_points.push_back(p2);
  ret_points.push_back(p3);


  return ret_points;

}

/*****************************************************
The calculate_r_points member function is almost identical to the calculate_l_points member function, but has a different set of formulas for getting the location of the next right-oriented square. I made a separate member function for left
and right because I thought it would be easier this way.
******************************************************/
vector<sf::Vector2f> Ptree::calculate_r_points(vector<sf::Vector2f> previous) const
{
  sf::Vector2f p2;
  sf::Vector2f p3;
  vector<sf::Vector2f> ret_points;
  ret_points.clear();
  ret_points.reserve(2);

  //calculate point 2 and 3 of the next base based on previous triangle coordinates
  p2.x = previous.at(1).x + (previous.at(2).x - previous.at(0).x);
  p2.y = previous.at(1).y + (previous.at(2).y - previous.at(0).y);

  p3.x = previous.at(2).x + (previous.at(2).x - previous.at(0).x);
  p3.y = previous.at(2).y + (previous.at(2).y - previous.at(0).y);

  ret_points.push_back(p2);
  ret_points.push_back(p3);

  return ret_points;
  //returns vector of points 2 and 3 for next square to be drawn for right


}

/****************************************************
I decided to make redefine the draw function to be recursive. It uses an algorithm very similar to a preorder tree traversal to draw all the objects
**************************************************/
void Ptree::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  vector<sf::Vector2f> tri;
  
  if(this->depth >= 1)
    {
      tri = this->getTriangle();
      target.draw(this->base);
      target.draw(this->triangle, states);
      Ptree left(tri, this->depth - 1, 'l');
      target.draw(left, states);
      Ptree right(tri, this->depth - 1, 'r');
      target.draw(right, states);

    }
  else
    {
      target.draw(this->base);
      //return;
    }
 
}

/***********************************************
I made this function for testing purposes only. It is not used anywhere in the main program. All it does is print the values of the base and triangle data members
**********************************************/
void Ptree::printValues(){
  cout << "BASE:" << endl;
  cout << "POINT 0: " << this->base.getPoint(0).x << ' ' << this->base.getPoint(0).y << endl;
  cout << "POINT 1: " << this->base.getPoint(1).x << ' ' << this->base.getPoint(1).y << endl;
  cout << "POINT 2: " << this->base.getPoint(2).x << ' ' << this->base.getPoint(2).y << endl;
  cout << "POINT 3: " << this->base.getPoint(3).x << ' ' << this->base.getPoint(3).y << endl;

  cout << "TRIANGLE: " << endl;
   cout << "POINT 0: " << this->triangle.getPoint(0).x << ' ' << this->triangle.getPoint(0).y << endl;
  cout << "POINT 1: " << this->triangle.getPoint(1).x << ' ' << this->triangle.getPoint(1).y << endl;
  cout << "POINT 2: " << this->triangle.getPoint(2).x << ' ' << this->triangle.getPoint(2).y << endl;
}

