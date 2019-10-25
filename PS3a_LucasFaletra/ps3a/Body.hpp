#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Body:public sf::Drawable{
 public:
//constructor needs to load image into texture, then load texture into sprite
  Body(double rad){this->U_center = rad;};
  Body(double radius_point, string x, string y, string velx, string vely, string m, string file_name); 

 void draw(sf::RenderTarget& target, sf::RenderStates state) const;
  friend istream &operator>>( istream &input, Body &B);
 private:
  sf::Vector2f center;
  string x, y, mass, velx, vely;
  double U_center;
  string file_name;
  sf::Texture texture;
  sf::Sprite sprite;
  
};
