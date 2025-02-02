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

#include "ngraph/op/op.hpp"

namespace ngraph
{
    namespace op
    {
        struct PriorBoxAttrs
        {
            // min_size         Desired min_size of prior boxes
            // max_size         Desired max_size of prior boxes
            // aspect_ratio     Aspect ratios of prior boxes
            // clip             Clip output to [0,1]
            // flip             Flip aspect ratios
            // step             Distance between prior box centers
            // offset           Box offset relative to top center of image
            // variance         Values to adjust prior boxes with
            // scale_all_sizes  Scale all sizes
            std::vector<float> min_size;
            std::vector<float> max_size;
            std::vector<float> aspect_ratio;
            bool clip = false;
            bool flip = false;
            float step = 1.0f;
            float offset = 0.0f;
            std::vector<float> variance;
            bool scale_all_sizes = false;
        };

        /// \brief Layer which generates prior boxes of specified sizes
        /// normalized to input image size
        class PriorBox : public Op
        {
        public:
            NGRAPH_API
            static const std::string type_name;
            const std::string& description() const override { return type_name; }
            /// \brief Constructs a PriorBox operation
            ///
            /// \param layer_shape    Shape of layer for which prior boxes are computed
            /// \param image_shape    Shape of image to which prior boxes are scaled
            /// \param attrs          PriorBox attributes
            PriorBox(const std::shared_ptr<Node>& layer_shape,
                     const std::shared_ptr<Node>& image_shape,
                     const PriorBoxAttrs& attrs);

            void validate_and_infer_types() override;

            virtual std::shared_ptr<Node>
                copy_with_new_args(const NodeVector& new_args) const override;

            const PriorBoxAttrs& get_attrs() const { return m_attrs; }
        private:
            PriorBoxAttrs m_attrs;
        };
    }
}
