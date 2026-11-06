# Neutrino Simulations — Láscar Volcano

Monte Carlo simulations and analysis of neutrino fluxes and interactions associated with the Láscar volcano in northern Chile.

## Overview

This repository documents a computational study involving neutrino simulations and the analysis of particle distributions using FLUKA, GENIE, and Python.

The project aims to organize the simulation configurations, computational tools, and analysis workflows used in the study.

## Simulation Tools

### FLUKA

FLUKA is a Monte Carlo simulation code used to model particle transport and interactions with matter.

The `FLUKA/` directory is intended to contain the original simulation inputs, configurations, and associated documentation.

### GENIE

GENIE is a Monte Carlo event generator designed for neutrino interactions.

The `GENIE/` directory is intended to contain simulation configurations and scripts associated with neutrino event generation.

### Python Analysis

Python is used to inspect ROOT files, process simulation outputs, and visualize particle distributions.

The analysis uses libraries including:

- NumPy
- Pandas
- Matplotlib
- uproot
- Awkward Array

## Repository Structure

```text
Neutrino-Simulations/
├── FLUKA/
├── GENIE/
├── analysis/
│   └── notebooks/
│       └── output_genie_numuflux_uproot.ipynb
├── .gitignore
├── README.md
└── requirements.txt
```

## Installation

Clone the repository:

```bash
git clone https://github.com/redshifttati/Neutrino-Simulations.git
cd Neutrino-Simulations
```

Install the Python dependencies:

```bash
pip install -r requirements.txt
```

## Running the Analysis

Launch Jupyter:

```bash
jupyter lab
```

Open:

`analysis/notebooks/output_genie_numuflux_uproot.ipynb`

The notebook requires the corresponding ROOT input files, which are not included in this repository.

## Reproducibility

The original simulation configurations, input datasets, software versions, and methodological details will be documented as they are recovered and incorporated.

## Documentation

Additional technical documentation and simulation results will be added as the project is organized.
