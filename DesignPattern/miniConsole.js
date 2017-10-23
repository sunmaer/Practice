// miniConsole.js

miniConsole = {
  log: function() {
    console.log([].join.call(arguments))
  }
}