#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
using namespace std;

class Ptree:public sf::Drawable{
public:
Ptree(double L, int N); 
Ptree(vector<sf::Vector2f> previous, int N, char lr_val);
int getDepth() const {return depth;}; //basic accessor for main function
  vector<sf::Vector2f> calculate_r_points(vector<sf::Vector2f> previous) const;
  vector<sf::Vector2f> calculate_l_points(vector<sf::Vector2f> previous) const;

  void printValues();

  vector<sf::Vector2f> getTriangle()const;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
  double start;
  int depth;


  sf::ConvexShape base;         //base is only utilized if first constructor called
  sf::ConvexShape triangle;     //after base called, init remaining shapes


  vector<sf::Vector2f> points;


};
