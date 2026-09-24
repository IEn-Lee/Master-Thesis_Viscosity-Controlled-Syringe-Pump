# Viscosity-Controlled Syringe Pump for Precise Filling of a Urological Implant with High-Viscosity Oils

**Master's Thesis — I-En Lee**  
M.Sc. Computational Engineering  
Friedrich-Alexander-Universität Erlangen-Nürnberg (FAU)  
Institute for Factory Automation and Production Systems (FAPS)  
2026

---

## Overview

This master's thesis focused on the development of a **viscosity-controlled syringe pump for precise filling of a urological implant with high-viscosity oils**.

The work combined:

- fluid-mechanical modeling
- mechanical and mechatronic design
- stepper-motor actuation
- embedded C/C++ control
- graphical user-interface development
- viscosity-dependent compensation
- prototype fabrication
- quantitative laboratory validation

The developed platform was designed to dispense fluids with viscosities ranging from approximately **1 to 60,000 mPa·s** through a narrow cannula while maintaining repeatable volumetric delivery.

---

## Background

Stress urinary incontinence has a substantial impact on quality of life and creates a significant burden on healthcare systems.

To address limitations of existing treatment approaches, research at FAU has investigated an **intraurethral implant for the treatment of urinary incontinence**. The implant concept is intended to provide a minimally invasive treatment approach and requires precise filling of an internal component with high-viscosity oil.

The filling process presents several engineering challenges. Increasing fluid viscosity and decreasing flow-path dimensions result in higher hydraulic resistance, while syringe mechanics, structural compliance, friction, and delayed material release can introduce deviations between commanded actuator motion and the actually delivered volume.

This thesis therefore addressed the filling process as a coupled **actuator–structure–fluid system** rather than as a purely kinematic syringe-pump problem.

---

## Research Objective

The objective of the thesis was to develop and experimentally validate a syringe-pump platform capable of accurately dispensing high-viscosity oils into the implant.

The system was developed around **B. Braun Injekt Luer Lock Solo 2 mL syringes** and was designed to support an efficient and repeatable laboratory workflow.

The main engineering tasks included:

### 1. Mechanical System Development

Development of the complete syringe-pump mechanism, including:

- syringe fixation
- actuator mounting
- linear guidance
- transmission design
- plunger-contact interface
- modular and replaceable components
- CAD-based mechanical development
- prototype fabrication and assembly

Design decisions considered alignment, manufacturability, assembly, dimensional tolerances, and repeatable syringe positioning.

---

### 2. Fluid-Mechanical Modeling

A simplified syringe–cannula model was developed to relate:

- fluid viscosity
- syringe geometry
- cannula geometry
- volumetric flow rate
- pressure demand
- actuator motion

For an idealized Newtonian flow through the cannula, the Hagen–Poiseuille relation was used as a first-order description of the pressure loss:

\[
\Delta p_c = \frac{8 \mu L_c Q}{\pi r_c^4}
\]

where:

- \( \mu \) = dynamic viscosity
- \( L_c \) = cannula length
- \( Q \) = volumetric flow rate
- \( r_c \) = cannula inner radius

The model was used to support actuator and motion-parameter selection rather than as an exact transient pressure predictor.

---

### 3. Embedded Control and User Interface

The system was controlled using an **Arduino GIGA R1 WiFi** with embedded C/C++ software.

The control architecture included:

- stepper-motor control
- motion-parameter generation
- viscosity and target-volume input
- process-duration calculation
- motor-driver communication
- viscosity-dependent compensation
- process monitoring
- touchscreen-based user interaction

The actuation system used a **NEMA 23 stepper motor** and a **TMC5160-based motor-driver architecture**.

A graphical interface was developed using **LVGL** to support routine operation and parameter configuration.

---

### 4. Viscosity-Dependent Compensation

Because commanded plunger displacement does not directly correspond to delivered volume under all fluid conditions, an experimentally calibrated compensation strategy was implemented.

Calibration conditions were established across the investigated viscosity range and used to construct a **monotonic interpolation map** for viscosity-dependent motion compensation.

This enabled the system to estimate appropriate actuator parameters for intermediate viscosity conditions without requiring manual retuning for every new fluid.

---

### 5. Experimental Validation

The completed system was assembled and validated under controlled laboratory conditions.

The validation workflow included:

- controlled syringe and cannula configuration
- gravimetric measurement of delivered fluid
- repeated extrusion trials
- calculation of volumetric deviation
- calibration of systematic deviations
- validation at an intermediate viscosity not used during calibration

The development and validation process followed the institute's quality-management framework for medical-device research.

---

## Engineering Workflow

The project followed a complete model-to-hardware development process:

**Physical modeling**  
↓  
**Numerical evaluation**  
↓  
**Mechanical and actuator design**  
↓  
**Embedded control implementation**  
↓  
**Prototype fabrication and integration**  
↓  
**Experimental calibration**  
↓  
**Quantitative validation**

---

## Technical Areas

### Mechanical & Mechatronic Systems
- CAD and mechanical design
- Precision actuation
- DFM / DfAM
- Modular prototyping
- Additive manufacturing
- Mechanical integration

### Control & Embedded Systems
- Embedded C/C++
- Stepper-motor control
- Model-based open-loop compensation
- Motor-driver integration
- Motion-parameter generation
- Process monitoring
- LVGL graphical interface

### Modeling & Computation
- Python
- Fluid-mechanical modeling
- Viscosity-dependent system modeling
- Numerical evaluation
- Monotonic interpolation
- Model-based parameter estimation

### Experimental Engineering
- Biomedical device prototyping
- Fluid handling
- Calibration
- Gravimetric measurement
- Repeated experimental trials
- Quantitative validation

---

## Repository Structure

```text
Master-Thesis_Viscosity-Controlled-Syringe-Pump/
│
├── README.md
├── figures/
│   └── selected figures and system diagrams
├── code/
│   └── selected software and analysis files
├── docs/
│   └── supporting technical documentation
└── ...
