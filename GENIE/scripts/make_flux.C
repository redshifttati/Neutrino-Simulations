{
  std::ifstream in("up_numuflux.csv");

  std::string line;
  getline(in,line); // header

  std::vector<double> E, F;

  double e, f;
  char comma;

  while(in >> e >> comma >> f){
    if(e <= 1000.0){
      E.push_back(e);
      F.push_back(f);
    }
  }

  int N = E.size();

  std::vector<double> edges(N+1);

  for(int i=1;i<N;i++)
    edges[i] = sqrt(E[i-1]*E[i]);

  edges[0] = E[0]*E[0]/edges[1];
  edges[N] = 1000.0;

  TFile fout("flux_numu_clean.root","RECREATE");
  TH1D h("numu","numu",N,&edges[0]);

  for(int i=0;i<N;i++)
    h.SetBinContent(i+1,F[i]);

  h.Write();
  fout.Close();
}
