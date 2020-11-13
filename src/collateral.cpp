// Copyright (c) 2020 The Ballotbox developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    CAmount nCollateralRequired;
    
    if (nHeight <= 400) {
        nCollateralRequired = 0 * COIN;
    } else if (nHeight <= 10000) {
        nCollateralRequired = 1 * COIN;
    } else if (nHeight <= 15000) {
        nCollateralRequired = 3 * COIN;
    } else if (nHeight <= 30000) {
        nCollateralRequired = 9 * COIN;
    } else if (nHeight <= 45000) {
        nCollateralRequired = 15 * COIN;
    } else if (nHeight <= 60000) {
        nCollateralRequired = 50 * COIN;
    } else if (nHeight <= 75000) {
        nCollateralRequired = 100 * COIN;
    } else if (nHeight <= 90000) {
        nCollateralRequired = 250 * COIN;
    } else if (nHeight <= 110000) {
        nCollateralRequired = 500 * COIN;
    } else if (nHeight <= 130000) {
        nCollateralRequired = 750 * COIN;
    } else if (nHeight <= 150000) {
        nCollateralRequired = 1000 * COIN;
    } else if (nHeight <= 165000) {
        nCollateralRequired = 1200 * COIN;
    } else if (nHeight <= 180000) {
        nCollateralRequired = 1400 * COIN;
    } else if (nHeight <= 200000) {
        nCollateralRequired = 1600 * COIN;
    } else if (nHeight <= 230000) {
        nCollateralRequired = 1850 * COIN;
    } else if (nHeight <= 260000) {
        nCollateralRequired = 2200 * COIN;
    } else if (nHeight <= 300000) {
        nCollateralRequired = 2500 * COIN;
    } else if (nHeight <= 350000) {
        nCollateralRequired = 5000 * COIN;
    } else if (nHeight <= 400000) {
        nCollateralRequired = 8000 * COIN;
    } else if (nHeight <= 500000) {
        nCollateralRequired = 10000 * COIN;
    } else {
        nCollateralRequired = 25000 * COIN;
    }

    return nCollateralRequired;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}