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


#include <stdint.h>
#include "cuda_runtime.h"

void NormalizeAndCHW(const uint8_t *in_batch, int N, int H, int W, int C,
                     const float *mean, const float *inv_std, float *out_batch,
                     cudaStream_t stream);

void Normalize(const uint8_t *in_batch, int N, int H, int W, int C,
               const float *mean, const float *inv_std, float *out_batch,
               cudaStream_t stream);