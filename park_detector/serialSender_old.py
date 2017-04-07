import serial
import time

#s = serial.Serial(port='/dev/tty.usbmodemfa141', baudrate=9600)
#s = serial.Serial(port='/dev/cu.wchusbserial1420', baudrate=9600)
ser = serial.Serial(
        port='/dev/cu.wchusbserial1420',
        baudrate = 9600,
        parity = serial.PARITY_NONE,
        stopbits = serial.STOPBITS_ONE,
        bytesize = serial.EIGHTBITS,
        timeout = 1)


print "Debut"

while 1:
    print "Boucle"
    
    data = ser.readline();
    if( len(data) == 0 or len(data)>20 ) :
            print("nothing read");
    else:
            print(data);

    #time.sleep(10)  # Delay for 1 minute (60 seconds)
