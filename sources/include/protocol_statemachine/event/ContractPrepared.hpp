/**
 * Copyright (C) JoyStream - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Bedeho Mender <bedeho.mender@gmail.com>, March 29 2016
 */

#ifndef JOYSTREAM_PROTOCOLSTATEMACHINE_EVENT_CONTRACTPREPARED_HPP
#define JOYSTREAM_PROTOCOLSTATEMACHINE_EVENT_CONTRACTPREPARED_HPP

#include <boost/statechart/event.hpp>
#include <common/typesafeOutPoint.hpp>
#include <common/KeyPair.hpp>

namespace sc = boost::statechart;

namespace joystream {
namespace protocol_statemachine {
namespace event {

    class ContractPrepared : public sc::event<ContractPrepared> {

    public:

        ContractPrepared();
        ContractPrepared(const Coin::typesafeOutPoint &, const Coin::KeyPair &, const Coin::PubKeyHash &, uint64_t);

        // Getters
        Coin::typesafeOutPoint anchor() const;

        Coin::KeyPair contractKeyPair() const;

        Coin::PubKeyHash finalPkHash() const;

        uint64_t value() const;

    private:

        // Anchor for contract
        Coin::typesafeOutPoint _anchor;

        // Contract output buyer multisig key
        Coin::KeyPair _buyerContractKeyPair;

        // Payment/Refund buyer output
        Coin::PubKeyHash _finalPkHash;

        // NB: may be temporary
        uint64_t _value;
    };

}
}
}

#endif // JOYSTREAM_PROTOCOLSTATEMACHINE_EVENT_CONTRACTPREPARED_HPP
