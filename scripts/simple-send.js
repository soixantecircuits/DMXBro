'use strict'

const spacebroClient = require('spacebro-client')

const actionList = [
  {
    name: 'DMX-data',
    trigger: function (data) {
      console.log(data)
    }
  }
]

spacebroClient.registerToMaster(actionList, 'sendDmx')

setTimeout(function () {
  spacebroClient.emit('DMX-data', {channel: Number(process.argv[2]), level: Number(process.argv[3])})
  setTimeout(function () {
    process.exit()
  }, 500)
}, 1000)