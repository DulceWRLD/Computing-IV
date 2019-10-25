/***********************
Copyright Lucas Faletra 2019
**********************/
#include "RingBuffer.hpp"
#include <SFML/Audio.hpp>
#include <stdint.h>
#include <vector>
#include <string>

class GuitarString {
public:
  GuitarString(double frequency);
  GuitarString(std::vector<sf::Int16> init);
  void pluck();
  void tic();
  sf::Int16 sample();
  int time_();
  sf::Sound get_sound();
  std::vector<sf::Int16> make_samples();
private:
  std::vector<sf::Int16> samples;
  sf::SoundBuffer buffer;
  sf::Sound sounds;
  
  RingBuffer* RB;
  int n_tics;
};
