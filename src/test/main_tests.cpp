// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/transaction.h"
#include "main.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(main_tests)

CAmount nMoneySupplyPoWEnd = 398360470 * COIN;

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    CAmount nSum = 0;

    // premin
    for (int nHeight = 0; nHeight < 1; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 0 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 1; nHeight <= 5; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 50000 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 6; nHeight < 7; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 450000 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 7; nHeight < 8; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 16000000 * COIN);
        nSum += nSubsidy;
    }

}

BOOST_AUTO_TEST_SUITE_END()
