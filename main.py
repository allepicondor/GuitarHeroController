import serial
import time
import sys
import signal
import keyboard
def signal_handler(signal, frame):
	print("closing program")
	SerialPort.close()
	sys.exit(0)

COM="COM6"
BAUD="9600"
SerialPort = serial.Serial(COM,BAUD,timeout=1)                                                   
#time.sleep(0.2)
#SerialPort.write("I")
#
while (1):
	IncomingData=SerialPort.readline()
	if(IncomingData):
		data = (IncomingData).decode('utf-8')
		print(data)
		if (len(data) < 7):
			continue
		if (data[0] == "1"):
			keyboard.press_and_release('a')
		if (data[1] == "1"):
			keyboard.press_and_release('s')
		if (data[2] == "1"):
			keyboard.press_and_release('d')
		if (data[3] == "1"):
			keyboard.press_and_release('f')
		if (data[4] == "1"):
			keyboard.press_and_release('g')
		if (data[5] == "1"):
			keyboard.press_and_release('up')
		if (data[6] == "1"):
			keyboard.press_and_release('down')
		if (data[7] == "1"):
			keyboard.press_and_release('enter')
		if (data[8] == "1"):
			keyboard.press_and_release('backspace')

	
