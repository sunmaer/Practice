(function(){function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s}return e})()({1:[function(require,module,exports){
"use strict";

var add = function add() {
  return 'add修改了哈哈哈';
};

module.exports = add;
},{}],2:[function(require,module,exports){
"use strict";

var block = document.getElementById('block');
block.innerHTML = require('./todo')() + '-' + require('./add')() + '-' + require('./list')();
},{"./add":1,"./list":3,"./todo":4}],3:[function(require,module,exports){
"use strict";

module.exports = function list() {
  return 'list';
};
},{}],4:[function(require,module,exports){
"use strict";

module.exports = function todo() {
  return 'todo修改';
};
},{}]},{},[2]);
