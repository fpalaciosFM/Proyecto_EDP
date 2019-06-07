#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

enum LambdaType{ NN, NP, NM, PN, PP, PM, MN, MP, MM };

double C = 1;
unsigned int N = 21;
double a = 0.;
double b = 1.;
double T = 6.;
double DD = (b-a)/(N-1);
double DX = DD;
// double DT = DD;
// double gamma = DX*C/DT;
double gamma = 1/M_PI;
double DT = DX*C/gamma;

double* u_minus;
double* u;
double* u_plus;
double* temp;

ofstream of;
ofstream ofgp;

//x_0, x_1, ..., x_i, ..., x_N-2, x_N-1
double X(unsigned int i){
    return i*DX;
}

double I(double x){
    return (a<=x && x<=b) ? ( (0<=x && x<=1./3.) ? 3*x/10. : 3*(1-x)/20. ) : 0.;
}

int main(){
    ofgp.open("Data\\AutoMake.gp");
    ofgp << "set terminal gif size 1024,768 animate delay 4" << endl;
    ofgp << "set output '1D_Waves.gif'" << endl;
    ofgp << "set xrange [" << a << ":" << b << "]" << endl;
    ofgp << "set yrange [" << -0.12 << ":" << 0.12 << "]" << endl;
    ofgp << "set key Left" << endl;

    u_minus = new double[N];
    u = new double[N];
    u_plus = new double[N];

    //Definición de u_minus, u y u_plus para representar la aproximación en los tiempos l-1, l y l+1 respectivamente
    for (unsigned int i = 0; i < N; i++){
        u_minus[i] = 0;
        u[i] = 0;
        u_plus[i] = 0;
    }

    //Establecer valores de condición inicial u[i][j] = I(xi, yj) i=1,...,N-2 j=1,...,N-2
    for(unsigned int i=1; i < N-1; i++){
        u[i] = I(X(i));
    }

    //Establecer valores artificiales u_minus[i][j] = I(xi, yj) i=1,...,N-2 j=1,...,N-2
    for(unsigned int i=1; i < N-1; i++){
        u_minus[i] = u[i] + 0.5*C*C*(u[i+1] - 2*u[i] + u[i-1]);
    }

    cout << "Working..." << endl;
    for(unsigned int l=0; l*DT<=T; l++){
        cout << "Progress: " << 100.*l*DT/T << " % \r";
        of.open("Data\\data_" + to_string(l) + ".txt");

        //Actualizar puntos interiores
        for (unsigned int i = 0; i < N; i++){
                if(i==0 || i==N-1){
                    of << X(i) << " " << u[i] << endl;
                    continue;
                }
                u_plus[i] = 2*u[i] - u_minus[i] + C*C*(u[i+1] - 2*u[i] + u[i-1]);
                of << X(i) << " " << u[i] << endl;
        }

        //Inicializar siguiente paso
        temp = u_minus;
        u_minus = u;
        u = u_plus;
        u_plus = temp;

        of.close();
        ofgp << "plot \"data_" + to_string(l) + ".txt\" title \"I(x)=(0<= x <=1) ? ( (0<= x <=1/3) ? 3*x/10 : 3*(1-x)/20 ) : 0\\n C = " << C << "\\n gamma = " << gamma << "\\n t=" << l*DT << "\" with lines" << endl;
    }
    cout << "\r";
    cout << "Progress: 100 % " << endl;
    cout << 1+int(T/DT) << " Data Files" << endl;
    ofgp.close();

    return 0;
}