import serial
import keyboard
import time

arduino = serial.Serial('COM7', 9600, timeout=1)
time.sleep(2)

last_cmd = 'S'

while True:
    if keyboard.is_pressed('up'):
        cmd = 'F'
    elif keyboard.is_pressed('down'):
        cmd = 'B'
    elif keyboard.is_pressed('left'):
        cmd = 'L'
    elif keyboard.is_pressed('right'):
        cmd = 'R'
    else:
        cmd = 'S'

    if cmd != last_cmd:
        arduino.write(cmd.encode())
        print("Sent:", cmd)
        last_cmd = cmd

    time.sleep(0.05)