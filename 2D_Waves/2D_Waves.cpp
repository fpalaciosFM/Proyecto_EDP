#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

enum LambdaType{ NN, NP, NM, PN, PP, PM, MN, MP, MM };

unsigned int N = 36;
double a = 0.;
double b = 1.;
double DD = (b-a)/(N-1);
double DX = DD;
double DY = DD;
double DT = DD;
double T = 5.;
double S = 1;
//double C = 1;

double** u_minus;
double** u;
double** u_plus;
double** temp;

ofstream of;
ofstream ofgp;

//x_0, x_1, ..., x_i, ..., x_N-2, x_N-1
double X(unsigned int i){
    return i*DX;
}

//y_0, y_1, ..., y_j, ..., y_N-2, y_N-1
double Y(unsigned int j){
    return j*DY;
}

double arithmeticMean(double x1, double x2){
    return 0.5*(x1+x2);
}

double geometicMean(double x1, double x2){
    return sqrt(x1*x2);
}

double harmonicMean(double x1, double x2){
    return 2.*x1*x2/(x1+x2);
}

double myMean(double x1, double x2){
    return arithmeticMean(x1,x2);
}

double g = 9.81;

double H(double x, double y){
    return 1;
}

//Velocidad dependiente de la posición
double lambda(unsigned int i, unsigned int j){
    return 0.5*H(X(i),Y(j));
}

double lambda(unsigned int i, unsigned int j, LambdaType lt){
    switch (lt){
        case PN:{
            return myMean(lambda(i+1,j),lambda(i,j));
            break;
        }
        case NP:{
            return myMean(lambda(i,j+1),lambda(i,j));
            break;
        }
        case MN:{
            return myMean(lambda(i,j),lambda(i-1,j));
            break;
        }
        case NM:{
            return myMean(lambda(i,j),lambda(i,j-1));
            break;
        }
    }

    return 0;
}

double delta_u(unsigned int i, unsigned int j){
    double A = DT*DT/(DX*DX);
    double B = DT*DT/(DY*DY);
    return      {A * ( lambda(i,j,PN) * (u[i+1][j] - u[i][j]) - lambda(i,j,MN) * (u[i][j] - u[i-1][j]) )
            +    B * ( lambda(i,j,NP) * (u[i][j+1] - u[i][j]) - lambda(i,j,NM) * (u[i][j] - u[i][j-1]) )};
}

double GaussBell(double x, double y){
    return exp( -200*( x*x + y*y ) );
}

double square(double x, double y){
    return (0.4<=x && x<=0.6 && 0.4<=y && y<=0.6) ? 0.9 : 0;
}

double I(double x, double y){
    return (a<=x && x<=b && a<=y && y<=b) ? (S*(GaussBell( x-0.5 , y-0.5 ))) : 0.;
}

int main(){
    ofgp.open("Data\\AutoMake.gp");
    ofgp << "set terminal gif size 1024,768 animate delay 4" << endl;
    ofgp << "set output '2D_Waves.gif'" << endl;
    ofgp << "set xyplane at 0" << endl;
    ofgp << "set palette defined ( 0 '#090088', 1 '#0011ff', 2 '#0099ff', 3 '#00ddff', 4 '#ddffff')" << endl;
    ofgp << "set xrange [" << a-0.1 << ":" << b+0.1 << "]" << endl;
    ofgp << "set yrange [" << a-0.1 << ":" << b+0.1 << "]" << endl;
    ofgp << "set zrange [" << -1 << ":" << 1 << "]" << endl;
    ofgp << "set cbrange [" << -.15 << ":" << .15 << "]" << endl;
    ofgp << "set pm3d" << endl;
    ofgp << "set hidden3d" << endl;
    ofgp << "set dgrid3d " << N << "," << N << endl;
    ofgp << "set key Left" << endl;

    u_minus = new double*[N];
    u = new double*[N];
    u_plus = new double*[N];

    //Definición de u_minus, u y u_plus para representar la aproximación en los tiempos l-1, l y l+1 respectivamente
    for (unsigned int i = 0; i < N; i++){
        u_minus[i] = new double[N];
        u[i] = new double[N];
        u_plus[i] = new double[N];

        for(unsigned int j = 0; j < N; j++){
            u_minus[i][j] = 0;
            u[i][j] = 0;
            u_plus[i][j] = 0;
        }
    }

    //Establecer valores de condición inicial u[i][j] = I(xi, yj) i=1,...,N-2 j=1,...,N-2
    for(unsigned int i=1; i < N-1; i++){
        for (unsigned int j = 1; j < N-1; j++){
            u[i][j] = I(X(i),Y(j));
        }
    }

    //Establecer valores artificiales u_minus[i][j] = I(xi, yj) i=1,...,N-2 j=1,...,N-2
    for(unsigned int i=1; i < N-1; i++){
        for (unsigned int j = 1; j < N-1; j++){
            u_minus[i][j] = u[i][j] + 0.5*delta_u(i,j);
        }
    }

    cout << "Working..." << endl;
    for(unsigned int l=0; l*DT<=T; l++){
        cout << "Progress: " << 100.*l*DT/T << " % \r";
        of.open("Data\\data_" + to_string(l) + ".txt");

        //Actualizar puntos interiores
        for (unsigned int i = 0; i < N; i++){
            for (unsigned int j = 0; j < N; j++){
                if(i==0 || j==0 || i==N-1 || j==N-1){
                    of << X(i) << " " << Y(j) << " " << u[i][j] << endl;
                    continue;
                }
                u_plus[i][j] = 2*u[i][j] - u_minus[i][j] + delta_u(i,j);
                of << X(i) << " " << Y(j) << " " << u[i][j] << endl;
            }
        }

        //Inicializar siguiente paso
        temp = u_minus;
        u_minus = u;
        u = u_plus;
        u_plus = temp;

        of.close();
        ofgp << "splot \"data_" + to_string(l) + ".txt\" title \"I(x)=exp( -200*( (x-0.5)^2 + (y-0.5)^2 ) )\\n t=" << l*DT << "\"" << endl;
    }
    cout << "\r" << endl;
    //cout << "Progress: 100 % " << endl;
    cout << 1+T/DT << " Data Files" << endl;
    ofgp.close();

    return 0;
}