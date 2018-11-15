#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include "listtest.h"
#include "vectortest.h"
#include "timer.h"

struct case_insensitive_cmp
{
  bool operator( ) ( const std::string& s1, const std::string& s2 ) const {
    bool less = true;
		for (size_t i = 0; i < s1.size(); i++) {
			int dif = s1[i] - s2[i];
      dif = abs(dif);
			if ((dif != 0) && (dif != 32)){
				if (tolower(s1[i]) > tolower(s2[i])) return false;
        if (tolower(s1[i]) < tolower(s2[i])) return true;
			}
		}
		if(less == true) return s1.size() < s2.size();
    else return less;
	};
};

struct case_insensitive_hash{
  size_t operator ( ) ( const std::string& s ) const{
    size_t h = 0;
    for( size_t i = 0; i != s. length( ); ++ i )
    {
      h += std::tolower(s[i]) * 5^i;
    }
    return h;
  };
};

struct case_insensitive_equality{
  bool operator ( ) ( const std::string& s1,const std::string& s2 ) const{
    if(s1.size() != s2.size()) return false;
    for(size_t i = 0; i < s1.size(); i++){
      int dif = s1[i] - s2[i];
      dif = abs(dif);
      if(dif != 0 and dif != 32) return false;
    }
    return true;
  };
};

std::map< std::string, unsigned int, case_insensitive_cmp >
frequencytable(const std::vector< std::string > &text ){
  std::map< std::string, unsigned int, case_insensitive_cmp > table;
  if(!text.empty()){
    int size = text.size();
    for(int i = 0; i < size; i++){
      std::string str = text[i];
    //  int counter = 1;
      //if(table.count(str) != 0){
        //counter = table[str] + 1;
      //}
      table[str]++;
    }
    return table;
  }
  return table;
};

std::unordered_map< std::string, unsigned int,case_insensitive_hash, case_insensitive_equality >
hashed_frequencytable( const std::vector< std::string >& text ){
  std::unordered_map< std::string, unsigned int, case_insensitive_hash, case_insensitive_equality > table;
  if(!text.empty()){
    int size = text.size();
    for(int i = 0; i < size; i++){
      std::string str = text[i];
      //int counter = 1;
      //if(table.count(str) != 0){
        //counter = table[str] + 1;
      //}
      table[str]++;
    }
    return table;
  }
  return table;
};

std::ostream&operator << ( std::ostream& out , const std::map< std::string, unsigned int, case_insensitive_cmp> &freq ){
  for(auto& element: freq){
    out << element.first << " - > " << element.second << "\n";
  }
  return out;
}

std::pair<std::string, unsigned int> most_frequent(const std::vector< std::string > & text ){
  std::map<std::string, unsigned int, case_insensitive_cmp> map = frequencytable(text);
  std::pair<std::string, unsigned int> temp = {"Temporary" , 0};
  for(auto& element: map){
    if (element.second > temp.second) temp = element;
  }
  return temp;
}

int main( int argc, char* argv [] )
{
  case_insensitive_cmp c;
  std::cout << c( "a", "A" ) << c( "a","b" ) << c( "A", "b" ) << "\n";
  case_insensitive_equality e;
  std::cout << e( "xxx", "XXX" ) << "\n";
  std::cout << frequencytable( std::vector< std::string >{ "AA", "aA", "Aa", "this", "THIS" });
  case_insensitive_hash h;
  std::cout << h( "xxx" ) << " " << h( "XXX" ) << "\n";
  std::cout << h( "Abc" ) << " " << h( "abC" ) << "\n";
  std::cout << h( "ba" ) << " " << h( "ab" ) << "\n";
  std::ifstream file("book.txt");
  std::vector <std::string> book = vectortest::readfile(file);
  std::unordered_map<std::string, unsigned int, case_insensitive_hash, case_insensitive_equality> umap;
  umap = hashed_frequencytable(book);
  std::cout << "Magnus: " << umap["magnus"] << "\n";
  std::cout << "Hominum: " << umap["hominum"] << "\n";
  std::cout << "Memoria: " << umap["memoria"] << "\n";
  std::pair<std::string, unsigned int> frequent = most_frequent(book);
  std::cout << "Most frequent word: " << frequent.first << " " << frequent.second << " times." <<"\n";
  return 0;
}
