import datetime
import random

import pygame
from pygame.sprite import Sprite


class Alien(Sprite):
    """class of enemy"""

    def __init__(self, ai_set, screen):
        """initialize"""
        super().__init__()
        self.screen = screen
        self.screen_rect = screen.get_rect()
        self.ai_set = ai_set

        # load image, set attributes
        self.image = pygame.image.load('image/alien.bmp')
        self.rect = self.image.get_rect()

        # initialize position info
        self.rect.x = self.rect.width
        self.rect.y = self.rect.height

        # using float
        self.x = float(self.rect.x)
        self.y = float(self.rect.y)

        # basic parameter
        self.health = 50
        self.atta = 1
        self.bullet_type = 1
        self.worth = 10
        self.prop_fall = 'S'
        self.birth = datetime.datetime.now()
        self.levelup = datetime.datetime.now()

        # shoot parameter
        self.shoot = True
        self.bullet_type = 'basic'
        self.shoot_speed = 5
        self.last_shoot_time = datetime.datetime.now()
        # name
        self.name = 'alien'

    def update(self, ship):
        # random move
        if ship.x > self.x:
            temx = random.uniform(-10, 15)
        else:
            temx = random.uniform(-15, 10)

        if ship.y < self.y:
            temy = random.uniform(-5, 3)
        else:
            temy = random.uniform(
                random.uniform(-10, 0), random.uniform(0, 10))

        if self.x + temx > 0 and self.x + temx <\
                self.screen_rect.width - 10:
            self.x += temx
        if self.y + temy > 0 and self.y + temy <\
                self.screen_rect.height / 1.33:
            self.y += temy

        self.rect.x = self.x
        self.rect.y = self.y

    def blitme(self):
        """DRAW"""
        self.screen.blit(self.image, self.rect)
