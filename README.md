# Neutrino Simulations — Láscar Volcano

Monte Carlo simulations of atmospheric neutrino interactions and secondary muon production for studies associated with the Láscar volcano in northern Chile.

## 1. Overview

This repository documents a computational study aimed at generating secondary muons from atmospheric neutrino interactions and preparing their kinematic distributions for future particle transport simulations in a volcanic environment.

The current workflow uses atmospheric neutrino flux calculations by Honda and collaborators, the GENIE neutrino event generator, and Python-based analysis tools.

The longer-term objective is to study muon propagation through the geological environment of the Láscar volcano.

## 2. Atmospheric Neutrino Flux

The atmospheric neutrino flux is obtained from the calculations by Honda and collaborators for the Kamioka site in Japan.

The flux is used as an initial approximation rather than a location-specific prediction for the Láscar volcano.

The initial study considers upward-going muon neutrinos, with flux information provided as a function of neutrino energy and zenith angle.

The original data source is:

http://www-rccn.icrr.u-tokyo.ac.jp/mhonda/public/

Processed flux tables are documented in `data/processed/`.

## 3. Flux Preparation

The atmospheric neutrino flux is processed to construct an energy-dependent input histogram for GENIE.

The following files are used:

- `up_numuflux.csv`: intermediate flux table.
- `up_numuflux_clean.csv`: processed flux table.
- `make_flux.C`: ROOT macro for flux histogram generation.
- `make_flux_root.C`: ROOT macro producing the GENIE-compatible flux histogram.

The final ROOT histogram is named `numu` and is stored in `flux_numu_rootnative.root`.

## 4. GENIE Event Generation

GENIE is used to simulate neutrino interactions with oxygen-16 nuclei.

The example simulation configuration uses:

- Incident particle: muon neutrino (PDG 14).
- Nuclear target: oxygen-16 (PDG 1000080160).
- Neutrino energy range: 0.1–999 GeV.
- Example event count: 100,000.

The GENIE GHEP output is subsequently converted into a simplified ROOT format using `read_genie_convert_root.cc`.

## 5. Secondary Muon Analysis

The analysis focuses on secondary muons produced in neutrino interactions.

Relevant quantities include:

- Muon energy.
- Momentum components.
- Propagation direction.
- Final-state particle identification.

The notebook `analysis/notebooks/output_genie_numuflux_uproot.ipynb` contains Python-based analysis and visualization tools.

## 6. Repository Structure

```text
Neutrino-Simulations/
├── FLUKA/
├── GENIE/
│   └── scripts/
├── analysis/
│   └── notebooks/
├── data/
│   └── processed/
├── docs/
├── README.md
├── requirements.txt
└── .gitignore
```

## 7. Installation

Clone the repository:

```bash
git clone https://github.com/redshifttati/Neutrino-Simulations.git
cd Neutrino-Simulations
```

Install the Python dependencies:

```bash
pip install -r requirements.txt
```

Launch Jupyter:

```bash
jupyter lab
```

Open `analysis/notebooks/output_genie_numuflux_uproot.ipynb`.

Some analyses require external ROOT input files that are not included in the repository.

## 8. Current Status and Future Work

The GENIE-based workflow provides an initial sample of secondary muon kinematics.

The following steps remain to be developed or fully documented:

- Verification of the atmospheric flux preparation and angular normalization.
- Incorporation of original FLUKA simulation configurations.
- Implementation and documentation of the volcanic geometry and detector in Geant4.
- Assignment of neutrino interaction vertices within the relevant geometry.
- Propagation of secondary muons through the volcanic environment.

## 9. References

1. T. K. Gaisser and M. Honda, *Flux of Atmospheric Neutrinos*, Annual Review of Nuclear and Particle Science **52**, 153–199 (2002).
2. M. Honda et al., *Atmospheric neutrino flux calculation using the NRLMSISE-00 atmospheric model*, Physical Review D **92**, 023004 (2015).
3. C. Andreopoulos et al., *The GENIE Neutrino Monte Carlo Generator: Physics and User Manual*, arXiv:1510.05494.
