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

/**
 * Flowunit Builder
 */
public class FlowUnitDesc extends NativeObject {
    public enum FlowOutputType {
        ORIGIN, EXPAND, COLLAPSE,
    }

    public enum FlowType {
        STREAM, NORMAL,
    }

    public enum ConditionType {
        NONE, IF_ELSE,
    }

    public enum LoopType {
        NOT_LOOP, LOOP,
    }

    public FlowUnitDesc() {
        setNativeHandle(FlowUnitDescNew());
    }

    public String GetFlowUnitName() {
        return FlowUnitDescGetFlowUnitName();
    }

    public String GetFlowUnitType() {
        return FlowUnitDescGetFlowUnitType();
    }

    public String GetFlowUnitAliasName() {
        return FlowUnitDescGetFlowUnitAliasName();
    }

    public String GetFlowUnitArgument() {
        return FlowUnitDescGetFlowUnitArgument();
    }

    public void SetFlowUnitName(String flowunit_name) {
        FlowUnitDescSetFlowUnitName(flowunit_name);
    }

    public void SetFlowUnitType(String flowunit_type) {
        FlowUnitDescSetFlowUnitType(flowunit_type);
    }

    public Status AddFlowUnitInput(FlowUnitInput flowunit_input) {
        return FlowUnitDescAddFlowUnitInput(flowunit_input);
    }

    public Status AddFlowUnitOutput(FlowUnitOutput flowunit_output) {
        return FlowUnitDescAddFlowUnitOutput(flowunit_output);
    }

    public Status AddFlowUnitOption(FlowUnitOption flowunit_option) {
        return FlowUnitDescAddFlowUnitOption(flowunit_option);
    }

    public void SetConditionType(ConditionType condition_type) {
        FlowUnitDescSetConditionType(condition_type.ordinal());
    }

    public void SetLoopType(LoopType loop_type) {
        FlowUnitDescSetLoopType(loop_type.ordinal());
    }

    public void SetOutputType(FlowOutputType output_type) {
        FlowUnitDescSetOutputType(output_type.ordinal());
    }

    public void SetFlowType(FlowType flow_type) {
        FlowUnitDescSetFlowType(flow_type.ordinal());
    }

    public void SetStreamSameCount(boolean is_stream_same_count) {
        FlowUnitDescSetStreamSameCount(is_stream_same_count);
    }

    public void SetInputContiguous(boolean is_input_contiguous) {
        FlowUnitDescSetInputContiguous(is_input_contiguous);
    }

    public void SetResourceNice(boolean is_resource_nice) {
        FlowUnitDescSetResourceNice(is_resource_nice);
    }

    public void SetCollapseAll(boolean is_collapse_all) {
        FlowUnitDescSetCollapseAll(is_collapse_all);
    }

    public void SetExceptionVisible(boolean is_exception_visible) {
        FlowUnitDescSetExceptionVisible(is_exception_visible);
    }

    public void SetDescription(String description) {
        FlowUnitDescSetDescription(description);
    }

    public void SetMaxBatchSize(long max_batch_size) {
        FlowUnitDescSetMaxBatchSize(max_batch_size);
    }

    public void SetDefaultBatchSize(long default_batch_size) {
        FlowUnitDescSetDefaultBatchSize(default_batch_size);
    }

    private native long FlowUnitDescNew();

    private native String FlowUnitDescGetFlowUnitName();

    private native String FlowUnitDescGetFlowUnitType();

    private native String FlowUnitDescGetFlowUnitAliasName();

    private native String FlowUnitDescGetFlowUnitArgument();

    private native void FlowUnitDescSetFlowUnitName(String flowunit_name);

    private native void FlowUnitDescSetFlowUnitType(String flowunit_type);

    private native Status FlowUnitDescAddFlowUnitInput(FlowUnitInput flowunit_input);

    private native Status FlowUnitDescAddFlowUnitOutput(FlowUnitOutput flowunit_output);

    private native Status FlowUnitDescAddFlowUnitOption(FlowUnitOption flowunit_option);

    private native void FlowUnitDescSetConditionType(long condition_type);

    private native void FlowUnitDescSetLoopType(long loop_type);

    private native void FlowUnitDescSetOutputType(long output_type);

    private native void FlowUnitDescSetFlowType(long flow_type);

    private native void FlowUnitDescSetStreamSameCount(boolean is_stream_same_count);

    private native void FlowUnitDescSetInputContiguous(boolean is_input_contiguous);

    private native void FlowUnitDescSetResourceNice(boolean is_resource_nice);

    private native void FlowUnitDescSetCollapseAll(boolean is_collapse_all);

    private native void FlowUnitDescSetExceptionVisible(boolean is_exception_visible);

    private native void FlowUnitDescSetDescription(String description);

    private native void FlowUnitDescSetMaxBatchSize(long max_batch_size);

    private native void FlowUnitDescSetDefaultBatchSize(long default_batch_size);
}
