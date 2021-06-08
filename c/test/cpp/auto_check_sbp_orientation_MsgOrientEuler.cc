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
// spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientEuler.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_handler.h>
#include <libsbp/legacy/cpp/message_traits.h>
class Test_auto_check_sbp_orientation_MsgOrientEuler0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_orient_euler_t> {
 public:
  Test_auto_check_sbp_orientation_MsgOrientEuler0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_orient_euler_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_orient_euler_t *>(last_msg_storage_)),
        last_msg_len_(),
        last_sender_id_(),
        n_callbacks_logged_(),
        dummy_wr_(),
        dummy_rd_(),
        dummy_buff_() {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    dummy_rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(dummy_buff_ + dummy_wr_, buf, real_n);
    dummy_wr_ += real_n;
    return (s32)real_n;
  }

 protected:
  void handle_sbp_msg(uint16_t sender_id, uint8_t message_length,
                      const msg_orient_euler_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_orient_euler_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_orientation_MsgOrientEuler0, Test) {
  uint8_t encoded_frame[] = {
      85, 33, 2, 66, 0, 29,  1,  0, 0, 0,  1,  0, 0, 0,   2,  0, 0,  0,   8,
      0,  0,  0, 0,  0, 224, 64, 0, 0, 64, 64, 0, 0, 224, 64, 3, 44, 226,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_orient_euler_t *test_msg = (msg_orient_euler_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 3;
  test_msg->pitch = 2;
  test_msg->pitch_accuracy = 3.0;
  test_msg->roll = 1;
  test_msg->roll_accuracy = 7.0;
  test_msg->tow = 1;
  test_msg->yaw = 8;
  test_msg->yaw_accuracy = 7.0;

  EXPECT_EQ(send_message(0x221, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 3)
      << "incorrect value for flags, expected 3, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->pitch, 2)
      << "incorrect value for pitch, expected 2, is " << last_msg_->pitch;
  EXPECT_LT((last_msg_->pitch_accuracy * 100 - 3.0 * 100), 0.05)
      << "incorrect value for pitch_accuracy, expected 3.0, is "
      << last_msg_->pitch_accuracy;
  EXPECT_EQ(last_msg_->roll, 1)
      << "incorrect value for roll, expected 1, is " << last_msg_->roll;
  EXPECT_LT((last_msg_->roll_accuracy * 100 - 7.0 * 100), 0.05)
      << "incorrect value for roll_accuracy, expected 7.0, is "
      << last_msg_->roll_accuracy;
  EXPECT_EQ(last_msg_->tow, 1)
      << "incorrect value for tow, expected 1, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->yaw, 8)
      << "incorrect value for yaw, expected 8, is " << last_msg_->yaw;
  EXPECT_LT((last_msg_->yaw_accuracy * 100 - 7.0 * 100), 0.05)
      << "incorrect value for yaw_accuracy, expected 7.0, is "
      << last_msg_->yaw_accuracy;
}
