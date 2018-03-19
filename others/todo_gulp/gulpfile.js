var gulp = require('gulp')
var shelljs = require('shelljs')
var browserify = require('browserify')
var fs = require('fs')
var sequence = require('run-sequence')
var watchify = require('watchify')
var babel = require('gulp-babel')

gulp.task('default', function() {
	// console.log('this is default task')
	// shelljs.exec('browserify js/index.js -o js/main.js')
	sequence('babel', 'babelWatch', 'mainjs')
})

gulp.task('mainjs', function() {
	var b = browserify({
		entries: ['build/js/index.js'],
		cache: {},
		packageCache: {},
		plugin: [watchify]
	})
	b.bundle().pipe(fs.createWriteStream('js/main.js'))
	b.on('update', function() {
		b.bundle().pipe(fs.createWriteStream('js/main.js'))
	})
})

gulp.task('watch', function() {
	gulp.watch(['assets/js/*.js'], function() {
		sequence('mainjs')
	})
})

gulp.task('babel', function() {
	gulp.src('./assets/js/*.js')
	.pipe(babel({presets: ['@babel/env']}))
	.pipe(gulp.dest('./build/js/'))
})

gulp.task('babelWatch', function() {
	gulp.watch(['assets/js/*.js'], function() {
		sequence('babel')
	})
})