/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "sign_scrambler_ff_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace scrambler {

sign_scrambler_ff::sptr
sign_scrambler_ff::make(uint64_t mask, uint64_t seed, uint8_t len, int64_t count)
{
    return gnuradio::make_block_sptr<sign_scrambler_ff_impl>(mask, seed, len, count);
}


/*
 * The private constructor
 */
sign_scrambler_ff_impl::sign_scrambler_ff_impl(uint64_t mask,
                                               uint64_t seed,
                                               uint8_t len,
                                               int64_t count)
    : gr::sync_block("sign_scrambler_ff",
                     gr::io_signature::make(
                         1, 1, sizeof(float)),
                     gr::io_signature::make(
                         1, 1, sizeof(float)))
{
  d_length = len;
  d_todo = len;
  d_state = 0x1c9;
}

/*
 * Our virtual destructor.
 */
sign_scrambler_ff_impl::~sign_scrambler_ff_impl() {}

int sign_scrambler_ff_impl::work(int noutput_items,
                                 gr_vector_const_void_star& input_items,
                                 gr_vector_void_star& output_items)
{
    float *in = (float *) input_items[0];
    float *out = (float *) output_items[0];
    int i;
    int fb;

    for (i=0; i<noutput_items; i++)
    {
      if (d_state & 0x1)
        out[i] = -in[i];
      else
        out[i] = in[i];
      fb = ((d_state >> 4) ^ d_state) & 0x1;
      d_state = d_state >> 1;
      if (fb)
        d_state ^= 1 << 8;
      d_todo--;
      if (d_todo == 0)
      {
        d_todo = d_length;
        d_state = 0x1c9;
      }
    }

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace scrambler */
} /* namespace gr */
