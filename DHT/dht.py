
from machine import Pin
import dht
import time

# Initialize DHT22 sensor on GP15
sensor = dht.DHT22(Pin(15))

while True:
    try:
        # Read sensor data
        sensor.measure()

        # Get temperature and humidity
        temperature = sensor.temperature()
        humidity = sensor.humidity()

        # Print readings
        print("Temperature: {:.1f} °C".format(temperature))
        print("Humidity: {:.1f} %".format(humidity))
        print("------------------------")

    except OSError as e:
        print("Failed to read DHT22:", e)

    # Wait 2 seconds
    time.sleep(2)

# For RPI Pico
