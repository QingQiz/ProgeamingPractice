import pygame
import datetime


class Ship():

    def __init__(self, screen):
        """initialize"""

        # Auxiliary parameter
        self.screen = screen
        # load ship image and get the rectangle of it
        self.image = pygame.image.load('image/ship.bmp')
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()
        # position parameter
        # palce the ship at the mid of screen
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom
        # use float to represent the position
        self.x = float(self.rect.centerx)
        self.y = float(self.rect.centery)
        # basic attributes
        self.ship_speed = 0.7
        self.health = 350
        # bullet attributes
        self.bullet_type = 'basic'
        self.bullet_numb = 1
        self.shoot = False
        self.shoot_speed = 5
        self.last_shoot_time = datetime.datetime.now()
        # flag parameter
        self.name = 'ship'
        # moving flg
        self.moving = {'l': False, 'r': False, 'u': False, 'd': False}

    def update(self):
        """update position coordinate"""
        if self.moving['l'] and self.rect.left > 0:
            self.x -= self.ship_speed
        if self.moving['r'] and self.rect.right < self.screen_rect.right:
            self.x += self.ship_speed
        if self.moving['u'] and self.rect.top > 0:
            self.y -= self.ship_speed
        if self.moving['d'] and self.rect.bottom < self.screen_rect.bottom:
            self.y += self.ship_speed

        self.rect.centerx = self.x
        self.rect.centery = self.y

    def blitme(self):
        """draw ship"""
        self.screen.blit(self.image, self.rect)
