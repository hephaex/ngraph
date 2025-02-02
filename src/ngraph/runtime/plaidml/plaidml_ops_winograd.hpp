//*****************************************************************************
// Copyright 2017-2019 Intel Corporation
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

#include <memory>

#include "ngraph/op/op.hpp"
#include "ngraph/runtime/plaidml/plaidml_ops_convolution.hpp"

namespace ngraph
{
    namespace runtime
    {
        namespace plaidml
        {
            namespace op
            {
                class Winograd;
            }
        }
    }
}

class ngraph::runtime::plaidml::op::Winograd final : public ngraph::op::Op
{
public:
    static const std::string type_name;
    const std::string& description() const override { return type_name; }
    Winograd(std::shared_ptr<Convolution> conv, const OutputVector& args);

    void validate_and_infer_types() final;

    std::shared_ptr<Node> copy_with_new_args(const NodeVector& new_args) const final;

    const std::shared_ptr<Convolution> get_conv() const { return m_conv; }
private:
    std::shared_ptr<Convolution> m_conv;
};
