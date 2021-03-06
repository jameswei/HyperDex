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

// HyperDex
#include "hyperdex.h"
#include "common/macros.h"

std::ostream&
operator << (std::ostream& lhs, hyperdatatype rhs)
{
    switch (rhs)
    {
        STRINGIFY(HYPERDATATYPE_GENERIC);
        STRINGIFY(HYPERDATATYPE_STRING);
        STRINGIFY(HYPERDATATYPE_INT64);
        STRINGIFY(HYPERDATATYPE_FLOAT);
        STRINGIFY(HYPERDATATYPE_LIST_GENERIC);
        STRINGIFY(HYPERDATATYPE_LIST_STRING);
        STRINGIFY(HYPERDATATYPE_LIST_INT64);
        STRINGIFY(HYPERDATATYPE_LIST_FLOAT);
        STRINGIFY(HYPERDATATYPE_SET_GENERIC);
        STRINGIFY(HYPERDATATYPE_SET_STRING);
        STRINGIFY(HYPERDATATYPE_SET_INT64);
        STRINGIFY(HYPERDATATYPE_SET_FLOAT);
        STRINGIFY(HYPERDATATYPE_MAP_GENERIC);
        STRINGIFY(HYPERDATATYPE_MAP_STRING_KEYONLY);
        STRINGIFY(HYPERDATATYPE_MAP_STRING_STRING);
        STRINGIFY(HYPERDATATYPE_MAP_STRING_INT64);
        STRINGIFY(HYPERDATATYPE_MAP_STRING_FLOAT);
        STRINGIFY(HYPERDATATYPE_MAP_INT64_KEYONLY);
        STRINGIFY(HYPERDATATYPE_MAP_INT64_STRING);
        STRINGIFY(HYPERDATATYPE_MAP_INT64_INT64);
        STRINGIFY(HYPERDATATYPE_MAP_INT64_FLOAT);
        STRINGIFY(HYPERDATATYPE_MAP_FLOAT_KEYONLY);
        STRINGIFY(HYPERDATATYPE_MAP_FLOAT_STRING);
        STRINGIFY(HYPERDATATYPE_MAP_FLOAT_INT64);
        STRINGIFY(HYPERDATATYPE_MAP_FLOAT_FLOAT);
        STRINGIFY(HYPERDATATYPE_GARBAGE);
        default:
            lhs << "unknown hyperdatatype";
            break;
    }

    return lhs;
}

std::ostream&
operator << (std::ostream& lhs, hyperpredicate rhs)
{
    switch (rhs)
    {
        STRINGIFY(HYPERPREDICATE_FAIL);
        STRINGIFY(HYPERPREDICATE_EQUALS);
        STRINGIFY(HYPERPREDICATE_LESS_EQUAL);
        STRINGIFY(HYPERPREDICATE_GREATER_EQUAL);
        STRINGIFY(HYPERPREDICATE_CONTAINS_LESS_THAN);
        default:
            lhs << "unknown hyperpredicate";
            break;
    }

    return lhs;
}
