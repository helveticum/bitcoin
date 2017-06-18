// Copyright (c) 2016 The Helveticum Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef HELVETICUM_WALLET_TEST_FIXTURE_H
#define HELVETICUM_WALLET_TEST_FIXTURE_H

#include "test/test_helveticum.h"

/** Testing setup and teardown for wallet.
 */
struct WalletTestingSetup: public TestingSetup {
    WalletTestingSetup(const std::string& chainName = CBaseChainParams::MAIN);
    ~WalletTestingSetup();
};

#endif

