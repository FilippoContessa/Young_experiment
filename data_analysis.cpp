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
    Double_t theta = x[0];

    const double_t k = 2 * TMath::Pi() / 640; // 640 nm

    Double_t arg1 = 0.5 * k * D * TMath::Sin(theta);
    Double_t arg2 = 0.5 * k * d * TMath::Sin(theta);

    Double_t result = I0 * TMath::Power(TMath::Cos(arg1), 2) * TMath::Power(TMath::Sin(arg2) / arg2, 2);

    return result;
}

void analysis()
{

    // Lettura del file di dati
    TGraph *g1 = new TGraph("Data1.txt", "%lg %lg");
    TH1 *h1 = g1->GetHistogram();

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

    // Definizione della funzione, setting parametri par[0] = I0; par[1] = D ; par[2] = d

    TF1 *f1 = new TF1("f1", myFunction, 0, 20000, 3);
    f1->SetParameters(10, 300, 100);

    TF1 *f2 = new TF1("f2", myFunction, 0, 20000, 3);
    f2->SetParameters(10, 300, 150);

    TF1 *f4 = new TF1("f4", myFunction, 0, 20000, 3);
    f4->SetParameters(10, 250, 150);

    TF1 *f5 = new TF1("f5", myFunction, 0, 20000, 3);
    f1->SetParameters(10, 500, 150);

    TH1 *htot[4] = {h1, h2, h4, h5};
    TF1 *ftot[4] = {f1, f2, f4, f5};

    TCanvas *c = new TCanvas("canvas", "Grafico");

    gI_0->Draw();
}
