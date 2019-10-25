#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "Body.hpp"

using namespace std;

Body::Body(double radius_point, string x, string y, string velx, string vely, string m, string file_name){
  this->center.x = radius_point + (stod(x.substr(0, x.find("e"))) * 200);
  this->center.y = radius_point + (stod(y.substr(0, y.find("e"))) * 200);


  //only x and y coordinates matter in this assignment, so I stored the rest of the info in strings
  this->velx = velx;
  this->vely = vely;
  this->mass = m;
  this->U_center = radius_point;

  
  this->texture.loadFromFile(file_name);
  this->sprite.setTexture(this->texture);
  this->sprite.setPosition(this->center);

}

//draw the sprite object
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const{
  target.draw(this->sprite, states);
}

//read in parameters and set the object's private data members
istream &operator>>(istream &input, Body &B){
  string tempy;
  string tempx;
  input >> tempx >> tempy >> B.velx >> B.vely >> B.mass >> B.file_name;

  //use the radius as an origin for x and y coordinates. Parse the number in the planets.txt file and scale it in a similar way to radius
  B.center.x = B.U_center + ((stod(tempx.substr(0, tempx.find("e")))) / ((11.0 - (stod(tempx.substr(tempx.find("e") + 1, tempx.length())))) * 10 + 1) * 200);
  B.center.y = B.U_center + (stod(tempy.substr(0, tempy.find("e"))) * 200);

  
  //set up the image that will be associated with the object
  B.texture.loadFromFile(B.file_name);
  B.sprite.setTexture(B.texture);
  B.sprite.setPosition(B.center);
  return input;
}



  
