# Simulation Data

This directory documents the input and output datasets used in the Láscar volcano neutrino simulation project.

## Atmospheric Neutrino Flux

The study uses atmospheric neutrino fluxes from the Honda calculations, initially considering the Kamioka site as an approximation.

The following ROOT files have been used or referenced during the analysis:

- `RHC_Flux_NOvA_ND_2017.root` — ROOT file containing flux data extracted from Honda, according to the original analysis notes. The preparation procedure remains to be verified.
- `flux_numu_rootnative.root` — ROOT flux input referenced in the GENIE event-generation workflow.

## GENIE Simulation Outputs

- `gntp.0.ghep.root` — GENIE event output in GHEP format.
- `gntp.0.ghep.1000_converted.root` — Example of a converted ROOT file used for subsequent analysis.

## Data Availability

The ROOT datasets are not currently included in this repository.

The exact preparation procedures, normalization conventions, and relationships between the input files will be documented after verification.

## Original Atmospheric Neutrino Flux

The atmospheric neutrino flux data used in this study were obtained from the calculations by M. Honda and collaborators.

**Original data source:**  
http://www-rccn.icrr.u-tokyo.ac.jp/mhonda/public/

**Original input file:** `kam-nu-20-01-000.d`

The analysis uses the atmospheric neutrino flux calculated for the Kamioka site as an initial approximation for the Láscar volcano study.

**Reference:**  
M. Honda et al., *Atmospheric neutrino flux calculation using the NRLMSISE-00 atmospheric model*, Physical Review D 92, 023004 (2015).  
https://doi.org/10.1103/PhysRevD.92.023004

The processed flux tables used for GENIE event generation are provided in `data/processed/`.
