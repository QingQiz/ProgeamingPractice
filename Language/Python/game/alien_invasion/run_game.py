#!/bin/python3

import pygame
from pygame.sprite import Group

from setting import Setting
from button import Button
from ship import Ship
from game_stats import GameStats
import game_function as gf


def run_game():
    # initialize screen object
    pygame.init()
    # ai info
    ai_set = Setting()
    screen = pygame.display.set_mode(
        (ai_set.width, ai_set.high))
    # tittle
    pygame.display.set_caption("xieyb")
    # create a ship
    ship = Ship(screen)
    # create an example for statistics
    stats = GameStats(ai_set)
    # create an enemy
    aliens = Group()
    # all bullets
    bullets = Group()
    # create Play button
    play_button = Button(ai_set, screen, "Play")
    # start the game main loop
    while True:
        gf.check_events(ship, aliens, bullets, play_button, stats)
        if stats.active:
            pygame.mouse.set_visible(False)
            gf.update_screen(
                ai_set, screen, ship, aliens, bullets, stats, play_button)
        else:
            pygame.mouse.set_visible(True)
            screen.fill((255, 0, 0), screen.get_rect())
            # if not active, draw button
            if not stats.active:
                play_button.draw_button()
            pygame.display.flip()


run_game()
