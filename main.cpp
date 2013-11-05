#include <cstdlib>
#include <iostream>
#include <cmath>
#include <time.h>  

using namespace std;
const double pi = 3.1415926535897932384626433832795 ;

double frand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

double branin(double *x)
{
  return ((x[1]-(5.1/(4*(pi*pi)))*(x[0]*x[0])+5*x[0]/pi-6)*(x[1]-(5.1/(4*(pi*pi)))*(x[0]*x[0])+5*x[0]/pi-6)+10*(1-(1/(8*pi)))*cos(x[0])+10);       
}

//double easom(double x[1], double x[2])
//{
// return (-cos(a)*cos(b)*exp(-(a-pi)^2-(b-pi)^2)) ;       
//}

int main(int argc, char *argv[])
{
    double x[9],xMin[9];
    double f,f2,min=0;
    int v1, v2;
   srand(100);   //srand (time(NULL));

  for(int i=0;i<100;i++){
  x[0] = frand(-5, 10);  
  x[1] = frand(0, 15); 
      f = branin(&x[0]);
        cout << i+1 << " : " << f << " taskai : " << x[0] << " " <<  x[1] << endl;
   if (i==0) min = f;
   else if (min > f) {min = f; xMin[0] = x[0]; xMin[1] = x[1]; };      
  }
   cout << "Minimumas : " << min << endl;
   cout << "xMin = (" << xMin[0] << ", " << xMin[1] << ")" << endl;

  
    system("PAUSE");
    return EXIT_SUCCESS;
}
