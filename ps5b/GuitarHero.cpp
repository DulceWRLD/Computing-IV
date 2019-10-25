/****************************
Copyright Lucas Faletra 2019
**************************/
#include "GuitarString.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <cmath>
#include <cstddef>


int main() {
  float frequency;
  int i;
  ptrdiff_t index;
  sf::Sound sound;
  sf::SoundBuffer buffer;
  GuitarString G(100);
  std::vector<std::vector<sf::Int16>> samples;
  std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  int arr[] = {16, 28, 22, 4, 30, 17, 31, 19, 24, 33, 20, 34, 8, 35,
	       14, 15, 56, 46, 55, 25, 23, 3, 2, 5, 21, 6, 1, 13, 9, 12, 10, 49, 50, 48, 52, 51, 57};

  std::vector<int> numbers;
  for(i = 0; i < 37; i++)
    numbers.push_back(arr[i]);

  // create 37 sample vectors using make samples function
  for(i = 0; i < 37; i++){
    frequency = 440 * (pow(2.0, ((24 - i)/12.0)));
    G = GuitarString(frequency);
    samples.push_back(G.make_samples());
  }
  
  sf::RenderWindow window(sf::VideoMode(500, 500), "Guitar String");
  while (window.isOpen())
    {
     sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          window.close();

	// take an arbitrary key, search the vector of values
	// if the key is not found an error message is displayed
	// otherwise, take the index of the key in the vector of values,
	// then find the corresponding letter
	
	if (event.type == sf::Event::KeyPressed)
	  {
	    index = std::find(numbers.begin(), numbers.end(), event.key.code) - numbers.begin();
	    if(index < 37)
	      {
		buffer.loadFromSamples(&(samples[int(index)][0]), samples[int(index)].size(), 2, 44100);
		sound.setBuffer(buffer);
           }
	    else
	       index = -1;
	  
	    if(int(index) != -1)
	      sound.play();
	  }

      }
      
    }
  
 return 0;
 
}
