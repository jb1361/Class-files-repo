/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId]) {
/******/ 			return installedModules[moduleId].exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			i: moduleId,
/******/ 			l: false,
/******/ 			exports: {}
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.l = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// define getter function for harmony exports
/******/ 	__webpack_require__.d = function(exports, name, getter) {
/******/ 		if(!__webpack_require__.o(exports, name)) {
/******/ 			Object.defineProperty(exports, name, {
/******/ 				configurable: false,
/******/ 				enumerable: true,
/******/ 				get: getter
/******/ 			});
/******/ 		}
/******/ 	};
/******/
/******/ 	// getDefaultExport function for compatibility with non-harmony modules
/******/ 	__webpack_require__.n = function(module) {
/******/ 		var getter = module && module.__esModule ?
/******/ 			function getDefault() { return module['default']; } :
/******/ 			function getModuleExports() { return module; };
/******/ 		__webpack_require__.d(getter, 'a', getter);
/******/ 		return getter;
/******/ 	};
/******/
/******/ 	// Object.prototype.hasOwnProperty.call
/******/ 	__webpack_require__.o = function(object, property) { return Object.prototype.hasOwnProperty.call(object, property); };
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(__webpack_require__.s = 1);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ (function(module, exports) {

module.exports = React;

/***/ }),
/* 1 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";

Object.defineProperty(exports, "__esModule", { value: true });
var App_1 = __webpack_require__(2);
/**
 * The main entry point of the js application.
 * Bootstrap and run the application.
 */
var app = new App_1.App();
// run the application
app.run();


/***/ }),
/* 2 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";

var __assign = (this && this.__assign) || Object.assign || function(t) {
    for (var s, i = 1, n = arguments.length; i < n; i++) {
        s = arguments[i];
        for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p))
            t[p] = s[p];
    }
    return t;
};
Object.defineProperty(exports, "__esModule", { value: true });
var EnfoldChildVisibility_1 = __webpack_require__(3);
var fullHeight_1 = __webpack_require__(4);
var fullWidth_1 = __webpack_require__(5);
var React = __webpack_require__(0);
var ReactDOM = __webpack_require__(6);
var HelloWorld_1 = __webpack_require__(7);
/**
 * The main js Application
 */
var App = (function () {
    function App() {
    }
    /**
     * Runs the application
     */
    App.prototype.run = function () {
        this.registerGlobals();
        console.log("application bootstrapped.");
        jQuery(document).ready(function ($) {
            // build each instance of the react component on the page
            $(".HelloWorldComponent").each(function (i, e) { return ReactDOM.render(React.createElement(HelloWorld_1.HelloWorld, __assign({}, e.dataset)), e); });
        });
    };
    /**
     * Register global methods and objects here
     */
    App.prototype.registerGlobals = function () {
        EnfoldChildVisibility_1.EnfoldChildVisibility.initialize();
        EnfoldChildVisibility_1.EnfoldChildVisibility.add('fullHeight', fullHeight_1.fullHeight);
        EnfoldChildVisibility_1.EnfoldChildVisibility.add('fullWidth', fullWidth_1.fullWidth);
    };
    return App;
}());
exports.App = App;


/***/ }),
/* 3 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";

Object.defineProperty(exports, "__esModule", { value: true });
/**
 * Inject methods and objects into the global space under
 * the EnfoldChild namespace to avoid conflicts
 */
var EnfoldChildVisibility = (function () {
    function EnfoldChildVisibility() {
    }
    /**
     * Initializes the namespace
     */
    EnfoldChildVisibility.initialize = function () {
        window[this.namespace] = {};
    };
    /**
     * Adds a function, class, or object to the global scope under
     * the default namespace
     * @param name The property name to inject under
     * @param object The object to inject
     */
    EnfoldChildVisibility.add = function (name, object) {
        window[this.namespace][name] = object;
    };
    /**
     * The namespace to inject methods and objects onto
     * @type {string}
     */
    EnfoldChildVisibility.namespace = "EnfoldChild";
    return EnfoldChildVisibility;
}());
exports.EnfoldChildVisibility = EnfoldChildVisibility;


/***/ }),
/* 4 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";

/**
 * @author Jason Gallavin
 * @updated 05/03/2016
 * @created 3/8/2016
 * @version 0.9
 */
Object.defineProperty(exports, "__esModule", { value: true });
/**
 * This is how you call the full height script. give it the selector for the footer and jquery to adjust the body size.
 * EnfoldChild.fullHeight("#socket", jQuery);
 * or
 * EnfoldChild.fullHeight("#socket");
 */
/**
 * Sets the footer to the bottom of the page if page height is less than the window
 * @param {string} footerSelector The footer of the page to move down
 * @param {jQuery} $ jQuery Object to use
 * @return {FullHeightHandle} The handle disable events with
 */
function fullHeight(footerSelector, $) {
    if ($ === void 0) { $ = jQuery; }
    if (footerSelector == null)
        throw new Error("selector not given");
    if ($ == null)
        throw new Error("jQuery not given and could not be found in the environment");
    var handle = new FullHeightHandle(footerSelector, $);
    handle.register();
    return handle;
}
exports.fullHeight = fullHeight;
/**
 * The handle to use for registering and de-registering the full height events
 */
var FullHeightHandle = (function () {
    /**
     * construct the handler
     * @param footerSelector The selector of the element that will stick to the bottom of the screen
     * @param $ The jQuery Object to use
     */
    function FullHeightHandle(footerSelector, $) {
        if ($ === void 0) { $ = jQuery; }
        this.footerSelector = footerSelector;
        this.$ = $;
    }
    /**
     * Register the event handlers
     */
    FullHeightHandle.prototype.register = function () {
        var _this = this;
        this.$(window).load(function () {
            _this.adjustFooterToScreen();
            _this.resizeHandle = function () { return _this.adjustFooterToScreen; };
            _this.$(window).on("resize", _this.resizeHandle);
        });
    };
    /**
     * Disable the event handlers
     */
    FullHeightHandle.prototype.unRegister = function () {
        this.$(window).off("resize", this.resizeHandle);
    };
    /**
     * Positions the element to the bottom of the screen
     */
    FullHeightHandle.prototype.adjustFooterToScreen = function () {
        var $body = this.$('body');
        $body.css("height", "");
        var windowHeight = this.$(window).height() - 6;
        var bodyHeight = $body.outerHeight();
        if (bodyHeight < windowHeight)
            $body.css("height", windowHeight);
        var wpAdminOffset = parseInt(this.$('html').css('margin-top').replace("px", ""));
        if (wpAdminOffset != undefined && wpAdminOffset > 0)
            windowHeight -= (wpAdminOffset - 1);
        if (bodyHeight < windowHeight)
            this.$(this.footerSelector).css("position", "fixed").css("width", "100%").css("bottom", "0");
        else
            this.$(this.footerSelector).css("position", "static");
    };
    return FullHeightHandle;
}());


/***/ }),
/* 5 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";

/**
 * @author Jason Gallavin
 * @created 8/25/2015.
 * @updated 04/25/2017
 * @version 1.3
 * Fix: instant set to false now doesn't check for the element until the page is loaded
 * Purpose: Expands a child container to full page width. Very helpful for Wordpress projects.
 */
Object.defineProperty(exports, "__esModule", { value: true });
/**
 * Force an element to fill the width of the window.
 * @param {String} containerSelector The selector of the element to make full screen
 * @param {boolean} instant If set to true, the script will load instantly and not on document load
 * @param {JQueryStatic} $ The jQuery Object to use
 * @return {FullWidthHandle} A handle to deactivate the full width events
 */
function fullWidth(containerSelector, instant, $) {
    if (instant === void 0) { instant = false; }
    if ($ === void 0) { $ = jQuery; }
    if (containerSelector == null)
        throw new Error("fullWidth.js - container is undefined");
    var fullWidthObject = new FullWidthHandle(containerSelector, instant, $);
    fullWidthObject.register();
    return fullWidthObject;
}
exports.fullWidth = fullWidth;
/**
 * The event handle that can be used to unregister the full width script
 */
var FullWidthHandle = (function () {
    function FullWidthHandle(containerSelector, instant, $) {
        if (instant === void 0) { instant = false; }
        if ($ === void 0) { $ = jQuery; }
        this.containerSelector = containerSelector;
        this.instant = instant;
        this.$ = $;
        this.$(containerSelector).css('opacity', '0');
    }
    /**
     * Register the events
     */
    FullWidthHandle.prototype.register = function () {
        var _this = this;
        if (this.instant)
            this.onLoad();
        else {
            this.loadHandler = function () { return _this.onLoad(); };
            this.$(window).on("load", this.loadHandler);
        }
        this.resizeHandler = function () { return _this.onResize(); };
        this.$(window).on("resize", this.resizeHandler);
    };
    /**
     * Disable the event handlers
     */
    FullWidthHandle.prototype.unRegister = function () {
        if (this.loadHandler)
            this.$(window).off("load", this.loadHandler);
        this.$(window).off("resize", this.resizeHandler);
    };
    /**
     * Resize the element to match the width of the screen
     */
    FullWidthHandle.prototype.onLoad = function () {
        console.log("load");
        if (this.$(this.containerSelector).length == 0) {
            console.log(this.containerSelector + " is not found");
            return;
        }
        this.sizeElementToWindow();
        this.$(this.containerSelector).fadeTo(500, 1);
    };
    /**
     * Resize the element when the window re-sizes
     */
    FullWidthHandle.prototype.onResize = function () {
        console.log("resizing");
        if (this.$(this.containerSelector).length == 0) {
            console.log(this.containerSelector + " is not found");
            return;
        }
        this.sizeElementToWindow();
    };
    /**
     * Resize the element to the window
     */
    FullWidthHandle.prototype.sizeElementToWindow = function () {
        var width = this.$(window).width();
        this.$(this.containerSelector).css('margin-left', "0");
        var left = this.$(this.containerSelector).offset().left;
        this.$(this.containerSelector).css('margin-left', "-" + left + "px").css('width', width + "px").css('max-width', 'none');
    };
    return FullWidthHandle;
}());
//Instantiate your object by selecting the element which you want to be full width. See below for an example.
//var myObject = new fullWidth(".kws_form", false); 


/***/ }),
/* 6 */
/***/ (function(module, exports) {

module.exports = ReactDOM;

/***/ }),
/* 7 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";

var __extends = (this && this.__extends) || (function () {
    var extendStatics = Object.setPrototypeOf ||
        ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
        function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
Object.defineProperty(exports, "__esModule", { value: true });
var React = __webpack_require__(0);
var HelloWorld = (function (_super) {
    __extends(HelloWorld, _super);
    function HelloWorld() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    HelloWorld.prototype.render = function () {
        return (React.createElement("h1", null,
            "Hello ",
            this.props.name,
            "!"));
    };
    return HelloWorld;
}(React.Component));
exports.HelloWorld = HelloWorld;


/***/ })
/******/ ]);
//# sourceMappingURL=app.bundle.js.map