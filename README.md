# particle-flow-meter

This project is designed for the Particle Photon to measure water flow using a flow sensor. It utilizes the `FlowMeter` library to calculate the flow rate and communicates with the Particle Cloud.

## Setup Instructions

- **Wiring Setup**:
  1. **Black Wire**: Connect to the **GND (Ground)** pin on the Particle Photon.
  2. **Red Wire**: Connect to the **VIN (Voltage In)** pin on the Particle Photon.
  3. **Yellow Wire**: Connect to **A1 (Analog Pin 1)** on the Particle Photon.
  4. **10k Ohm Pull-Up Resistor**: Connect one end to the **3V3 (3.3V)** pin on the Particle Photon, and the other end to **A1**.

  This wiring setup ensures that the Particle Photon can accurately read the pulse signals from the flow sensor, which are used to calculate the flow rate.

- **Software Setup**:
  - Use [Particle Build](https://build.particle.io) to flash the `particle_flow_meter.ino` file to your Particle Photon device.

## Flow Sensor

- [HA-1044 Flow Meter](https://h2oprotech.com/collections/general-purpose-flow-meters/products/flow-meter-3-wire)

## Required Libraries

- [FlowMeter Library](https://github.com/sekdiy/FlowMeter)

Make sure to include the `FlowMeter` library in your Particle project.