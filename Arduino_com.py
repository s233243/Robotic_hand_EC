### Code for the communication with Arduino
import serial
import csv
import time

# # Open the serial port to communicate with Arduino
# ser = serial.Serial('COM7', 9600)  # Adjust 'COM3' to match your Arduino's serial port

ser = serial.Serial('COM7', 9600, timeout=3)
# Read data from CSV file
with open(r"C:\Users\emmie\Documents\DTU\Special course\Code\classification_kaggle\our_input_subject2\results_pca4.csv", 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        # Send data row to Arduino
        row= int(float(row[0]))
        ser.write(str(row).encode())  # Encode data as bytes before sending
        print("Sending data to Arduino:", row)
        time.sleep(2)

        ack = ser.readline().strip().decode()
        print("Received ACK from Arduino:", ack)
        time.sleep(2)

# Close the serial port
ser.close()

# import serial
# import csv
# import time

# # # # Open the serial port to communicate with Arduino
# # # ser = serial.Serial('COM7', 9600)  # Adjust 'COM3' to match your Arduino's serial port

# try:
#     ser=serial.Serial(baudrate='115200', timeout=.5, port='com7')
# except:
#     print('Port open error')

# time.sleep(5)#no delete!

# # ser = serial.Serial('COM7', 9600, timeout=5)
# # # Read data from CSV file
# with open(r"C:\Users\emmie\Documents\DTU\Special course\Code\classification_kaggle\our_input_subject2\results_pca4.csv", 'r') as file:
#     reader = csv.reader(file)
#     for row in reader:
#         # # Send data row to Arduino
#         # row= int(float(row[0]))
#         # ser.write(str(row).encode())  # Encode data as bytes before sending
#         # print("Sending data to Arduino:", row)
#         # time.sleep(2)

#         row_str = ','.join(row)
#         row_str=str(row_str)
        
#         # Send the concatenated row string to Arduino
#         ser.write(row_str.encode())  # Encode data as bytes before sending
#         print("Sending data to Arduino:", row_str)

#         ack = ser.readline().strip()
#         print("Received ACK from Arduino:", ack)
#         # time.sleep(2)

# # Close the serial port
# ser.close()

# # import serial
# # import time
# # import csv

# # import serial
# # from struct import *
# # import sys
# # import time
# # import random
# # import ast


# try:
#     ser=serial.Serial(baudrate='115200', timeout=.5, port='com7')
# except:
#     print('Port open error')

# time.sleep(5)#no delete!
# while True:
#     try:
#         ser.write(pack ('15h',0,1,2,3,4,666,6,7,444,9,10,2222,12,13,random.randint(0,100)))#the 15h is 15 element, and h is an int type data
#                                                                     #random test, that whether data is updated
#         time.sleep(.01)#delay
#         dat=ser.readline()#read a line data
        
#         if dat!=b''and dat!=b'\r\n':
#             try:                #convert in list type the readed data
#                 dats=str(dat)
#                 dat1=dats.replace("b","")
#                 dat2=dat1.replace("'",'')
#                 dat3=dat2[:-4]
#                 list_=ast.literal_eval(dat3) #list_ value can you use in program
#                 print(dat3)
#             except:
#                 print('Error in corvert, readed: ', dats)
#         time.sleep(.05)
#     except KeyboardInterrupt:
#         break
#     except:
#         print(str(sys.exc_info())) #print error
#         break
