
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

#include "com_modelbox_FlowUnitOption.h"
#include "jni_native_object.h"
#include "scoped_jvm.h"
#include "throw.h"
#include "utils.h"

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOptionNew
 * Signature: (Ljava/lang/String;Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOptionNew__Ljava_lang_String_2Ljava_lang_String_2(
    JNIEnv *env, jobject j_this, jstring j_name, jstring j_type) {
  return 0;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOptionNew
 * Signature: (Ljava/lang/String;Ljava/lang/String;Z)J
 */
JNIEXPORT jlong JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOptionNew__Ljava_lang_String_2Ljava_lang_String_2Z(
    JNIEnv *env, jobject j_this, jstring j_name, jstring j_type,
    jboolean j_required) {
  return 0;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOptionNew
 * Signature:
 * (Ljava/lang/String;Ljava/lang/String;ZLjava/lang/String;Ljava/lang/String;Ljava/util/HashMap;)J
 */
JNIEXPORT jlong JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOptionNew__Ljava_lang_String_2Ljava_lang_String_2ZLjava_lang_String_2Ljava_lang_String_2Ljava_util_HashMap_2(
    JNIEnv *env, jobject j_this, jstring j_name, jstring j_type,
    jboolean j_required, jstring j_default_value, jstring j_desc,
    jobject j_values) {
  return 0;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOptionNew
 * Signature:
 * (Ljava/lang/String;Ljava/lang/String;ZLjava/lang/String;Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOptionNew__Ljava_lang_String_2Ljava_lang_String_2ZLjava_lang_String_2Ljava_lang_String_2(
    JNIEnv *env, jobject j_this, jstring /*unused*/, jstring /*unused*/,
    jboolean /*unused*/, jstring /*unused*/, jstring /*unused*/) {
  return 0;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_SetOptionName
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1SetOptionName(JNIEnv *env,
                                                               jobject j_this,
                                                               jstring j_name) {

}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_SetOptionType
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1SetOptionType(
    JNIEnv *env, jobject j_this, jstring /*unused*/) {}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_SetOptionRequire
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1SetOptionRequire(
    JNIEnv *env, jobject j_this, jboolean /*unused*/) {}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_SetOptionDesc
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1SetOptionDesc(
    JNIEnv *env, jobject j_this, jstring /*unused*/) {}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_AddOptionValue
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1AddOptionValue(
    JNIEnv *env, jobject j_this, jstring /*unused*/, jstring /*unused*/) {}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_GetOptionName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1GetOptionName(JNIEnv *env,
                                                               jobject j_this) {
  return nullptr;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_GetOptionType
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1GetOptionType(JNIEnv *env,
                                                               jobject j_this) {
  return nullptr;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_IsRequire
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1IsRequire(JNIEnv *env,
                                                           jobject j_this) {
  return false;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_GetOptionDefault
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1GetOptionDefault(
    JNIEnv *env, jobject j_this) {
  return nullptr;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_GetOptionDesc
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1GetOptionDesc(JNIEnv *env,
                                                               jobject j_this) {
  return nullptr;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_GetOptionValues
 * Signature: ()Ljava/util/HashMap;
 */
JNIEXPORT jobject JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1GetOptionValues(
    JNIEnv *env, jobject j_this) {
  return nullptr;
}

/*
 * Class:     com_modelbox_FlowUnitOption
 * Method:    FlowUnitOption_GetOptionValue
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
Java_com_modelbox_FlowUnitOption_FlowUnitOption_1GetOptionValue(
    JNIEnv *env, jobject j_this, jstring /*unused*/) {
  return nullptr;
}
