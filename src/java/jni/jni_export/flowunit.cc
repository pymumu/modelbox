
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

#include <modelbox/base/log.h>
#include <modelbox/flowunit.h>

#include <memory>

#include "com_modelbox_FlowUnit.h"
#include "jni_native_object.h"
#include "scoped_jvm.h"
#include "throw.h"
#include "utils.h"

class JavaFlowUnit : public modelbox::FlowUnit {
 public:
  JavaFlowUnit() = default;

  modelbox::Status JavaInit(JNIEnv *env, jobject j_flowunit) {
    if (env == nullptr) {
      std::string errmsg = "invalid env";
      return {modelbox::STATUS_INVALID, errmsg};
    }

    jclass cls = env->GetObjectClass(j_flowunit);
    if (cls == nullptr) {
      std::string errmsg = "get object class failed.";
      return {modelbox::STATUS_INVALID, errmsg};
    }
    Defer { env->DeleteLocalRef(cls); };

    open_method_id_ = env->GetMethodID(
        cls, "open", "(Lcom/modelbox/Configuration;)Lcom/modelbox/Status;");
    if (open_method_id_ == nullptr) {
      std::string errmsg = "get method id failed.";
      return {modelbox::STATUS_INVALID, errmsg};
    }

    close_method_id_ =
        env->GetMethodID(cls, "close", "()Lcom/modelbox/Status;");
    if (close_method_id_ == nullptr) {
      std::string errmsg = "get method id failed.";
      return {modelbox::STATUS_INVALID, errmsg};
    }

    process_method_id_ = env->GetMethodID(
        cls, "process", "(Lcom/modelbox/DataContext;)Lcom/modelbox/Status;");
    if (process_method_id_ == nullptr) {
      std::string errmsg = "get method id failed.";
      return {modelbox::STATUS_INVALID, errmsg};
    }

    data_pre_method_id_ = env->GetMethodID(
        cls, "dataPre", "(Lcom/modelbox/DataContext;)Lcom/modelbox/Status;");
    if (data_pre_method_id_ == nullptr) {
      std::string errmsg = "get method id failed.";
      return {modelbox::STATUS_INVALID, errmsg};
    }

    data_post_method_id_ = env->GetMethodID(
        cls, "dataPost", "(Lcom/modelbox/DataContext;)Lcom/modelbox/Status;");
    if (data_post_method_id_ == nullptr) {
      std::string errmsg = "get method id failed.";
      return {modelbox::STATUS_INVALID, errmsg};
    }

    j_flowunit_ = env->NewGlobalRef(j_flowunit);

    return modelbox::STATUS_SUCCESS;
  }

  ~JavaFlowUnit() override {
    modelbox::ScopedJvm scope;
    auto *env = scope.GetJNIEnv();
    if (env == nullptr) {
      return;
    }

    if (j_flowunit_ == nullptr) {
      return;
    }

    env->DeleteGlobalRef(j_flowunit_);
  }

  modelbox::Status Open(
      const std::shared_ptr<modelbox::Configuration> &config) override {
    modelbox::ScopedJvm scope;
    auto *env = scope.GetJNIEnv();
    if (env == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get JNIEnv"};
    }

    auto *j_config = modelbox::JNINativeObject::NewJObject(
        env, "com/modelbox/Configuration", config);
    if (j_config == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to create Configuration"};
    }

    auto *j_status =
        env->CallObjectMethod(j_flowunit_, open_method_id_, j_config);
    if (j_status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to call open"};
    }

    auto status =
        modelbox::JNINativeObject::GetNativeSharedPtr<modelbox::Status>(
            env, j_status);
    if (status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get Status"};
    }

    return *status;
  }

  modelbox::Status Process(
      std::shared_ptr<modelbox::DataContext> data_ctx) override {
    modelbox::ScopedJvm scope;
    auto *env = scope.GetJNIEnv();
    if (env == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get JNIEnv"};
    }

    auto *j_data_ctx = modelbox::JNINativeObject::NewJObject(
        env, "com/modelbox/DataContext", data_ctx);
    if (j_data_ctx == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to create DataContext"};
    }

    auto *j_status =
        env->CallObjectMethod(j_flowunit_, process_method_id_, j_data_ctx);
    if (j_status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to call process"};
    }

    auto status =
        modelbox::JNINativeObject::GetNativeSharedPtr<modelbox::Status>(
            env, j_status);
    if (status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get Status"};
    }

    return *status;
  }

  modelbox::Status Close() override {
    modelbox::ScopedJvm scope;
    auto *env = scope.GetJNIEnv();
    if (env == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get JNIEnv"};
    }

    auto *j_status = env->CallObjectMethod(j_flowunit_, close_method_id_);
    if (j_status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to call close"};
    }

    auto status =
        modelbox::JNINativeObject::GetNativeSharedPtr<modelbox::Status>(
            env, j_status);
    if (status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get Status"};
    }

    return *status;
  }

  modelbox::Status DataPre(
      std::shared_ptr<modelbox::DataContext> data_ctx) override {
    modelbox::ScopedJvm scope;
    auto *env = scope.GetJNIEnv();
    if (env == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get JNIEnv"};
    }

    auto *j_data_ctx = modelbox::JNINativeObject::NewJObject(
        env, "com/modelbox/DataContext", data_ctx);
    if (j_data_ctx == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to create DataContext"};
    }

    auto *j_status =
        env->CallObjectMethod(j_flowunit_, data_pre_method_id_, j_data_ctx);
    if (j_status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to call data pre process"};
    }

    auto status =
        modelbox::JNINativeObject::GetNativeSharedPtr<modelbox::Status>(
            env, j_status);
    if (status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get Status"};
    }

    return *status;
  }

  modelbox::Status DataPost(
      std::shared_ptr<modelbox::DataContext> data_ctx) override {
    modelbox::ScopedJvm scope;
    auto *env = scope.GetJNIEnv();
    if (env == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get JNIEnv"};
    }

    auto *j_data_ctx = modelbox::JNINativeObject::NewJObject(
        env, "com/modelbox/DataContext", data_ctx);
    if (j_data_ctx == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to create DataContext"};
    }

    auto *j_status =
        env->CallObjectMethod(j_flowunit_, data_post_method_id_, j_data_ctx);
    if (j_status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to call data post process"};
    }

    auto status =
        modelbox::JNINativeObject::GetNativeSharedPtr<modelbox::Status>(
            env, j_status);
    if (status == nullptr) {
      return {modelbox::STATUS_INVALID, "Failed to get Status"};
    }

    return *status;
  }

 private:
  jobject j_flowunit_{nullptr};
  jmethodID open_method_id_{nullptr};
  jmethodID process_method_id_{nullptr};
  jmethodID close_method_id_{nullptr};
  jmethodID data_pre_method_id_{nullptr};
  jmethodID data_post_method_id_{nullptr};
};

/*
 * Class:     com_modelbox_FlowUnit
 * Method:    FlowUnit_New
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_com_modelbox_FlowUnit_FlowUnit_1New(JNIEnv *env, jobject j_this) {
  auto n_flowunit = std::make_shared<JavaFlowUnit>();
  auto ret = n_flowunit->JavaInit(env, j_this);
  if (!ret) {
    modelbox::ModelBoxJNIThrow(env, ret);
    return 0;
  }

  return modelbox::JNINativeObject::NewHandle(j_this, n_flowunit);
}
