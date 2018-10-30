import os   
import time   
os.system ("sudo pigpiod") 
time.sleep(1) 
import pigpio
import RPi.GPIO as GPIO


servoPIN = 17
GPIO.setmode(GPIO.BCM)
GPIO.setup(servoPIN, GPIO.OUT)

p = GPIO.PWM(servoPIN, 50) # GPIO 17 for PWM with 50Hz
p.start(6.5)

ESC=4   #gpio pin

pi = pigpio.pi();
pi.set_servo_pulsewidth(ESC, 0) 

max_value = 1830 
min_value = 1100

print ("For first time launch, select calibrate")
print ("calibrate OR manual OR control OR arm OR stop")


def calibrate():   
    pi.set_servo_pulsewidth(ESC, 0)
    print("Disconnect the battery and press Enter")
    input_value = input()
    if input_value == '':
        pi.set_servo_pulsewidth(ESC, max_value)
        print("Connect the battery NOW.. you will here two beeps, then wait for a gradual falling tone then press Enter")
        input_value = input()
        if input_value == '':            
            pi.set_servo_pulsewidth(ESC, min_value)
            time.sleep(7)
            print ("Wait for it ....")
            time.sleep (5)
            pi.set_servo_pulsewidth(ESC, 0)
            time.sleep(2)
            pi.set_servo_pulsewidth(ESC, min_value)
            time.sleep(1)
            control() 
            
            
def manual_drive(): 
    print ("You have selected manual option so give a value between 0 and you max value")    
    while True:
        input_value = input()
        if input_value == "stop":
            stop()
            break
        elif input_value == "control":
            control()
            break
        elif input_value == "arm":
            arm()
            break   
        else:
            pi.set_servo_pulsewidth(ESC,input_value)
            
def control(): 
    print ("I'm Starting the motor, I hope its calibrated and armed, if not restart by giving 'x'")
    time.sleep(1)
    speed = 1300  # change your speed if you want to.... it should be between 700 - 2000
    print ("Controls - a to decrease speed & d to increase speed OR q to decrease a lot of speed & e to increase a lot of speed")
    while True:
        pi.set_servo_pulsewidth(ESC, speed)
        input_value = input()
        
        if input_value == "q":
            speed -= 10    # decrementing the speed like hell
            print ("speed = %d" % speed)
        elif input_value == "e":    
            speed += 10    # incrementing the speed like hell
            print ("speed = %d" % speed)
        elif input_value == "a":
            speed -= 5     # decrementing the speed
            print ("speed = %d" % speed)
        elif input_value == "d":
            speed += 5     # incrementing the speed 
            print ("speed = %d" % speed)
        elif input_value == "ll":
            p.ChangeDutyCycle(7.5)
            time.sleep(0.5)
        elif input_value == "l":
            p.ChangeDutyCycle(6.5)
            time.sleep(0.5)
        elif input_value == "r":
            p.ChangeDutyCycle(3.5)
            time.sleep(0.5)
        elif input_value == "rr":
            p.ChangeDutyCycle(2.5)
            time.sleep(0.5)
        elif input_value == "stop":
            stop()          #going for the stop function
            break
        elif input_value == "manual":
            manual_drive()
            break
        elif input_value == "arm":
            arm()
            break   
        else:
            print ("WHAT DID I SAID!! Press a,q,d or e")
            
def arm(): #This is the arming procedure of an ESC 
    print ("Connect the battery and press Enter")
    if input_value == '':
        pi.set_servo_pulsewidth(ESC, 0)
        time.sleep(1)
        pi.set_servo_pulsewidth(ESC, max_value)
        time.sleep(1)
        pi.set_servo_pulsewidth(ESC, min_value)
        time.sleep(1)
        control()
        
def direction():
    print("L for Left- R for Right")
    input_value = input()
    if input_value == "l":
        p.ChangeDutyCycle(7.5)
        time.sleep(0.5) 
        
    if input_value == "r":
        p.ChangeDutyCycle(2.5)
        time.sleep(0.5)
      
def stop(): #This will stop every action your Pi is performing for ESC ofcourse.
    pi.set_servo_pulsewidth(ESC, 0)
    pi.stop()

#This is the start of the program actually, to start the function it needs to be initialized before calling... stupid python.    
input_value = input()
if input_value == "manual":
    manual_drive()
elif input_value == "calibrate":
    calibrate()
elif input_value == "arm":
    arm()
elif input_value == "control":
    control()
elif input_value == "direction":
    direction()
elif input_value == "stop":
    stop()

else :
    print ("Steps not followed properly!")
