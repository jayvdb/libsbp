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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFGNSS.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgPosECEFGNSS0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_pos_ecef_gnss_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgPosECEFGNSS0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_pos_ecef_gnss_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_pos_ecef_gnss_t *>(last_msg_storage_)),
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
                      const msg_pos_ecef_gnss_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_pos_ecef_gnss_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgPosECEFGNSS0, Test) {
  uint8_t encoded_frame[] = {
      85,  41,  2,   0,   16, 32,  24,  229, 233, 29, 52,  254, 158, 218,
      42,  142, 68,  193, 69, 162, 89,  91,  34,  68, 80,  193, 131, 21,
      176, 129, 239, 174, 77, 65,  182, 0,   18,  4,  135, 2,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_pos_ecef_gnss_t *test_msg = (msg_pos_ecef_gnss_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 182;
  test_msg->flags = 4;
  test_msg->n_sats = 18;
  test_msg->tow = 501867800;
  test_msg->x = -2694229.7079770807;
  test_msg->y = -4264073.427345817;
  test_msg->z = 3890655.013186158;

  EXPECT_EQ(send_message(0x229, 4096, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4096);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 182)
      << "incorrect value for accuracy, expected 182, is "
      << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 4)
      << "incorrect value for flags, expected 4, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 18)
      << "incorrect value for n_sats, expected 18, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 501867800)
      << "incorrect value for tow, expected 501867800, is " << last_msg_->tow;
  EXPECT_LT((last_msg_->x * 100 - -2694229.70798 * 100), 0.05)
      << "incorrect value for x, expected -2694229.70798, is " << last_msg_->x;
  EXPECT_LT((last_msg_->y * 100 - -4264073.42735 * 100), 0.05)
      << "incorrect value for y, expected -4264073.42735, is " << last_msg_->y;
  EXPECT_LT((last_msg_->z * 100 - 3890655.01319 * 100), 0.05)
      << "incorrect value for z, expected 3890655.01319, is " << last_msg_->z;
}
