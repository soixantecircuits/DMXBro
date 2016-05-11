# DMXBro

DMXBro allows you to listen to [spacebro](https://github.com/soixantecircuits/spacebro) events and send specific value to specific DMX channels.

**Currently works with Linux only, because [ofxSpacebroClient](https://github.com/soixantecircuits/ofxSpacebroClient) too.**

## Usage

DMXBro connects to [spacebro](https://github.com/soixantecircuits/spacebro) and listen for `DMX-data` event with `{channel: [int], level: [int]}` parameters. That's all.

## Tips

- You need to be in the `dialout` group (`sudo adduser $USER dialout`).
- You'll need to provide the serial port to communicate with your DMX controller in the `bin/data/config.json`.
- For now, as we use [ofxDmx](https://github.com/kylemcdonald/ofxDmx), we only support Enttec DmxPro controllers.
- [DmxUsbProArduino](https://github.com/emmanuelgeoffray/DmxUsbProArduino) could be useful about that last point.

## Example

An example script is available in the scripts folder. Once DMXBro is up and running, type:

```
$ cd scripts
$ npm i
$ node sendDmx.js
$ # or
$ node simple-send.js [channel] [level]
```
