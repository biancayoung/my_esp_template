# My ESP Template

This repository contains a template for ESP32 projects using the Arduino framework. It is designed to provide a starting point for embedded projects with pre-configured settings and examples.

## Features

- Basic configuration for WiFi and RTC.
- Example codes for WiFi management and RTC synchronization.
- Modular design for easy customization.
- uses elegantOTA for over the air updates
- uses multiwifi alowing several credential to be stored
- PlatformIO ready


## Installation

To clone this repository and use it in your projects, follow these steps:

```bash
git clone https://github.com/lpgn/my_esp_template.git
cd my_esp_template
```

## Usage
After cloning the repository, you can open the project in your preferred IDE or editor that supports PlatformIO.

## Configuring Your WiFi

create a file named credentials.txt in the data directory
Edit the credentials.txt file to include your specific WiFi settings in the following format

```
YourNetworkName_1,YourNetworkPassword
YourNetworkName_2,YourNetworkPassword
YourNetworkName_3,YourNetworkPassword
YourNetworkName_4,YourNetworkPassword
YourNetworkName_5,YourNetworkPassword
YourNetworkName_6,YourNetworkPassword
```

## Real Time Clock (RTC)
Ensure that your hardware setup corresponds to the pin configurations specified in the TimeHandler.cpp file.

## Contributing
Contributions to this project are welcome! To contribute:

Acknowledgements
ESP32 Arduino Core
Contributors and community members
Thank you for checking out my ESP template!
