# DMXBro

DMXBro allows you to listen to [spacebro](https://github.com/soixantecircuits/spacebro) events and send specific value to specific DMX channels.

## Usage

DMXBro connects to spacebro and listen for `DMX-data` event with `{channel: [int], level: [int]}` parameters. That's all.

## Example

An example script is available in the scripts folder once DMXBro is up and running do the following to launch it:

cd scripts && node sendDmx.js
