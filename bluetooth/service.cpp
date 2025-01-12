//
// Copyright 2016 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#define LOG_TAG "android.hardware.bluetooth@1.1-service.vbt"

#include <android/hardware/bluetooth/1.1/IBluetoothHci.h>
#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>


#include "bluetooth_hci.h"

using ::android::hardware::configureRpcThreadpool;
using ::android::hardware::bluetooth::V1_1::IBluetoothHci;
using ::android::hardware::bluetooth::V1_1::implementation::BluetoothHci;
using ::android::hardware::joinRpcThreadpool;
using ::android::sp;

int main(int /* argc */, char** /* argv */) {
  sp<IBluetoothHci> bluetooth = new BluetoothHci;
  configureRpcThreadpool(1, true);
  bluetooth->registerAsService();
  joinRpcThreadpool();
}
