#!/bin/bash

now=$(date +"%m_%d_%Y")



# Check if is root
if [ "$(whoami)" != "root" ]; then
  echo "Script must be run as user: root"
  exit -1
fi

apt install unzip

echo && echo "going to root directory"
cd ~/

echo && echo "Stopping daemon..."
omotenashicoin-cli stop

echo && echo "downloading update"
wget https://github.com/omotenashicoin-project/OmotenashiCoin/releases/download/v1.2.0/omotenashicoin-linux-ubuntu1604-v1.2.0.zip -O omotenashicoin-v1.2.0.zip

mkdir omotenashicoinbackup
cd omotenashicoinbackup
mkdir $now

backuppath=~/omotenashicoinbackup/$now

echo && echo "backing up wallet.dat masternode.conf omotenashicoin.conf to ${backuppath}"
cd ../.omotenashicoin
cp wallet.dat $backuppath
cp masternode.conf $backuppath
cp omotenashicoin.conf $backuppath

cd ~/

echo && echo "unzipping daemons"
unzip omotenashicoin-v1.1.0.zip -d ~/omotenashicoin-release
cd omotenashicoin-release
chmod +x omotenashicoind
chmod +x omotenashicoin-cli
chmod +x omotenashicoin-tx
chmod +x omotenashicoin-qt

echo && echo "moving to /usr/bin"
sudo mv omotenashicoin-cli /usr/local/bin/omotenashicoin-cli
sudo mv omotenashicoin-tx /usr/local/bin/omotenashicoin-tx
sudo mv omotenashicoind /usr/local/bin/omotenashicoind

echo && echo "cleaning up"
cd ~/
rm omotenashicoin-release -rf
rm omotenashicoin-v1.2.0.zip

echo && echo "starting daemon"
omotenashicoind
