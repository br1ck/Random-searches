#include <cstdlib>
#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>

double xx[100][2], yy[20][2];

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
   srand(101);   //srand (time(NULL));
   ofstream myfile, myfile2, myfile3;
   myfile.open ("rezvisixf.txt");
double a1 = -5 ,a2 = 10 ,a3 = 0 ,a4 = 15;

  for(int i=0;i<100;i++){
  x[0] = frand(a1, a2);
xx[i][0] = x[0];
  x[1] = frand(a3, a4);
xx[i][1] = x[1];
  f = branin(&x[0]);

if (myfile.is_open())
 myfile <<  x[0] << " " << x[1] << " " << f << "\n";

    cout << i+1 << " : " << f << " taskai : " << x[0] << " " <<  x[1] << endl;
   if (i==0) min = f;
   else if (min > f) {min = f; xMin[0] = x[0]; xMin[1] = x[1]; }; w[i]=f;

  }

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

selection(w, 0, 79); // rusiuoju tik pirmus 80

cout<<endl<<"******************************************"<<endl;
cout<<"Surusiuota :"<<endl<<endl;

  for(int i=0;i<80;i++)
      cout << i+1 << " : " << w[i] << " taskai : " << xx[i][0] << " " <<  xx[i][1] << endl;
      
   cout << endl << "Minimumas : " << min << endl;
   cout << "xMin = (" << xMin[0] << ", " << xMin[1] << ")" << endl;      
      
cout<<"******************************************"<<endl<<endl; // nauja sritis
cout<<"5 geriausi taskai:"<<endl;
for(int i=0;i<5;i++)
cout << i+1 << " : " << w[i] << " taskai : " << xx[i][0] << " " <<  xx[i][1] << endl;

  for(int i=0;i<5;i++)
  {
            for(int j=0;j<4;j++)
            {
x[0] = frand(xx[i][0]-((a2-a1)*0.05), xx[i][0]+((a4-a3)*0.05));
yy[i*4+j][0] = x[0];
x[1] = frand(xx[i][1]-((a2-a1)*0.05), xx[i][1]+((a4-a3)*0.05));
yy[i*4+j][1] = x[1];
//cout<<yy[i*5+j][0] << "  " << yy[i*5+j][1] << endl;   (tikrinimas)
  f = branin(&x[0]); 
  
  // cout << i*4+j+1 << " : " << f << " taskai : " << x[0] << " " <<  x[1] << endl;

   if (min > f) {
           min = f; xMin[0] = x[0]; xMin[1] = x[1];
           cout << endl << "Pagerinome : " << f << " taskai : " << x[0] << " " <<  x[1] << endl; 
           }; 
   w[80+i*4+j]=f;
}  
}

   cout << endl << "Minimumas : " << min << endl;
   cout << "xMin = (" << xMin[0] << ", " << xMin[1] << ")" << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
