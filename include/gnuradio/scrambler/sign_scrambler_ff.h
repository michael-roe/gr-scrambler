/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SCRAMBLER_SIGN_SCRAMBLER_FF_H
#define INCLUDED_SCRAMBLER_SIGN_SCRAMBLER_FF_H

#include <gnuradio/scrambler/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace scrambler {

/*!
 * \brief <+description of block+>
 * \ingroup scrambler
 *
 */
class SCRAMBLER_API sign_scrambler_ff : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<sign_scrambler_ff> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of scrambler::sign_scrambler_ff.
     *
     * To avoid accidental use of raw pointers, scrambler::sign_scrambler_ff's
     * constructor is in a private implementation
     * class. scrambler::sign_scrambler_ff::make is the public interface for
     * creating new instances.
     */
    static sptr make(uint64_t mask, uint64_t seed, uint8_t len, int64_t count);
};

} // namespace scrambler
} // namespace gr

#endif /* INCLUDED_SCRAMBLER_SIGN_SCRAMBLER_FF_H */
