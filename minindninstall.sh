sudo su -
apt update
apt get install git python-pip -y
apt add-apt-repository ppa:named-data/ppa
apt update
apt install nfd nlsr ndn-tools ndn-traffic-generator ndnmap-data-collector -y
cd ~
git clone https://github.com/named-data/mini-ndn.git
cd mini-ndn
./install.sh -qa
pip install -u upgrade
cd mininet-wifi
util/install.sh -Wlnfv