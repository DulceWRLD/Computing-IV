#include "ED.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>



ED::ED(std::string str1, std::string str2){
  
  this->first = str1;
  
  this->second = str2;
  
  int i = 0;
  
  int j = 0;
  
  int k = 0;
  
  this->first += "-";
  
  this->second += "-";
  
  int collumn_size = str1.length();
  
  int n_rows = str2.length();
  
  this->M = collumn_size;
  
  this->N = n_rows;
  
  std::vector<std::vector<int>> numbers(M + 1);
  
  for(i = 0; i <= this->N; i+=2)
    
    {
      
      numbers.at(M).push_back(this->N - (i));
      
    }
  

  for(i = 0; i <= M; i++)
    for(j = 0; j <= N; j++)
      numbers.at(i).push_back(0);
  
 for(i = (this->M); i >= 0; i--)
    
    {
      
      numbers.at(i).back() = (2 * (this->M - i));
      
    }
  

  
  this->numbers = numbers;
  }

int ED::penalty(char a, char b){
  
  if(a == b)
    
    return 0;
  
  else
    
    return 1;
  
}

int ED::min(int a, int b, int c){
  
  int min;
  
  min = std::min(a, b);
  
  min = std::min(min, c);
  
  return min;
  
}

int ED::OptDistance(){
  
  //populate the matrix
  
  //traverse it to find opt distance

  
  int i, j;
  
  int val;
  
  int distance = 0;
  
  //std::vector<std::vector<int>> numbers = this->numbers;
  
  for(i = ((M)-1); i >= 0; i--)
    
    {
      
      for(j = ((N)-1); j >= 0; j--)
	
        {
	  
          val = this->penalty(this->first.at(i), this->second.at(j));
	  
          numbers[i][j] = this->min((numbers.at(i+1).at(j+1)) + val, (numbers.at(i+1).at(j)) + 2, (numbers.at(i).at(j+1)) + 2);
	  
        }
      

      
    }
  
  this->numbers = numbers;
  
  return numbers[0][0];
  
}

std::string ED::Allignment(){
  
  std::string ret;
  
  int i = 0;
  
  int j = 0;
  int distance = this->OptDistance();
  
  
  while(i < M && j < N)
    
    {
      
      if(this->numbers[i][j] == this->numbers[i+1][j+1] + this->penalty(this->first.at(i), this->second.at(j)))
	
          {
	      ret += (this->second.at(j));
				
              ret += (" ");
	      
              ret += (this->first.at(i));
	      
              if(this->penalty(this->first.at(i), this->second.at(j)) == 0)
                  ret += (" 0  \n");
	      
              else
                  ret += (" 1  \n");
	      
              i+=1;
	      
              j+=1;
	      
           }
      

      
      else if(this->numbers[i][j] == this->numbers[i+1][j] + 2)                                                                                                        
        {                                                                                                                                        

	  ret += "- ";
						       
          ret += this->first.at(i);
	  
          ret += " 2  \n";
	  
          i+=1;
	  
        }                                                                                                                                                              
       else if(this->numbers[i][j] == this->numbers[i][j+1] + 2)                                                                                 
	 {
	   
	  ret += this->second.at(j);
									    
          ret += (" - 2   \n");
	
          j+=1;
         }
	
      
    }
    std::cout << "Edit distance is " << distance << std::endl;
    this->distance = distance;
    return ret;
  
}



