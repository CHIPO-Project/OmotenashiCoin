Multi masternode config
=======================

The multi masternode config allows you to control multiple masternodes from a single wallet. The wallet needs to have a valid collateral output of 25000 coins for each masternode. To use this, place a file named masternode.conf in the data directory of your install:
 * Windows: %APPDATA%\OMOTENASHICOIN\
 * Mac OS: ~/Library/Application Support/OMOTENASHICOIN/
 * Unix/Linux: ~/.omotenashicoin/

The new masternode.conf format consists of a space seperated text file. Each line consisting of an alias, IP address followed by port, masternode private key, collateral output transaction id, collateral output index, donation address and donation percentage (the latter two are optional and should be in format "address:percentage").

Example: To connect testnet(mainnet port : 12181)
```
mn1 <GlobalIpaddr_1>:12281 72NRiBgNFusVkByXerttwxZAGMWuh1QNRgDCGDf5BKruwxVc3iY rf3w718684a35c9e43572e409a3edfd461cc9689529b85dcfe9f76325c0dbadb 0
mn2 <GlobalIpaddr_2>:12281 72Jz3U7ydCKPK99dba7xKJ2PHu4SWsbCYXAras8cKQB2aspJNmz 45tgbv18684a35c9e43572e409a3edfd461cc9689529b85dcfe9f76325c0dbadb 0 7gnwGHt17heGpG9Crfeh4KGpYNFugPhJdh:33
mn3 <GlobalIpaddr_3>:12281 71bRZsUftXkiEVHhPS3FPexm7XwBg9oSTLGctEmtRiA1bqB3bkJ VFRaBGTa8684a35c9e43572e409a3edfd461cc9689529b85dcfe9f76325c0dbadb 1 7gnwGHt17heGpG9Crfeh4KGpYNFugPhJdh
```

In the example above:
* the collateral for mn1 consists of transaction 9ad313bfefe0a7e76852727f93fee2abe1c6f8fac3993b0f9608c1905e2f9077, output index 0 has amount 10000


When using the multi masternode setup, it is advised to run the wallet with 'masternode=0' as it is not needed anymore.
