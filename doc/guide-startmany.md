#start-many Setup Guide

## Two Options for Setting up your Wallet
There are many ways to setup a wallet to support start-many. This guide will walk through two of them.

1. [Importing an existing wallet (recommended if you are consolidating wallets).](#option1)
2. [Sending 10000 MTNS to new wallet addresses.](#option2)

## <a name="option1"></a>Option 1. Importing an existing wallet

This is the way to go if you are consolidating multiple wallets into one that supports start-many.

### From your single-instance MasterNode Wallet

Open your QT Wallet and go to console (from the menu select Tools => Debug Console)

Dump the private key from your MasterNode's pulic key.

```
walletpassphrase [your_wallet_passphrase] 600
dumpprivkey [mn_public_key]
```

Copy the resulting priviate key. You'll use it in the next step.

### From your multi-instance MasterNode Wallet

Open your QT Wallet and go to console (from the menu select Tools => Debug Console)

Import the private key from the step above.

```
walletpassphrase [your_wallet_passphrase] 600
importprivkey [single_instance_private_key]
```

The wallet will re-scan and you will see your available balance increase by the amount that was in the imported wallet.

[Skip Option 2. and go to Create masternode.conf file](#masternodeconf)

## <a name="option2"></a>Option 2. Starting with a new wallet

[If you used Option 1 above, then you can skip down to Create masternode.conf file.](#masternodeconf)

### Create New Wallet Addresses

1. Open the QT Wallet.
2. Click the Receive tab.
3. Fill in the form to request a payment.
    * Label: mn01
    * Amount: 10000 (optional)
    * Click *Request payment*
5. Click the *Copy Address* button

Create a new wallet address for each MasterNode.

Close your QT Wallet.

### Send 10000 MTNS to New Addresses

Just like setting up a standard MN. Send exactly 10 000 MTNS to each new address created above.

### Create New Masternode Private Keys

Open your QT Wallet and go to console (from the menu select Tools => Debug Console)

Issue the following:

```masternode genkey```

*Note: A masternode private key will need to be created for each MasterNode you run. You should not use the same masternode private key for multiple MasterNodes.*

Close your QT Wallet.

## <a name="masternodeconf"></a>Create masternode.conf file

Remember... this is local. Make sure your QT is not running.

Create the masternode.conf file in the same directory as your wallet.dat.

Copy the masternode private key and correspondig collateral output transaction that holds the 10 000 MTNS.

The masternode private key may be an existing key from [Option 1](#option1), or a newly generated key from [Option 2](#option2).

*Please note, the masternode priviate key is not the same as a wallet private key. Never put your wallet private key in the masternode.conf file. That is equivalent to putting your 10 000 MTNS on the remote server and defeats the purpose of a hot/cold setup.*

### Get the collateral output

Open your QT Wallet and go to console (from the menu select Tools => Debug Console)

Issue the following:

```masternode outputs```

Make note of the hash (which is your collaterla_output) and index.

### Enter your MasterNode details into your masternode.conf file
[From the omotenashicoin github repo](https://github.com/omotenashicoin-project/OmotenashiCoin/blob/master/doc/masternode_conf.md)

The new masternode.conf format consists of a space seperated text file. Each line consisting of an alias, IP address followed by port, masternode private key, collateral output transaction id and collateral output index, donation address and donation percentage (the latter two are optional and should be in format "address:percentage").

```
alias ipaddress:port masternode_private_key collateral_output collateral_output_index donationin_address:donation_percentage
```



Example:

```
mn01 <your_global_ipaddress>:12181 7FPr2d9T36uJ7VQX9LKv1KLAkd8RNxtUFzPwK7eiSAXx7QsyFGn bd8286ee3d18b1386812d06e111ebf196723088a272f05b6cf8a8589135c0e97 0
```

## What about the omotenashicoin.conf file?

If you are using a masternode.conf file you no longer need the omotenashicoin.conf file. The exception is if you need custom settings (thanks oblox).

## Update omotenashicoin.conf on server

If you generated a new masternode private key, you will need to update the remote omotenashicoin.conf files.

Shut down the daemon and then edit the file.

Example for Linux:

```sudo nano ~/.omotenashicoin/omotenashicoin.conf```

### Edit the masternodeprivkey
If you generated a new masternode private key, you will need to update the masternodeprivkey value in your remote omotenashicoin.conf file.

## Start your MasterNodes

### Remote

If your remote server is not running, start your remote daemon as you normally would.

I usually confirm that remote is on the correct block by issuing:

```omotenashicoind getinfo```


Starting masternode process.

```startmasternode local false```


### Local

Finally... time to start from local.

OR

```startmasternode alias false mn01```

#### Open up your QT Wallet

From the menu select Tools => Debug Console

If you want to review your masternode.conf setting before starting the MasterNodes.
