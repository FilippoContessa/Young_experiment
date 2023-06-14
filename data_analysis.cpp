#include <iostream>
#include <math.h>
#include <TF1.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TH1.h>




Double_t myFunction(Double_t *x, Double_t *par)
{
    Double_t I0 = par[0];
    Double_t D = par[1];
    Double_t d = par[2];
    Double_t x_0 = par[3];
    Double_t X = x[0];

    const double l = 78.4 * TMath::Power(10, 4); // micron

    const double_t k = 2 * TMath::Pi() / 0.633; //  micron

    Double_t arg1 = 0.5 * k * D * TMath::Sin((X - x_0) / l);
    Double_t arg2 = 0.5 * k * d * TMath::Sin((X - x_0) / l);

    Double_t result = I0 * TMath::Power(TMath::Cos(arg1), 2) * TMath::Power(TMath::Sin(arg2) / arg2, 2);

    return result;
}

Double_t myFunction2(Double_t *x, Double_t *par)
{
    Double_t I0 = par[0];
    Double_t D = par[1];
    Double_t d = par[2];
    Double_t x_0 = par[3];
    Double_t X = x[0];

    const double l = 78.4 * TMath::Power(10, 4); // micron

    const double_t k = 2 * TMath::Pi() / 0.633; //  micron

    Double_t arg1 = 0.5 * k * D * TMath::Sin((X - x_0) / l);
    Double_t arg2 = 0.5 * k * d * TMath::Sin((X - x_0) / l);

    Double_t result = I0 * TMath::Power(TMath::Sin(arg2) / arg2, 2);

    return result;
}

Double_t myFunction3(Double_t *x, Double_t *par)
{
    Double_t I0 = par[0];
    Double_t D = par[1];
    Double_t d = par[2];
    Double_t x_0 = par[3];
    Double_t X = x[0];

    const double l = 78.4 * TMath::Power(10, 4); // micron

    const double_t k = 2 * TMath::Pi() / 0.633; //  micron

    Double_t arg1 = 0.5 * k * D * TMath::Sin((X - x_0) / l);
    Double_t arg2 = 0.5 * k * d * TMath::Sin((X - x_0) / l);

    Double_t result = 4* I0 * TMath::Power(TMath::Cos(arg1), 2) ;
    return result;
}

void analysis()
{
    // Lettura del file di dati
    TGraph *g1 = new TGraph("Data1.txt", "%lg %lg");
    TH1 *h1 = g1->GetHistogram();

    TGraphErrors *g1R = new TGraphErrors("Data1.txt", "%lg %lg %*lg %lg");
    TH1 *h1R = g1R->GetHistogram();

    TGraph *g2 = new TGraph("Data2.txt", "%lg%lg");
    TH1 *h2 = g2->GetHistogram();

    TGraph *g4 = new TGraph("Data4_10x.txt", "%lg%lg");
    TH1 *h4 = g4->GetHistogram();

    TGraphErrors *g4R = new TGraphErrors("Data4R.txt", "%lg %lg %*lg %lg");
    TH1 *h4R = g4R->GetHistogram();


    /*   TGraph *g4_100x = new TGraph("Data4_100x.txt", "%lg%lg");
     TH1 *h4_100x = g4_100x->GetHistogram(); */

    /* TGraphErrors *g4R_100x = new TGraphErrors("Data4R_100x.txt", "%lg %lg %*lg %lg");
     TH1 *h4R_100x = g4R_100x->GetHistogram(); */

    TGraph *g5G = new TGraph("Data5_10x_Green.txt", "%lg%lg");
    TH1 *h5G = g5G->GetHistogram();

    /* TGraphErrors *g5R = new TGraphErrors("Data5R.txt", "%lg %lg %*lg %lg");
  TH1 *h5R = g5R->GetHistogram(); */

    TGraph *g5 = new TGraph("Data5_10x.txt", "%lg%lg");
    TH1 *h5 = g5->GetHistogram();

    /*  TGraph *g5_100x = new TGraph("Data5_100x.txt", "%lg%lg");
      TH1 *h5_100x = g5_100x->GetHistogram(); */

    /* TGraphErrors *g5R = new TGraphErrors("Data5R.txt", "%lg %lg %*lg %lg");
     TH1 *h5R = g5R->GetHistogram(); */

    TGraph *gI_0 = new TGraph("I_0.txt", "%lg%lg");
    TH1 *hI_0 = gI_0->GetHistogram();

    Int_t numPoints, shiftValue;

    // Definizione delle funzioni, setting parametri par[0] = I0; par[1] = D ; par[2] = d

    TF1 *f1 = new TF1("f1", myFunction, 59000, 67900, 4);
    f1->SetParameters(2.26, 300, 100, 63400);

    TF1 *f1d = new TF1("f1d", myFunction2, 59000, 67900, 4);
    f1d->SetParameters(2.33, 300, 100, 63400);
    TF1 *f1i = new TF1("f1i", myFunction3, 59000, 67700, 4);
    f1i->SetParameters(2.33, 300, 100, 63400);

    TF1 *f2 = new TF1("f2", myFunction, 59000, 67900, 4);
    f2->SetParameters(4.7, 300, 150, 63400);

    TF1 *f4 = new TF1("f4", myFunction, 58700, 69000, 4);
    f4->SetParameters(0.6, 250, 150, 63400);

    TF1 *f4_100x = new TF1("f4_100x", myFunction, -5000, 5000, 3);
    f4_100x->SetParameters(4.7, 250, 150); // verify par 1, 2

    TF1 *f5 = new TF1("f5", myFunction, 60550, 67200, 4);
    f5->SetParameters(0.5, 500, 150, 63400);

    TF1 *f5G = new TF1("f5G", myFunction, 58900, 67000, 4);
    f5G->SetParameters(0.5, 500, 150, 62900);

    TF1 *f5_100x = new TF1("f5_100x", myFunction, -2000, 2000, 3);
    f5_100x->SetParameters(4.7, 500, 150);

    TCanvas *c = new TCanvas("canvas", "Grafico");
      f5G->SetLineColor(kGreen-3);
      g1R->Fit(f1i, "R");
      


    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->SetHeader("Dati", "C"); // option "C" allows to center the header
    legend->SetFillStyle(0);
    legend->SetTextSize(0.03);
    legend->AddEntry(f1i, "Fit", "l");
     legend->AddEntry(g1R, "Dati sperimentali", "l");
  
    gStyle->SetStatX(0.9);   // Coordinata x del vertice in basso a sinistra del box
    gStyle->SetStatY(0.7);   // Coordinata y del vertice in basso a sinistra del box
    gStyle->SetStatW(0.112);   // Larghezza del box
    gStyle->SetStatH(0.10);    // Altezza del box    
    gStyle->SetOptFit(111);

    g1R->SetTitle("; x [10^-6 m]; Intensita' [unita' arbitrarie]");
    g1R->Draw();
    legend->Draw("same");
    c->Print("Data1i.png");
}
