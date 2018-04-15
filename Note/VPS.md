## VPS 科学上网简述

### 更改密码

> passwd

### 基本应用

> yum install vim
> yum install git
> yum install pytho*

### 修改服务器开放的端口

> vi /etc/ssh/sshd_config

> iptables -I INPUT -p tcp -m state --state NEW -m tcp --dport \<port\> -j ACCEPT

> iptables -I INPUT -p tcp -m state --state NEW -m tcp --dport \<port\> -j ACCEPT

> iptables-save

### 部署 ssr

> wget -N --no-check-certificate https://raw.githubusercontent.com/91yun/serverspeeder/master/serverspeeder-all.sh && bash serverspeeder-all.sh

> vi /etc/shadowsocks.json

```json
"server":"0.0.0.0",
"server_port":<port>,
"local_address":"127.0.0.1",
"local_port":1080,
"port_password":{
    "<port>":"<password>",
    "<port>":"<password>"
},
"timeout":300,
"method":"aes-256-cfb",
"fast_open":true
```

> iptables -I INPUT -m state --state NEW -m tcp -p tcp --dport \<port\> -j ACCEPT

> iptables -I INPUT -m state --state NEW -m tcp -p tcp --dport \<port\> -j ACCEPT

> iptables-save

> /etc/init.d/shadowsocks restart


### 更改内核版本

> rpm -ivh http://soft.91yun.org/ISO/Linux/CentOS/kernel/kernel-3.10.0-229.1.2.el7.x86_64.rpm --force

### 部署锐速

> wget -N --no-check-certificate https://raw.githubusercontent.com/91yun/serverspeeder/master/serverspeeder-all.sh && bash serverspeeder-all.sh

> systemctl restart sshd.service
