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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDopsDepA.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/navigation.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static void *DUMMY_MEMORY_FOR_CALLBACKS = (void *)0xdeadbeef;
static void *DUMMY_MEMORY_FOR_IO = (void *)0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

static void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

static void msg_callback(u16 sender_id, sbp_msg_type_t msg_type,
                         const sbp_msg_t *msg, void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

START_TEST(test_auto_check_sbp_navigation_MsgDopsDepA) {
  static sbp_msg_callbacks_node_t n;

  // State of the SBP message parser.
  // Must be statically allocated.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x206, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6,   2, 246, 215, 14,  8, 48,  39, 0,   180,
        0,  190, 0, 170, 0,   160, 0, 150, 0,  121, 170,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops_dep_a.gdop = 180;

    test_msg.dops_dep_a.hdop = 160;

    test_msg.dops_dep_a.pdop = 190;

    test_msg.dops_dep_a.tdop = 170;

    test_msg.dops_dep_a.tow = 2568200;

    test_msg.dops_dep_a.vdop = 150;

    sbp_message_send(&sbp_state, SbpMsgDopsDepA, 55286, &test_msg,
                     &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgDopsDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.dops_dep_a.gdop == 180,
        "incorrect value for last_msg.msg.dops_dep_a.gdop, expected 180, is %d",
        last_msg.msg.dops_dep_a.gdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.hdop == 160,
        "incorrect value for last_msg.msg.dops_dep_a.hdop, expected 160, is %d",
        last_msg.msg.dops_dep_a.hdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.pdop == 190,
        "incorrect value for last_msg.msg.dops_dep_a.pdop, expected 190, is %d",
        last_msg.msg.dops_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tdop == 170,
        "incorrect value for last_msg.msg.dops_dep_a.tdop, expected 170, is %d",
        last_msg.msg.dops_dep_a.tdop);

    ck_assert_msg(last_msg.msg.dops_dep_a.tow == 2568200,
                  "incorrect value for last_msg.msg.dops_dep_a.tow, expected "
                  "2568200, is %d",
                  last_msg.msg.dops_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.vdop == 150,
        "incorrect value for last_msg.msg.dops_dep_a.vdop, expected 150, is %d",
        last_msg.msg.dops_dep_a.vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x206, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6,   2, 246, 215, 14,  240, 51,  39, 0,  180,
        0,  190, 0, 170, 0,   160, 0,   150, 0,  78, 169,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops_dep_a.gdop = 180;

    test_msg.dops_dep_a.hdop = 160;

    test_msg.dops_dep_a.pdop = 190;

    test_msg.dops_dep_a.tdop = 170;

    test_msg.dops_dep_a.tow = 2569200;

    test_msg.dops_dep_a.vdop = 150;

    sbp_message_send(&sbp_state, SbpMsgDopsDepA, 55286, &test_msg,
                     &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgDopsDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.dops_dep_a.gdop == 180,
        "incorrect value for last_msg.msg.dops_dep_a.gdop, expected 180, is %d",
        last_msg.msg.dops_dep_a.gdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.hdop == 160,
        "incorrect value for last_msg.msg.dops_dep_a.hdop, expected 160, is %d",
        last_msg.msg.dops_dep_a.hdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.pdop == 190,
        "incorrect value for last_msg.msg.dops_dep_a.pdop, expected 190, is %d",
        last_msg.msg.dops_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tdop == 170,
        "incorrect value for last_msg.msg.dops_dep_a.tdop, expected 170, is %d",
        last_msg.msg.dops_dep_a.tdop);

    ck_assert_msg(last_msg.msg.dops_dep_a.tow == 2569200,
                  "incorrect value for last_msg.msg.dops_dep_a.tow, expected "
                  "2569200, is %d",
                  last_msg.msg.dops_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.vdop == 150,
        "incorrect value for last_msg.msg.dops_dep_a.vdop, expected 150, is %d",
        last_msg.msg.dops_dep_a.vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x206, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6,   2, 246, 215, 14,  216, 55,  39, 0,  180,
        0,  190, 0, 170, 0,   160, 0,   150, 0,  71, 218,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops_dep_a.gdop = 180;

    test_msg.dops_dep_a.hdop = 160;

    test_msg.dops_dep_a.pdop = 190;

    test_msg.dops_dep_a.tdop = 170;

    test_msg.dops_dep_a.tow = 2570200;

    test_msg.dops_dep_a.vdop = 150;

    sbp_message_send(&sbp_state, SbpMsgDopsDepA, 55286, &test_msg,
                     &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgDopsDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.dops_dep_a.gdop == 180,
        "incorrect value for last_msg.msg.dops_dep_a.gdop, expected 180, is %d",
        last_msg.msg.dops_dep_a.gdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.hdop == 160,
        "incorrect value for last_msg.msg.dops_dep_a.hdop, expected 160, is %d",
        last_msg.msg.dops_dep_a.hdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.pdop == 190,
        "incorrect value for last_msg.msg.dops_dep_a.pdop, expected 190, is %d",
        last_msg.msg.dops_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tdop == 170,
        "incorrect value for last_msg.msg.dops_dep_a.tdop, expected 170, is %d",
        last_msg.msg.dops_dep_a.tdop);

    ck_assert_msg(last_msg.msg.dops_dep_a.tow == 2570200,
                  "incorrect value for last_msg.msg.dops_dep_a.tow, expected "
                  "2570200, is %d",
                  last_msg.msg.dops_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.vdop == 150,
        "incorrect value for last_msg.msg.dops_dep_a.vdop, expected 150, is %d",
        last_msg.msg.dops_dep_a.vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x206, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6,   2, 195, 4, 14, 212, 157, 67, 24,  247,
        0,  215, 0, 123, 0, 17, 1,   44,  0,  206, 21,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops_dep_a.gdop = 247;

    test_msg.dops_dep_a.hdop = 273;

    test_msg.dops_dep_a.pdop = 215;

    test_msg.dops_dep_a.tdop = 123;

    test_msg.dops_dep_a.tow = 407084500;

    test_msg.dops_dep_a.vdop = 44;

    sbp_message_send(&sbp_state, SbpMsgDopsDepA, 1219, &test_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgDopsDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.dops_dep_a.gdop == 247,
        "incorrect value for last_msg.msg.dops_dep_a.gdop, expected 247, is %d",
        last_msg.msg.dops_dep_a.gdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.hdop == 273,
        "incorrect value for last_msg.msg.dops_dep_a.hdop, expected 273, is %d",
        last_msg.msg.dops_dep_a.hdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.pdop == 215,
        "incorrect value for last_msg.msg.dops_dep_a.pdop, expected 215, is %d",
        last_msg.msg.dops_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tdop == 123,
        "incorrect value for last_msg.msg.dops_dep_a.tdop, expected 123, is %d",
        last_msg.msg.dops_dep_a.tdop);

    ck_assert_msg(last_msg.msg.dops_dep_a.tow == 407084500,
                  "incorrect value for last_msg.msg.dops_dep_a.tow, expected "
                  "407084500, is %d",
                  last_msg.msg.dops_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.vdop == 44,
        "incorrect value for last_msg.msg.dops_dep_a.vdop, expected 44, is %d",
        last_msg.msg.dops_dep_a.vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x206, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  6,   2,   195, 4, 14, 0, 0, 0, 0,   255,
        255, 255, 255, 0,   0, 0,  0, 0, 0, 146, 12,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops_dep_a.gdop = 65535;

    test_msg.dops_dep_a.hdop = 0;

    test_msg.dops_dep_a.pdop = 65535;

    test_msg.dops_dep_a.tdop = 0;

    test_msg.dops_dep_a.tow = 0;

    test_msg.dops_dep_a.vdop = 0;

    sbp_message_send(&sbp_state, SbpMsgDopsDepA, 1219, &test_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgDopsDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.dops_dep_a.gdop == 65535,
                  "incorrect value for last_msg.msg.dops_dep_a.gdop, expected "
                  "65535, is %d",
                  last_msg.msg.dops_dep_a.gdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.hdop == 0,
        "incorrect value for last_msg.msg.dops_dep_a.hdop, expected 0, is %d",
        last_msg.msg.dops_dep_a.hdop);

    ck_assert_msg(last_msg.msg.dops_dep_a.pdop == 65535,
                  "incorrect value for last_msg.msg.dops_dep_a.pdop, expected "
                  "65535, is %d",
                  last_msg.msg.dops_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tdop == 0,
        "incorrect value for last_msg.msg.dops_dep_a.tdop, expected 0, is %d",
        last_msg.msg.dops_dep_a.tdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tow == 0,
        "incorrect value for last_msg.msg.dops_dep_a.tow, expected 0, is %d",
        last_msg.msg.dops_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.vdop == 0,
        "incorrect value for last_msg.msg.dops_dep_a.vdop, expected 0, is %d",
        last_msg.msg.dops_dep_a.vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x206, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6,  2, 195, 4, 14,  128, 165, 68, 24,  92,
        1,  56, 1, 155, 0, 125, 2,   113, 0,  129, 93,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops_dep_a.gdop = 348;

    test_msg.dops_dep_a.hdop = 637;

    test_msg.dops_dep_a.pdop = 312;

    test_msg.dops_dep_a.tdop = 155;

    test_msg.dops_dep_a.tow = 407152000;

    test_msg.dops_dep_a.vdop = 113;

    sbp_message_send(&sbp_state, SbpMsgDopsDepA, 1219, &test_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgDopsDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.dops_dep_a.gdop == 348,
        "incorrect value for last_msg.msg.dops_dep_a.gdop, expected 348, is %d",
        last_msg.msg.dops_dep_a.gdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.hdop == 637,
        "incorrect value for last_msg.msg.dops_dep_a.hdop, expected 637, is %d",
        last_msg.msg.dops_dep_a.hdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.pdop == 312,
        "incorrect value for last_msg.msg.dops_dep_a.pdop, expected 312, is %d",
        last_msg.msg.dops_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tdop == 155,
        "incorrect value for last_msg.msg.dops_dep_a.tdop, expected 155, is %d",
        last_msg.msg.dops_dep_a.tdop);

    ck_assert_msg(last_msg.msg.dops_dep_a.tow == 407152000,
                  "incorrect value for last_msg.msg.dops_dep_a.tow, expected "
                  "407152000, is %d",
                  last_msg.msg.dops_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.vdop == 113,
        "incorrect value for last_msg.msg.dops_dep_a.vdop, expected 113, is %d",
        last_msg.msg.dops_dep_a.vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x206, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6,  2, 195, 4, 14,  104, 169, 68, 24,  92,
        1,  55, 1, 155, 0, 125, 2,   113, 0,  209, 128,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops_dep_a.gdop = 348;

    test_msg.dops_dep_a.hdop = 637;

    test_msg.dops_dep_a.pdop = 311;

    test_msg.dops_dep_a.tdop = 155;

    test_msg.dops_dep_a.tow = 407153000;

    test_msg.dops_dep_a.vdop = 113;

    sbp_message_send(&sbp_state, SbpMsgDopsDepA, 1219, &test_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgDopsDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.dops_dep_a.gdop == 348,
        "incorrect value for last_msg.msg.dops_dep_a.gdop, expected 348, is %d",
        last_msg.msg.dops_dep_a.gdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.hdop == 637,
        "incorrect value for last_msg.msg.dops_dep_a.hdop, expected 637, is %d",
        last_msg.msg.dops_dep_a.hdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.pdop == 311,
        "incorrect value for last_msg.msg.dops_dep_a.pdop, expected 311, is %d",
        last_msg.msg.dops_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tdop == 155,
        "incorrect value for last_msg.msg.dops_dep_a.tdop, expected 155, is %d",
        last_msg.msg.dops_dep_a.tdop);

    ck_assert_msg(last_msg.msg.dops_dep_a.tow == 407153000,
                  "incorrect value for last_msg.msg.dops_dep_a.tow, expected "
                  "407153000, is %d",
                  last_msg.msg.dops_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.vdop == 113,
        "incorrect value for last_msg.msg.dops_dep_a.vdop, expected 113, is %d",
        last_msg.msg.dops_dep_a.vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x206, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6,  2, 195, 4, 14,  80, 173, 68, 24, 92,
        1,  55, 1, 155, 0, 125, 2,  112, 0,  30, 6,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops_dep_a.gdop = 348;

    test_msg.dops_dep_a.hdop = 637;

    test_msg.dops_dep_a.pdop = 311;

    test_msg.dops_dep_a.tdop = 155;

    test_msg.dops_dep_a.tow = 407154000;

    test_msg.dops_dep_a.vdop = 112;

    sbp_message_send(&sbp_state, SbpMsgDopsDepA, 1219, &test_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgDopsDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.dops_dep_a.gdop == 348,
        "incorrect value for last_msg.msg.dops_dep_a.gdop, expected 348, is %d",
        last_msg.msg.dops_dep_a.gdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.hdop == 637,
        "incorrect value for last_msg.msg.dops_dep_a.hdop, expected 637, is %d",
        last_msg.msg.dops_dep_a.hdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.pdop == 311,
        "incorrect value for last_msg.msg.dops_dep_a.pdop, expected 311, is %d",
        last_msg.msg.dops_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tdop == 155,
        "incorrect value for last_msg.msg.dops_dep_a.tdop, expected 155, is %d",
        last_msg.msg.dops_dep_a.tdop);

    ck_assert_msg(last_msg.msg.dops_dep_a.tow == 407154000,
                  "incorrect value for last_msg.msg.dops_dep_a.tow, expected "
                  "407154000, is %d",
                  last_msg.msg.dops_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.vdop == 112,
        "incorrect value for last_msg.msg.dops_dep_a.vdop, expected 112, is %d",
        last_msg.msg.dops_dep_a.vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x206, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6,  2, 195, 4, 14,  56, 177, 68, 24, 92,
        1,  55, 1, 155, 0, 125, 2,  112, 0,  70, 67,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops_dep_a.gdop = 348;

    test_msg.dops_dep_a.hdop = 637;

    test_msg.dops_dep_a.pdop = 311;

    test_msg.dops_dep_a.tdop = 155;

    test_msg.dops_dep_a.tow = 407155000;

    test_msg.dops_dep_a.vdop = 112;

    sbp_message_send(&sbp_state, SbpMsgDopsDepA, 1219, &test_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgDopsDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.dops_dep_a.gdop == 348,
        "incorrect value for last_msg.msg.dops_dep_a.gdop, expected 348, is %d",
        last_msg.msg.dops_dep_a.gdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.hdop == 637,
        "incorrect value for last_msg.msg.dops_dep_a.hdop, expected 637, is %d",
        last_msg.msg.dops_dep_a.hdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.pdop == 311,
        "incorrect value for last_msg.msg.dops_dep_a.pdop, expected 311, is %d",
        last_msg.msg.dops_dep_a.pdop);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.tdop == 155,
        "incorrect value for last_msg.msg.dops_dep_a.tdop, expected 155, is %d",
        last_msg.msg.dops_dep_a.tdop);

    ck_assert_msg(last_msg.msg.dops_dep_a.tow == 407155000,
                  "incorrect value for last_msg.msg.dops_dep_a.tow, expected "
                  "407155000, is %d",
                  last_msg.msg.dops_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.dops_dep_a.vdop == 112,
        "incorrect value for last_msg.msg.dops_dep_a.vdop, expected 112, is %d",
        last_msg.msg.dops_dep_a.vdop);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgDopsDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgDopsDepA");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgDopsDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgDopsDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}