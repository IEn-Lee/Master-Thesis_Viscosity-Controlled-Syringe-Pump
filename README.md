# Viscosity-Controlled Syringe Pump for Precise Filling of a Urological Implant with High-Viscosity Oils

**Master's Thesis — I-En Lee**  
M.Sc. Computational Engineering  
Friedrich-Alexander-Universität Erlangen-Nürnberg (FAU)  
Institute for Factory Automation and Production Systems (FAPS)  
2026

**Thesis grade: 1.0 (highest possible grade in the German grading system)**  
**Recognition: Outstanding Master's Thesis** — [View certificate](https://github.com/IEn-Lee/Master-Thesis_Viscosity-Controlled-Syringe-Pump/blob/main/Certificate%20Outstanding%20Master's%20Thesis_Lee.pdf)<br>
**Full master's thesis:** The complete thesis is available as a PDF in this repository — [Full master's thesis](https://github.com/IEn-Lee/Master-Thesis_Viscosity-Controlled-Syringe-Pump/blob/main/Master_s%20Thesis.pdf). <br>
*(If GitHub fails to display the PDF preview, please download the file and open it locally)* <br>
<br>
> **RheoPilot | James Dyson Award 2026**  
> **[Explore the RheoPilot project on the James Dyson Award website](https://www.jamesdysonaward.org/en-US/2026/project/rheopilot)**

---

## Overview

This master's thesis developed **RheoPilot**, a **viscosity-controlled syringe pump for precise filling of a urological implant with high-viscosity oils**. The platform combines physical modeling, mechanical design, embedded control, sensor–actuator integration, a touchscreen interface, and experimental calibration in a working laboratory prototype.

The investigated fluids spanned approximately **1–60,000 mPa·s**, from water to high-viscosity silicone oils. The system was developed around **B. Braun Injekt Luer Lock Solo 2 mL syringes** and a narrow cannula, with a validation target of **1 mL delivery within ±1% volumetric deviation** under defined laboratory conditions.

<p align="center">
  <img src="Images/01_Prototype_CAD_and_Hardware.png" alt="CAD installation reference beside the assembled syringe-pump prototype" width="760">
</p>

*Figure 1. From CAD to a test-ready prototype. Left: installation reference. Right: the assembled syringe pump used for experimental evaluation. Source: original thesis Figure 39.*

**Key results**

- **Calibrated conditions:** maximum absolute volumetric deviation of **0.62%** across the reported trials at 1, 5,000, 30,000, and 60,000 mPa·s.
- **Intermediate validation:** at a nominal **40,000 mPa·s**, which was not a calibration point, **all five trials met the ±1% tolerance** using interpolated parameters without additional manual retuning.
- **Validation accuracy:** maximum absolute deviation of **0.93%** and mean absolute deviation of **0.72%** at that intermediate condition.
- **Post-extrusion handling:** retracting the plunger-contact interface enabled a standardized **3-minute post-release waiting interval** for the oil-based tests.

## Why This Research Was Needed

RheoPilot originated from a specific medical-device research problem: filling an internal component of an intraurethral implant with high-viscosity oil through a narrow cannula. This task requires a combination of accurate small-volume delivery, repeatable syringe positioning, manageable mechanical loading, and a practical laboratory workflow.

**Accurate plunger positioning alone does not guarantee accurate delivery at the outlet.** Under high-viscosity loading, syringe compliance, friction, structural deformation, and delayed outflow can change the relationship between commanded motion and delivered volume. In the thesis experiments, the uncompensated setting produced a mean absolute volumetric deviation of **30.31% at 60,000 mPa·s**, despite relatively consistent repeated trials. This made application-specific compensation necessary.

The equipment-selection challenge was to combine syringe-based operation with viscosity-dependent process planning and experimental flexibility. The thesis identified the following gap between existing approaches and the intended filling workflow:

| Approach considered in the thesis | Relevant capability | Additional need for this application |
|---|---|---|
| Conventional syringe pumps | Programmable plunger motion using syringe geometry, volume, and flow settings. | Compensation for the specific syringe–cannula system under high-viscosity loading, including delayed release. |
| Industrial viscous-material dispensers | Specialized metering of viscous materials. | Integration with the specified disposable 2 mL syringe and small-cannula implant-filling procedure. |
| Manual or semi-automated filling | Flexible preparation and operator intervention. | More reproducible actuation and post-extrusion handling, with traceable process settings. |

*This comparison summarizes the application-specific assessment in thesis Section 3.2 and Table 1; it is not an exhaustive benchmark of all commercial products.*

The resulting research objective was to develop an integrated **actuator–structure–fluid platform** that connects volume and viscosity inputs to motion planning, calibrated compensation, operator guidance, and quantitative validation.

### Why a Small Outlet Matters

<p align="center">
  <img src="Images/11_Small_Outlet_Scale.png" alt="Visual scale comparison between a 0.5 mm mechanical-pencil lead and the RheoPilot cannula outlet" width="900">
</p>

*Small-outlet scale comparison. The approximately 0.5 mm outlet scale is illustrated alongside a mechanical-pencil lead. This is a visual scale reference rather than a dimensional measurement.*

<p align="center">
  <img src="Images/12_Implant_Filling_Context.png" alt="Cannula positioned at the filling interface of a small transparent implant component held between gloved fingers" width="720">
</p>

*Application context: cannula-based access to a small implant component. Image provided by the author; UroPro image credit: Alexander Preis, FAU FAPS.*

Small components can offer only a restricted filling interface. A narrow cannula provides localized access, but it also increases the resistance encountered by the fluid. Increasing the outlet size may therefore be incompatible with the component geometry or the required filling procedure.

For the idealized flow model used in this thesis, pressure loss scales with the inverse fourth power of the cannula radius. **Halving the radius increases the predicted pressure demand sixteenfold at the same viscosity, cannula length, and flow rate.** This makes a small outlet an important process constraint rather than merely a geometric detail.

RheoPilot addresses this constraint by relating viscosity and flow-path geometry to motion planning, then applying calibrated compensation for the actual syringe–cannula system. The objective is to deliver a defined volume through the required access point while accounting for mechanical loading and delayed material response.

## What Makes RheoPilot Different

**RheoPilot combines viscosity-dependent compensation with a compact, modular, standalone syringe-based workflow.** Its distinguishing feature is the combination of functions around the investigated filling task.

| Design feature | Practical value |
|---|---|
| **Viscosity-dependent motion planning and compensation** | Converts the filling task into motion settings that account for modeled loading and experimentally observed delivery deviations. |
| **Disposable-syringe compatibility** | Integrates the specified 2 mL syringe and Luer Lock cannula into a repeatable filling setup. |
| **Guided standalone operation** | Routine operation starts from target volume and viscosity; the embedded controller handles calculations, interface guidance, and motor commands on the device. |
| **Modular, fabrication-oriented construction** | Standard components and replaceable printed parts support assembly, modification, and iterative development. |
| **Advanced configuration access** | Exposes relevant setup parameters for research, while routine users interact with a simpler interface. |
| **Defined post-extrusion release** | Includes contact-element retraction and a standardized waiting step to address the delayed response of high-viscosity oils. |

The [RheoPilot project page on the James Dyson Award website](https://www.jamesdysonaward.org/en-US/2026/project/rheopilot) estimates **prototype parts costs of approximately €300–450**. This is a parts estimate, not a commercial selling price or a like-for-like comparison with a complete supported dispensing system.

The design supports adaptation of the syringe holder and outlet arrangement. **Each changed configuration would require appropriate calibration and validation**; the performance results below apply to the tested setup.

Figures 1, 4, and 5 show the physical implementation and modular interfaces; Figures 7–9 illustrate guided operation; Figure 10 and the validation tables explain the compensation strategy and measured results.

## My Contributions

- Developed a fluid-mechanical model and used Python for numerical evaluation of viscosity-dependent operating constraints.
- Designed the syringe fixation, plunger-contact interface, guidance, actuator mounting, and transmission interfaces in CAD.
- Applied **DFM and DfAM considerations**, including assembly clearances, printed-part tolerances, modular interfaces, and replaceable components.
- Integrated stepper-motor actuation, motor-driver electronics, electrical monitoring, embedded C/C++ software, and a touchscreen interface.
- Implemented **model-based open-loop compensation** using calibrated motion parameters and monotonic interpolation.
- Fabricated and assembled the prototype, conducted gravimetric experiments, and evaluated an intermediate condition excluded from calibration.

## 1. System Architecture and Integration

<p align="center">
  <img src="Images/02_System_Architecture.png" alt="Five functional subsystems: mechanics, drive and actuation, control and compensation, user interface and guidance, and validation" width="800">
</p>

*Figure 2. Functional decomposition of the syringe-pump platform. Source: original thesis Figure 16.*

The architecture connects five engineering functions:

| Subsystem | Role in the filling process |
|---|---|
| Mechanical structure | Positions the syringe, supports the actuator, and guides the moving plunger-contact element. |
| Drive and actuation | Transfers motor rotation through the transmission and leadscrew into linear plunger displacement. |
| Control and compensation | Converts target volume and viscosity into executable, compensated motion commands. |
| User interface and guidance | Supports parameter entry, confirmation, process monitoring, and operator guidance. |
| Validation | Measures delivered volume and evaluates accuracy and repeatability under documented conditions. |

This structure made **system integration** central to the project: the model, hardware, firmware, interface, and measurement workflow had to operate consistently together.

## 2. Fluid-Mechanical Modeling and Motion Planning

<p align="center">
  <img src="Images/03_Syringe_Cannula_Model.png" alt="Syringe–cannula model showing plunger displacement, plunger velocity, volumetric flow, and cannula pressure drop" width="800">
</p>

*Figure 3. Simplified syringe–cannula model linking actuator motion to fluid flow and pressure demand. Source: original thesis Figure 5.*

The model relates plunger displacement and velocity to delivered displacement volume and volumetric flow. For idealized Newtonian flow through a cylindrical cannula, the Hagen–Poiseuille relation provides a first-order pressure-loss estimate:

$$
\Delta p_c = \frac{8\mu L_c Q}{\pi r_c^4}
$$

where $\mu$ is dynamic viscosity, $L_c$ is cannula length, $Q$ is volumetric flow rate, and $r_c$ is cannula inner radius.

**Figure 3 explains why actuator motion must account for the fluid path.** Increasing viscosity or flow rate increases the predicted pressure demand, while decreasing cannula radius has a particularly strong effect because of the fourth-power dependence. The pressure and force-transmission analysis informed feasible plunger motion and mechanical loading.

Python-based numerical evaluation supported parameter selection before hardware implementation. Defined acceleration and deceleration phases were used to avoid abrupt motion changes. The simplified model supported engineering decisions; it was not an exact predictor of transient pressure or delivered volume.

### Viscosity-Adaptive Motion Planning

<p align="center">
  <img src="Images/13_Adaptive_Motion_Concept.png" alt="Conceptual volume and flow profiles illustrating different dispensing durations and flow rates for increasing viscosity" width="700">
</p>

*Conceptual illustration supplied by the author: viscosity-dependent volume and flow profiles. The curves illustrate the planning principle; their numerical values are not experimental results or a quantitative model-validation plot.*

**The same target volume can require different motion profiles for different fluid conditions.** The upper panel illustrates accumulated volume approaching a similar target over different durations. The lower panel illustrates the corresponding flow-rate concept, including gradual increases and decreases rather than abrupt starts and stops.

The intended progression from blue and orange to green and red represents increasing viscosity. Within the modeled load constraints, a higher-viscosity fluid can require a lower planned flow rate and a longer dispensing time. For a fixed syringe cross-section, this corresponds to adapting plunger velocity and the acceleration and deceleration phases.

In RheoPilot, this adaptation occurs **before extrusion**, using the entered viscosity, target volume, configured geometry, and calibrated compensation settings. Here, “adaptive” means **parameter-dependent motion planning**. Direct outlet-flow or pressure measurements do not update the command during execution.

Motion-profile selection determines how the delivery is performed; the compensation map in Section 6 corrects the relationship between commanded displacement and measured delivered volume.

## 3. Mechanical Design, DFM, and DfAM

<p align="center">
  <img src="Images/04_Mechanical_Assembly.png" alt="Two CAD perspectives showing the syringe fixation, moving contact element, actuator support, and transmission" width="760">
</p>

*Figure 4. Mechanical subsystem viewed from two perspectives. Source: original thesis Figure 17.*

The CAD assembly makes the force path and component interfaces visible. The **orange fixation** locates the syringe; the **purple moving element** contacts its plunger; the guide structure supports linear travel; and the **green frame section** supports the actuator. The gear and leadscrew arrangement converts motor rotation into plunger displacement.

The design priorities were axial alignment, repeatable syringe positioning, stable guidance, and practical assembly. Manufacturing and assembly considerations included:

- **Tolerance-aware contact:** clearance at the plunger-contact interface accommodates small alignment and dimensional deviations without rigidly locking the syringe plunger to the actuator.
- **Defined sliding interfaces:** a sliding bearing and stainless-steel guide rod reduce dependence on the surface quality of printed parts.
- **Modular construction:** replaceable printed components and defined interfaces support fabrication, maintenance, and iterative refinement.
- **Practical assembly:** leadscrew clearances, mounting features, and accessible component interfaces support repeatable installation.

<p align="center">
  <img src="Images/05_Quick_Release_Syringe_Fixture.png" alt="Annotated syringe fixation with snap-fit, semi-enclosing support, barrel flange contour, leadscrew slot, and mounting holes" width="680">
</p>

*Figure 5. Quick-release syringe fixation and locating features. Source: original thesis Figure 19.*

**The fixation in Figure 5 supports both repeatability and efficient syringe exchange.** A snap-fit enables insertion and removal, while the semi-enclosing support and barrel-flange contour resist unwanted displacement and tilting. The design avoids unnecessary over-constraint of the disposable syringe. The cannula connects directly through the syringe's standardized Luer Lock interface.

## 4. Actuation, Embedded Control, and Sensor Integration

The actuation system combines a **NEMA 23 stepper motor**, a **custom TMC5160-TA-based motor-driver board**, and leadscrew-driven linear motion. An **Arduino GIGA R1 WiFi** provides the main embedded controller, with embedded C/C++ software handling parameter processing, motion execution, driver communication, and user interaction.

<p align="center">
  <img src="Images/06_Motor_Driver_Board.png" alt="Custom motor-driver board integrating the TMC5160-TA and electrical monitoring hardware" width="720">
</p>

*Figure 6. Motor-driver electronics integrated into the syringe-pump platform. Source: original thesis Figure 25.*

**INA228-based electrical measurements** and motor-driver information support motor-side status monitoring. These functions connect sensing, actuation, and process visualization within the integrated system.

The extrusion strategy is **model-based open-loop control**: motion parameters are calculated and compensated before execution. The prototype does not use direct outlet-flow or pressure feedback to correct delivery during a run. Electrical monitoring and driver status therefore support process visibility without constituting closed-loop volumetric control.

## 5. Touchscreen Interface and Operator Workflow

The touchscreen interface separates routine filling tasks from advanced configuration. Routine operation focuses on viscosity and target volume; advanced access supports development, calibration, and manual motor functions.

<p align="center">
  <img src="Images/07_GUI_Routine_and_Advanced.png" alt="Routine viscosity and volume input screen beside the advanced developer information screen" width="900">
</p>

*Figure 7. Routine input screen on the left and advanced information access on the right. Source: original thesis Figure 33.*

**Figure 7 shows how the interface limits the complexity of normal operation** while preserving access to configuration parameters needed during research. Additional screens provide parameter customization, manual motor control, input warnings, and tab-specific help.

<p align="center">
  <img src="Images/08_GUI_Confirmation_and_Monitoring.png" alt="Pre-extrusion confirmation dialog beside the active process monitoring screen" width="900">
</p>

*Figure 8. Pre-extrusion confirmation and process-state monitoring. Source: original thesis Figure 35.*

Before motion starts, the confirmation dialog summarizes the intended filling operation. During extrusion, the progress view displays process information such as elapsed and remaining duration, distance, and progress. These displays communicate the planned or reported motion state; they are not direct measurements of outlet volume.

<p align="center">
  <img src="Images/09_GUI_Protected_Operation.png" alt="Stop confirmation dialog and advanced controls disabled during active extrusion" width="900">
</p>

*Figure 9. Protected interaction during active extrusion. Source: original thesis Figure 36.*

A stop-confirmation dialog reduces accidental interruption, and selected advanced controls are disabled during active extrusion to prevent unintended changes. The interface was reviewed qualitatively against **Nielsen's 10 usability heuristics** as part of prototype design qualification.

## 6. Viscosity-Dependent Calibration and Compensation

Uncompensated experiments showed repeatable but viscosity-dependent under-delivery for the oils. This supported correcting a systematic process offset through an **effective motion scale**, which adjusts the relationship between commanded actuator motion and delivered volume.

Four conditions were used as calibration anchors: **1, 5,000, 30,000, and 60,000 mPa·s**. A monotonic interpolation map was constructed in the **logarithmic viscosity domain** to estimate compensation between these anchors.

<p align="center">
  <img src="Images/10_Viscosity_Compensation_Map.png" alt="Monotonic compensation curve through four calibration anchors with an interpolated point at 40,000 mPa seconds" width="850">
</p>

*Figure 10. Viscosity-dependent effective motion scale and the interpolated validation setting. Source: original thesis Figure 44.*

**How to read Figure 10:** the anchor points represent experimentally calibrated settings, and the curve estimates the effective motion scale between them. The highlighted **40,000 mPa·s** point gives a predicted scale of **41,001.71**. That value was obtained from interpolation, not from an additional manual calibration at the validation condition.

The effective motion scale is a firmware compensation quantity, not a directly measured fluid property. Its relationship with viscosity is specific to the investigated hardware and process conditions.

## 7. Experimental Validation and Quantitative Results

The evaluation followed a **DQ/IQ/OQ/PQ-inspired structure**, covering design requirements, installation readiness, operational behavior, and compensated performance.

### Measurement Conditions

- Nominal target volume: **1 mL**.
- Laboratory temperature: approximately **23 °C**.
- Fixed syringe type and cannula configuration; syringes used once.
- Gravimetric measurement using a **KERN PCD balance**.
- For water, measurement of the collected mass; for oils, measurement of syringe mass before and after extrusion.
- Mass-to-volume conversion using the specified fluid density.
- For oil-based trials, retraction of the plunger-contact interface followed by a standardized **3-minute post-release waiting interval**.

### Calibration Results

| Viscosity [mPa·s] | Baseline mean absolute deviation [%] | Calibrated mean absolute deviation [%] | Calibrated maximum absolute deviation [%] |
|---:|---:|---:|---:|
| 1 | 0.20 | 0.20 | 0.30 |
| 5,000 | 6.43 | 0.45 | 0.62 |
| 30,000 | 20.45 | 0.19 | 0.31 |
| 60,000 | 30.31 | 0.36 | 0.52 |

*Source: original thesis Tables 9 and 10; five reported trials per condition. These calibrated results were used for compensation-parameter selection.*

The baseline deviations increased with viscosity, while within-condition variation remained relatively small. Calibration reduced the reported absolute deviations, establishing the anchor settings used in the interpolation map.

### Validation at an Intermediate Viscosity

A nominal **40,000 mPa·s** condition, prepared by mixing the 30,000 and 60,000 mPa·s oils, was reserved for validation. The interpolated setting was applied **without additional manual retuning**.

| Validation metric | Result |
|---|---:|
| Repeated trials | 5 |
| Trials within ±1% volumetric deviation | 5 / 5 |
| Mean absolute volumetric deviation | 0.72% |
| Maximum absolute volumetric deviation | 0.93% |

*Source: original thesis Table 11.*

This result supports the feasibility of interpolation-based compensation at an intermediate condition within the tested range and setup.

### Why Post-Extrusion Release Matters

Stopping the motor does not immediately eliminate residual loading and delayed fluid response. Because the plunger is not rigidly coupled to the moving contact element, retracting that element releases the pushing contact and allows passive relaxation.

At **30,000 mPa·s**, a reference test without this release step still showed a mean absolute deviation of **8.53%** after **30 minutes**, with a **5.70-percentage-point** range between trials. The standard oil-based protocol incorporated release and a **3-minute** waiting interval.

This comparison demonstrates why post-motion handling belongs to the process design. It should not be interpreted as an isolated tenfold reduction in the complete filling-cycle duration.

## Future Development and Application Scenarios

RheoPilot provides a basis for extending a single filling operation into **programmable, time-scheduled fluid and material delivery**. A promising next step is to combine its viscosity-dependent dispensing method with the scheduling, sensor–actuator integration, touchscreen configuration, and fault-recovery experience developed in my project thesis on an automated biomedical test bench.

### Scheduled Dosing for Pharmaceutical and Biomedical Research

A future version could let users define **volume per dose, delivery interval, number of cycles, and dispensing duration**. The controller could then execute repeated dosing sequences and display the next scheduled event, completed cycles, and cumulative commanded volume.

Potential applications include reagent addition, repeated dosing in in-vitro experiments, and laboratory evaluation of drug-delivery schedules. A non-blocking scheduler would allow timing, user interaction, and process monitoring to operate together. Any extension to patient-facing drug delivery would require dedicated safety engineering and application-specific validation.

### Timed Material Feeding for Manufacturing Experiments

The platform could also be extended to deliver defined quantities of oils, silicone components, or other process materials at programmed times or in response to an external trigger.

Possible scenarios include repeated cavity filling, intermittent material addition, and synchronized feeding within a laboratory manufacturing setup. Material compatibility, the usable processing time of reactive materials, and the syringe–outlet configuration would guide the required hardware and control changes.

### Integration with Automated Test Platforms

Combining RheoPilot with a test-bench controller could coordinate dispensing with other experimental steps, such as pump operation, incubation periods, sensor acquisition, or sample preparation.

| Future capability | Relevant experience from the project thesis | Intended use |
|---|---|---|
| Scheduled delivery cycles | Non-blocking timing and automated cycle execution | Repeated doses or material additions at defined intervals. |
| Configurable experiment recipes | Touchscreen UI and parameter handling | User-defined volumes, intervals, and cycle counts. |
| Coordinated equipment operation | Sensor–actuator integration | Dispensing synchronized with other laboratory devices. |
| Monitored unattended operation | Communication-failure recovery and long-duration testing | Detecting faults and managing interruptions during repeated experiments. |

### Development Priorities

Further work would include repeated-dose accuracy testing, cumulative delivery assessment, refill handling, interruption and restart behavior, and timestamped event logging. Actual cumulative delivery would need measurement-based verification rather than relying only on the sum of commanded doses. Additional pressure, flow, or gravimetric sensing could support future delivery verification and feedback control.

**These are proposed extensions.** The current quantitative results apply to the tested single-delivery configuration; new fluids, geometries, schedules, and application scenarios would require their own calibration and validation.

## Outcome and Technical Skills

The work established an integrated workflow from **physical modeling and numerical evaluation to mechanical design, embedded implementation, prototype assembly, calibration, and experimental validation**.

Its main contribution is a working filling platform that combines viscosity-dependent motion planning with experimentally calibrated compensation and a defined post-extrusion procedure.

**Keywords:** Precision Fluid Handling · High-Viscosity Dispensing · Fluid-Mechanical Modeling · Mechanical Design · DFM · DfAM · Embedded C/C++ · System Integration · Sensor–Actuator Integration · Model-Based Open-Loop Compensation · Touchscreen UI · Experimental Validation
