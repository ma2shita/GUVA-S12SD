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
#ifndef _GUVA-S12SD_h
#define _GUVA-S12SD_h
#include "arduino.h"

class GUVAS12SD
{
  public:
    GUVAS12SD(int connectedPinNo, float workingVoltage = 5.0, int samplingCount = 1000);
  public:
    float read();
    float index(float read_mV);
  private:
    int port, s;
    float v;
};

#endif
