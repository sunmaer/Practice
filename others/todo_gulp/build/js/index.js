"use strict";

var block = document.getElementById('block');
block.innerHTML = require('./todo')() + '-' + require('./add')() + '-' + require('./list')();