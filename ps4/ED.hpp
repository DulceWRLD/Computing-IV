#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
class ED{
public:
  ED(std::string str1, std::string str2);
  int penalty(char a, char b);
  int min(int a, int b, int c);
  int OptDistance();
  int get_distance(){return this->distance;};
  std::string Allignment();
  
private:
  std::string first, second;
  std::vector<std::vector<int>> numbers;
  int M, N;
  int distance;
  
};  
