## Config in ArchLinux 

### 电源管理

`/etc/systemd/logind.conf`

### shadowsocks

`/etc/shadowsocks/`

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

### Chinese

#### 解决qt界面无法输入中文

$ `qtconfig-qt4`

> Interface -> Default Input Method -> iBus

~~在 zshrc, xinitrc 添加~~

```shell
export GTK_IM_MODULE=ibus
export XMODIFIERS=@im=ibus
export QT_IM_MODULE=ibus
```

修改i3config 添加(修改) `exec --no-startup-id ibus-daemon --xim -d`

### Sound

\#  `pacman -S alsamixer`

#### 华硕笔记本电脑的声音问题

$ `vim $HOME/.asoundrc`

```shell
defaults.ctl.card 1
defaults.pcm.card 1
defaults.timer.card 1
```

### YouComplete

\# `ln -s /usr/lib/libtinfo.so.6 /usr/lib/libtinfo.so.5`

### AUR

\# `vi /etc/pacman.d`

```conf
[archlinuxcn]
SigLevel = Optional TrustAll
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
```

\# `pacman -S yaourt`

#### yaourt 使用代理

\# `pacman -S privoxy`

\# `vi /etc/privoxy/config`

`rward-socks5 / 127.0.0.1:1080 .`

\# `pacman systemctl start privoxy.service`

$ `export https_proxy=127.0.0.1:8118; export http_proxy=127.0.0.1:8118`

### i3-gap

参考[eoli3n 的dotfiles](https://github.com/eoli3n/dotfiles)

