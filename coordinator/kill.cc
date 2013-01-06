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
#include "coordinator/coordinator.h"
#include "coordinator/kill.h"
#include "coordinator/util.h"

using hyperdex::coordinator;
using hyperdex::server_id;
using hyperdex::space;

extern "C"
{

void
hyperdex_coordinator_kill(struct replicant_state_machine_context* ctx,
                          void* obj, const char* data, size_t data_sz)
{
    PROTECT_UNINITIALIZED;
    coordinator* c = static_cast<coordinator*>(obj);
    uint64_t _sid;
    e::unpacker up(data, data_sz);
    up = up >> _sid;

    if (up.error())
    {
        return generate_response(ctx, c, hyperdex::COORD_MALFORMED);
    }

    server_id sid(_sid);

    for (std::list<space>::iterator s = c->spaces.begin(); s != c->spaces.end(); ++s)
    {
        for (size_t i = 0; i < s->subspaces.size(); ++i)
        {
            for (size_t j = 0; j < s->subspaces[i].regions.size(); ++j)
            {
                size_t k = 0;

                while (k < s->subspaces[i].regions[j].replicas.size())
                {
                    if (s->subspaces[i].regions[j].replicas[k].si == sid)
                    {
                        for (size_t r = k; r + 1 < s->subspaces[i].regions[j].replicas.size(); ++r)
                        {
                            s->subspaces[i].regions[j].replicas[r] = s->subspaces[i].regions[j].replicas[r + 1];
                        }

                        s->subspaces[i].regions[j].replicas.pop_back();
                    }
                    else
                    {
                        ++k;
                    }
                }

                if (s->subspaces[i].regions[j].replicas.empty())
                {
                    replicant_state_machine_log_error(ctx, "kill completely emptied a region");
                }
            }
        }
    }

    c->regenerate(ctx);
    return generate_response(ctx, c, hyperdex::COORD_SUCCESS);
}

} // extern "C"
