Masternode Budget API
=======================

Get paid
------------------------

When Phase `from 4 to 9` is reached you'll receive a payment for `90% – 0,1%(50MTNS - 0.1 MTNS)` Omotenashi Coins.


RPC Commands
------------------------

The following new RPC commands are supported:
#### mnbudget "command"... ( "passphrase" )

##### Vote or show current budgets
##### This command is depreciated, please see individual command documentation for future reference

- Available commands:
  * prepare            - Prepare proposal for network by signing and creating tx
  * submit             - Submit proposal for network
  * vote-many          - Vote on a OmotenashiCoin initiative
  * vote-alias         - Vote on a OmotenashiCoin initiative
  * vote               - Vote on a OmotenashiCoin initiative/budget
  * getvotes           - Show current masternode budgets
  * getinfo            - Show current masternode budgets
  * show               - Show all budgets
  * projection         - Show the projection of which proposals will be paid the next cycle
  * check              - Scan proposals and remove invalid
  * nextblock          - Get next superblock for budget system





#### mnbudgetvote "local|many|alias" "votehash" "yes|no" ( "alias" )
##### Vote on a budget proposal

- Arguments:
 * "mode"      (string, required) The voting mode. 'local' for voting directly from a masternode, 'many' for voting with a MN controller and casting the same vote for each MN, 'alias' for voting with a MN controller and casting a vote for a single MN
 * "votehash"  (string, required) The vote hash for the proposal
 * "votecast"  (string, required) Your vote. 'yes' to vote for the proposal, 'no' to vote against
 * "alias"     (string, required for 'alias' mode) The MN alias to cast a vote for.

* Result:
 ```
{
  "overall": "xxxx",      (string) The overall status message for the vote cast
  "detail": [
    {
      "node": "xxxx",      (string) 'local' or the MN alias
      "result": "xxxx",    (string) Either 'Success' or 'Failed'
      "error": "xxxx",     (string) Error message, if vote failed
    }
    ,...
  ]
}
```
* Examples:
```
omotenashicoin-cli mnbudgetvote "local" "ed2f83cedee59a91406f5f47ec4d60bf5a7f9ee6293913c82976bd2d3a658041" "yes"
curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "mnbudgetvote", "params": ["local" "ed2f83cedee59a91406f5f47ec4d60bf5a7f9ee6293913c82976bd2d3a658041" "yes"] }' -H 'content-type: text/plain;' http://127.0.0.1:12180/
```

#### mnbudgetrawvote "masternode-tx-hash" masternode-tx-index "proposal-hash" yes|no time "vote-sig"

##### Compile and relay a proposal vote with provided external signature instead of signing vote internally

 * Arguments:
  * "masternode-tx-hash"  (string, required) Transaction hash for the masternode
  * masternode-tx-index   (numeric, required) Output index for the masternode
  * "proposal-hash"       (string, required) Proposal vote hash
  * yes|no                (boolean, required) Vote to cast
  * time                  (numeric, required) Time since epoch in seconds
  * "vote-sig"            (string, required) External signature


 * Result:
 ```
  "status"     (string) Vote status or error message
```

* Examples:
```
omotenashicoin-cli mnbudgetrawvote
curl --user myusername --data-binary '{"jsonrpc": "1.0", "id":"curltest", "method": "mnbudgetrawvote", "params": [] }' -H 'content-type: text/plain;' http://127.0.0.1:12180/
```
