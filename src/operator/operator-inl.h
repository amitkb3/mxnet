/*!
 * Copyright (c) 2015 by Contributors
 * \file operator-inl.h
 * \brief device invarient code to create operators
 * \author Bing Xu
*/
#ifndef MXNET_OPERATOR_INL_H_
#define MXNET_OPERATOR_INL_H_
#include <mxnet/base.h>
#include <dmlc/logging.h>
#include "./mshadow_op.h"
#include "./activation_op-inl.h"
#include "./fully_connect_op-inl.h"

namespace mxnet {
namespace op {
/*!
 * \brief device invariant function to create operators 
 * \param type the type of operator
 * \tparam xpu the device type we are at
 */
template<typename xpu>
inline Operator *CreateOperator_(OpType type) {
  switch (type) {
    case kReLU:
      return new ActivationOp<xpu, relu, relu_grad>();
    case kFullc:
      return new FullyConnectOp<xpu>();
    default: LOG(FATAL) << "unknown OpType";
  }
  return NULL;
}
}  // namespace op
}  // namespace mxnet
#endif  // MXNET_OPERATOR_INL_H_