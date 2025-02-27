//
// Copyright (C) 2019-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkBandwidthUsage.yaml by generate.py. Do not modify by hand!

use crate::*;

#[test]
fn test_auto_check_sbp_piksi_msg_network_bandwidth_usage() {
    {
        let mut payload = Cursor::new(vec![
            85, 189, 0, 207, 121, 200, 94, 105, 178, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 99, 97, 110, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 105, 178,
            128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 97, 110, 49, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 105, 178, 128, 0, 0, 0, 0, 165, 235, 94, 203, 0, 0,
            0, 0, 237, 14, 148, 240, 184, 220, 202, 218, 101, 116, 104, 48, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 94, 105, 178, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 108, 111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 105, 178, 128, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 105, 116, 48, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 27, 133,
        ]);

        // Test the round trip payload parsing
        let sbp_msg = {
            let mut msgs = iter_messages(&mut payload);
            msgs.next()
                .expect("no message found")
                .expect("failed to parse message")
        };
        match &sbp_msg {
            sbp::messages::Sbp::MsgNetworkBandwidthUsage(msg) => {
                assert_eq!(
                    msg.message_type(),
                    0xBD,
                    "Incorrect message type, expected 0xBD, is {}",
                    msg.message_type()
                );
                let sender_id = msg.sender_id().unwrap();
                assert_eq!(
                    sender_id, 0x79CF,
                    "incorrect sender id, expected 0x79CF, is {}",
                    sender_id
                );
                assert_eq!(
                    msg.interfaces[0].duration, 2159176030,
                    "incorrect value for interfaces[0].duration, expected 2159176030, is {}",
                    msg.interfaces[0].duration
                );
                assert_eq!(msg.interfaces[0].interface_name.to_string(), "can0            ".to_string(), "incorrect value for msg.interfaces[0].interface_name, expected string '{}', is '{}'", "can0            ".to_string(), msg.interfaces[0].interface_name);
                assert_eq!(
                    msg.interfaces[0].rx_bytes, 0,
                    "incorrect value for interfaces[0].rx_bytes, expected 0, is {}",
                    msg.interfaces[0].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[0].total_bytes, 0,
                    "incorrect value for interfaces[0].total_bytes, expected 0, is {}",
                    msg.interfaces[0].total_bytes
                );
                assert_eq!(
                    msg.interfaces[0].tx_bytes, 0,
                    "incorrect value for interfaces[0].tx_bytes, expected 0, is {}",
                    msg.interfaces[0].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[1].duration, 2159176030,
                    "incorrect value for interfaces[1].duration, expected 2159176030, is {}",
                    msg.interfaces[1].duration
                );
                assert_eq!(msg.interfaces[1].interface_name.to_string(), "can1            ".to_string(), "incorrect value for msg.interfaces[1].interface_name, expected string '{}', is '{}'", "can1            ".to_string(), msg.interfaces[1].interface_name);
                assert_eq!(
                    msg.interfaces[1].rx_bytes, 0,
                    "incorrect value for interfaces[1].rx_bytes, expected 0, is {}",
                    msg.interfaces[1].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[1].total_bytes, 0,
                    "incorrect value for interfaces[1].total_bytes, expected 0, is {}",
                    msg.interfaces[1].total_bytes
                );
                assert_eq!(
                    msg.interfaces[1].tx_bytes, 0,
                    "incorrect value for interfaces[1].tx_bytes, expected 0, is {}",
                    msg.interfaces[1].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[2].duration, 2159176030,
                    "incorrect value for interfaces[2].duration, expected 2159176030, is {}",
                    msg.interfaces[2].duration
                );
                assert_eq!(msg.interfaces[2].interface_name.to_string(), "eth0            ".to_string(), "incorrect value for msg.interfaces[2].interface_name, expected string '{}', is '{}'", "eth0            ".to_string(), msg.interfaces[2].interface_name);
                assert_eq!(
                    msg.interfaces[2].rx_bytes, 4036234989,
                    "incorrect value for interfaces[2].rx_bytes, expected 4036234989, is {}",
                    msg.interfaces[2].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[2].total_bytes, 3411995557,
                    "incorrect value for interfaces[2].total_bytes, expected 3411995557, is {}",
                    msg.interfaces[2].total_bytes
                );
                assert_eq!(
                    msg.interfaces[2].tx_bytes, 3670727864,
                    "incorrect value for interfaces[2].tx_bytes, expected 3670727864, is {}",
                    msg.interfaces[2].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[3].duration, 2159176030,
                    "incorrect value for interfaces[3].duration, expected 2159176030, is {}",
                    msg.interfaces[3].duration
                );
                assert_eq!(msg.interfaces[3].interface_name.to_string(), "lo              ".to_string(), "incorrect value for msg.interfaces[3].interface_name, expected string '{}', is '{}'", "lo              ".to_string(), msg.interfaces[3].interface_name);
                assert_eq!(
                    msg.interfaces[3].rx_bytes, 0,
                    "incorrect value for interfaces[3].rx_bytes, expected 0, is {}",
                    msg.interfaces[3].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[3].total_bytes, 0,
                    "incorrect value for interfaces[3].total_bytes, expected 0, is {}",
                    msg.interfaces[3].total_bytes
                );
                assert_eq!(
                    msg.interfaces[3].tx_bytes, 0,
                    "incorrect value for interfaces[3].tx_bytes, expected 0, is {}",
                    msg.interfaces[3].tx_bytes
                );
                assert_eq!(
                    msg.interfaces[4].duration, 2159176030,
                    "incorrect value for interfaces[4].duration, expected 2159176030, is {}",
                    msg.interfaces[4].duration
                );
                assert_eq!(msg.interfaces[4].interface_name.to_string(), "sit0            ".to_string(), "incorrect value for msg.interfaces[4].interface_name, expected string '{}', is '{}'", "sit0            ".to_string(), msg.interfaces[4].interface_name);
                assert_eq!(
                    msg.interfaces[4].rx_bytes, 0,
                    "incorrect value for interfaces[4].rx_bytes, expected 0, is {}",
                    msg.interfaces[4].rx_bytes
                );
                assert_eq!(
                    msg.interfaces[4].total_bytes, 0,
                    "incorrect value for interfaces[4].total_bytes, expected 0, is {}",
                    msg.interfaces[4].total_bytes
                );
                assert_eq!(
                    msg.interfaces[4].tx_bytes, 0,
                    "incorrect value for interfaces[4].tx_bytes, expected 0, is {}",
                    msg.interfaces[4].tx_bytes
                );
            }
            _ => panic!("Invalid message type! Expected a MsgNetworkBandwidthUsage"),
        };
        let frame = sbp::to_vec(&sbp_msg).unwrap();
        assert_eq!(frame, payload.into_inner());
    }
}
