
#include<cmath>
#include<fstream>
#include<iostream>

using namespace std;

void hamiltonian(double& H, double& p1, double& p2, double& q1, double& q2);
//-----------------------------------------------------------------------------------------------------
int main(){
  const double dt = 0.05,
	       tend = 20*M_PI,
	       e = 0.6;
  const int N = int(tend/dt);
  double p1, p2, q1, q2, t, H, Rq;
  q1 = 1-e;			//initial conditions
  q2 = 0;
  p1 = 0;
  p2 = sqrt((1+e)/(1-e));
  hamiltonian(H, p1, p2, q1, q2);
  
  ofstream out("data.txt");
  out <<  0 << "\t" << q1 << "\t" << q2 << "\t" << p1 << "\t" << p2 << "\t" << H << endl; 
  
  for(int i=1; i<N; i++){
    t = i*dt;

    Rq = pow(q1,2)+pow(q2,2);
    
    p1 -= dt*pow(Rq,-3./2)*q1;
    p2 -= dt*pow(Rq,-3./2)*q2;
    q1 += dt*p1;
    q2 += dt*p2;
    
    hamiltonian(H, p1, p2, q1, q2);
      
    out <<  t << "\t" << q1 << "\t" << q2 << "\t" << p1 << "\t" << p2 << "\t" << H << endl; 
  }
  
  
  
  out.close();
  return 0;
}



void hamiltonian(double& H, double& p1, double& p2, double& q1, double& q2){
  H = 0.5*(pow(p1,2)+pow(p2,2))-1./(sqrt(pow(q1,2)+pow(q2,2)));
}

