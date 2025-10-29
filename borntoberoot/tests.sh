lsblk
systemctl status ssh
cat /etc/ssh/sshd_config
ufw status verbose
visudo
cat /etc/hostname
cat /etc/passwd
id sandrzej
cat /etc/group

chage -l root
chage -l sandrzej
cat /etc/login.defs
cat /etc/security/pwquality.conf

crontab -e

#head -n 2 /etc/os-release
#/urs/sbin/aa-status
#ss -tunlp

systemctl status cockpit
systemctl status ssh
systemctl status php8.4-fpm
systemctl status mariadb
systemctl status lighttpd
