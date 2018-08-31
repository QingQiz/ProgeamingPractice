import sys
import datetime

import pygame
import pygame.sprite

import bullet as bl
from alien import Alien
from setting import Setting
from ship import Ship


def check_events(ship, aliens, bullets, play_button, stats):
    """response keboard or mouse event"""
    for event in pygame.event.get():
        # response quit
        if event.type == pygame.QUIT:
            sys.exit()
        elif event.type == pygame.MOUSEBUTTONDOWN:
            mouse_x, mouse_y = pygame.mouse.get_pos()
            if play_button.rect.collidepoint(mouse_x, mouse_y):
                stats.active = True
                aliens.add(Alien(Setting(), ship.screen))
                ship = Ship(ship.screen)
                return

        # response move
        elif event.type == pygame.KEYDOWN:
            check_key_action(event, ship, 'key_down')
        elif event.type == pygame.KEYUP:
            check_key_action(event, ship, 'key_up')

    update_status(ship, aliens, bullets)


def make_bullet(ship, aliens, bullets):
    """add bullet"""
    now = datetime.datetime.now()
    # me
    if (now - ship.last_shoot_time).microseconds\
            >= 1.0 / ship.shoot_speed * 1000000:
        if ship.shoot is True:
            bullets.add(find_bullet(ship))
            ship.last_shoot_time = now
    # oth
    for alien in aliens:
        if (now - alien.last_shoot_time).microseconds\
                >= 1.0 / alien.shoot_speed * 1000000:
            bullets.add(find_bullet(alien))
            alien.last_shoot_time = now


def find_bullet(obj):
    bullet_type = {'basic': '1'}
    bt = obj.bullet_type
    name = obj.name
    if bullet_type[bt] == '1':
        if 'sh' in name:
            return bl.Bullet(obj)
        else:
            return bl.Enemy_Bullet(obj)


def check_key_action(event, ship, status):
    """response keboard"""
    up_down = {'key_down': True, 'key_up': False}
    if event.key == pygame.K_RIGHT:
        ship.moving['r'] = up_down[status]
    if event.key == pygame.K_LEFT:
        ship.moving['l'] = up_down[status]
    if event.key == pygame.K_UP:
        ship.moving['u'] = up_down[status]
    if event.key == pygame.K_DOWN:
        ship.moving['d'] = up_down[status]
    if event.key == pygame.K_SPACE:
        ship.shoot = up_down[status]
    if event.key == pygame.K_q:
        sys.exit()


def update_status(ship, aliens, bullets):
    """update attributes"""
    # update the group of bullets
    make_bullet(ship, aliens, bullets)
    # update the position of ship
    ship.update()
    # update the position of enemy
    aliens.update(ship)
    # bullet hitted
    for bullet in bullets:
        bullet.update(ship, aliens)
    # delete the effected bullet or who out of bounds
    for bullet in bullets.copy():
        if bullet.act_flg is True:
            bullets.remove(bullet)
    # collided
    for alien in aliens:
        if pygame.sprite.collide_rect(alien, ship):
            alien.health -= 1
            ship.health -= 1


def game_over(ship, aliens, stats):
    """update game status(game over)"""
    if len(aliens) == 0:
        print('win')
        stats.active = False
    elif ship.health <= 0:
        stats.ships_left -= 1
        ship.health = 350

    if stats.ships_left < 0:
        print('lost')
        stats.active = False


def add_leveup_alien(ai_set, screen, ship, aliens):
    """update aliens"""
    mint = 10000
    now = datetime.datetime.now()
    for alien in aliens.copy():
        if alien.health <= 0:
            aliens.remove(alien)
            ship.shoot_speed += 1
            continue
        if mint > (now - alien.birth).seconds:
            mint = (now - alien.birth).seconds
        if (now - alien.levelup).seconds > 10:
            # enemy levelup
            alien.shoot_speed += 1
            alien.levelup = now

    if mint >= 10:
        # add one enemy every 10''
        if aliens:
            aliens.add(Alien(ai_set, screen))


def update_screen(ai_set, screen, ship, aliens, bullets, stats, play_button):
    """update screen status"""
    # fill background color
    screen.fill(ai_set.color)
    # draw ship
    ship.blitme()
    # draw enemy
    for alien in aliens:
        alien.blitme()
    # draw bullet
    for bullet in bullets:
        bullet.draw_bullet()
    # game over
    game_over(ship, aliens, stats)
    # add new enemy
    add_leveup_alien(ai_set, screen, ship, aliens)
    # recent drawn visible
    pygame.display.flip()
