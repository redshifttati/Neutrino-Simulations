# GENIE Neutrino Interaction Simulations

This directory contains the scripts and documentation associated with neutrino interaction simulations performed using the GENIE Monte Carlo event generator.

The simulations are part of a preliminary study of atmospheric neutrinos for the Láscar volcano project in northern Chile.

## 1. Atmospheric Neutrino Flux

Atmospheric neutrino flux predictions from Honda et al. were used as input for the simulations.

The original flux tables correspond to the Kamioka site in Japan and were adopted as an initial approximation for the study.

The flux preparation scripts are available in `scripts/`, while the original flux data and processed CSV files are stored in `../data/`.

## 2. Neutrino Event Generation

GENIE was used to simulate interactions of muon neutrinos with oxygen-16 nuclei.

An example event generation command used in the study is:

```bash
gevgen -n 100000 -p 14 -t 1000080160 -e 0.1,999 -f flux_numu_rootnative.root,numu
```

The command specifies:

- `-n 100000`: Number of generated events.
- `-p 14`: Muon neutrino (PDG code 14).
- `-t 1000080160`: Oxygen-16 nuclear target.
- `-e 0.1,999`: Neutrino energy range in GeV.
- `-f`: ROOT flux file and histogram name.

The precise configurations of the archived simulation outputs should be verified against their original generation records.

## 3. ROOT File Conversion

GENIE event outputs were converted into simplified ROOT files for subsequent analysis.

The conversion code is available in:

`scripts/read_genie_convert_root.cc`

The resulting files contain neutrino interaction information and final-state particle kinematics.

## 4. Data Analysis

The generated events are analyzed using Python and `uproot`.

The analysis notebooks are located in:

`../analysis/notebooks/`

They provide access to the ROOT event trees and allow the study of neutrino interactions and secondary particles, including muons.

## 5. Repository Structure

- `scripts/`: Flux preparation and ROOT conversion scripts.
- `../data/honda/`: Original atmospheric neutrino flux data.
- `../data/processed/`: Processed flux tables.
- `../data/root/`: ROOT files used in the analysis.
- `../analysis/notebooks/`: Python analysis notebooks.

## 6. References

M. Honda et al., *Atmospheric neutrino flux calculation using the NRLMSISE-00 atmospheric model*, Physical Review D 92, 023004 (2015).

https://doi.org/10.1103/PhysRevD.92.023004

Original atmospheric neutrino flux tables:

http://www-rccn.icrr.u-tokyo.ac.jp/mhonda/public/
