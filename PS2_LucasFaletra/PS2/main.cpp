#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Ptree.hpp"
using namespace std;


int main(){


  double L;
  int N;
  cin >> L;
  cin >> N;
  Ptree tree(L, N);
  sf::RenderWindow window(sf::VideoMode((6 * L), (4 * L)), "Ptree");


  while(window.isOpen())
    {
      sf::Event event;
      while(window.pollEvent(event))
	{
	  if(event.type == sf::Event::Closed)
	    window.close();
	}
      window.clear();
      window.draw(tree);
      window.display();
  

    }
  return 0;
}
