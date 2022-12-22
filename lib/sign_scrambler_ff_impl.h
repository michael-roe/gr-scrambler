/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SCRAMBLER_SIGN_SCRAMBLER_FF_IMPL_H
#define INCLUDED_SCRAMBLER_SIGN_SCRAMBLER_FF_IMPL_H

#include <gnuradio/scrambler/sign_scrambler_ff.h>

namespace gr {
namespace scrambler {

class sign_scrambler_ff_impl : public sign_scrambler_ff
{
private:
    int d_length;
    int d_todo;
    unsigned int d_state;

public:
    sign_scrambler_ff_impl(uint64_t mask, uint64_t seed, uint8_t len, int64_t count);
    ~sign_scrambler_ff_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace scrambler
} // namespace gr

#endif /* INCLUDED_SCRAMBLER_SIGN_SCRAMBLER_FF_IMPL_H */
