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
package com.swiftnav.sbp.observation;

// This file was auto-generated from yaml/swiftnav/sbp/observation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).
 *
 * <p>You can have MSG_EPHEMERIS_DEP_B inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgEphemerisDepB extends SBPMessage {
    public static final int TYPE = 0x0046;

    /** Group delay differential between L1 and L2 */
    public double tgd;

    /** Amplitude of the sine harmonic correction term to the orbit radius */
    public double c_rs;

    /** Amplitude of the cosine harmonic correction term to the orbit radius */
    public double c_rc;

    /** Amplitude of the cosine harmonic correction term to the argument of latitude */
    public double c_uc;

    /** Amplitude of the sine harmonic correction term to the argument of latitude */
    public double c_us;

    /** Amplitude of the cosine harmonic correction term to the angle of inclination */
    public double c_ic;

    /** Amplitude of the sine harmonic correction term to the angle of inclination */
    public double c_is;

    /** Mean motion difference */
    public double dn;

    /** Mean anomaly at reference time */
    public double m0;

    /** Eccentricity of satellite orbit */
    public double ecc;

    /** Square root of the semi-major axis of orbit */
    public double sqrta;

    /** Longitude of ascending node of orbit plane at weekly epoch */
    public double omega0;

    /** Rate of right ascension */
    public double omegadot;

    /** Argument of perigee */
    public double w;

    /** Inclination */
    public double inc;

    /** Inclination first derivative */
    public double inc_dot;

    /** Polynomial clock correction coefficient (clock bias) */
    public double af0;

    /** Polynomial clock correction coefficient (clock drift) */
    public double af1;

    /** Polynomial clock correction coefficient (rate of clock drift) */
    public double af2;

    /** Time of week */
    public double toe_tow;

    /** Week number */
    public int toe_wn;

    /** Clock reference time of week */
    public double toc_tow;

    /** Clock reference week number */
    public int toc_wn;

    /** Is valid? */
    public int valid;

    /** Satellite is healthy? */
    public int healthy;

    /** PRN being tracked */
    public int prn;

    /** Issue of ephemeris data */
    public int iode;

    public MsgEphemerisDepB(int sender) {
        super(sender, TYPE);
    }

    public MsgEphemerisDepB() {
        super(TYPE);
    }

    public MsgEphemerisDepB(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tgd = parser.getDouble();
        c_rs = parser.getDouble();
        c_rc = parser.getDouble();
        c_uc = parser.getDouble();
        c_us = parser.getDouble();
        c_ic = parser.getDouble();
        c_is = parser.getDouble();
        dn = parser.getDouble();
        m0 = parser.getDouble();
        ecc = parser.getDouble();
        sqrta = parser.getDouble();
        omega0 = parser.getDouble();
        omegadot = parser.getDouble();
        w = parser.getDouble();
        inc = parser.getDouble();
        inc_dot = parser.getDouble();
        af0 = parser.getDouble();
        af1 = parser.getDouble();
        af2 = parser.getDouble();
        toe_tow = parser.getDouble();
        toe_wn = parser.getU16();
        toc_tow = parser.getDouble();
        toc_wn = parser.getU16();
        valid = parser.getU8();
        healthy = parser.getU8();
        prn = parser.getU8();
        iode = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putDouble(tgd);
        builder.putDouble(c_rs);
        builder.putDouble(c_rc);
        builder.putDouble(c_uc);
        builder.putDouble(c_us);
        builder.putDouble(c_ic);
        builder.putDouble(c_is);
        builder.putDouble(dn);
        builder.putDouble(m0);
        builder.putDouble(ecc);
        builder.putDouble(sqrta);
        builder.putDouble(omega0);
        builder.putDouble(omegadot);
        builder.putDouble(w);
        builder.putDouble(inc);
        builder.putDouble(inc_dot);
        builder.putDouble(af0);
        builder.putDouble(af1);
        builder.putDouble(af2);
        builder.putDouble(toe_tow);
        builder.putU16(toe_wn);
        builder.putDouble(toc_tow);
        builder.putU16(toc_wn);
        builder.putU8(valid);
        builder.putU8(healthy);
        builder.putU8(prn);
        builder.putU8(iode);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tgd", tgd);
        obj.put("c_rs", c_rs);
        obj.put("c_rc", c_rc);
        obj.put("c_uc", c_uc);
        obj.put("c_us", c_us);
        obj.put("c_ic", c_ic);
        obj.put("c_is", c_is);
        obj.put("dn", dn);
        obj.put("m0", m0);
        obj.put("ecc", ecc);
        obj.put("sqrta", sqrta);
        obj.put("omega0", omega0);
        obj.put("omegadot", omegadot);
        obj.put("w", w);
        obj.put("inc", inc);
        obj.put("inc_dot", inc_dot);
        obj.put("af0", af0);
        obj.put("af1", af1);
        obj.put("af2", af2);
        obj.put("toe_tow", toe_tow);
        obj.put("toe_wn", toe_wn);
        obj.put("toc_tow", toc_tow);
        obj.put("toc_wn", toc_wn);
        obj.put("valid", valid);
        obj.put("healthy", healthy);
        obj.put("prn", prn);
        obj.put("iode", iode);
        return obj;
    }
}
