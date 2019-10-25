#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "LFSR.hpp"

int main()
{
  std::string source, destination, seed;
  int tap;
  std::cin >> source;
  std::cin >> destination;
  std::cin >> seed;
  std::cin >> tap;
  
  LFSR lfsr(seed, tap); //construct the LFSR with initial seed & tap
  
	sf::Image Source_png;
	if (!Source_png.loadFromFile(source))
		return -1;

	sf::Image Destination_png;
	if(!Destination_png.loadFromFile(destination))
	  return -1;

	

	
	sf::Color p;
	sf::Color p2;
	for (unsigned int x = 0; x<Destination_png.getSize().x; x++) {
	  for (unsigned int y = 0; y<Destination_png.getSize().y; y++) {
			p = Destination_png.getPixel(x, y);
			p2 = Source_png.getPixel(x, y);
			p.r = p2.r ^ lfsr.generate(32);
			p.g = p2.g ^ lfsr.generate(32);
			p.b = p2.b ^ lfsr.generate(32);
			Destination_png.setPixel(x, y, p);
	      //set all pixels in destination image, given coordinates
	      //loops through all pixels by accessing image dimensions

	  }
	}

	sf::Vector2u size = Source_png.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "original");

	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "updated");

	sf::Texture texture_win1;
	texture_win1.loadFromImage(Source_png);

	sf::Texture texture_win2;
	texture_win2.loadFromImage(Destination_png);

	sf::Sprite sprite_win1;
	sprite_win1.setTexture(texture_win1);

	sf::Sprite sprite_win2;
	sprite_win2.setTexture(texture_win2);

	while (window1.isOpen() && window2.isOpen())
	{
		sf::Event event;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window1.close();
		}

		while (window2.pollEvent(event))
		  {
		    if(event.type == sf::Event::Closed)
		      window2.close();
		  }

		window1.clear();
		window1.draw(sprite_win1);
		window1.display();
		window2.clear();
		window2.draw(sprite_win2);
		window2.display();
	}
	if (!Destination_png.saveToFile(destination))
		return -1;

	return 0;
}
