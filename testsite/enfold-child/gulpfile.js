'use strict';
const gulp = require('gulp');
const sass = require('gulp-sass');
const autoPrefixer = require('gulp-autoprefixer');
const sourceMaps = require('gulp-sourcemaps');
const gulpWebpack = require('gulp-webpack');
const webpack = require('webpack');
const shell = require('gulp-shell');
const cleanCSS = require('gulp-clean-css');
/**
 * Get the command to run the php code sniffer
 * @return {string}
 */
function getPhpCsCommand() {
    let isWin = /^win/.test(process.platform);
    let phpcsCommand = '';
    if(isWin)
        phpcsCommand = 'vendor\\bin\\phpcs -s --standard=ruleset_standard.xml --extensions=php src\\';
    else
        phpcsCommand = './vendor/bin/phpcs -s --standard=ruleset_standard.xml --extensions=php src/';
    return phpcsCommand
}


/**
 * Compile Sass into style.css
 */
gulp.task('scss', function() {
    return gulp.src('assets/scss/style.scss')
        .pipe(sourceMaps.init())
        .pipe(sass().on('error', sass.logError))
        .pipe(autoPrefixer())
        .pipe(sourceMaps.write('./'))
        .pipe(gulp.dest('./'));
});

/**
 * Compile Sass into style.css
 */
gulp.task('scss-production', function() {
    return gulp.src('assets/scss/style.scss')
        .pipe(sourceMaps.init())
        .pipe(sass().on('error', sass.logError))
        .pipe(autoPrefixer())
        .pipe(cleanCSS({}))
        .pipe(sourceMaps.write('./'))
        .pipe(gulp.dest('./'));
});

gulp.task('watch-scss', ['scss'],  function() {
    gulp.watch('assets/scss/**/*.scss', ['scss']);
});

/**
 * Build typescript with webpack
 */
gulp.task('ts',function() {
    gulp.src('assets/ts/src/main.ts')
        .pipe(gulpWebpack(require('./webpack.config.js'), webpack))
        .pipe(gulp.dest('assets/ts/dist/'))
});

/**
 * Build typescript with webpack
 */
gulp.task('ts-production',function() {
    let webPackConfig = require('./webpack.config.js');
    webPackConfig.plugins.push( new webpack.optimize.UglifyJsPlugin({ sourceMap: true }));
    gulp.src('assets/ts/src/main.ts')
        .pipe(gulpWebpack(webPackConfig, webpack))
        .pipe(gulp.dest('assets/ts/dist/'))
});

/**
 * Watch the typescript compilation
 */
gulp.task('watch-ts',function() {
    let webPackConfig = require('./webpack.config.js');
    webPackConfig.watch = true;
    gulp.src('assets/ts/src/main.ts')
        .pipe(gulpWebpack(webPackConfig, webpack))
        .pipe(gulp.dest('assets/ts/dist/'))
});

/**
 * Watch sass and typescript compilation
 */
gulp.task('watch', ['watch-scss', 'watch-ts']);

/**
 * Build sass and typescript for production.
 */
gulp.task('build-production', ['ts-production', 'scss-production']);
/**
 * Build sass and typescript for local development
 */
gulp.task('build', ['ts', 'scss']);

/**
 * lint php code. This is platform independent
 */
gulp.task('php-lint', shell.task(getPhpCsCommand(), { ignoreErrors : true }));
