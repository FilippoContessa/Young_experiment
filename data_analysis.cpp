#include <iostream>
#include <math.h>
#include <TF1.h>
#include <TGraph.h>
#include <TCanvas.h>
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

    Double_t arg1 = 0.5 * k * D * TMath::Sin((X-x_0) / l);
    Double_t arg2 = 0.5 * k * d * TMath::Sin((X-x_0) / l);

    Double_t result = I0 * TMath::Power(TMath::Cos(arg1), 2) * TMath::Power(TMath::Sin(arg2) / arg2, 2);

    return result;
}

void analysis()
{
    // Lettura del file di dati
    TGraph *g1 = new TGraph("Data1.txt", "%lg %lg");
    TH1 *h1 = g1->GetHistogram();


    TGraphErrors *g1R = new TGraphErrors("Data1R.txt", "%lg %lg %*lg %lg");
    TH1 *h1R = g1R->GetHistogram();

    TGraph *g2 = new TGraph("Data2.txt", "%lg%lg");
    TH1 *h2 = g2->GetHistogram();

    TGraph *g4 = new TGraph("Data4_10x.txt", "%lg%lg");
    TH1 *h4 = g4->GetHistogram();

    TGraph *g4_100x = new TGraph("Data4_100x.txt", "%lg%lg");
    TH1 *h4_100x = g4_100x->GetHistogram();

    TGraph *g5G = new TGraph("Data5_10x_Green.txt", "%lg%lg");
    TH1 *h5G = g5G->GetHistogram();

    TGraph *g5 = new TGraph("Data5_10x.txt", "%lg%lg");
    TH1 *h5 = g5->GetHistogram();

    TGraph *g5_100x = new TGraph("Data5_100x.txt", "%lg%lg");
    TH1 *h5_100x = g5_100x->GetHistogram();

    TGraph *gI_0 = new TGraph("I_0.txt", "%lg%lg");
    TH1 *hI_0 = gI_0->GetHistogram();

    Int_t numPoints; 
    Int_t shiftValue; 
    
    // g1 shift

    /*
    numPoints= g1->GetN();
    shiftValue= 63400;
    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        g1->GetPoint(i, x, y);

        x -= shiftValue;

        g1->SetPoint(i, x, y);
    }
    // g1R shift
   numPoints= g1R->GetN();
    shiftValue= 63400;
    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        g1R->GetPoint(i, x, y);

        x -= shiftValue;

        g1R->SetPoint(i, x, y);
    }

    // g2 shift
    numPoints = g2->GetN();
    shiftValue = 64200;
    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        g2->GetPoint(i, x, y);

        x -= shiftValue;

        g2->SetPoint(i, x, y);
    }
    // g4 shift
    numPoints = g4->GetN();
    shiftValue = 63800;
    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        g4->GetPoint(i, x, y);

        x -= shiftValue;

        g4->SetPoint(i, x, y);
    }
    // g4_100x shift
    numPoints = g4_100x->GetN();
    shiftValue = 63800;
    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        g4_100x->GetPoint(i, x, y);

        x -= shiftValue;

        g4_100x->SetPoint(i, x, y);
    }
    // g5 shift
    numPoints = g5->GetN();
    shiftValue = 63800;
    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        g5->GetPoint(i, x, y);

        x -= shiftValue;

        g5->SetPoint(i, x, y);
    }
    // g5_100x shift
    numPoints = g5_100x->GetN();
    shiftValue = 63700;
    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        g5_100x->GetPoint(i, x, y);

        x -= shiftValue;

        g5_100x->SetPoint(i, x, y);
    }
    // g5G shift
    numPoints = g5G->GetN();
    shiftValue = 62900;
    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        g5G->GetPoint(i, x, y);

        x -= shiftValue;

        g5G->SetPoint(i, x, y);
    }
    // valore I_0
        TF1 *fI_0 = new TF1("fI_0", "gaus", 0, 10000);
        gI_0->Fit(fI_0);
        Double_t mean = fI_0->GetParameter(0);
    */

    // Definizione delle funzioni, setting parametri par[0] = I0; par[1] = D ; par[2] = d

    TF1 *f1 = new TF1("f1", myFunction, 52000, 77000, 4);
    f1->SetParameters(2.26, 300, 100,63400);
   //  f1->SetParLimits(0, 2, 3);
    //  f1->SetParLimits(1, 300, 301);
    // f1->SetParLimits(2, 99, 101);

    TF1 *f2 = new TF1("f2", myFunction, 52000,77000 , 4);
    f2->SetParameters(4.7, 300, 150,63400);

    TF1 *f4 = new TF1("f4", myFunction, -5000, 5000, 3);
    f4->SetParameters(0.6, 250, 150);

    TF1 *f4_100x = new TF1("f4_100x", myFunction, -5000, 5000, 3);
    f4_100x->SetParameters(4.7, 250, 150); // verify par 1, 2

    TF1 *f5 = new TF1("f5", myFunction, -2000, 2000, 3);
    f5->SetParameters(0.5, 500, 150);

    TF1 *f5G = new TF1("f5G", myFunction, -2000, 2000, 3);
    f5G->SetParameters(0.5, 500, 150);

    TF1 *f5_100x = new TF1("f5_100x", myFunction, -2000, 2000, 3);
    f5_100x->SetParameters(4.7, 500, 150);

    TCanvas *c = new TCanvas("canvas", "Grafico");
   
   
   
   g1R->Fit(f1,"R");

   g1R->Draw("APL");
   // f1->SetLineColor(kRed);
   // f1->Draw("Lsame");
    
}
