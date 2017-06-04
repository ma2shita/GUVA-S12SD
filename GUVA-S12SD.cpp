/**
 * Copyright 2017 Kohei MATSUSHITA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "arduino.h"
#include "GUVA-S12SD.h"

/* https://github.com/Marzogh/Tricorder/blob/master/Tricorder/GUVAS12SD.ino */

GUVAS12SD::GUVAS12SD(int connectedPinNo, float workingVoltage = 5.0, int samplingCount = 1000)
{
  port = connectedPinNo;
  v = workingVoltage;
  s = samplingCount;
}

float GUVAS12SD::read()
{
  float sum = 0;
  for(int i=0; i<s; i++) {
    float v = analogRead(port);
    sum = v + sum;
    delay(2);
  }
  float sensor_value_average = sum / s;
  float mV = sensor_value_average * v;
  return mV;
}

float GUVAS12SD::index(float read_mV) {
  float voltage = read_mV / 1024.0;
  int uv_index = voltage / 0.1;
  return uv_index;
}
