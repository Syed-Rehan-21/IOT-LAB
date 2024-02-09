import RPi.GPIO as GPIO
import time

# Define GPIO pins for trigger and echo
TRIGGER_PIN = 21
ECHO_PIN = 18

# Set GPIO mode (BCM or BOARD)
GPIO.setmode(GPIO.BCM)

# Set trigger pin as output
GPIO.setup(TRIGGER_PIN, GPIO.OUT)

# Set echo pin as input
GPIO.setup(ECHO_PIN, GPIO.IN)

def measureDistance():
  # Send 10 microsecond pulse to trigger pin
  GPIO.output(TRIGGER_PIN, True)
  time.sleep(0.00001)
  GPIO.output(TRIGGER_PIN, False)

  # Measure pulse duration on echo pin
  pulseStart = time.time()
  while GPIO.input(ECHO_PIN) == 0:
    pulseStart = time.time()
  while GPIO.input(ECHO_PIN) == 1:
    pulseEnd = time.time()

  pulseDuration = pulseEnd - pulseStart

  # Calculate distance in centimeters
  distance = pulseDuration * 17000 / 2

  return distance

if __name__ == '__main__':
  try:
    while True:
      # Get distance reading
      distanceCm = measureDistance()

      # Print distance to console
      print("Distance:", distanceCm, "cm")

      time.sleep(1) # Adjust delay as needed

  except KeyboardInterrupt:
    # Clean up GPIO on exit
    GPIO.cleanup()