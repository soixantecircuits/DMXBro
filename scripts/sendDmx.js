'use strict'

const maxChannel = 64
const interval = 5 // in seconds

const spacebroClient = require('spacebro-client')

var actionList = [
  {
    name: 'DMX-data',
    trigger: function (data) {
      console.log(data)
    }
  }
]

spacebroClient.registerToMaster(actionList, 'sendDmx')

setInterval(function () {
  for (let i = 1; i <= maxChannel; i++) {
    spacebroClient.emit('DMX-data', {channel: i, level: 255})
    setTimeout(function () {
      spacebroClient.emit('DMX-data', {channel: i, level: 1})
    }, (interval * 1000) / 2)
  }
}, (interval * 1000))

