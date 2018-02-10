# Slide Puzzle
# By Al Sweigart al@inventwithpython.com
# http://inventwithpython.com/pygame
# Creative Commons BY-NC-SA 3.0 US

import pygame, sys, random
from pygame.locals import *

BOARD_WIDTH = 4
BOARD_HEIGHT = 4
TILE_SIZE = 80
WINDOW_WIDTH = 640
WINDOW_HEIGHT = 480
FPS = 30
BLANK = None

BLACK          = (  0,   0,   0)
WHITE          = (255, 255, 255)
BRIGHT_BLUE    = (  0,  50, 255)
DARK_TURQUOISE = (  3,  54,  73)
GREEN          = (  0, 204,   0)

BG_COLOR = DARK_TURQUOISE
TILE_COLOR = GREEN
TEXT_COLOR = WHITE
BORDER_COLOR = BRIGHT_BLUE
BASIC_FONT_SIZE = 20

BUTTON_COLOR = WHITE
BUTTON_TEXT_COLOR = BLACK
MESSAGE_COLOR = WHITE

X_MARGIN = int((WINDOW_WIDTH - (TILE_SIZE * BOARD_WIDTH + \
  (BOARD_WIDTH - 1))) / 2)
Y_MARGIN = int((WINDOW_HEIGHT - (TILE_SIZE * BOARD_HEIGHT + \
  (BOARD_HEIGHT - 1))) / 2)
UP = 'up'
DOWN = 'down'
LEFT = 'left'
RIGHT = 'right'

def main():
  global FPS_CLOCK, SURFACE, FONT, RESET_SURFACE, REST_RECT, NEW_SURFACE, \
    NEW_RECT, SOLVE_SURFACE, SOLVE_RECT

  pygame.init()
  FPS_CLOCK = pygame.time.Clock()
  SURFACE = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
  pygame.display.set_caption('Slide Puzzle')
  FONT = pygame.font.Font('freesansbold.ttf', BASIC_FONT_SIZE)

  RESET_SURFACE, REST_RECT = makeText('Reset', TEXT_COLOR, TILE_COLOR, \
    WINDOW_WIDTH - 120, WINDOW_HEIGHT - 90)
  NEW_SURFACE, NEW_RECT = makeText('New Game', TEXT_COLOR, TILE_COLOR, \
    WINDOW_WIDTH - 120, WINDOW_HEIGHT - 60)

  SOLVE_SURFACE, SOLVE_RECT = makeText('Solve', TEXT_COLOR, TILE_COLOR, \
    WINDOW_WIDTH - 120, windowh - 30)
  main_board, solution_sequence = generate_new_puzzle(80);
  SOLVED_BOARD = get_starting_board()
  all_moves = []

  while True:
    slide_to = None
    message = ''

    if main_board == SOLVED_BOARD:
      message = 'Solved!'

    draw_board(main_board, message)

    check_for_quit()

    for event in pygame.event.get():
      if event.type == MOUSEBUTTONUP:
        spot_x, spot_y = get_spot_clicked(main_board, event.pos[0], event.pos[1])

        if (spot_x, spot_y) == (None, None):
          if REST_RECT.collide_point(event.pos):
            reset_animation(main_board, all_moves)
            all_moves = []
          elif NEW_RECT.collide_point(event.pos):
            main_board, solution_sequence = generate_new_puzzle(80)
            all_moves = []
          elif SOLVE_RECT.collide_point(event.pos):
            reset_animation(main_board, solution_sequence + all_moves)
          else:
            blank_x, blank_y = get_blank_position(main_board)
            if spot_x == blank_x + 1 and spot_y == blank_y:
              slide_to = LEFT
            elif spot_x == blank_x - 1 and spot_y == blank_y:
              slide_to = RIGHT
            elif spot_x == blank_x and spot_y == blank_y + 1:
              slide_to = UP
            elif spot_x == blank_x and spot_y == blank_y - 1:
              slide_to = DOWN

      elif event.type == KEYUP:
        if event.key in (K_LEFT, K_a) and is_valid_move(main_board, LEFT):
          slide_to = LEFT
        if event.key in (K_RIGHT, K_d) and is_valid_move(main_board, RIGHT):
          slide_to = RIGHT
        if event.key in (K_UP, K_w) and is_valid_move(main_board, UP):
          slide_to = UP
        if event.key in (K_DOWN, K_s) and is_valid_move(main_board, DOWN):
          slide_to = DOWN
    if slide_to:
      slide_animation(main_board, slide_to, \
        'Click tile or press arrow kets to slide.', 8)
      make_move(main_board, slide_to)
      all_moves.append(slide_to)
    pygame.display.update()
    FPS_CLOCK.tick(FPS)


def terminate():
  pygame.quit()
  sys.exit()


def check_for_quit():
  for event in pygame.event.get(QUIT):
    terminate()
  for event in pygame.event.get(KEYUP):
    if event.key == K_ESCAPE:
      terminate()
    pygame.event.post(event)


def get_starting_board():
  counter = 1
  board = []
  for x in range(BOARD_WIDTH):
    column = []
    for y in range(BOARD_HEIGHT):
      column.append(counter)
      counter += BOARD_WIDTH
    board.append(column)
    counter -= BOARD_WIDTH * (BOARD_HEIGHT - 1) + BOARD_WIDTH - 1

    board[BOARD_WIDTH - 1][BOARD_HEIGHT - 1] = None
    return board


def get_blank_position(board):
  for x in range(BOARD_WIDTH):
    for y in range(BOARD_HEIGHT):
      if board[x][y] == None:
        return (x, y)


def make_move(board, move):
  blank_x, blank_y = get_blank_position(board)

  if move == UP:
    board[blank_x][blank_y], blard[blank_x][blank_y + 1] \
      = board[blank_x][blank_y + 1], board[blank_x][blank_y]
  elif move == DOWN:
    board[blank_x][blank_y], board[blank_x][blank_y -1] \
      = board[blank_x][blank_y -1], board[blank_x][blank_y]
  elif move == LEFT:
    board[blank_x][blank_y], board[blank_x + 1][blank_y] \
      = board[blank_x + 1][blank_y], board[blank_x][blank_y]
  elif move == RIGHT:
    board[blank_x][blank_y], board[blank_x - 1][blank_y] \
      = board[blank_x - 1][blank_y], board[blank_x][blank_y]


def is_valid_move(board, move):
  blank_x, blank_y = get_blank_position(board)
  return (move == UP and blank_y != len(board[0]) - 1) or \
         (move == DOWN and blank_y != 0) or \
         (move == LEFT and blank_x != len(board) - 1) or \
         (move == RIGHT and blank_x != 0)


def get_random_move(board, last_move = None):
  valid_moves = [UP, DOWN, LEFT, RIGHT]

  if last_move == UP or not is_valid_move(board, DOWN):
    valid_moves.remove(DOWN)
  if last_move == DOWN or not is_valid_move(board, UP):
    valid_moves.remove(UP)
  if last_move == LEFT or not is_valid_move(board, RIGHT):
    valid_moves.remove(RIGHT)
  if last_move == RIGHT or not is_valid_move(board, LEFT):
    valid_moves.remove(LEFT)

  return random.choice(valid_moves)


def get_left_top_of_tile(tile_x, tile_y):
  left = X_MARGIN + (tile_x * TILE_SIZE) + (tile_x - 1)
  top = Y_MARGIN + (tile_y * TILE_SIZE) + (tile_y - 1)
  return (left, top)


def get_spot_clicked(board, x, y):
  for tile_x in range(len(board)):
    for tile_y in range(len(board[0])):
      left, top = get_left_top_of_tile(tile_x, tile_y)
      tile_rect = pygame.Rect(left, top, TILE_SIZE, TILE_SIZE)
      if tile_rect.collide_point(x, y):
        return (tile_x, tile_y)
  return (None, None)


def draw_tile(tile_x, tile_y, number, adjx = 0, adjy = 0):
  left, top = get_left_top_of_tile(tile_x, tile_y)
  pygame.draw.rect(SURFACE, TILE_COLOR, (left + adjx, top + adjy, \
    TILE_SIZE, TILE_SIZE))
  text_surface = FONT.render(str(number), True, TEXT_COLOR)
  text_rect = text_surface.get_rect()
  text_rect.center = left + int(TILE_SIZE / 2) + adjx, top + \
    int(TILE_SIZE / 2) + adjy
  SURFACE.BLIT(text_surface, text_rect)


























































