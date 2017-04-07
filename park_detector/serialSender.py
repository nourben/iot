import serial
import time
import requests

class Action:
	#Read data from the GPS
	def read(self):	
                prefix = "PARK-IOT_"

                ser = serial.Serial(port='/dev/cu.wchusbserial1420',baudrate = 9600,parity = serial.PARITY_NONE,stopbits = serial.STOPBITS_ONE, bytesize = serial.EIGHTBITS,timeout = 1)
                ser.flush

                while True:
                        data = ser.readline();
                        if( len(data) == 0 or len(data)>25 ) :
                                print("nothing to read");
                        else:
                                if(data[:9] == prefix):
                                        return data
                                else:
                                        return "null"
                                
print "--------------------"
print "Start"

prgm = Action()
while True:
        print "waiting for data..."
        try:
                rawValues = prgm.read();
                [pref, parkingSpot, value] = rawValues.split("_")
                print "data received..."
                print "sending request..."
                
                boolVal = False
                print "value received : -" + value +"-"

                if(value.startswith("True")):
                        boolVal = True
                        print "bool : true"
                else : 
                        boolVal = False
                        print "bool : false"
                        
                try:
                        r = requests.put("https://parking-sensors.herokuapp.com/api/parking/"+parkingSpot, json={"isFree": boolVal})
                        print(r.status_code, r.reason)
                        print(r.text)
                except requests.exceptions.ConnectionError as err:
                        print "Probleme serveur inaccessible", err

                time.sleep(2)

	except serial.serialutil.SerialException as err:
		print "serialPB exception", err
		time.sleep(2)
	except ValueError as err:
		print "value Error", err
	except IndexError:
		print "Unable to read"
	except KeyboardInterrupt:
		#f.close()
		print "Exiting"
		sys.exit(0)