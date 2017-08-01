int lightSensor = A0;
int lightSensorReading = 0;
int interval = 5000;
bool lightOn = false;

void setup() {
    Serial.begin(9600);
    pinMode(lightSensor, OUTPUT);
}

void loop() {
    if (Time.hour() > 8 && Time.hour() < 18) {
        interval = 5000;
    } else {
        interval = 3600000;
    }
    lightSensorReading = analogRead(lightSensor);
    if (lightSensorReading > 1000 && !lightOn) {
        lightOn = true;
        Particle.publish("lightTurnedOn");
    } else if (lightSensorReading < 1000 && lightOn) {
        lightOn = false;
        Particle.publish("lightTurnedOff");
    }
    delay(interval);
}
