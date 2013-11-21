#include <cstdlib>
#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>

double xx[10000][2], yy[10000][2];


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
   int ntrial = 100;
    double nproc = 0.85;
    int nclusters = 5;
   float eps = 0.5;
   float gmin = 0.397887;
    
    if (argc > 1) {
    ntrial = atoi(argv[1]);
    nproc = atof(argv[2]);
    nclusters = atoi(argv[3]);
    eps = atof(argv[4]);
    gmin = atof(argv[5]);
                  }  
    
    double x[9],xMin[9],w[10000];
    double f,f2,min=10000;
    int i=0, size = 100;
    int v1, v2;
    double *ww;
   srand(108);   //srand (time(NULL));
   ofstream myfile, myfile2, myfile3;
   myfile.open ("rezvisixf.txt");
double a1 = -5 ,a2 = 10 ,a3 = 0 ,a4 = 15;

  for(int i=0;i<ntrial;i++){
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
for(int i=0;i<ntrial;i++){
if (myfile2.is_open())
 myfile2 <<  i+1 << " " << w[i] << "\n";
  }
   myfile2.close();

      myfile3.open ("rezif.txt");
    myfile3 <<  1 << " " << w[0] << "\n";
    min=w[0];
for(int i=1;i<ntrial;i++){
if (myfile3.is_open() & (min > w[i]))
{
min = w[i]; myfile3 <<  i+1 << " " << w[i] << "\n";
}
  }
   myfile3.close();

selection(w, 0, 79); // rusiuoju tik pirmus 80

cout<<endl<<"******************************************"<<endl;
cout<<"Surusiuota :"<<endl<<endl;

  for(int i=0;i<ntrial*nproc;i++)
      cout << i+1 << " : " << w[i] << " taskai : " << xx[i][0] << " " <<  xx[i][1] << endl;
      
   cout << endl << "Minimumas : " << min << endl;
   cout << "xMin = (" << xMin[0] << ", " << xMin[1] << ")" << endl;      
      
cout<<"******************************************"<<endl<<endl; // nauja sritis
cout<< nclusters <<" geriausi taskai:"<<endl;
for(int i=0;i<nclusters;i++)
cout << i+1 << " : " << w[i] << " taskai : " << xx[i][0] << " " <<  xx[i][1] << endl;
int q=0;
  for(int i=0;i<nclusters;i++)
  {
            for(int j=0;j<nclusters*nproc;j++)
            {
x[0] = frand(xx[i][0]-((a2-a1)*0.05), xx[i][0]+((a4-a3)*0.05));
yy[i*4+j][0] = x[0];
x[1] = frand(xx[i][1]-((a2-a1)*0.05), xx[i][1]+((a4-a3)*0.05));
yy[i*4+j][1] = x[1];
//cout<<yy[i*4+j][0] << "  " << yy[i*4+j][1] << endl;   (tikrinimas)
  f = branin(&x[0]); 
  
 

   if (min > f) { 
           min = f; xMin[0] = x[0]; xMin[1] = x[1];q= 1;
           cout << endl << "Pagerinome : " << f << " taskai : " << x[0] << " " <<  x[1] << endl; 
           }; 
   w[80+i*4+j]=f;
}  
}
if (q == 0) cout << endl << "Nepagerinome :( " <<endl; 
   cout << endl << "Minimumas : " << min << endl;
   cout << "xMin = (" << xMin[0] << ", " << xMin[1] << ")" << endl;
   
cout<<"******************************************"<<endl<<endl; // while variantas
cout<<"Iveskite betka, kad pradeti ieskoti, kol nerasime minimumo " << eps << " tikslumu."<<endl<<endl; // while variantas
char qqq;
cin>>qqq;
min=100000;
   srand(108);   //srand (time(NULL));   
 
    double *wq = new double [100];   
   
while (abs(min-gmin) > eps)
{
  x[0] = frand(a1, a2);
//xx[i][0] = x[0];
  x[1] = frand(a3, a4);
//xx[i][1] = x[1];
  f = branin(&x[0]);


    cout << i+1 << " : " << f << " taskai : " << x[0] << " " <<  x[1] << endl;
 if (min > f) {min = f; xMin[0] = x[0]; xMin[1] = x[1]; };
 
 if (i >= size ) 
{

ww=wq;    
wq = new double [size*2];
size*=2;

for (int j = 0; j < i; j++) wq[j]=ww[j];   
 delete[] ww;   
}


  wq[i]=f;
i++; 
  }


   cout << endl << "Minimumas : " << min << endl;
   cout << "xMin = (" << xMin[0] << ", " << xMin[1] << ")" << endl;
   cout << endl << "Minimumas su " << eps << " paklaida, rastas per " << i << " bandymu" << endl;   

    system("PAUSE");
    return EXIT_SUCCESS;
}
