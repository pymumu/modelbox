/*
 * Copyright 2021 The Modelbox Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.modelbox;

import java.util.HashMap;

/**
 * FlowUnitOption
 */
public class FlowUnitOption extends NativeObject {
    public FlowUnitOption(String name, String type) {
        setNativeHandle(FlowUnitOptionNew(name, type));
    }

    public FlowUnitOption(String name, String type, boolean require) {
        setNativeHandle(FlowUnitOptionNew(name, type, require));
    }

    FlowUnitOption(String name, String type, boolean require, String default_value, String desc,
            HashMap<String, String> values) {
        setNativeHandle(FlowUnitOptionNew(name, type, require, default_value, desc, values));
    }

    FlowUnitOption(String name, String type, boolean require, String default_value, String desc) {
        setNativeHandle(FlowUnitOptionNew(name, type, require, default_value, desc));
    }

    public void SetOptionName(String option_name) {
        FlowUnitOption_SetOptionName(option_name);
    }

    public void SetOptionType(String option_type) {
        FlowUnitOption_SetOptionType(option_type);
    }

    public void SetOptionRequire(boolean option_require) {
        FlowUnitOption_SetOptionRequire(option_require);
    }

    public void SetOptionDesc(String option_desc) {
        FlowUnitOption_SetOptionDesc(option_desc);
    }

    public void AddOptionValue(String key, String value) {
        FlowUnitOption_AddOptionValue(key, value);
    }

    public String GetOptionName() {
        return FlowUnitOption_GetOptionName();
    }

    public String GetOptionType() {
        return FlowUnitOption_GetOptionType();
    }

    public boolean IsRequire() {
        return FlowUnitOption_IsRequire();
    }

    public String GetOptionDefault() {
        return FlowUnitOption_GetOptionDefault();
    }

    public String GetOptionDesc() {
        return FlowUnitOption_GetOptionDesc();
    }

    public HashMap<String, String> GetOptionValues() {
        return FlowUnitOption_GetOptionValues();
    }

    public String GetOptionValue(String key) {
        return FlowUnitOption_GetOptionValue(key);
    }

    private native long FlowUnitOptionNew(String name, String type);

    private native long FlowUnitOptionNew(String name, String type, boolean require);

    private native long FlowUnitOptionNew(String name, String type, boolean require,
            String default_value, String desc, HashMap<String, String> values);

    private native long FlowUnitOptionNew(String name, String type, boolean require,
            String default_value, String desc);

    private native void FlowUnitOption_SetOptionName(String option_name);

    private native void FlowUnitOption_SetOptionType(String option_type);

    private native void FlowUnitOption_SetOptionRequire(boolean option_require);

    private native void FlowUnitOption_SetOptionDesc(String option_desc);

    private native void FlowUnitOption_AddOptionValue(String key, String value);

    private native String FlowUnitOption_GetOptionName();

    private native String FlowUnitOption_GetOptionType();

    private native boolean FlowUnitOption_IsRequire();

    private native String FlowUnitOption_GetOptionDefault();

    private native String FlowUnitOption_GetOptionDesc();

    private native HashMap<String, String> FlowUnitOption_GetOptionValues();

    private native String FlowUnitOption_GetOptionValue(String key);
}
