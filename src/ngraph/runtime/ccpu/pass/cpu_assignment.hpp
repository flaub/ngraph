//*****************************************************************************
// Copyright 2017-2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include "ngraph/pass/pass.hpp"
#include "ngraph/runtime/ccpu/ccpu_external_function.hpp"
#include "ngraph/runtime/ccpu/ccpu_tensor_view.hpp"

#define ASSIGN_DECL(op_name)                                                                       \
    assign<op_name>(ngraph::runtime::cpu::CCPUExternalFunction * external_function,                \
                    ngraph::Node * node)

namespace ngraph
{
    namespace runtime
    {
        namespace cpu
        {
            namespace pass
            {
                using AssignFunction = std::function<void(CCPUExternalFunction*, ngraph::Node*)>;

                using AssignOpMap = std::unordered_map<std::type_index, AssignFunction>;

                class CPUAssignment : public ngraph::pass::CallGraphPass
                {
                public:
                    CPUAssignment(CCPUExternalFunction* external_function)
                        : m_external_function(external_function)
                    {
                    }

                    virtual bool
                        run_on_call_graph(const std::list<std::shared_ptr<Node>>& nodes) override;

                    template <typename OP>
                    static void
                        assign(ngraph::runtime::cpu::CCPUExternalFunction* external_function,
                               ngraph::Node* node)
                    {
                        throw std::runtime_error("Unimplemented op in CPU assignment");
                    }

                private:
                    CCPUExternalFunction* m_external_function;
                };
            }
        }
    }
}
