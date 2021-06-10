/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_OBSERVATION_OBSERVATIONHEADERDEP_H
#define LIBSBP_V4_OBSERVATION_OBSERVATIONHEADERDEP_H

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/observation_macros.h>
#include <libsbp/v4/gnss.h>
#include <libsbp/v4/gnss/GPSTimeDep.h>
#include <libsbp/v4/string/double_null_terminated.h>
#include <libsbp/v4/string/multipart.h>
#include <libsbp/v4/string/null_terminated.h>
#include <libsbp/v4/string/unterminated.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;

/******************************************************************************
 *
 * SBP_OBSERVATIONHEADERDEP
 *
 *****************************************************************************/
/** Header for observation message
 *
 * Header of a GPS observation message.
 */
typedef struct {
  /**
   * GPS time of this observation
   */
  sbp_gps_time_dep_t t;

  /**
   * Total number of observations. First nibble is the size of the sequence (n),
   * second nibble is the zero-indexed counter (ith packet of n)
   */
  u8 n_obs;
} sbp_observation_header_dep_t;

/**
 * Get encoded size of an instance of sbp_observation_header_dep_t
 *
 * @param msg sbp_observation_header_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_observation_header_dep_encoded_len(
    const sbp_observation_header_dep_t *msg);

/**
 * Encode an instance of sbp_observation_header_dep_t to wire representation
 *
 * This function encodes the given instance in to the user provided buffer. The
 * buffer provided to this function must be large enough to store the encoded
 * message otherwise it will return SBP_ENCODE_ERROR without writing anything to
 * the buffer.
 *
 * Specify the length of the destination buffer in the \p len parameter. If
 * non-null the number of bytes written to the buffer will be returned in \p
 * n_written.
 *
 * @param buf Destination buffer
 * @param len Length of \p buf
 * @param n_written If not null, on success will be set to the number of bytes
 * written to \p buf
 * @param msg Instance of sbp_observation_header_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_observation_header_dep_encode(uint8_t *buf, uint8_t len,
                                     uint8_t *n_written,
                                     const sbp_observation_header_dep_t *msg);

/**
 * Decode an instance of sbp_observation_header_dep_t from wire representation
 *
 * This function decodes the wire representation of a
 * sbp_observation_header_dep_t message to the given instance. The caller must
 * specify the length of the buffer in the \p len parameter. If non-null the
 * number of bytes read from the buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_observation_header_dep_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_observation_header_dep_decode(const uint8_t *buf, uint8_t len,
                                     uint8_t *n_read,
                                     sbp_observation_header_dep_t *msg);

/**
 * Compare two instances of sbp_observation_header_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_observation_header_dep_t instance
 * @param b sbp_observation_header_dep_t instance
 * @return 0, <0, >0
 */
int sbp_observation_header_dep_cmp(const sbp_observation_header_dep_t *a,
                                   const sbp_observation_header_dep_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_observation_header_dep_t &lhs,
                              const sbp_observation_header_dep_t &rhs) {
  return sbp_observation_header_dep_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_observation_header_dep_t &lhs,
                              const sbp_observation_header_dep_t &rhs) {
  return sbp_observation_header_dep_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_observation_header_dep_t &lhs,
                             const sbp_observation_header_dep_t &rhs) {
  return sbp_observation_header_dep_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_observation_header_dep_t &lhs,
                              const sbp_observation_header_dep_t &rhs) {
  return sbp_observation_header_dep_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_observation_header_dep_t &lhs,
                             const sbp_observation_header_dep_t &rhs) {
  return sbp_observation_header_dep_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_observation_header_dep_t &lhs,
                              const sbp_observation_header_dep_t &rhs) {
  return sbp_observation_header_dep_cmp(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_V4_OBSERVATION_OBSERVATIONHEADERDEP_H */
