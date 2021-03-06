// Copyright (c) 2012, Cornell University
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of HyperDex nor the names of its contributors may be
//       used to endorse or promote products derived from this software without
//       specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef datatypes_set_h_
#define datatypes_set_h_

// e
#include <e/slice.h>

// HyperDex
#include "hyperdex.h"
#include "common/funcall.h"
#include "datatypes/microerror.h"

bool
validate_as_set_string(const e::slice& value);

bool
parse_as_set_string(const e::slice& value);

bool
validate_as_set_int64(const e::slice& value);

bool
validate_as_set_float(const e::slice& value);

bool
sizeof_set_string(const e::slice& value, uint64_t* count);

bool
sizeof_set_int64(const e::slice& value, uint64_t* count);

bool
sizeof_set_float(const e::slice& value, uint64_t* count);

uint8_t*
apply_set_string(const e::slice& old_value,
                 const hyperdex::funcall* funcs, size_t num_funcs,
                 uint8_t* writeto, microerror* error);

uint8_t*
apply_set_int64(const e::slice& old_value,
                const hyperdex::funcall* funcs, size_t num_funcs,
                uint8_t* writeto, microerror* error);

uint8_t*
apply_set_float(const e::slice& old_value,
                const hyperdex::funcall* funcs, size_t num_funcs,
                uint8_t* writeto, microerror* error);

#endif // datatypes_set_h_
