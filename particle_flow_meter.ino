#include <FlowMeter.h>
#include "Particle.h"

// Use automatic connection to Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Log system and application messages to the USB serial port
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// Measurement interval in milliseconds
unsigned long period = 1000;
unsigned long lastNotificationTime = 0;
const unsigned long notifyInterval = 3600000; // 1 hour in ms

// Global variables for flow state
bool isFlowing = false;
bool previousIsFlowing = true;
double flowRate = 0.0;

// Flow meter object
FlowMeter Meter;

// Interrupt Service Routine: called on every rising pulse from the flow sensor
void MeterISR() {
    Meter.count();  // count the pulse
}

void setup() {
    Serial.begin(9600);

    // Set pin A1 as input for flow sensor pulses
    pinMode(A1, INPUT);

    // Attach the interrupt to count pulses
    attachInterrupt(A1, MeterISR, RISING);

    // Expose flow state variables to the Particle Cloud
    Particle.variable("is_flowing", isFlowing);
    Particle.variable("flow_rate", flowRate);
}

void loop() {
    delay(period);  // wait between readings

    // Calculate flow based on pulses counted over the period
    Meter.tick(period);

    // Update global variables
    flowRate = Meter.getCurrentFlowrate();
    isFlowing = (flowRate > 0);
    
    unsigned long now = millis();

    // Only publish when flow transitions from flowing → not flowing
    // OR if it’s been clogged for a while and it's time to remind
    if (!isFlowing && (previousIsFlowing || (now - lastNotificationTime > notifyInterval))) {
        Particle.publish("is_flowing", "false", PRIVATE);
        lastNotificationTime = now;
    }

    // Reset tracking if flow resumes
    // if (isFlowing && !previousIsFlowing) {
    //     Particle.publish("is_flowing", "true", PRIVATE);
    // }

    previousIsFlowing = isFlowing;

    // Log to serial for debugging
    Serial.printf("Flow rate: %.2f l/min\n", flowRate);
}
