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
 * Automatically generated from yaml/swiftnav/sbp/tracking.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

#ifndef LIBSBP_NEW_TRACKING_MSG_TRACKING_STATE_DETAILED_DEP_MESSAGES_H
#define LIBSBP_NEW_TRACKING_MSG_TRACKING_STATE_DETAILED_DEP_MESSAGES_H

#include <endian.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <libsbp/common.h>
#include <libsbp/new/gnss.h>
#include <libsbp/new/gnss/CarrierPhase.h>
#include <libsbp/new/gnss/GPSTimeDep.h>
#include <libsbp/new/gnss/GnssSignalDep.h>
#include <libsbp/new/string/double_null_terminated.h>
#include <libsbp/new/string/multipart.h>
#include <libsbp/new/string/null_terminated.h>
#include <libsbp/new/string/unterminated.h>
#include <libsbp/tracking_macros.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sbp_state;
/******************************************************************************
 *
 * SBP_MSG_TRACKING_STATE_DETAILED_DEP
 *
 *****************************************************************************/
/** Deprecated
 *
 * Deprecated.
 */
typedef struct {
  /**
   * Receiver clock time. [ns]
   */
  u64 recv_time;

  /**
   * Time of transmission of signal from satellite. TOW only valid when TOW
   * status is decoded or propagated. WN only valid when week number valid flag
   * is set.
   */
  sbp_gps_time_dep_t tot;

  /**
   * Pseudorange observation. Valid only when pseudorange valid flag is set. [2
   * cm]
   */
  u32 P;

  /**
   * Pseudorange observation standard deviation. Valid only when pseudorange
   * valid flag is set. [2 cm]
   */
  u16 P_std;

  /**
   * Carrier phase observation with typical sign convention. Valid only when PLL
   * pessimistic lock is achieved. [cycles]
   */
  sbp_carrier_phase_t L;

  /**
   * Carrier-to-Noise density [dB Hz / 4]
   */
  u8 cn0;

  /**
   * Lock time. It is encoded according to DF402 from the RTCM 10403.2 Amendment
   * 2 specification. Valid values range from 0 to 15.
   */
  u16 lock;

  /**
   * GNSS signal identifier.
   */
  sbp_gnss_signal_dep_t sid;

  /**
   * Carrier Doppler frequency. [Hz / 16]
   */
  s32 doppler;

  /**
   * Carrier Doppler frequency standard deviation. [Hz / 16]
   */
  u16 doppler_std;

  /**
   * Number of seconds of continuous tracking. Specifies how much time signal is
   * in continuous track. [s]
   */
  u32 uptime;

  /**
   * TCXO clock offset. Valid only when valid clock valid flag is set. [s / (2 ^
   * 20)]
   */
  s16 clock_offset;

  /**
   * TCXO clock drift. Valid only when valid clock valid flag is set. [(s / s) /
   * (2 ^ 31)]
   */
  s16 clock_drift;

  /**
   * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing. [ns]
   */
  u16 corr_spacing;

  /**
   * Acceleration. Valid only when acceleration valid flag is set. [g / 8]
   */
  s8 acceleration;

  /**
   * Synchronization status flags.
   */
  u8 sync_flags;

  /**
   * TOW status flags.
   */
  u8 tow_flags;

  /**
   * Tracking loop status flags.
   */
  u8 track_flags;

  /**
   * Navigation data status flags.
   */
  u8 nav_flags;

  /**
   * Parameters sets flags.
   */
  u8 pset_flags;

  /**
   * Miscellaneous flags.
   */
  u8 misc_flags;
} sbp_msg_tracking_state_detailed_dep_t;

/**
 * Get encoded size of an instance of sbp_msg_tracking_state_detailed_dep_t
 *
 * @param msg sbp_msg_tracking_state_detailed_dep_t instance
 * @return Length of on-wire representation
 */
size_t sbp_packed_size_sbp_msg_tracking_state_detailed_dep_t(
    const sbp_msg_tracking_state_detailed_dep_t *msg);

/**
 * Encode an instance of sbp_msg_tracking_state_detailed_dep_t to wire
 * representation
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
 * @param msg Instance of sbp_msg_tracking_state_detailed_dep_t to encode
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_encode_sbp_msg_tracking_state_detailed_dep_t(
    uint8_t *buf, uint8_t len, uint8_t *n_written,
    const sbp_msg_tracking_state_detailed_dep_t *msg);

/**
 * Decode an instance of sbp_msg_tracking_state_detailed_dep_t from wire
 * representation
 *
 * This function decodes the wire representation of a
 * sbp_msg_tracking_state_detailed_dep_t message to the given instance. The
 * caller must specify the length of the buffer in the \p len parameter. If
 * non-null the number of bytes read from the buffer will be returned in \p
 * n_read.
 *
 * @param buf Wire representation of the sbp_msg_tracking_state_detailed_dep_t
 * instance
 * @param len Length of \p buf
 * @param n_read If not null, on success will be set to the number of bytes read
 * from \p buf
 * @param msg Destination
 * @return SBP_OK on success, or other libsbp error code
 */
s8 sbp_decode_sbp_msg_tracking_state_detailed_dep_t(
    const uint8_t *buf, uint8_t len, uint8_t *n_read,
    sbp_msg_tracking_state_detailed_dep_t *msg);
/**
 * Send an instance of sbp_msg_tracking_state_detailed_dep_t with the given
 * write function
 *
 * An equivalent of #sbp_send_message which operates specifically on
 * sbp_msg_tracking_state_detailed_dep_t
 *
 * The given message will be encoded to wire representation and passed in to the
 * given write function callback. The write callback will be called several
 * times for each invocation of this function.
 *
 * @param s SBP state
 * @param sender_id SBP sender id
 * @param msg Message to send
 * @param write Write function
 * @param SBP_OK on success, or other libsbp error code
 */
s8 sbp_send_sbp_msg_tracking_state_detailed_dep_t(
    struct sbp_state *s, u16 sender_id,
    const sbp_msg_tracking_state_detailed_dep_t *msg, sbp_write_fn_t write);

/**
 * Compare two instances of sbp_msg_tracking_state_detailed_dep_t
 *
 * The two instances will be compared and a value returned consistent with the
 * return codes of comparison functions from the C standard library
 *
 * 0 will be returned if \p a and \p b are considered equal
 * A value less than 0 will be returned if \p a is considered to be less than \p
 * b A value greater than 0 will be returned if \p b is considered to be greater
 * than \p b
 *
 * @param a sbp_msg_tracking_state_detailed_dep_t instance
 * @param b sbp_msg_tracking_state_detailed_dep_t instance
 * @return 0, <0, >0
 */
int sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(
    const sbp_msg_tracking_state_detailed_dep_t *a,
    const sbp_msg_tracking_state_detailed_dep_t *b);

#ifdef __cplusplus
}
static inline bool operator==(
    const sbp_msg_tracking_state_detailed_dep_t &lhs,
    const sbp_msg_tracking_state_detailed_dep_t &rhs) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&lhs, &rhs) == 0;
}

static inline bool operator!=(
    const sbp_msg_tracking_state_detailed_dep_t &lhs,
    const sbp_msg_tracking_state_detailed_dep_t &rhs) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&lhs, &rhs) != 0;
}

static inline bool operator<(const sbp_msg_tracking_state_detailed_dep_t &lhs,
                             const sbp_msg_tracking_state_detailed_dep_t &rhs) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&lhs, &rhs) < 0;
}

static inline bool operator<=(
    const sbp_msg_tracking_state_detailed_dep_t &lhs,
    const sbp_msg_tracking_state_detailed_dep_t &rhs) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&lhs, &rhs) <= 0;
}

static inline bool operator>(const sbp_msg_tracking_state_detailed_dep_t &lhs,
                             const sbp_msg_tracking_state_detailed_dep_t &rhs) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&lhs, &rhs) > 0;
}

static inline bool operator>=(
    const sbp_msg_tracking_state_detailed_dep_t &lhs,
    const sbp_msg_tracking_state_detailed_dep_t &rhs) {
  return sbp_cmp_sbp_msg_tracking_state_detailed_dep_t(&lhs, &rhs) >= 0;
}

#endif

#endif /* LIBSBP_NEW_TRACKING_MESSAGES_H */
