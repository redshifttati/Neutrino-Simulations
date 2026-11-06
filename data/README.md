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
