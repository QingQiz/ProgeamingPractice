#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import threading
import random
import datetime
from time import sleep


def log(dic):
    """
    :param dic: log dict(e.g. {name: value})
    """
    res = datetime.datetime.now().strftime('[\033[0;32;1m%y-%m-%d %H:%M:%S\033[0m]') + ' '
    for key in dic:
        flg = dic[key] is not None
        res += format(key, ' <20')
        res += format('\033[0;33;1m' + dic[key] + '\033[0m' if flg else '', ' <30')
    print(res)


def rand_real(a, b):
    """
    :param a: real
    :param b: real
    :return: random real between a and b
    """
    return (random.randint(0, 10000) / 10000) * (b - a) + a


def send(tsk):
    """
    to simulate send action
    :param tsk: task size
    """
    sleep(tsk)


def tsk_send(tsk_size, tsk_name, ident, conflict_num=0):
    """
    to deal with a single task
    :param tsk_size: task size
    :param tsk_name: task name
    :param ident: thread identity
    :param conflict_num: conflict times
    """
    global bus
    while bus != 0:
        sleep(0.01)

    if conflict_num != 0:
        log({'tsk resend:': tsk_name, 'resend times:': str(conflict_num)})

    sleep(0)

    bus += ident
    send(tsk_size)
    if bus == ident:
        log({'\033[0;34;1mSEND SUCCESS:\t': tsk_name})
        bus = 0
        sleep(rand_real(0, 1))
    else:
        t = 51.2 * 10 ** -6
        sleep_time = random.choice(range(0, 1 << (10 if conflict_num > 10 else conflict_num))) * 2 * t

        log({'conflict detected:': tsk_name, 'sleep time:': str(sleep_time)})
        bus = 0
        if conflict_num == 16:
            log({'\033[0;31;1mSEND FAILED:\t': tsk_name})
            return
        sleep(sleep_time)
        tsk_send(tsk_size, tsk_name, ident, conflict_num + 1)


def thread_main(thread_name, tsks):
    """
    :param thread_name: thread name
    :param tsks: task list to deal with
    """
    log({thread_name + ' started:': None})
    global bus
    ident = threading.currentThread().ident
    for tsk in tsks:
        tsk_send(tsk, tsks[tsk], ident)
    log({thread_name + ':': 'DONE'})
    log({thread_name + ':': 'EXIT'})


def sender_settings(sender_nr, task_nr):
    """
    :param sender_nr: number of senders
    :param task_nr: number of tasks
    :return: sender list (thread.Thread)
    """
    task_l = [{rand_real(0, 1): "Task_{}_{}".format(i + 1, j + 1) for j in range(task_nr)} for i in range(sender_nr)]
    return [threading.Thread(target=thread_main, args=['sender_' + str(i + 1), task_l[i]]) for i in range(sender_nr)]


def start_sender(sender_l):
    """
    start all senders in sender_l and join them
    :param sender_l: sender list
    """
    for i in sender_l:
        try:
            i.start()
        except AttributeError:
            pass
    for i in sender_l:
        try:
            i.join()
        except (AttributeError, RuntimeError):
            pass


if __name__ == '__main__':
    bus = 0

    senders = sender_settings(sender_nr=4, task_nr=5)
    start_sender(senders)

