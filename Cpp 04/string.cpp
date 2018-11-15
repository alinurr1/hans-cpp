#include "string.h"

string& string::operator += ( char c ){
   char* temp = new char[len+1];
   for( size_t i = 0; i != len; ++ i )
      temp[i] = p[i];
   temp[len] = c;
   delete[] p;
   len++;
   p = temp;
   return *this;
}

string& operator += ( string& s1, const string& s2 ){
   size_t slen = s2.len;
   for( size_t i = 0; i != slen; ++ i)
      s1 += s2[i];
   return s1;
}

string operator + ( string s1, const string& s2 ){
   return std::move( s1 += s2 );  
   return s1; // automatic move. 
}

std::ostream& operator << ( std::ostream& out, const string& s ){
   for( char c : s )
      out << c;
   return out;
}

bool operator == ( const string& s1, const string& s2 ){
   bool equal = true;
   if(s1.len == s2.len){
      for(size_t i = 0; i < s1.len; ++i){
         if(s1[i] != s2[i]) equal = false;
      }
   }else{
      equal = false;
   }
   return equal;
}

bool operator < ( const string& s1, const string& s2 ){
   bool less = true;
   size_t index = s2.len;
   if (s1 == s2) return !less;
   if (s1.len < s2.len) index = s1.len;
   for(size_t i = 0; i != index; ++i){
      if(s1[i] > s2[i]){
         return !less;
      }else if(s1[i] < s2[i]){
         return less;
      }
   } 
   if (s1.len < s2.len) less = true;
   else if (s1.len > s2.len) less = false;
   return less;
}

const string& greater( const string& s1, const string& s2 ){
   std::cout << " Reference greater for " << s1 << " " << s2 << "\n";
   if(s1 < s2) return s2;
   else return s1;
}







