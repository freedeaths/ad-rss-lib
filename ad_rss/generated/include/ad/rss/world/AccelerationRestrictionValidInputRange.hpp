/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 11.0.0-1988
 */

#pragma once

#include <cmath>
#include <limits>
#include "ad/physics/AccelerationRangeValidInputRange.hpp"
#include "ad/rss/world/AccelerationRestriction.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given AccelerationRestriction is within valid input range
 *
 * \param[in] input the AccelerationRestriction as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if AccelerationRestriction is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members, plus:
 *       ::ad::rss::world::TimeIndex(1) <= timeIndex
 */
inline bool withinValidInputRange(::ad::rss::world::AccelerationRestriction const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.lateralLeftRange, logErrors)
    && withinValidInputRange(input.longitudinalRange, logErrors)
    && withinValidInputRange(input.lateralRightRange, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::rss::world::AccelerationRestriction)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  // check for individual input ranges
  if (inValidInputRange)
  {
    inValidInputRange = (::ad::rss::world::TimeIndex(1) <= input.timeIndex);
    if (!inValidInputRange && logErrors)
    {
      spdlog::error("withinValidInputRange(::ad::rss::world::AccelerationRestriction)>> {} element {} out of valid "
                    "input range [{}, {}]",
                    input,
                    input.timeIndex,
                    ::ad::rss::world::TimeIndex(1),
                    "Undefined"); // LCOV_EXCL_BR_LINE
    }
  }

  return inValidInputRange;
}
