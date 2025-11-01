
apt install ufw
ufw default deny incoming
ufw default deny outgoing
ufw allow 4242
ufw enable

#sshd_config

adduser sandrzej
usermod -aG sudo sandrzej
groupadd user42
usermod -aG user42 sandrzej

apt install sudo
#visudo

#login.defs

apt install libpam-pwquality
#pwquality.conf
