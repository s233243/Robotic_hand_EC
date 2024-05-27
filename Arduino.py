### Code for the communication with Arduino
import serial
import csv
import time

# Path to the CSV file
file_path = r"C:\Users\emmie\Documents\DTU\Special course\Code\classification_codes\our_input_subject2\results_pca4.csv"

# Initialize an empty list to store the data
data = []

# Open the CSV file and read its contents into the list
with open(file_path, 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        data.append(row)

print(data)

# Convert the data list to a string
data_str = ''
for row in data:
    data_str += ','.join(row) + '\n'

# Function to open serial connection with retries
def open_serial_connection(port, baudrate, retries=3, delay=2):
    for _ in range(retries):
        try:
            ser = serial.Serial(port, baudrate)
            return ser
        except serial.SerialException as e:
            print(f"Failed to open port {port}: {e}")
            time.sleep(delay)
    raise serial.SerialException(f"Could not open port {port} after {retries} retries")

# Set up the serial connection to the Arduino
port = 'COM7'  # Change to your Arduino port
baudrate = 9600

try:
    ser = open_serial_connection(port, baudrate)
    time.sleep(2)  # Wait for the connection to be established

    # Ensure Arduino is ready
    while True:
        if ser.in_waiting:
            response = ser.readline().decode('utf-8').strip()
            print(f"Arduino says: {response}")
            if response == "Ready to receive data...":
                break

    # Send the data to the Arduino
    ser.write(data_str.encode())
    print("Data sent to Arduino")
    time.sleep(2)

    # Read and print the data received from the Arduino
    while ser.in_waiting:
        received_data = ser.readline().decode('utf-8').strip()
        print(f"Arduino says: {received_data}")
    
    # Close the serial connection
    ser.close()
except serial.SerialException as e:
    print(f"Error: {e}")