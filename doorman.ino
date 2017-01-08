int lightSensor = A0;
int lightSensorReading = 0;
bool lightOn = false;

void setup() {
    Serial.begin(9600);
    pinMode(lightSensor, OUTPUT);
}

void loop() {
    lightSensorReading = analogRead(lightSensor);
    if (lightSensorReading > 1000 && !lightOn) {
        lightOn = true;
        Particle.publish("lightTurnedOn");
    } else if (lightSensorReading < 1000 && lightOn) {
        lightOn = false;
        Particle.publish("lightTurnedOff");
    }
    delay(10000);
}
