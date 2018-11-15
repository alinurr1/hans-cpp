
#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <list>
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <sstream>
#include "string.h"

int main( int argc, char* argv [ ] )
{
   string s1 = "good";
   string s2 = " evening";
   string s3 = "good";
   std::cout << "Comparing" << "\n";
   bool something = s1 <= s3;
   std::cout << something << "\n";
   std::cout << s1[3] << "\n";
   std::cout << s1 << "\n";
   std::cout << s2 << "\n";
   s1 += 'x';
   std::cout << s1 << "\n";
   s1 += s1;
   std::cout << s1 << "\n";
   string s4 = s1 + s2;
   std::cout << s4 << "\n";
}


