import pygame
from pygame.sprite import Sprite


class Bullet(Sprite):

    def __init__(self, ship):
        """create a bullet at right position"""
        super().__init__()

        # basic parameter
        self.fly_speed = 1
        self.width = 3
        self.high = 15
        self.color = 250, 0, 0
        self.atta = 1
        self.belones = 1
        # flag
        self.act_flg = False
        # Auxiliary parameter
        self.screen = ship.screen
        self.screen_rect = ship.screen_rect

        # position parameter
        # create a rectangle and move it to right position
        self.rect = pygame.Rect(0, 0, self.width, self.high)
        self.rect.centerx = ship.rect.centerx
        self.rect.top = ship.rect.top
        # using float
        self.y = float(self.rect.y)

    def update(self, ship, aliens):
        """move bullet"""
        self.y -= self.fly_speed
        self.rect.y = self.y
        # out of bounds?
        if self.y < 0:
            self.act_flg = True
            return

        for alien in aliens:
            # detect collision
            if pygame.sprite.collide_rect(self, alien) and\
                    self.belones == 1:
                alien.health -= 1
                self.act_flg = True

    def draw_bullet(self):
        """draw bullet"""
        pygame.draw.rect(self.screen, self.color, self.rect)


class Enemy_Bullet(Bullet):
    """enemy's bullet"""
    def __init__(self, alien):
        super().__init__(alien)

        # changes
        # basic parameter
        self.color = 0, 250, 0
        self.belones = 2
        self.fly_speed = 0.5
        # Auxiliary parameter
        self.rect.top = alien.rect.bottom

    def update(self, ship, alien):
        """move bullet"""
        self.y += self.fly_speed
        self.rect.y = self.y
        # out of bounds?
        if self.y > self.screen_rect.height:
            self.act_flg = True
            return

        # detect collision
        if pygame.sprite.collide_rect(self, ship) and\
                self.belones != 1:
            ship.health -= 1
            self.act_flg = True
