/* Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.test;

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgThreadState.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgThreadState;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgThreadStateTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 109,
                    (byte) 97,
                    (byte) 105,
                    (byte) 110,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 156,
                    (byte) 9,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "main                ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 2460 + "'",
                    value.equals(BigInteger.valueOf(2460L)));
        } else {
            value = value.longValue();
            expected = 2460L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 105,
                    (byte) 100,
                    (byte) 108,
                    (byte) 101,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 83,
                    (byte) 2,
                    (byte) 36,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 595 + "'", value.equals(BigInteger.valueOf(595L)));
        } else {
            value = value.longValue();
            expected = 595L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "idle                ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 78,
                    (byte) 65,
                    (byte) 80,
                    (byte) 32,
                    (byte) 73,
                    (byte) 83,
                    (byte) 82,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 14,
                    (byte) 0,
                    (byte) 116,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 14 + "'", value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "NAP ISR             ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 1140 + "'",
                    value.equals(BigInteger.valueOf(1140L)));
        } else {
            value = value.longValue();
            expected = 1140L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 83,
                    (byte) 66,
                    (byte) 80,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 196,
                    (byte) 19,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "SBP                 ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 5060 + "'",
                    value.equals(BigInteger.valueOf(5060L)));
        } else {
            value = value.longValue();
            expected = 5060L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 109,
                    (byte) 97,
                    (byte) 110,
                    (byte) 97,
                    (byte) 103,
                    (byte) 101,
                    (byte) 32,
                    (byte) 97,
                    (byte) 99,
                    (byte) 113,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 7,
                    (byte) 0,
                    (byte) 20,
                    (byte) 9,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 7 + "'", value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "manage acq          ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 2324 + "'",
                    value.equals(BigInteger.valueOf(2324L)));
        } else {
            value = value.longValue();
            expected = 2324L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test6() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 109,
                    (byte) 97,
                    (byte) 105,
                    (byte) 110,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 148,
                    (byte) 9,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "main                ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 2452 + "'",
                    value.equals(BigInteger.valueOf(2452L)));
        } else {
            value = value.longValue();
            expected = 2452L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test7() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test7");
        byte[] payload =
                new byte[] {
                    (byte) 105,
                    (byte) 100,
                    (byte) 108,
                    (byte) 101,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 228,
                    (byte) 1,
                    (byte) 36,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 484 + "'", value.equals(BigInteger.valueOf(484L)));
        } else {
            value = value.longValue();
            expected = 484L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "idle                ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test8() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test8");
        byte[] payload =
                new byte[] {
                    (byte) 78,
                    (byte) 65,
                    (byte) 80,
                    (byte) 32,
                    (byte) 73,
                    (byte) 83,
                    (byte) 82,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 138,
                    (byte) 1,
                    (byte) 92,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 394 + "'", value.equals(BigInteger.valueOf(394L)));
        } else {
            value = value.longValue();
            expected = 394L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "NAP ISR             ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 1884 + "'",
                    value.equals(BigInteger.valueOf(1884L)));
        } else {
            value = value.longValue();
            expected = 1884L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test9() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test9");
        byte[] payload =
                new byte[] {
                    (byte) 83, (byte) 66, (byte) 80, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 1, (byte) 0, (byte) 4,
                    (byte) 12, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "SBP                 ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 3076 + "'",
                    value.equals(BigInteger.valueOf(3076L)));
        } else {
            value = value.longValue();
            expected = 3076L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test10() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test10");
        byte[] payload =
                new byte[] {
                    (byte) 109,
                    (byte) 97,
                    (byte) 110,
                    (byte) 97,
                    (byte) 103,
                    (byte) 101,
                    (byte) 32,
                    (byte) 97,
                    (byte) 99,
                    (byte) 113,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 10,
                    (byte) 0,
                    (byte) 124,
                    (byte) 9,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 10 + "'", value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "manage acq          ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 2428 + "'",
                    value.equals(BigInteger.valueOf(2428L)));
        } else {
            value = value.longValue();
            expected = 2428L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test11() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgThreadStateTest.test11");
        byte[] payload =
                new byte[] {
                    (byte) 109,
                    (byte) 97,
                    (byte) 110,
                    (byte) 97,
                    (byte) 103,
                    (byte) 101,
                    (byte) 32,
                    (byte) 116,
                    (byte) 114,
                    (byte) 97,
                    (byte) 99,
                    (byte) 107,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 28,
                    (byte) 9,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x17, payload);
        MsgThreadState msg = new MsgThreadState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cpu + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "manage track        ");
        value = msg.stack_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_free + "' != '" + 2332 + "'",
                    value.equals(BigInteger.valueOf(2332L)));
        } else {
            value = value.longValue();
            expected = 2332L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
