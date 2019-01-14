## VPS 科学上网简述

### 安全配置

参考 [Linux VPS 安全配置](https://www.cnblogs.com/darknebula/p/7250235.html)

### 部署 ssr

\# `pip install shadowsocks`

\# `vim /path/to/ss.json`

```json
{  
    "server":"your server name",  
    "local_address":"127.0.0.1",  
    "local_port":1080,  
    "port_password":{
	    "port":"password",
	    "xxxx":"xxxxxxxx"
    },
    "timeout":300,
    "method":"aes-256-cfb",  
    "fast-open":false  
} 
```

\# `vim /etc/systemd/system/ssserver.service`

```systemd
[Unit]
Description = Start ssserver

[Service]
Type=simple
ExecStart=/usr/bin/ssserver -c /path/to/ss.json
ExecStartPost=/sbin/iptables -I INPUT -m state --state NEW -m tcp -p tcp --dport 3389 -j ACCEPT
ExecStartPost=/sbin/iptables -I INPUT -m state --state NEW -m udp -p udp --dport 3389 -j ACCEPT
ExecStartPost=/sbin/ip6tables -I INPUT -m state --state NEW -m tcp -p tcp --dport 3389 -j ACCEPT
ExecStartPost=/sbin/ip6tables -I INPUT -m state --state NEW -m udp -p udp --dport 3389 -j ACCEPT
ExecStartPost=/sbin/iptables-save
ExecStartPost=/sbin/ip6tables-save
Restart=always
RestartSce=2s

[Install]
WantedBy=multi-user.target
```

\# `systemctl start ssserver.service`

\# `systemctl enable ssserver.service`


客户端配置

```json
{
    "server":"xx.xx.xx.xx",
    "server_port":xxxx,
    "local_address": "127.0.0.1",
    "local_port":1080,
    "password":"xxxxxxxx",
    "timeout":300,
    "method":"aes-256-cfb",
    "fast_open": false,
    "workers": 1,
    "prefer_ipv6": false
}
```

### TCP FAST OPEN

\# `vi /etc/rc.local`

`echo 3 > /proc/sys/net/ipv4/tcp_fastopen`

\# `vi /etc/sysctl.conf`

`net.ipv4.tcp_fastopen = 3`

### 部署 Google BBR

\# `wget --no-check-certificate https://github.com/teddysun/across/raw/master/bbr.sh`

\# `chmod +x bbr.sh`

\# `./bbr.sh`

\# `reboot`

\# `sysctl net.ipv4.tcp_available_congestion_control`

> this command will return `net.ipv4.tcp_available_congestion_control = bbr cubic reno`
