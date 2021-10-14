# Mini-ndn requirement and steps

## Dependency tree
```
mini-ndn
├── mininet
├── NLSR
│   ├── NFD
│   │   ├── sudo apt install libpcap-dev libsystemd-dev
│   │   └── ndn-cxx
│   │       ├── sudo apt install build-essential pkg-config python3-minimal libboost-all-dev libssl-dev libsqlite3-dev
│   │       ├── sudo apt install doxygen graphviz python3-pip
│   │       └── pip3 install --user sphinx sphinxcontrib-doxylink
│   └── PSync
│       ├── ChronoSync
│       │   └── ndn-cxx*
│       └── ndn-cxx*
└── ndn-tools
    ├── ndn-cxx*
    └── sudo apt install libpcap-dev*
    
*: Repetisi
```

## Req
```
sudo apt install libpcap-dev libsystemd-dev build-essential pkg-config python3-minimal libboost-all-dev libssl-dev libsqlite3-dev doxygen graphviz python3-pip python -y
pip3 install --user sphinx sphinxcontrib-doxylink
```
