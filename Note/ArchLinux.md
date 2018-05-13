## Config in ArchLinux 

### 电源管理

``/etc/systemd/logind.conf``

### host

/etc/hosts

### 源

``/etc/pacman.d/mirrirlist``

### grub

``/etc/default/grub``

### shadowsocks

``/etc/shadowsocks/``

### Chinese

解决qt界面无法输入中文

> $ ``qtconfig-qt4``
> > Interface -> Default Input Method -> iBus
在 zshrc, xinitrc 添加
```shell
export GTK_IM_MODULE=ibus
export XMODIFIERS=@im=ibus
export QT_IM_MODULE=ibus
```
修改i3config 添加(修改) ``exec --no-startup-id ibus-daemon --xim -d``

### Sound

\#  ``pacman -S alsamixer``

华硕笔记本电脑的声音问题

> $ ``vim $HOME/.asoundrc``
```shell
defaults.ctl.card 1
defaults.pcm.card 1
defaults.timer.card 1
```
