// Copyright (c) 2024 PaddlePaddle Authors. All Rights Reserved.
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

#pragma once
#include <functional>
#include "paddle/cinn/operator_fusion/pattern_node.h"
#include "paddle/cinn/operator_fusion/pir_graph_analyzing/anchor_transform.h"
#include "paddle/cinn/operator_fusion/policy/policy_base.h"
#include "paddle/cinn/operator_fusion/utils.h"
#include "paddle/common/enforce.h"

namespace cinn::fusion {

template <typename T>
struct AnchorSearchPolicy final : public PolicyBase<T> {
  static constexpr PolicyKind Kind = PolicyKind::AnchorSearch;
  bool HasUpstreamAnchor(const PatternNodePtr<T>& upstream,
                         const PatternNodePtr<T>& downstream);
  bool HasDownstreamAnchor(const PatternNodePtr<T>& upstream,
                           const PatternNodePtr<T>& downstream);
  std::optional<AnchorTransformRoute> FindUpstreamAnchorTransformRoute(
      const PatternNodePtr<T>& upstream, const PatternNodePtr<T>& downstream);
  std::optional<AnchorTransformRoute> FindDownstreamAnchorTransformRoute(
      const PatternNodePtr<T>& upstream, const PatternNodePtr<T>& downstream);

  std::string Name() { return "AnchorSearchPolicy"; }
};

}  // namespace cinn::fusion
