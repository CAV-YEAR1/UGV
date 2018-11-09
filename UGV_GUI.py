import pygame
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
p.start(6.0)

ESC=4   #gpio pin

pi = pigpio.pi();
pi.set_servo_pulsewidth(ESC, 0) 

max_value = 1830 
min_value = 1100
Direction = 6.0 #for turning
speed = 1560

pygame.init()

width_height = (1150, 700)

#screen = pygame.display.set_mode(width_height)

buttonFont = pygame.font.SysFont("monospace", 25)
pygame.display.set_caption("HEVT")
#backdrop = pygame.image.load("HEVT_m.png").convert()  #back ground
#backdropbox = screen.get_rect()

# calibrate Button 
calibrate_button = pygame.Rect(100, 100, 160, 60)
calibrate_button.x = 880
calibrate_button.y = 10

manual_button = pygame.Rect(100, 100, 160, 60) #change
manual_button.x = 880# change
manual_button.y = 130#change

#increase
increase_button = pygame.Rect(100, 100, 40, 50)
increase_button.x = 880
increase_button.y = 230

#Decrese
decrease_button = pygame.Rect(100, 100, 40, 50)
decrease_button.x = 930
decrease_button.y = 230

#left
left_button = pygame.Rect(100, 100, 40, 50)
left_button.x = 880
left_button.y = 330

#right
right_button = pygame.Rect(100, 100, 40, 50)
right_button.x = 930
right_button.y = 330

# Stop Button 
stop_button = pygame.Rect(100, 100, 160, 60)
stop_button.x = 880
stop_button.y = 500

Label_Font = pygame.font.SysFont("monospace", 20)

calibrate_Label = buttonFont.render("calibrate", 1, (0, 0, 0)) #calibrate BUTTON
manual_Label = buttonFont.render("manual", 1, (0, 0, 0)) #manual BUTTON
Increase_Label = buttonFont.render("+", 1, (0, 0, 0)) #calibrate BUTTON
Decrease_Label = buttonFont.render("-", 1, (0, 0, 0)) #calibrate BUTTON
Left_Label = buttonFont.render("L", 1, (0, 0, 0)) #calibrate BUTTON
Right_Label = buttonFont.render("R", 1, (0, 0, 0)) #calibrate BUTTON
Stop_Label = buttonFont.render("STOP", 1, (0, 0, 0)) #calibrate BUTTON

Speed_Label = Label_Font.render("SPEED", 1, (255, 255, 0))
Direction_Label = Label_Font.render("Direction", 1, (255, 255, 0))

Current_SD_Label = Label_Font.render("Current", 1, (255, 255, 0))
Current_Speed_Label = Label_Font.render("Speed:", 1, (255, 255, 0))
Current_Direction_Label = Label_Font.render("Direction:", 1, (255, 255, 0))


def calibrate():
    pi.set_servo_pulsewidth(ESC, 0)
    print("Disconnect the battery")
    pi.set_servo_pulsewidth(ESC, max_value)
    time.sleep(5)
    print("Connect the battery")
    pi.set_servo_pulsewidth(ESC, min_value)
    time.sleep(2)
    print ("Wait for it ....")
    time.sleep (5)
    pi.set_servo_pulsewidth(ESC, 0)
    time.sleep(2)
    pi.set_servo_pulsewidth(ESC, min_value)
    time.sleep(1)
    print ("Now you can press the buttons!")
    
def increase_speed():
    global speed
    print("inc_speed")
    speed = speed + 20
    pi.set_servo_pulsewidth(ESC, speed)
    print("speed:", speed)
    
def decrease_speed():
    global speed
    print("dec_speed") 
    speed = speed - 20
    pi.set_servo_pulsewidth(ESC, speed)
    print("speed:", speed)
    
def left_side():
    global Direction
    print("left_side")
    Direction = Direction + 0.5
    p.ChangeDutyCycle(Direction)
    time.sleep(0.5)
    
def right_side():
    global Direction
    print("right_side")
    Direction = Direction - 0.5
    p.ChangeDutyCycle(Direction)
    time.sleep(0.5)
    
def stop():
    print("stop")
    pi.set_servo_pulsewidth(ESC, 0)
    pi.stop()
    
clock = pygame.time.Clock()

def cmd_line():
    user_input = raw_input("cal, left = a, right = d , up = w , down = s , stop:   ")
    cmd_true = True
    while cmd_true:
        if user_input is not None: 
            if user_input == "cal":
                print("calibrate")
                calibrate()
                cmd_true = False
                cmd_line()
                        
            if user_input == "w":
                print(" + ")
                increase_speed()
                cmd_true = False 
                cmd_line()
                         
            if user_input == "s":
                print(" - ")
                decrease_speed()
                cmd_true = False
                cmd_line()
                
            if user_input == "a":
                print("LEFT")
                left_side()
                cmd_true = False
                cmd_line()
            
            if user_input == "d":
                print("RIGHT")
                right_side()
                cmd_true = False
                cmd_line()
                
            if user_input == "stop":
                print("STOP")
                stop()
                cmd_true = False
                cmd_line()
                
def gui():
    #global Direction, speed, ESC
    screen = pygame.display.set_mode(width_height)
    main = True
    while main:
        for event in pygame.event.get():
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                    
                    if calibrate_button.collidepoint(event.pos):
                        print("calibrate")
                        calibrate()
                                
                    if manual_button.collidepoint(event.pos):
                        print("manual")
                          
                    if increase_button.collidepoint(event.pos):
                        print(" + ")
                        increase_speed()
                                 
                    if decrease_button.collidepoint(event.pos):
                        print(" - ")
                        decrease_speed()
                        
                    if left_button.collidepoint(event.pos):
                        print("LEFT")
                        left_side()
                        
                    if right_button.collidepoint(event.pos):
                        print("RIGHT")
                        right_side()
                        
                    if stop_button.collidepoint(event.pos):
                        print("STOP")
                        stop()
                        
                
        screen.fill((30, 30, 30))
        #screen.blit(backdrop, backdropbox)
        
        screen.blit(Speed_Label, (900, 200))
        screen.blit(Direction_Label, (900, 300))
        screen.blit(Current_SD_Label, (900, 400))
        screen.blit(Current_Speed_Label, (900, 430))
        screen.blit(Current_Direction_Label, (900, 460))
        
        SPEED_SHOW = buttonFont.render(str(speed), True, (255, 255, 0))
        width = max(200, SPEED_SHOW.get_width()+10)
        screen.blit(SPEED_SHOW , (1050,430))
        
        Direction_SHOW = buttonFont.render(str(Direction), True, (255, 255, 0))
        width = max(200, Direction_SHOW.get_width()+10)
        screen.blit(Direction_SHOW , (1050,460))
        
        #screen.blit(Current_Speed_Label_1, (950, 430))
        #screen.blit(Current_Direction_Label_1, (950, 460))
        
        ## BUTTONS ##
        pygame.draw.rect(screen, [255, 255, 255], calibrate_button)
        screen.blit(calibrate_Label, (900, 30))
        
        pygame.draw.rect(screen, [255, 255, 255], manual_button)
        screen.blit(manual_Label, (900, 130))
        
        pygame.draw.rect(screen, [255, 255, 0], increase_button)
        screen.blit(Increase_Label, (895, 240))
        
        pygame.draw.rect(screen, [255, 255, 0], decrease_button)
        screen.blit(Decrease_Label, (945, 240))
        
        pygame.draw.rect(screen, [255, 255, 0], left_button)
        screen.blit(Left_Label, (895, 340))
        
        pygame.draw.rect(screen, [255, 255, 0], right_button)
        screen.blit(Right_Label, (945, 340))
        
        pygame.draw.rect(screen, [255, 255, 255], stop_button)
        screen.blit(Stop_Label, (900, 530))
                        
        pygame.display.flip()
        clock.tick(60)
    
def auto():
    global speed
    print("will follow EPA US06 or Supplemental Fedral Test Procedure")
    user_input = raw_input("cal, start: ")
    cmd_true = True
    while cmd_true:
        if user_input is not None: 
            if user_input == "cal":
                print("calibrate")
                calibrate()
                cmd_true = False
                auto()
                        
            if user_input == "start":
                for x in range (0,30):
                    speed = speed + 5
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    x = x+1
                    time.sleep(0.5)
                
                time.sleep(0.5)   
                for y in range (0,30):
                    speed = speed -5
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    y = y +1
                    time.sleep(0.5)
                
                time.sleep(0.5)
                for z in range (0,30):
                    speed = speed + 9
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    z = z+1
                    time.sleep(0.5)
                
                time.sleep(0.5)
                for a in range (0,30):
                    speed = speed -9
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    a = a +1
                    time.sleep(0.5)
                
                #third 
                time.sleep(0.5)
                for b in range (0,10):
                    speed = speed + 15
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    b = b+1
                    time.sleep(0.5)
                
                time.sleep(0.5)
                for c in range (0,30):
                    speed = speed + 2
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    c = c +1
                    time.sleep(0.5)
                    
                time.sleep(0.5)
                for d in range (0,10):
                    speed = speed + 3
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    d = d+1
                    time.sleep(0.5)
                
                time.sleep(0.5)
                for e in range (0,10):
                    speed = speed -3 
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    e = e +1
                    time.sleep(0.5)
                    
                time.sleep(0.5)
                for f in range (0,30):
                    speed = speed -2 
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    f = f +1
                    time.sleep(0.5)
                    
                time.sleep(0.5)
                for g in range (0,10):
                    speed = speed - 15 
                    pi.set_servo_pulsewidth(ESC, speed)
                    print("speed:", speed)
                    g = g +1
                    time.sleep(0.5)
                    
                #fourth
                pi.set_servo_pulsewidth(ESC, 1610)
                print("speed:", speed)
                time.sleep(0.5)
                pi.set_servo_pulsewidth(ESC, 1580)
                print("speed:", speed)
                time.sleep(0.5)
                pi.set_servo_pulsewidth(ESC, 1640)
                print("speed:", speed)
                time.sleep(0.5)
                pi.set_servo_pulsewidth(ESC, 1570)
                print("speed:", speed)
                time.sleep(0.5)
                pi.set_servo_pulsewidth(ESC, 1640)
                print("speed:", speed)
                time.sleep(0.5)
                pi.set_servo_pulsewidth(ESC, 1580)
                print("speed:", speed)
                time.sleep(0.5)
                pi.set_servo_pulsewidth(ESC, 1670)
                print("speed:", speed)
                time.sleep(0.5)
                pi.set_servo_pulsewidth(ESC, 1580)
                print("speed:", speed)
                time.sleep(0.5)
                pi.set_servo_pulsewidth(ESC, 1780)
                print("speed:", speed)
                time.sleep(0.5)
                pi.set_servo_pulsewidth(ESC, 1560)
                print("speed:", speed)
                pi.set_servo_pulsewidth(ESC, 0)
                    
                    
                
                
                
                 
    

def main():
    user_input = raw_input("gui, cmd , auto:   ")
    if user_input == "gui":
        gui()
    elif user_input == "cmd":
        cmd_line()
    elif user_input == "auto":
        auto()
               
        
 
if __name__ == '__main__':
    main()