import pygame
import os   
import time
import CPP_PWM_CODE

max_value = 1830 
min_value = 1100
direction = 6.0 #for turning
speed = 1500

pygame.init()

width_height = (1150, 700)
screen = pygame.display.set_mode(width_height)
buttonFont = pygame.font.SysFont("monospace", 25)
pygame.display.set_caption("HEVT")
backdrop = pygame.image.load("HEVT_m.png").convert()  #back ground
backdropbox = screen.get_rect()

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

clock = pygame.time.Clock()

def main():
	global is_blue, x, y, direction, speed, ESC
	while True:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				pygame.quit()
			if event.type == pygame.MOUSEBUTTONDOWN:
				if event.button == 1:
					if calibrate_button.collidepoint(event.pos):
						###calibrate??? is this needed for the jetson arduino?
						print("calibrate")  
						print(testFunc())
						

					if manual_button.collidepoint(event.pos):
						##print("manual")
						print("manual")
							
					if increase_button.collidepoint(event.pos):
						speed += 20
						###speed increase
						print("speed increase")
							 
					if decrease_button.collidepoint(event.pos):
						speed -= 20
						###speed decrease
						print("decrease increase")

					if left_button.collidepoint(event.pos):
						direction += 0.5
						###left turn
						print("left turn")

					if right_button.collidepoint(event.pos):
						direction -= 0.5
						###right turn
						print("right turn")

					if stop_button.collidepoint(event.pos):
						###stop button
						print("stop")
		drawScreen()
        
        
def drawScreen():
	screen.fill((30, 30, 30))
	screen.blit(backdrop, backdropbox)
	
	screen.blit(Speed_Label, (900, 200))
	screen.blit(Direction_Label, (900, 300))
	screen.blit(Current_SD_Label, (900, 400))
	screen.blit(Current_Speed_Label, (900, 430))
	screen.blit(Current_Direction_Label, (900, 460))
	
	SPEED_SHOW = buttonFont.render(str(speed), True, (255, 255, 0))
	width = max(200, SPEED_SHOW.get_width()+10)
	screen.blit(SPEED_SHOW , (1050,430))
	
	Direction_SHOW = buttonFont.render(str(direction), True, (255, 255, 0))
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
        
if __name__ == '__main__':
    main()
