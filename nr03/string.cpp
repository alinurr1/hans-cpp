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

void string::operator += ( const string& s ){
   size_t sz = len + s.len;
   char* temp = new char[sz];
   for( size_t i = 0; i != len; ++ i )
      temp[i] = p[i];
   for( size_t i = 0; i != s.len; ++i)
      temp[i+len] = s[i];
   delete[] p;
   len = sz;
   p = temp;
}

string& operator += ( string& s1, const string& s2 ){
   size_t slen = s2.len;
   for( size_t i = 0; i != slen; ++ i)
      s1 += s2[i];
   return s1;
}

string operator + ( string s1, const string& s2 ){
   return s1+=s2;
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





