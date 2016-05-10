'use strict'

const maxChannel = require('../bin/data/config.json').maxChannel

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

setTimeout(function () {
  for (let i = 1; i <= maxChannel; i++) {
    spacebroClient.emit('DMX-data', {channel: i, level: 255})
  }
  setTimeout(function () {
    process.exit()
  }, 100)
}, 1000)
