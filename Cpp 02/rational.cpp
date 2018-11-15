#include "rational.h"

int rational::gcd( int n1, int n2 ){
   if(n1 == 0){
      return n2;
   }if(n2 == 0){
      return n1;
   }
   return gcd(n2%n1, n1);
};

void rational::normalize(){
   int gcd1 = rational::gcd(num, denum);
   if(gcd1 < 0) gcd1 = gcd1 * (-1);
   if(denum < 0){
      denum = denum * (-1);
      num = num * (-1);
   }
   if(gcd1 !=1){
      num = num / gcd1;
      denum = denum / gcd1;
   }
};

rational operator - ( rational r ){
   r.num = r.num * (-1);
   return r;
};

rational operator + ( const rational& r1, const rational& r2 ){
   rational temp;
   if(r1.denum == r2.denum){
      temp.num = r1.num + r2.num;
      temp.denum = r1.denum;
      temp.normalize();
      return temp;
   }else{
      temp.num = r1.num*r2.denum + r2.num*r1.denum;
      temp.denum = r1.denum * r2.denum;
      temp.normalize();
      return temp;
   }
};

rational operator - ( const rational& r1, const rational& r2 ){
   rational temp;
   if(r1.denum == r2.denum){
      temp.num = r1.num - r2.num;
      temp.denum = r1.denum;
      temp.normalize();
      return temp;
   }else{
      temp.num = r1.num*r2.denum - r2.num*r1.denum;
      temp.denum = r1.denum * r2.denum;
      temp.normalize();
      return temp;
   }
};

rational operator * ( const rational& r1, const rational& r2 ){
   rational temp;
   temp.num = r1.num * r2.num;
   temp.denum = r1.denum * r2.denum;
   temp.normalize();
   return temp;
};

rational operator / ( const rational& r1, const rational& r2 ){
   rational temp;
   temp.num = r1.num * r2.denum;
   temp.denum = r1.denum * r2.num;
   temp.normalize();
   return temp;
};

bool operator == ( const rational& r1, const rational& r2 ){
   if(r1.num == r2.num && r1.denum == r2.denum){
      return true;
   }else{
      return false;
   }
};

bool operator != ( const rational& r1, const rational& r2 ){
   if(r1.num != r2.num && r1.denum != r2.denum){
      return true;
   }else{
      return false;
   }
};

std::ostream& operator << ( std::ostream& out, const rational& r ){
   if(r.denum == 1){
   std::cout << r.num;
   }else{
   std::cout << r.num << "/" << r.denum;
   }
};


