#include <cstdlib>
#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>

double xx[100][2];

template <class T>
  void exch(T &A, T &B)
    { T t = A ; A = B; B = t; }


template <class T>
void selection(T a[], int l, int r)
  { for (int i = l; i < r; i++)
      { int min = i;
        for (int j = i+1; j <= r; j++)
        {
                      if (a[j] < a[min]) {min = j; };
        }

        exch(a[i], a[min]);
        exch(xx[i][0], xx[min][0]);
        exch(xx[i][1], xx[min][1]);
      }
  }



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


int main(int argc, char *argv[])
{
    double x[9],xMin[9],w[110];

    double f,f2,min=0;
    int v1, v2;
   srand(100);   //srand (time(NULL));
   ofstream myfile, myfile2, myfile3;
   myfile.open ("rezvisixf.txt");


  for(int i=0;i<100;i++){
  x[0] = frand(-5, 10);
xx[i][0] = x[0];
  x[1] = frand(0, 15);
xx[i][1] = x[1];
  f = branin(&x[0]);

if (myfile.is_open())
 myfile <<  x[0] << " " << x[1] << " " << f << "\n";



    cout << i+1 << " : " << f << " taskai : " << x[0] << " " <<  x[1] << endl;
   if (i==0) min = f;
   else if (min > f) {min = f; xMin[0] = x[0]; xMin[1] = x[1]; }; w[i]=f;

  }
   cout << "Minimumas : " << min << endl;
   cout << "xMin = (" << xMin[0] << ", " << xMin[1] << ")" << endl;

   myfile.close();


   myfile2.open ("rezvisiif.txt");
for(int i=0;i<100;i++){
if (myfile2.is_open())
 myfile2 <<  i+1 << " " << w[i] << "\n";
  }
   myfile2.close();

      myfile3.open ("rezif.txt");
    myfile3 <<  1 << " " << w[0] << "\n";
    min=w[0];
for(int i=1;i<100;i++){
if (myfile3.is_open() & (min > w[i]))
{
min = w[i]; myfile3 <<  i+1 << " " << w[i] << "\n";
}
  }
   myfile3.close();

selection(w, 0, 99);
  for(int i=0;i<100;i++)
      cout << i+1 << " : " << w[i] << " taskai : " << xx[i][0] << " " <<  xx[i][1] << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
