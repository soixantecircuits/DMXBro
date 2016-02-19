const spacebroClient = require('spacebro-client')

var actionList = [
  {
    name: 'DMX-data',
    trigger: function (data) {
      console.log(data)
    }
  }
]

spacebroClient.iKnowMyMaster('127.0.0.1', '8888')
spacebroClient.registerToMaster(actionList, 'sendDmx')


setInterval(function () {
  spacebroClient.emit('DMX-data', {channel: 1, level:255})
  spacebroClient.emit('DMX-data', {channel: 2, level:60})
  spacebroClient.emit('DMX-data', {channel: 3, level:60})
  spacebroClient.emit('DMX-data', {channel: 4, level:255})
  spacebroClient.emit('DMX-data', {channel: 5, level:255})
  spacebroClient.emit('DMX-data', {channel: 6, level:255})
}, 5000)

setTimeout(function () {
  setInterval(function () {
    spacebroClient.emit('DMX-data', {channel: 1, level:0})
    spacebroClient.emit('DMX-data', {channel: 2, level:10})
    spacebroClient.emit('DMX-data', {channel: 3, level:10})
    spacebroClient.emit('DMX-data', {channel: 4, level:0})
    spacebroClient.emit('DMX-data', {channel: 5, level:0})
    spacebroClient.emit('DMX-data', {channel: 6, level:0})
  }, 5000)
}, 2500)


