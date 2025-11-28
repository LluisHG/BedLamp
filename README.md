# BedLamp

An Arduino-based bed lamp controller that cycles through different brightness levels using a push button. Built for ESP8266 using WS2812B LED strips and the FastLED library.

## Features

- **Three brightness levels**: OFF, Low (first 6 LEDs), High (all LEDs)
- **Push button control**: Single button cycles through all states
- **Debounced button handling**: Reliable press detection with software debouncing
- **Diagnostic startup**: LED chase sequence on power-up to verify wiring
- **Warm white lighting**: Configurable color temperature for comfortable bedside illumination
- **VSCode development**: Configured for development in Visual Studio Code with Arduino extension

## Hardware Requirements

- **Microcontroller**: ESP8266 D1 Mini
- **LED Strip**: WS2812B LED strip with 14 LEDs (configurable)
- **Push Button**: Momentary push button (active-low)
- **Power Supply**: 5V DC power supply suitable for your LED strip
- **Connections**:
  - LED data pin → ESP8266 GPIO4 (D2)
  - Button pin → ESP8266 GPIO14 (D5)
  - Power and ground connections

## Software Requirements

- **Arduino IDE** or **Visual Studio Code** with Arduino extension
- **FastLED library** (install via Arduino Library Manager)
- **ESP8266 board support** in Arduino IDE

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/LluisHG/BedLamp.git
   cd BedLamp
   ```

2. **Open in VSCode**:
   - Launch Visual Studio Code
   - Open the BedLamp folder
   - The project is pre-configured with `arduino.json` and `c_cpp_properties.json`

3. **Install dependencies**:
   - Ensure FastLED library is installed in Arduino
   - Verify ESP8266 board package is installed

4. **Configure board**:
   - Board: ESP8266 D1 Mini
   - Port: COM7 (or your ESP8266 port)
   - Flash Frequency: 80MHz
   - Upload Speed: 115200

5. **Upload the sketch**:
   - Use Arduino: Upload command in VSCode (Ctrl+Alt+U)

## Configuration

Edit `config.h` to customize:

- `NUM_LEDS`: Number of LEDs in your strip (default: 14)
- `DATA_PIN`: GPIO pin for LED data (default: 4)
- `BUTTON_PIN`: GPIO pin for button (default: 14)
- `INTENSITY1`/`INTENSITY2`: Brightness levels (0-255)
- `BASE_COLOR`: LED color (default: warm white CRGB(180,160,140))

## Usage

1. **Power on**: The lamp performs a diagnostic LED chase to verify all LEDs are working
2. **Control**: Press the button to cycle through:
   - **OFF**: All LEDs off
   - **Low**: First 6 LEDs on at medium brightness
   - **High**: All LEDs on at full brightness
3. **Repeat**: Press again to cycle back to OFF

## Development

This project is set up for development in Visual Studio Code with the Arduino extension. The included configuration files provide:

- Proper include paths for ESP8266 and FastLED
- IntelliSense support
- Board and port configuration

## Troubleshooting

- **LEDs not lighting**: Check data pin connection and power supply
- **Button not responding**: Verify button wiring and pin configuration
- **Upload fails**: Check COM port and board selection
- **Diagnostic chase fails**: Check LED strip wiring direction and solder joints

## License

See LICENSE file for details.
