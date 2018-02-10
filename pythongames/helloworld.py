import pygame, sys
from pygame.locals import *

h = 400
w = 300
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
l = 100
r = 200
pygame.init()
DISPLAYSURF = pygame.display.set_mode((h, w))
pygame.display.set_caption('hello world')

pixObj = pygame.PixelArray(DISPLAYSURF)
pixObj[l][r] = WHITE
while True:
  for event in pygame.event.get():
    if event.type == QUIT:
      pygame.quit()
      sys.exit()
    if event.type == KEYUP:
      pixObj[l][r] = BLACK
      l += 10
      pixObj[l][r] = WHITE
  pygame.display.update()
