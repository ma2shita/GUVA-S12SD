# Arduino library for GUVA-S12SD (UV sensor)

GUVA-S12SD is used in [Grove UV sensor](http://wiki.seeed.cc/Grove-UV_Sensor/)

## Getting Started

```arduino
#include <GUVA-S12SD.h>
GUVAS12SD uv(A0);

void setup()
{
    // Nothing TODO
}

void loop()
{
  float mV = uv.read();
  float uv_index = uv.index(mV);
  Serial.println(uv_index);
}
```

## Library Reference

* `GUVAS12SD(int connectedPinNo, float workingVoltage = 5.0, int samplingCount = 1000)` - Constructor
* `float read()` - Return milli voltage by reading GUVA-S12SD
* `float index(float read_mV)` - Calculate UV index from milli voltage

### EPS UV Index

`#index` returns float. As below when you need EPA UV index;

```arduino
  int epa_uv_index = (int) uv.index(uv.read()) + 1;
```

## LICENCE

Apache 2.0

EoT;