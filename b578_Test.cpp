#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
 
 long double n,a,b,c;
 cin>>n;
 while(n--)
 {
  cin>>a>>b>>c;
  cout << a << "\n\n\n" << endl;
  if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b)
  {
   cout << "right triangle" <<endl;
  }
  else if(a*a<b*b+c*c&&b*b<a*a+c*c&&c*c<a*a+b*b)
  {
   cout << "acute triangle" <<endl;
  }
  else
  {
   cout << "obtuse triangle"<<endl;
  }
 }
 return 0;
}


