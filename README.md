# AnalogKeys

Library used to read Keys connected to an analog input pin via a resistor network.

The `AnalogKey` class is made to transform an analog value into a proper value beloning to a certain key.  
Therfor it supports 5 Buttons / 6 States within an enum type `KeyValues`:

0. NONE = 0
1. UP = 1
2. DOWN = 2
3. LEFT = 3
4. RIGHT = 4
5. SELECT = 10

See [AnalogKeys](https://github.com/RedCali/AnalogKeys.git) for more detailed information on how to use AnalogKeys

## Open topics / Ideas

- [ ] Documentation of Methods

## Include the Library in your project

To include the Library in your project you need to install it and include the `AnalogKeys.h` header into your project.

```cpp
// Include Library
#include <AnalogKeys.h>
```

Instantiate an object of the LCD

```cpp
AnalogKeys<720,730, 0,10, 480,490, 130,140, 310,320, false> analogKey;
```

Reading the Key value:

```cpp
analogKey.Read(analogeValue);
```

Get a string rely on to the button selected:

```cpp
analogKey.GetString(y);
```

Depending on the resistor network you have chosen and the order of buttons, the Library is configurable within the value ranges using C++ Class template.

```cpp
AnalogKeys<
  720, // int ANL_SELECT_Lower,
  730, // int ANL_SELECT_Upper,
    0, // int ANL_RIGHT_Lower,
   10, // int ANL_RIGHT_Upper,
  480, // int ANL_LEFT_Lower,
  490, // int ANL_LEFT_Upper,
  130, // int ANL_UP_Lower,
  140, // int ANL_UP_Upper,
  310, // int ANL_DOWN_Lower,
  320, // int ANL_DOWN_Upper,
 false // Bool: TRUE: returnEmptyString if no button is preset, FALSE: return "none"
   > analogKey;
```

## Using with different IDE'S

### Arduino

The easiest way to get started on the Arduino Platform is, to use an example project like `AnalogKeys`, as there is already included the `AnalogKeys.h` file.

### PlatformIO

To include the Library in your PlatformIO project, you need simply to add it to your `platformio.ini`:

```yaml
lib_deps =
    https://github.com/RedCali/AnalogKeys.git
```
