#include <DHT.h>

const uint8_t dhtPin = 2;
const uint8_t dhtType = DHT22;

DHT dht(dhtPin, dhtType);

float temperature;
float humidity;

void setup()
{
    Serial.begin(115200);
    Serial.println(F("DHT22 example!"));

    dht.begin();
}

void loop()
{
    readDhtSensor();
    printSerialTemperatureAndHumidity();

    // Wait
    delay(2000);
}

void readDhtSensor()
{
    // Note: in order to get good readings wait about 2 secs between readings
    temperature = dht.readTemperature(); // using global vars to save the readings
    humidity = dht.readHumidity();

    // Check if any reads failed and exit early (to try again).
    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }
}

void printSerialTemperatureAndHumidity()
{
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print(F("%  Temperature: "));
    Serial.print(temperature);
    Serial.println(F("°C "));
}