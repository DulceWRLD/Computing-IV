#include "ED.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
int main(){

  sf::Clock clock;
  sf::Time t;
  
  std::string str1, str2;
  
  std::cin >> str1;
  
  std::cin >> str2;
  
  ED test(str1, str2);
  
  std::cout << test.Allignment();

  std::cout << test.get_distance() << std::endl;
  t = clock.getElapsedTime();
  std::cout << "Execution time is " << t.asSeconds() << " seconds" << std::endl;
  return 0;
}  
