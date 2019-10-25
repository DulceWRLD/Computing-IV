#include <iostream>
#include <vector>
#include <string>
#include "Body.hpp"
using namespace std;
int main(){
  
  int i = 0;
  int num_planets;
  string radius_string;
  double decimal;
  double radius;

  sf::Texture texture;
  texture.loadFromFile("background.png");
  sf::Sprite sprite;
  sprite.setTexture(texture);
  
  vector <unique_ptr<Body>> pointers;
  
  cin >> num_planets;
  cin >> radius_string;
  
  decimal = stod(radius_string.substr(0, radius_string.find("+")));
  radius = decimal * 200;

  sprite.setPosition(0, 0);
  
  for(i = 0; i < num_planets; i++)
      pointers.push_back(make_unique<Body>(radius));
  for(i = 0; i < num_planets; i++)
      cin >> *(pointers.at(i));

  sf::RenderWindow window(sf::VideoMode((radius * 2), (radius * 2)), "NBody simulation - ps3a");
  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event))
      {
	if(event.type == sf::Event::Closed)
	  window.close();
      }
    
  window.clear();
  window.draw(sprite);
  for(i = 0; i < num_planets; i++)
    window.draw(*(pointers.at(i)));
  
  window.display();
  }
  return 0;
}
