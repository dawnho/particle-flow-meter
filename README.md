# particle-flow-meter

This project is designed for the Particle Photon to measure water flow using a flow sensor. It utilizes the `FlowMeter` library to calculate the flow rate and communicates with the Particle Cloud.

## Setup Instructions

1. **Hardware Setup**: Connect the flow sensor to pin A1 on the Particle Photon.
2. **Software Setup**:
   - Ensure you have the Particle CLI or Particle Workbench set up.
   - Flash the `particle_flow_meter.ino` file to your Particle Photon device.

## Required Libraries

- [FlowMeter Library](https://github.com/sekdiy/FlowMeter)

Make sure to include the `FlowMeter` library in your Particle project.