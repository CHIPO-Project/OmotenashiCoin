#/bin/bash

# Check if is root
if [ "$(whoami)" != "root" ]; then
  echo "Script must be run as user: root"
  exit -1
fi

echo && echo "Stopping omotenashicoin"
omotenashicoin-cli stop

echo && echo "moving omotenashicoin executables to another directory"
mv /usr/bin/omotenashicoind /usr/local/bin/omotenashicoind
mv /usr/bin/omotenashicoin-tx /usr/local/bin/omotenashicoin-tx
mv /usr/bin/omotenashicoin-cli /usr/local/bin/omotenashicoin-cli

echo && echo "starting omotenashicoind"
omotenashicoind