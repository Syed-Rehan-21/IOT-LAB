import serial

# Replace '/dev/ttyUSB0' with the actual serial port your Arduino is connected to
ser = serial.Serial('/dev/ttyUSB0', 9600)

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode('utf-8').rstrip()
        print(f"Received from Arduino: {data}")