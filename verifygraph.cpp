// Builds a graph with errors, displays it and saves it as an image
#include "TH1F.h"
#include "TROOT.h"
#include "TH1.h"
#include "TStyle.h"
#include "TStyle.h"
#include <iostream>
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TF1.h"
// #include "TMath.h"
#include "cmath"
using namespace std;
void setStyle()
{
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}
/*double myfunctions(double *x,double *par){
  double a=1;
  double xx=x[0];
  double b=0.000066;
  //double val=x[0]*b;
  double val=3;
  return val;
}*/
double myfunctions(double *x,double *par){
  double i=3.88184;
  double k=9929180*1e-6;
  double L=0.3055*1e6;
  double D=0.5*1e3;
  double d=0.15*1e3;
  double xx=x[0];
  double u=55745;
  double val=i*pow((cos((k*D*(x[0]-u))/(2*sqrt((x[0]-u)*(x[0]-u)+L*L)))),2)*pow(sin(((k*d*(x[0]-u))/(2*sqrt((x[0]-u)*(x[0]-u)+L*L))))/((k*d*(x[0]-u))/(2*sqrt((x[0]-u)*(x[0]-u)+L*L))),2);
 
  return val;
}
void doppia(){

  // The values and the errors on the X and Y axis
  /*const int n_points = 4;
  double x_vals[n_points] = {2,3,5,6};
  double y_vals[n_points] = {3.1,4,4.9,6.1};
  double y_errs[n_points] = {0.1,0.1,0.1,0.1};
  double x_errs[n_points] = {0.1,0.1,0.1,0.1};
*/
  // Instance of the graph
   //TGraphErrors * graph =new TGraphErrors(n_points,x_vals,y_vals,0,y_errs);
  // TGraphErrors * graph =new TGraphErrors(n_points,x_vals,y_vals,x_errs,y_errs);
  TGraphErrors *graph = new TGraphErrors("fend_copy.dat", "%lg %lg 0 0");
  // TGraphErrors * graph =new TGraphErrors("grafico.dat","%lg %lg %lg %lg");

  graph->SetTitle("Verifica della legge di Ohm;DDP (V); Corrente (A)");

  // Cosmetics
  gStyle->SetMarkerSize(11);
  graph->SetMarkerStyle(11);
  graph->SetMarkerColor(kBlue);
  graph->SetLineColor(kBlue);

  // The canvas on which we'll draw the graph
  TCanvas *myCanvas = new TCanvas();

  // Define a linear function

 
 TF1 *f = new TF1("linear",myfunctions,50e3,60e3,0);
 TF1 *f0 = new TF1("linear1",myfunctions,50e3,51.1e3,0);
 TF1 *f1 = new TF1("linear2",myfunctions,51e3,52.1e3,0);
 TF1 *f2 = new TF1("linear3",myfunctions,52e3,53.1e3,0);
 TF1 *f3 = new TF1("linear4",myfunctions,53e3,54.1e3,0);
 TF1 *f4 = new TF1("linear5",myfunctions,54e3,55.1e3,0);
 TF1 *f5 = new TF1("linear6",myfunctions,55e3,56.1e3,0);
 TF1 *f6 = new TF1("linear7",myfunctions,56e3,57.1e3,0);
 TF1 *f7 = new TF1("linear8",myfunctions,57e3,58.1e3,0);
 TF1 *f8 = new TF1("linear9",myfunctions,58e3,59.1e3,0);
 TF1 *f9 = new TF1("linear10",myfunctions,59e3,60e3,0);


f1->Draw();

}

