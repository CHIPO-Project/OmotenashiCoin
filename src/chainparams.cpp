// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2018-2019 The OmotenashiCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
                // OmotenashiCoinDevs - RELEASE CHANGE - Checkpoints, timestamp of last checkpoint, total nr. of transactions
                (       0,       uint256("00000e04317329056e236da90ebbd1cafacf2cbe1337509231289677cec3f192"))
                (       1,       uint256("0000007dfa713bc64e46805379bb0a39540e89628e446bc2092cd71c522d04ef"))
                (       2,       uint256("00000343b40004fa8f782399e5beb51a6c60b88bc1e0f8dcc2c5cbb65748d470"))
                (       3,       uint256("000000ade3040eaa3d850a526b003c1ebf7b4c235f31479a07ba0abb9dfd7e47"))
                (       4,       uint256("00000ba86d779643cb731042c1b088d6704978febb9f66128ce40c02b15ca1c8"))
                (       5,       uint256("00000822ba96477102d67dd5c0b367a230d019ce82d904b77a3d92c69c17c9d7"))
                (       6,       uint256("000008dff65f665f1da2aabba8f8e48915ba5def55bb0a3a39f2155744735881"))
                (       7,       uint256("00000ce3fbd3f12df7294375539f611e1eeb878e59a41f30b5850cd1abdd6f9d"))
                (       8,       uint256("000007aa83da08e19f3a5cb599812f18da582679533499843dbc6abcc35c29df"))
                (       200,     uint256("0000000000f41e197125cc04bf6af4046fc3a6c79f1585fd7152475f8dc226c4"))
                
                
        ;

static const Checkpoints::CCheckpointData data = {
        &mapCheckpoints,
        1564816072, // * UNIX timestamp of last checkpoint block
        206,       // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
                (       0, uint256("000001780e5aa2fa2df9e9e8a4e86f40261cd5851134c236b32e767e58b12dc6"))
        ;        // First PoW block
static const Checkpoints::CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1562394946,
        0,
        300};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("000004e7b00f32cdc9b02864181ab996fc003d3ed1bdb1377ba1a6b30f35cab2"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1509321649,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0xd1;
        pchMessageStart[1] = 0xb5;
        pchMessageStart[2] = 0xa5;
        pchMessageStart[3] = 0xdd;
        vAlertPubKey = ParseHex("0408cbbe0018cb99d62c237aff5d82fe90cf316d7d52a4eac25ce96f9ba307f78e07f34094d1c7485a107be045c9a80256de7a728d22213ad523e879e2e1cc1469");

        nDefaultPort = 12181;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // OmotenashiCoin starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;       // Halving interval
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nCurrentHeaderVersion = 3;              //Block headers BIP66
        nMinerThreads = 0;                      // Obsolete (**TODO**)
        nTargetTimespan = 1 * 90;               // OmotenashiCoin: 1.5 minute
        nTargetSpacing = 1 * 90;                // OmotenashiCoin: 1.5 minute
        nMaturity = 60;                         // Block maturity
        nMasternodeCountDrift = 5;
        nMaxMoneyOut = 330000000 * COIN;        // Large number effectively unlimited. Will deprecate TODO
        nMasternodeCollateral = 10000;          // Masternode Collateral requirement
        /** Height or Time Based Activations **/
        nLastPOWBlockOffset = 99;               // never PoS
        nModifierUpdateBlock = 1100;            // Modify block on height
        nZerocoinStartHeight = std::numeric_limits<int>::max();         // DISABLED FOR NOW TODO Zerocoin start height
        nZerocoinStartTime = 4102444799;        // off 2099/12/31 not supported.
        nBlockEnforceSerialRange = 1;           // Enforce serial range starting this block
        nBlockRecalculateAccumulators = std::numeric_limits<int>::max(); // Trigger a recalculation of accumulators
        nBlockFirstFraudulent = std::numeric_limits<int>::max();           // 1110; //First block that bad serials emerged (currently we do not have any) *** TODO ***
        nBlockLastGoodCheckpoint = std::numeric_limits<int>::max();        // Last valid accumulator checkpoint (currently we do not have any) *** TODO ***
        nBlockEnforceInvalidUTXO = 5;        // Start enforcing the invalid UTXO's

        const char* pszTimestamp = "for breaking Wimbledon dress code";

        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 1 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("042174344a54c5fcea1e9264714fc4a91a61910fb085ca44e2f8925262f17b7b94a2b5d3a32ffe7f383d6806780df0b20bfef07ae19c2d8b58d734d5cee45768da") << OP_CHECKSIG;

        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1; // do not change.
        genesis.nTime = 1562394945;
        genesis.nBits = 0x1e0fffff;
        genesis.nNonce = 736911;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("00000e04317329056e236da90ebbd1cafacf2cbe1337509231289677cec3f192"));
        assert(genesis.hashMerkleRoot == uint256("b6cda4b7463d0a79da67d3bdcef946154cdba5334f2eb0253cc5aa2eab0fad86"));

        vSeeds.clear();

        vSeeds.push_back(CDNSSeedData("seed1.hashseeds.net","seed1.hashseeds.net"));
        vSeeds.push_back(CDNSSeedData("seed2.seedhash.net","seed2.seedhash.net"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 63); //S
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 18); //8
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 191);

        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x03)(0xA3)(0x95)(0xDA).convert_to_container<std::vector<unsigned char> >(); //momv
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x03)(0xA3)(0x95)(0x55).convert_to_container<std::vector<unsigned char> >(); //momb
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x01)(0x55).convert_to_container<std::vector<unsigned char> >(); //BIP44

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "0408cbbe0018cb99d62c237aff5d82fe90cf316d7d52a4eac25ce96f9ba307f78e07f34094d1c7485a107be045c9a80256de7a728d22213ad523e879e2e1cc1469";
        strObfuscationPoolDummyAddress = "MgvN4Uzgtdd9R8fH12APsSNUTnrcjN9eH6";
        nStartMasternodePayments = 1530342535; //30.06 2018

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};

static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";

        pchMessageStart[0] = 0x63;
        pchMessageStart[1] = 0x43;
        pchMessageStart[2] = 0x64;
        pchMessageStart[3] = 0x54;
        vAlertPubKey = ParseHex("04e9e89f0e79a4236a4ad75ecb6500587faa26338fbc46624c95726a4c76264e618127c7c30f77b62196c0e163fcfbd5d75d076e8032b733ef33a2bc8f0c33ec40");

        nDefaultPort = 12281;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // OmotenashiCoin: 1 day
        nTargetSpacing = 1 * 60;  // OmotenashiCoin: 2 minutes
        nLastPOWBlockOffset = 3;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 1; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 1000000000 * COIN;
        nZerocoinStartHeight = 250;
        nZerocoinStartTime = 1546300800; // Saturday, Jan 1, 2019 00:00:00 AM (GMT)
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 1500; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 891737; //First block that bad serials emerged (currently we do not have any) *** TODO ***
        nBlockLastGoodCheckpoint = 1001; //Last valid accumulator checkpoint (currently we do not have any) *** TODO ***
        nBlockEnforceInvalidUTXO = 1600; //Start enforcing the invalid UTXO's

        genesis.nTime = 1562394946;
        genesis.nNonce = 2709267;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("000001780e5aa2fa2df9e9e8a4e86f40261cd5851134c236b32e767e58b12dc6"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("167.179.73.101", "167.179.73.101"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 83);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 18);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 193);

        // 0x04346b86,     0x04346B01     # Omotenashi     testnet : tmov / tmob
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x34)(0x6B)(0x01).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x34)(0x6B)(0x86).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        // we enable for test purpose low dif mining on main
        nPoolMaxTransactions = 2;
        strSporkKey = "04d7641f4b6859e8bf524553152b40193adcb3320a066800c059d2537b1a3f6bb77b7248dd4a6b531cfc2a67f520d201e3db7e0af6ee828c1ecb5e92fbff3c5cba";
        strObfuscationPoolDummyAddress = "";
        nStartMasternodePayments = 1510272000;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";

        pchMessageStart[0] = 0x13;
        pchMessageStart[1] = 0x53;
        pchMessageStart[2] = 0x94;
        pchMessageStart[3] = 0x64;

        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // OmotenashiCoin: 1 day
        nTargetSpacing = 1 * 60;        // OmotenashiCoin: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1509321649;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 1458278;
       
        nDefaultPort = 13374;
        hashGenesisBlock = genesis.GetHash();


        assert(hashGenesisBlock == uint256("000004e7b00f32cdc9b02864181ab996fc003d3ed1bdb1377ba1a6b30f35cab2"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
