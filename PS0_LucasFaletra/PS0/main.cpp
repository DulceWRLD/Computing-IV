/***************************************
Lucas Faletra
PS0 - SFML Hello world assignment
*****************************************/

#include <SFML/Graphics.hpp>
int main(void){
   sf::RenderWindow window(sf::VideoMode(1000, 1000), "Lucas Faletra");


   int x, y = 100; //positions for sprite
   int limit = 10; //variable for frame limit
   window.setFramerateLimit(limit);

   while (window.isOpen())
       {
          sf::Event event;
          sf::Texture texture;
          texture.loadFromFile("sprite.png");
          sf::Sprite sprite;
          sprite.setTexture(texture);
          sprite.setPosition(x, y);
   
          while (window.pollEvent(event))
              {
                 if (event.type == sf::Event::Closed)
	             window.close();
                 else if(event.type == sf::Event::KeyPressed) /*if a key is pressed the sprite moves faster. Resets after reaching 100*/
	             {
	                 if(limit > 100)
	                   limit = 10;
	                 else
	                   limit += 10;
	                 window.setFramerateLimit(limit);

	             }
              }
         x+=10;
         y+=10;
         if(x >= 750 || y >= 750)/*reset the x and y coordinates if they get too far out of range*/
	      {
	             x = 100;
	             y = 100;
	      }

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde)) /*if the ~ key is pressed the sprite is briefly rotated by 50 degrees*/
	       sprite.setRotation(sprite.getRotation() + 50.0);
   window.clear();
   window.draw(sprite);
   window.display();
}

 return 0;
}
