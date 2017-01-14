// This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
// To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/ or send a letter to
// Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.


#ifndef ODEPACK_DLSODA_H
#define ODEPACK_DLSODA_H
#include <math.h>

class odepack_dlsoda {

public:
  
  odepack_dlsoda(int npar_, int neq_);
  virtual ~odepack_dlsoda();
  
  void hmax(double value){xrwork[5] = value; if(value !=0) xiopt=1;}
  void hmin(double value){xrwork[6] = value;  if(value !=0) xiopt=1;}
  void ixpr(int value){xiwork[4] = value; if(value !=0) xiopt=1;}
  void maxsteps(int value){xiwork[5] = value; if(value !=0) xiopt=1;}
  void mxhnil(int value){xiwork[6] = value; if (value !=0) xiopt=1;}
  int  istate(){return xistate;}
  void istate(int value){xistate = value;}
  void lsoda_init(){xistate=1;}
  int  itask(){return xitask;}
  void itask(int itask){xitask = itask;}
  void tol(double atol, double rtol);
  
  double* rwork(){return xrwork;}
  void    rwork(int pos, double value){xrwork[pos] = value;}
  int*    iwork(){return xiwork;}
  void    iwork(int pos,int value){xiwork[pos] = value;}
  void    tcrit(double value){xrwork[0] = value;}
  double* y(){return Y;}
  void    y(const int pos, const double value){Y[pos] = value;}
  double  y(const int pos){return Y[pos];}
  double* ydot(){return Ydot;}
  
  int     npar() {return Npar;}
  int     neq(){return Neq;}
  
protected :

  int     xliwork, xlrwork,xistate;
  int     xitask,xiopt,xitol;
  int     Neq, Npar;
  int     xjt;
  double  xatol,xrtol;
  double* xrwork;
  int*    xiwork;
  double* Y;
  double* Ydot;
};


#endif


