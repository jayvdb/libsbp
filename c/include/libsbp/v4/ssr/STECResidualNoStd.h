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
 * Automatically generated from yaml/swiftnav/sbp/ssr.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_SSR_STECRESIDUALNOSTD_H
#define LIBSBP_V4_SSR_STECRESIDUALNOSTD_H

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/ssr_macros.h>
#include <libsbp/v4/gnss.h>
#include <libsbp/v4/gnss/SvId.h>
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
 * SBP_STECRESIDUALNOSTD
 *
 *****************************************************************************/
/** None
 *
 * STEC residual for the given satellite at the grid point.
 */
typedef struct {
  /**
   * space vehicle identifier
   */
  sbp_sv_id_t sv_id;

  /**
   * STEC residual [0.04 TECU]
   */
  s16 residual;
} sbp_stec_residual_no_std_t;

/**
 * Get encoded size of an instance of sbp_stec_residual_no_std_t
 *
 * @param msg sbp_stec_residual_no_std_t instance
 * @return Length of on-wire representation
 */
size_t sbp_stec_residual_no_std_encoded_len(
    const sbp_stec_residual_no_std_t *msg);

/**
 * Encode an instance of sbp_stec_residual_no_std_t to wire representation
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
 * @param msg Instance of sbp_stec_residual_no_std_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_stec_residual_no_std_encode(uint8_t *buf, uint8_t len,
                                   uint8_t *n_written,
                                   const sbp_stec_residual_no_std_t *msg);

/**
 * Decode an instance of sbp_stec_residual_no_std_t from wire representation
 *
 * This function decodes the wire representation of a sbp_stec_residual_no_std_t
 * message to the given instance. The caller must specify the length of the
 * buffer in the \p len parameter. If non-null the number of bytes read from the
 * buffer will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_stec_residual_no_std_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_stec_residual_no_std_decode(const uint8_t *buf, uint8_t len,
                                   uint8_t *n_read,
                                   sbp_stec_residual_no_std_t *msg);

/**
 * Compare two instances of sbp_stec_residual_no_std_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_stec_residual_no_std_t instance
 * @param b sbp_stec_residual_no_std_t instance
 * @return 0, <0, >0
 */
int sbp_stec_residual_no_std_cmp(const sbp_stec_residual_no_std_t *a,
                                 const sbp_stec_residual_no_std_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_stec_residual_no_std_t &lhs,
                              const sbp_stec_residual_no_std_t &rhs) {
  return sbp_stec_residual_no_std_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_stec_residual_no_std_t &lhs,
                              const sbp_stec_residual_no_std_t &rhs) {
  return sbp_stec_residual_no_std_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_stec_residual_no_std_t &lhs,
                             const sbp_stec_residual_no_std_t &rhs) {
  return sbp_stec_residual_no_std_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_stec_residual_no_std_t &lhs,
                              const sbp_stec_residual_no_std_t &rhs) {
  return sbp_stec_residual_no_std_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_stec_residual_no_std_t &lhs,
                             const sbp_stec_residual_no_std_t &rhs) {
  return sbp_stec_residual_no_std_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_stec_residual_no_std_t &lhs,
                              const sbp_stec_residual_no_std_t &rhs) {
  return sbp_stec_residual_no_std_cmp(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_V4_SSR_STECRESIDUALNOSTD_H */
