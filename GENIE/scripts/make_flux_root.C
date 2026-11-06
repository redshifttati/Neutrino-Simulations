#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

void make_flux_root() {
  std::ifstream in("up_numuflux_clean.csv");
  if (!in.is_open()) {
    std::cerr << "No pude abrir up_numuflux_clean.csv" << std::endl;
    return;
  }

  std::string line;
  std::getline(in, line); // header

  std::vector<double> E, F;

  while (std::getline(in, line)) {
    if (line.empty()) continue;

    std::stringstream ss(line);
    std::string sE, sF;

    if (!std::getline(ss, sE, ',')) continue;
    if (!std::getline(ss, sF, ',')) continue;

    double e = std::stod(sE);
    double f = std::stod(sF);

    if (e > 0.0 && e <= 1000.0 && f >= 0.0) {
      E.push_back(e);
      F.push_back(f);
    }
  }

  int N = E.size();
  if (N < 2) {
    std::cerr << "Muy pocos puntos en el CSV" << std::endl;
    return;
  }

  std::vector<double> edges(N + 1);

  for (int i = 1; i < N; ++i) {
    edges[i] = std::sqrt(E[i - 1] * E[i]);
  }

  edges[0] = E[0] * E[0] / edges[1];
  edges[N] = 999.0;

  for (int i = 1; i <= N; ++i) {
    if (!(edges[i] > edges[i - 1])) {
      std::cerr << "Edges no crecientes en i=" << i
                << " : " << edges[i - 1] << " , " << edges[i] << std::endl;
      return;
    }
  }

  TFile *fout = new TFile("flux_numu_rootnative.root", "RECREATE");
  TH1D *h = new TH1D("numu", "numu", N, &edges[0]);

  for (int i = 0; i < N; ++i) {
    h->SetBinContent(i + 1, F[i]);
    h->SetBinError(i + 1, 0.0);
  }

  h->Write();
  fout->Close();

  std::cout << "Creado flux_numu_rootnative.root con histograma numu" << std::endl;
}
