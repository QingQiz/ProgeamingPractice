## VPS 科学上网简述

### 安全配置

参考 [Linux VPS 安全配置](https://www.cnblogs.com/darknebula/p/7250235.html)

### 部署 ssr

\# `pip install shadowsocks`

\# `mkdir /root/shadowsocks`

\# `vim ss.json`

```json
{  
    "server":"xx.xx.xx.xx",  
    "local_address":"127.0.0.1",  
    "local_port":1080,  
    "port_password":{
	    "xxxx":"xxxxxxxx",
	    "xxxx":"xxxxxxxx"
    },
    "timeout":300,
    "method":"aes-256-cfb",  
    "fast-open":false  
} 
```

\# `iptables -I INPUT -m state --state NEW -m tcp -p tcp --dport <port> -j ACCEPT`

\# `iptables -I INPUT -m state --state NEW -m udp -p udp --dport <port> -j ACCEPT`

\# `iptables-save`

\# `ssserver -c /root/shadowsocks/ss.json -d start`

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

### 部署锐速

#### 更改内核版本

\# `rpm -ivh http://soft.91yun.org/ISO/Linux/CentOS/kernel/kernel-3.10.0-229.1.2.el7.x86_64.rpm --force`

#### 下载锐速

\# `wget -N --no-check-certificate https://raw.githubusercontent.com/91yun/serverspeeder/master/serverspeeder-all.sh && bash serverspeeder-all.sh`

\# ssserver -c /root/shadowsocks/ss.json -d restart
