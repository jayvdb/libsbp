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
 * Automatically generated from yaml/swiftnav/sbp/gnss.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_V4_GNSS_GPSTIME_H
#define LIBSBP_V4_GNSS_GPSTIME_H

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/gnss_macros.h>
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
 * SBP_GPSTIME
 *
 *****************************************************************************/
/** Nanosecond-accurate receiver clock time
 *
 * A wire-appropriate receiver clock time, defined as the time since the
 * beginning of the week on the Saturday/Sunday transition. In most cases,
 * observations are epoch aligned so ns field will be 0.
 */
typedef struct {
  /**
   * Milliseconds since start of GPS week [ms]
   */
  u32 tow;

  /**
   * Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
   * 500000) [ns]
   */
  s32 ns_residual;

  /**
   * GPS week number [week]
   */
  u16 wn;
} sbp_sbp_gps_time_t;

/**
 * Get encoded size of an instance of sbp_sbp_gps_time_t
 *
 * @param msg sbp_sbp_gps_time_t instance
 * @return Length of on-wire representation
 */
size_t sbp_sbp_gps_time_encoded_len(const sbp_sbp_gps_time_t *msg);

/**
 * Encode an instance of sbp_sbp_gps_time_t to wire representation
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
 * @param msg Instance of sbp_sbp_gps_time_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_sbp_gps_time_encode(uint8_t *buf, uint8_t len, uint8_t *n_written,
                           const sbp_sbp_gps_time_t *msg);

/**
 * Decode an instance of sbp_sbp_gps_time_t from wire representation
 *
 * This function decodes the wire representation of a sbp_sbp_gps_time_t message
 * to the given instance. The caller must specify the length of the buffer in
 * the \p len parameter. If non-null the number of bytes read from the buffer
 * will be returned in \p n_read.
 *
 * @param buf Wire representation of the sbp_sbp_gps_time_t instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_sbp_gps_time_decode(const uint8_t *buf, uint8_t len, uint8_t *n_read,
                           sbp_sbp_gps_time_t *msg);

/**
 * Compare two instances of sbp_sbp_gps_time_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_sbp_gps_time_t instance
 * @param b sbp_sbp_gps_time_t instance
 * @return 0, <0, >0
 */
int sbp_sbp_gps_time_cmp(const sbp_sbp_gps_time_t *a,
                         const sbp_sbp_gps_time_t *b);

#ifdef __cplusplus
}

static inline bool operator==(const sbp_sbp_gps_time_t &lhs,
                              const sbp_sbp_gps_time_t &rhs) {
  return sbp_sbp_gps_time_cmp(&lhs, &rhs) == 0;
}

static inline bool operator!=(const sbp_sbp_gps_time_t &lhs,
                              const sbp_sbp_gps_time_t &rhs) {
  return sbp_sbp_gps_time_cmp(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_sbp_gps_time_t &lhs,
                             const sbp_sbp_gps_time_t &rhs) {
  return sbp_sbp_gps_time_cmp(&lhs, &rhs) < 0;
}

static inline bool operator<=(const sbp_sbp_gps_time_t &lhs,
                              const sbp_sbp_gps_time_t &rhs) {
  return sbp_sbp_gps_time_cmp(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_sbp_gps_time_t &lhs,
                             const sbp_sbp_gps_time_t &rhs) {
  return sbp_sbp_gps_time_cmp(&lhs, &rhs) > 0;
}

static inline bool operator>=(const sbp_sbp_gps_time_t &lhs,
                              const sbp_sbp_gps_time_t &rhs) {
  return sbp_sbp_gps_time_cmp(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_V4_GNSS_GPSTIME_H */
