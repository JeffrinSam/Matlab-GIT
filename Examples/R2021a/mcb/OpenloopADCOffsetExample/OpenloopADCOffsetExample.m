%% Run 3-Phase AC Motors in Open-Loop Control and Calibrate ADC Offset
% This example uses open-loop control (also known as scalar control or Volts/Hz control) to run a motor. This technique varies the stator voltage and frequency to control the rotor speed without using any feedback from the motor. You can use this technique to check the integrity of the hardware connections. A constant speed application of open-loop control uses a fixed-frequency motor power supply. An adjustable speed application of open-loop control needs a variable-frequency power supply to control the rotor speed. To ensure a constant stator magnetic flux, keep the supply voltage amplitude proportional to its frequency.
% 
% Open-loop motor control does not have the ability to consider the external conditions that can affect the motor speed. Therefore, the control system cannot automatically correct the deviation between the desired and the actual motor speed.
% 
% This model runs the motor by using an open-loop motor control algorithm. The model helps you get started with Motor Control Blockset(TM) and verify the hardware setup by running the motor. The target model algorithm also reads the ADC values from the current sensors and sends the values to the host model by using serial communication.
% 
% You can use this model to:
% 
% * Check connectivity with the target.
% * Check serial communication with the target.
% * Verify the hardware and software environment.
% * Check ADC offsets for current sensors.
% * Run a new motor with an inverter and target setup for the first time.
% 

% Copyright 2020 The MathWorks, Inc.

%% Models
% 
% The example includes these models:
% 
% * <matlab:open_system('mcb_open_loop_control_f28069M_DRV8312') mcb_open_loop_control_f28069M_DRV8312>
% 
% * <matlab:open_system('mcb_open_loop_control_f28069MLaunchPad') mcb_open_loop_control_f28069MLaunchPad>
% 
% * <matlab:open_system('mcb_open_loop_control_f28379d') mcb_open_loop_control_f28379d>
% 
% You can use these models for both simulation and code generation. You can also use the open_system command to open the Simulink(R) models. For example, use this command for a F28069M based controller:
%%
open_system('mcb_open_loop_control_f28069M_DRV8312.slx');
%%
% 
% For the model names that you can use for different hardware configurations, see the Required Hardware topic in the Generate Code and Deploy Model to Target Hardware section.
% 
%% Required MathWorks(R) Products
% 
% *To simulate model:*
% 
% *1.* For the models: *mcb_open_loop_control_f28069M_DRV8312* and *mcb_open_loop_control_f28069MLaunchPad*
% 
% * Motor Control Blockset(TM)
% * Fixed-Point Designer(TM)
% 
% *2.* For the model: *mcb_open_loop_control_f28379d*
% 
% * Motor Control Blockset(TM)
% 
% *To generate code and deploy model:*
% 
% *1.* For the models: *mcb_open_loop_control_f28069M_DRV8312* and *mcb_open_loop_control_f28069MLaunchPad*
% 
% * Motor Control Blockset(TM)
% * Embedded Coder(R)
% * Embedded Coder(R) Support Package for Texas Instruments(TM) C2000(TM) Processors
% * Fixed-Point Designer(TM)
%
% *2.* For the model: *mcb_open_loop_control_f28379d*
% 
% * Motor Control Blockset(TM)
% * Embedded Coder(R)
% * Embedded Coder(R) Support Package for Texas Instruments(TM) C2000(TM) Processors
% * Fixed-Point Designer(TM) (only needed for optimized code generation)
% 
%% Prerequisites
% 
% *1.* For BOOSTXL-DRV8323, use these steps to update the model:
% 
% * Navigate to this path in the model: /Open Loop Control/Codegen/Hardware Initialization.
% 
% * For LAUNCHXL-F28379D: Update *DRV830x Enable block* from GPIO124 to GPIO67.
% 
% * For LAUNCHXL-F28069M: Update *DRV830x Enable block* from GPIO50 to GPIO12.
% 
% *2.* For BOOSTXL-3PHGANINV, use these steps to update the model:
% 
% * For LAUNCHXL-F28379D: In the *Configuration* panel of
% *mcb_open_loop_control_f28379d*, set *Inverter Enable Logic* to *Active
% Low*.
% 
% *NOTE:* When using BOOSTXL-3PHGANINV inverter, ensure that proper insulation is available between bottom layer of BOOSTXL-3PHGANINV and the LAUNCHXL board. 
% 
% 
%% Simulate Model
% 
% This example supports simulation. Follow these steps to simulate the
% model.
% 
% *1.* Open a model included with this example.
% 
% *2.* Click *Run* on the *Simulation* tab to simulate the model.
% 
% *3.* Click *Data Inspector* on the *Simulation* tab to view and analyze the simulation
% results.
% 
%% Generate Code and Deploy Model to Target Hardware
% This section instructs you to generate code and run the motor by using open-loop control.
% 
% The example uses a host and a target model. The host model is a user interface to the controller hardware board.  You can run the host model on the host computer. The prerequisite to use the host model is to deploy the target model to the controller hardware board. The host model uses serial communication to command the target Simulink(R) model and run the motor in a closed-loop control.
% 
% *Required Hardware*
%
% This example supports these hardware configurations. You can also use the target model name to open the model for the corresponding hardware configuration, from the MATLAB(R) command prompt.
% 
% * F28069M controller card + DRV8312-69M-KIT inverter: <matlab:open_system('mcb_open_loop_control_f28069M_DRV8312') mcb_open_loop_control_f28069M_DRV8312>
% 
% For connections related to the preceding hardware configuration, see <docid:mcb_gs#mw_5f4d03ef-ffbd-4718-a6c2-499733b1529e Hardware Connections for DRV8312-69M-KIT board>.
% 
% * LAUNCHXL-F28069M controller + (BOOSTXL-DRV8301 or BOOSTXL-DRV8305 or BOOSTXL-DRV8323 or BOOSTXL-3PHGANINV) inverter: <matlab:open_system('mcb_open_loop_control_f28069MLaunchPad') mcb_open_loop_control_f28069MLaunchPad>
% 
% * LAUNCHXL-F28379D controller + (BOOSTXL-DRV8301 or BOOSTXL-DRV8305 or BOOSTXL-DRV8323 or BOOSTXL-3PHGANINV) inverter: <matlab:open_system('mcb_open_loop_control_f28379d') mcb_open_loop_control_f28379d>
% 
% To configure the model *mcb_open_loop_control_f28379d*, set the *Inverter Enable Logic* field (in the *Configuration* panel of target model) to:
% 
% * *Active High*: To use the model with BOOSTXL-DRV8301 or BOOSTXL-DRV8305 or BOOSTXL-DRV8323 inverter.
% * *Active Low*: To use the model with BOOSTXL-3PHGANINV inverter.
% 
% For connections related to the preceding hardware configurations, see <docid:mcb_gs#mw_8a869325-5b0d-4631-afd5-05a23622cc5c Hardware Connections for LAUNCHXL board>.
% 
% 
% *NOTE:*  
% 
% * This example supports any type of three-phase AC motor (PMSM or induction) and any type of inverter attached to the supported hardware.
% 
% * Some PMSMs do not run at higher speeds, especially when the shaft is loaded. To resolve this issue, you should apply more voltages corresponding to a given frequency. You can use these steps to increase the applied voltages in the model:
% 
% *1.* Navigate to this path in the model: /Open Loop Control/Control_System/VabcCalc/.
% 
% *2.* Update the gain Correction_Factor_sinePWM as 20%.
% 
% *3.* For safety reasons, regularly monitor the motor shaft, motor current, and motor temperature.
% 
%  
% *Generate Code and Run Model to Implement Open-Loop Control*
%
% *1.* Simulate the target model and observe the simulation results.
% 
% *2.* Complete the hardware connections.
% 
% *3.* Open the target model for the hardware configuration that you want to use. If you want to change the default hardware configuration settings for the target model, see <docid:mcb_gs#mw_3286e9a5-4b65-4b84-9133-a92130b252bc Model Configuration
% Parameters for Sensors>.
% 
% *4.* Update these motor parameters in the *Configuration* panel of the target model.
% 
% * *Number of Pole Pairs*
% * *PWM Frequency [Hz]*
% * *Base Speed [RPM]*
% * *Data type for control algorithm*
% * *Inverter Enable Logic* (only available in
% *mcb_open_loop_control_f28379d* target model)
% 
% *5.* Load a sample program to CPU2 of LAUNCHXL-F28379D, for example, a program that operates the CPU2 blue LED by using GPIO31 (c28379D_cpu2_blink.slx), to ensure that CPU2 is not mistakenly configured to use the board peripherals intended for CPU1.
% 
% *6.* Click *Build, Deploy & Start* on the *Hardware* tab to deploy the target model to the hardware.
% 
% *NOTE:* Ignore the warning message "Multitask data store option in the Diagnostics page of the Configuration Parameter Dialog is none" displayed by the model advisor, by clicking the Always Ignore button. This is part of the intended workflow.
% 
% *7.* Click the *host model* hyperlink in the target model to open the associated host model. You can also use the open_system command to open the host model. For example, use this command for a F28069M based controller:
%%
open_system('mcb_open_loop_control_host_model.slx'); 
%%
% For details about the serial communication between the host and target
% models, see <docid:mcb_gs#mw_7d703f4b-0b29-4ec7-a42b-0b300f580ccc Communication between Host and Target>.
% 
% *8.* In the Host Serial Setup block mask of the host model, select a *Port name*.
% 
% *9.* Select a target (either TI F28069M or TI F28379D) in the *Configuration Panel* of the host model.
% 
% *10.* Enter the Reference Speed value in the host model.
%  
% *11.* Click *Run* on the *Simulation* tab to run the host model.
% 
% *12.* Change the position of the Start / Stop Motor switch to On, to start running the motor.
% 
% *13.* After the motor is running, observe the ADC counts for the ${I_a}$ and ${I_b}$ currents in the Time Scope.
% 
% *NOTE:* This example may not allow the motor to run at full capacity. Begin running the motor at a small speed. In addition, it is recommended to change the Reference Speed in small steps (for example, for a motor having a base speed of 3000 rpm, start running the motor at 500 rpm and then increase or decrease the speed in steps of 200 rpm).
% 
% If the motor does not run, change the position of the Start / Stop Motor switch to Off, to stop the motor and change the Reference Speed in the host model. Then, change the position of the Start / Stop Motor switch to On, to run the motor again.
% 
% *Generate Code and Run Model to Calibrate ADC Offset*
% 
% *1.* Simulate the target model and observe the simulation results.
% 
% *2.* Complete the hardware connections.
% 
% *3.* Disconnect the motor wires for three phases from the hardware board terminals.
% 
% *4.* Open the target model for the hardware configuration that you want to use. If you want to change the default hardware configuration settings for the target model, see <docid:mcb_gs#mw_3286e9a5-4b65-4b84-9133-a92130b252bc Model Configuration
% Parameters for Sensors>.
% 
% *5.* Load a sample program to CPU2 of LAUNCHXL-F28379D (for example, program that operates the CPU2 blue LED using GPIO31) to ensure that CPU2 is not mistakenly configured to use the board peripherals intended for CPU1.
% 
% *6.* Click *Build, Deploy & Start* on the *Hardware* tab to deploy the target model to the hardware.
% 
% *NOTE:* Ignore the warning message "Multitask data store option in the Diagnostics page of the Configuration Parameter Dialog is none" displayed by the model advisor, by clicking the Always Ignore button. This is part of the intended workflow.
% 
% *7.* Click the *host model* hyperlink in the target model to open the associated host model.
% 
% *8.* In the Host Serial Setup block mask of the host model, select a *Port name*.
% 
% *9.* Click *Run* on the *Simulation* tab to run the host model.
% 
% *10.* Observe the ADC counts for the ${I_a}$ and ${I_b}$ currents in the Time Scope. The average values of the ADC counts are the ADC offset corrections for the currents ${I_a}$ and ${I_b}$. To obtain the average (median) values of ADC counts:
% 
% * In the *Scope* window, navigate to *Tools* > *Measurements* and select *Signal Statistics* to display the *Trace Selection* and *Signal Statistics* areas.
% 
% <<../mcb_open_loop_scope.png>>
% 
% * Under *Trace Selection*, select a signal (${I_a}$ or ${I_b}$). The characteristics of the selected signal are displayed in the *Signal Statistics* pane. You can see the median value of the selected signal in the Median field.
% 
% <<../mcb_open_loop_scope1.png>>
% 
% For the Motor Control Blockset examples, update the computed ADC (or current) offset value in the inverter.CtSensAOffset and inverter.CtSensBOffset variables in the model initialization script linked to the example. For instructions, see <docid:mcb_gs#mw_dd32d1fd-68d8-4cfd-8dea-ef7f7ed008c0 Estimate Control Gains from Motor Parameters>.
% 