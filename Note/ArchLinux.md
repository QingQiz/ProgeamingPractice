# Config in ArchLinux 

## 电源管理

`/etc/systemd/logind.conf`

## Language

### 解决qt界面无法输入中文

$ `qtconfig-qt4`

> Interface -> Default Input Method -> iBus

~~在 zshrc, xinitrc 添加~~

```shell
export GTK_IM_MODULE=ibus
export XMODIFIERS=@im=ibus
export QT_IM_MODULE=ibus
```

修改i3config 添加(修改) `exec --no-startup-id ibus-daemon --xim -d`

## Sound

\#  `pacman -S alsamixer`

### 华硕笔记本电脑的声音问题

$ `vim $HOME/.asoundrc`

```shell
defaults.ctl.card 1
defaults.pcm.card 1
defaults.timer.card 1
```

## VIM

### YouComplete

\# `ln -s /usr/lib/libtinfo.so.6 /usr/lib/libtinfo.so.5`

## Package Manager

### AUR

\# `vi /etc/pacman.d`

```conf
[archlinuxcn]
SigLevel = Optional TrustAll
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
```


### yaourt

\# `pacman -S yaourt`

proxy

\# `pacman -S privoxy`

\# `vi /etc/privoxy/config`

`rward-socks5 / 127.0.0.1:1080 .`

\# `systemctl start privoxy.service`

$ `export https_proxy=127.0.0.1:8118; export http_proxy=127.0.0.1:8118`

## i3-gap

参考[eoli3n 的dotfiles](https://github.com/eoli3n/dotfiles)

## Application

### Mathematica

打开mathematica时出错

> `/opt/Mathematica/SystemFiles/FrontEnd/Binaries/Linux-x86-64/Mathematica: symbol lookup error: /usr/lib/libfontconfig.so.1: undefined symbol: FT_Done_MM_Var`
Solution: [Mathematica and freetype-2.9 undefined symbol](https://forums.gentoo.org/viewtopic-p-8198000.html?sid=ab27c1ca8e1927691858595185e18284)
> I discovered the source of the problem. Mathematica includes its own freetype.so.6 library in the directory ${TopDirectory}/SystemFiles/Libraries/Linux-x86-64. This freetype library will call the system fontconfig which will give the error.
> To fix this, just remove or rename the mathematica freetype.so.6 library. This will force Mathematica to use the system freetype library.
> This solution will allow one to keep the latest freetype-2.9 and no downgrade will be necessary.
> If Mathematica gives other errors on startup, like with libz.so, check if that library is installed in ${TopDirectory}/SystemFiles/Libraries/Linux-x86-64 and if so then remove or rename it.
> I hope this helps.

mathematica 自动在`$HOME`创建`Wolfram Mathematica`

\# `pacman -S xdg-user-dirs`

$ `xdg-user-dirs-update`

## touchpad

\# `pacman -S xf86-input-synaptics`

自然滚动 `synclient VertScrollDelta=-66`

环形滚动 `synclient CircularScrolling=1`

指针速度

```shell
synclient MaxSpeed=xxx
synclient MinSpeed=xxx
```

单击, 双击, 中键

```shell
synclient TapButton1=1
synclient TapButton2=3
synclient TapButton3=2
```

## Network

### wifi-menu "No network found"

\# `ip link set wlo1 up`

if

> RTNETLINK answers: Operation not possible due to RF-kill

then \# `rfkill unblock wifi`


### shadowsocks

`vim /etc/shadowsocks/`

```json
{
    "server":"my_server_ip",
    "server_port":8388,
    "local_address": "127.0.0.1",
    "local_port":1080,
    "password":"mypassword",
    "timeout":300,
    "method":"aes-256-cfb",
    "fast_open": false,
    "workers": 1,
    "prefer_ipv6": false
}
```


## Bluetooth

install `bliez` and `bluez-utils`, load `btusb` and start the `bluetooth.service`

```shell
pacman -S bluez
pacman -S bluez-utils
modprobe btusb
systemctl start bluetooth.service
```

use `bluetoothctl` to config it.

this is an example below

> [NEW] Controller 00:10:20:30:40:50 pi [default]
> [bluetooth]# agent KeyboardOnly 
> Agent registered
> [bluetooth]# default-agent 
> Default agent request successful
> [bluetooth]# scan on
> Discovery started
> [CHG] Controller 00:10:20:30:40:50 Discovering: yes
> [NEW] Device 00:12:34:56:78:90 myLino
> [CHG] Device 00:12:34:56:78:90 LegacyPairing: yes
> [bluetooth]# pair 00:12:34:56:78:90
> Attempting to pair with 00:12:34:56:78:90
> [CHG] Device 00:12:34:56:78:90 Connected: yes
> [CHG] Device 00:12:34:56:78:90 Connected: no
> [CHG] Device 00:12:34:56:78:90 Connected: yes
> Request PIN code
> [agent] Enter PIN code: 1234
> [CHG] Device 00:12:34:56:78:90 Paired: yes
> Pairing successful
> [CHG] Device 00:12:34:56:78:90 Connected: no
> [bluetooth]# connect 00:12:34:56:78:90
> Attempting to connect to 00:12:34:56:78:90
> [CHG] Device 00:12:34:56:78:90 Connected: yes
> Connection successful

## some useful applications

[k3b](https://userbase.kde.org/K3b)
> K3b is a simple, yet powerful and highly-configurable graphical optical disk burning application for audio, video, data projects and more!
