#!/bin/bash
#[ "$(whoami)" != "root" ] && exec sudo -- "$0" "$@"
echo "Run as $(whoami)"
echo;

echo "====apt update====";
sudo apt update;
echo;

echo "====install git, pyton, pip===="
sudo apt install git -y;
sudo apt install python -y
sudo apt install python-pip -y;
echo;

echo "====add ppa====";
sudo add-apt-repository ppa:named-data/ppa -y;
sudo apt update;
echo;

echo "====install dependencies====";
sudo apt install nfd nlsr ndn-tools ndn-traffic-generator ndnmap-data-collector ndn-cxx libndn-cxx -y;
sudo apt install libpcap-dev libsystemd-dev build-essential pkg-config python3-minimal libboost-all-dev libssl-dev libsqlite3-dev doxygen graphviz python3-pip -y;
pip3 install --user sphinx sphinxcontrib-doxylink;
git clone https://github.com/named-data/PSync.git;
cd PSync;
./waf configure;
./waf;
sudo ./waf install;
cd ..;
echo;

echo "====cloning mininet====";
git clone --depth 1 https://github.com/mininet/mininet.git;
echo;

echo "====installing mininet====";
cd mininet;
./util/install.sh -nv;
sudo mn --test pingall;		
cd ..;
echo;

echo "====cloning minindn to ~/mini-ndn====";
echo "Current directory: $(pwd)";
echo "Current user: $(whoami)";
git clone https://github.com/named-data/mini-ndn.git;
cd mini-ndn;
echo;

echo "====installing mini-ndn====";
./install.sh -qa;
pip install -u upgrade;
#echo;

#echo "====reinstalling mininet-wifi====";
#cd mininet-wifi;
#util/install.sh -Wlnf;
