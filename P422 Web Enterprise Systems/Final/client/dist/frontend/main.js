(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["main"],{

/***/ "./src/$$_lazy_route_resource lazy recursive":
/*!**********************************************************!*\
  !*** ./src/$$_lazy_route_resource lazy namespace object ***!
  \**********************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

function webpackEmptyAsyncContext(req) {
	// Here Promise.resolve().then() is used instead of new Promise() to prevent
	// uncaught exception popping up in devtools
	return Promise.resolve().then(function() {
		var e = new Error("Cannot find module '" + req + "'");
		e.code = 'MODULE_NOT_FOUND';
		throw e;
	});
}
webpackEmptyAsyncContext.keys = function() { return []; };
webpackEmptyAsyncContext.resolve = webpackEmptyAsyncContext;
module.exports = webpackEmptyAsyncContext;
webpackEmptyAsyncContext.id = "./src/$$_lazy_route_resource lazy recursive";

/***/ }),

/***/ "./src/app/app-routing.module.ts":
/*!***************************************!*\
  !*** ./src/app/app-routing.module.ts ***!
  \***************************************/
/*! exports provided: AppRoutingModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppRoutingModule", function() { return AppRoutingModule; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
/* harmony import */ var _syllabus_syllabus_component__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./syllabus/syllabus.component */ "./src/app/syllabus/syllabus.component.ts");
/* harmony import */ var _assignment_assignment_component__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./assignment/assignment.component */ "./src/app/assignment/assignment.component.ts");
/* harmony import */ var _assignment_detail_assignment_detail_component__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./assignment-detail/assignment-detail.component */ "./src/app/assignment-detail/assignment-detail.component.ts");
/* harmony import */ var _page_not_found_page_not_found_component__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./page-not-found/page-not-found.component */ "./src/app/page-not-found/page-not-found.component.ts");
/* harmony import */ var _homepage_homepage_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./homepage/homepage.component */ "./src/app/homepage/homepage.component.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};







var routes = [
    { path: 'courses/:section/syllabus', component: _syllabus_syllabus_component__WEBPACK_IMPORTED_MODULE_2__["SyllabusComponent"] },
    { path: 'courses/:section/assignments', component: _assignment_assignment_component__WEBPACK_IMPORTED_MODULE_3__["AssignmentComponent"] },
    { path: 'courses/:section/assignments/:name', component: _assignment_detail_assignment_detail_component__WEBPACK_IMPORTED_MODULE_4__["AssignmentDetailComponent"] },
    { path: '', component: _homepage_homepage_component__WEBPACK_IMPORTED_MODULE_6__["HomepageComponent"] },
    { path: 'courses/:section', redirectTo: 'courses/:section/syllabus' },
    { path: '**', component: _page_not_found_page_not_found_component__WEBPACK_IMPORTED_MODULE_5__["PageNotFoundComponent"] }
];
var AppRoutingModule = /** @class */ (function () {
    function AppRoutingModule() {
    }
    AppRoutingModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["NgModule"])({
            imports: [_angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"].forRoot(routes)],
            exports: [_angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"]]
        })
    ], AppRoutingModule);
    return AppRoutingModule;
}());



/***/ }),

/***/ "./src/app/app.component.css":
/*!***********************************!*\
  !*** ./src/app/app.component.css ***!
  \***********************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".active {\r\n\tfont-weight: bold;\r\n\tfont-color: red;\r\n}\r\n\r\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvYXBwLmNvbXBvbmVudC5jc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7Q0FDQyxrQkFBa0I7Q0FDbEIsZ0JBQWdCO0NBQ2hCIiwiZmlsZSI6InNyYy9hcHAvYXBwLmNvbXBvbmVudC5jc3MiLCJzb3VyY2VzQ29udGVudCI6WyIuYWN0aXZlIHtcclxuXHRmb250LXdlaWdodDogYm9sZDtcclxuXHRmb250LWNvbG9yOiByZWQ7XHJcbn1cclxuIl19 */"

/***/ }),

/***/ "./src/app/app.component.html":
/*!************************************!*\
  !*** ./src/app/app.component.html ***!
  \************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"container\">\r\n<h1>Campus</h1>\r\n<app-homepage></app-homepage>\r\n<router-outlet></router-outlet>\r\n</div>\r\n"

/***/ }),

/***/ "./src/app/app.component.ts":
/*!**********************************!*\
  !*** ./src/app/app.component.ts ***!
  \**********************************/
/*! exports provided: AppComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppComponent", function() { return AppComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};

var AppComponent = /** @class */ (function () {
    function AppComponent() {
    }
    AppComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-root',
            template: __webpack_require__(/*! ./app.component.html */ "./src/app/app.component.html"),
            styles: [__webpack_require__(/*! ./app.component.css */ "./src/app/app.component.css")]
        })
    ], AppComponent);
    return AppComponent;
}());



/***/ }),

/***/ "./src/app/app.module.ts":
/*!*******************************!*\
  !*** ./src/app/app.module.ts ***!
  \*******************************/
/*! exports provided: AppModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppModule", function() { return AppModule; });
/* harmony import */ var _angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/platform-browser */ "./node_modules/@angular/platform-browser/fesm5/platform-browser.js");
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/fesm5/http.js");
/* harmony import */ var _ng_bootstrap_ng_bootstrap__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @ng-bootstrap/ng-bootstrap */ "./node_modules/@ng-bootstrap/ng-bootstrap/fesm5/ng-bootstrap.js");
/* harmony import */ var _angular_forms__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! @angular/forms */ "./node_modules/@angular/forms/fesm5/forms.js");
/* harmony import */ var _app_routing_module__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./app-routing.module */ "./src/app/app-routing.module.ts");
/* harmony import */ var _app_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./app.component */ "./src/app/app.component.ts");
/* harmony import */ var _syllabus_syllabus_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./syllabus/syllabus.component */ "./src/app/syllabus/syllabus.component.ts");
/* harmony import */ var _assignment_assignment_component__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! ./assignment/assignment.component */ "./src/app/assignment/assignment.component.ts");
/* harmony import */ var _page_not_found_page_not_found_component__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(/*! ./page-not-found/page-not-found.component */ "./src/app/page-not-found/page-not-found.component.ts");
/* harmony import */ var _assignment_detail_assignment_detail_component__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__(/*! ./assignment-detail/assignment-detail.component */ "./src/app/assignment-detail/assignment-detail.component.ts");
/* harmony import */ var _course_selection_course_selection_component__WEBPACK_IMPORTED_MODULE_11__ = __webpack_require__(/*! ./course-selection/course-selection.component */ "./src/app/course-selection/course-selection.component.ts");
/* harmony import */ var _section_selector_section_selector_component__WEBPACK_IMPORTED_MODULE_12__ = __webpack_require__(/*! ./section-selector/section-selector.component */ "./src/app/section-selector/section-selector.component.ts");
/* harmony import */ var _homepage_homepage_component__WEBPACK_IMPORTED_MODULE_13__ = __webpack_require__(/*! ./homepage/homepage.component */ "./src/app/homepage/homepage.component.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};














var AppModule = /** @class */ (function () {
    function AppModule() {
    }
    AppModule.prototype.setActive = function (course) {
        this.selectedCourse = course;
    };
    AppModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_1__["NgModule"])({
            declarations: [
                _app_component__WEBPACK_IMPORTED_MODULE_6__["AppComponent"],
                _syllabus_syllabus_component__WEBPACK_IMPORTED_MODULE_7__["SyllabusComponent"],
                _assignment_assignment_component__WEBPACK_IMPORTED_MODULE_8__["AssignmentComponent"],
                _page_not_found_page_not_found_component__WEBPACK_IMPORTED_MODULE_9__["PageNotFoundComponent"],
                _assignment_detail_assignment_detail_component__WEBPACK_IMPORTED_MODULE_10__["AssignmentDetailComponent"],
                _course_selection_course_selection_component__WEBPACK_IMPORTED_MODULE_11__["CourseSelectionComponent"],
                _section_selector_section_selector_component__WEBPACK_IMPORTED_MODULE_12__["SectionSelectorComponent"],
                _homepage_homepage_component__WEBPACK_IMPORTED_MODULE_13__["HomepageComponent"]
            ],
            imports: [
                _angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__["BrowserModule"],
                _app_routing_module__WEBPACK_IMPORTED_MODULE_5__["AppRoutingModule"],
                _angular_common_http__WEBPACK_IMPORTED_MODULE_2__["HttpClientModule"],
                _ng_bootstrap_ng_bootstrap__WEBPACK_IMPORTED_MODULE_3__["NgbModule"],
                _angular_forms__WEBPACK_IMPORTED_MODULE_4__["FormsModule"],
                _angular_forms__WEBPACK_IMPORTED_MODULE_4__["ReactiveFormsModule"]
            ],
            providers: [],
            bootstrap: [_app_component__WEBPACK_IMPORTED_MODULE_6__["AppComponent"]]
        })
    ], AppModule);
    return AppModule;
}());



/***/ }),

/***/ "./src/app/assignment-detail/assignment-detail.component.css":
/*!*******************************************************************!*\
  !*** ./src/app/assignment-detail/assignment-detail.component.css ***!
  \*******************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".text-area {\r\n  height: 150px;\r\n  margin-bottom: 20px;\r\n}\r\n.alerts {\r\n  display: flex;\r\n  flex-direction: column;\r\n}\r\n\r\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvYXNzaWdubWVudC1kZXRhaWwvYXNzaWdubWVudC1kZXRhaWwuY29tcG9uZW50LmNzcyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiQUFBQTtFQUNFLGNBQWM7RUFDZCxvQkFBb0I7Q0FDckI7QUFDRDtFQUNFLGNBQWM7RUFDZCx1QkFBdUI7Q0FDeEIiLCJmaWxlIjoic3JjL2FwcC9hc3NpZ25tZW50LWRldGFpbC9hc3NpZ25tZW50LWRldGFpbC5jb21wb25lbnQuY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLnRleHQtYXJlYSB7XHJcbiAgaGVpZ2h0OiAxNTBweDtcclxuICBtYXJnaW4tYm90dG9tOiAyMHB4O1xyXG59XHJcbi5hbGVydHMge1xyXG4gIGRpc3BsYXk6IGZsZXg7XHJcbiAgZmxleC1kaXJlY3Rpb246IGNvbHVtbjtcclxufVxyXG4iXX0= */"

/***/ }),

/***/ "./src/app/assignment-detail/assignment-detail.component.html":
/*!********************************************************************!*\
  !*** ./src/app/assignment-detail/assignment-detail.component.html ***!
  \********************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<h3>\r\n  Assignment name: {{assignmentName|async}}\r\n</h3>\r\n<h3>\r\n  Section: {{sectionName|async}}\r\n</h3>\r\n<div class=\"alerts\">\r\n  <label class=\"alert-success\" *ngIf=\"postSuccess\">Assignment Submitted</label>\r\n  <label class=\"alert-danger\" *ngIf=\"error\">Error Submitting Assignment.</label>\r\n  <label class=\"alert-danger\" *ngIf=\"error\"> {{errorReason}}</label>\r\n</div>\r\n<form (ngSubmit)=\"onSubmit()\" [formGroup]=\"assForm\">\r\n  <div class=\"form-group\">\r\n    <label>Assignment Name</label>\r\n    <input type=\"text\" class=\"form-control\" formControlName=\"assName\" [ngModel]=\"(sectionName|async)\" readonly>\r\n  </div>\r\n  <div class=\"form-group\">\r\n    <label>Section</label>\r\n    <input type=\"text\" class=\"form-control\" formControlName=\"secName\"  [ngModel]=\"(assignmentName|async)\" readonly>\r\n  </div>\r\n  <div class=\"form-group\">\r\n    <label>Name</label>\r\n    <input type=\"text\" class=\"form-control\" formControlName=\"name\" [ngClass]=\"{ 'is-invalid': submitted && f.name.errors }\">\r\n      <div *ngIf=\"submitted && f.name.errors\" class=\"invalid-feedback\">\r\n        <div *ngIf=\"f.name.errors.required\">Name is required</div>\r\n      </div>\r\n  </div>\r\n  <div class=\"form-group\">\r\n    <label>Text Box</label>\r\n    <textarea type=\"text\" class=\"form-control text-area\" formControlName=\"textArea\" [ngClass]=\"{ 'is-invalid': submitted && f.textArea.errors }\"></textarea>\r\n      <div *ngIf=\"submitted && f.textArea.errors\" class=\"invalid-feedback\">\r\n        <div *ngIf=\"f.textArea.errors.required\">Text Area is required</div>\r\n      </div>\r\n  </div>\r\n  <button type=\"submit\" class=\"btn btn-success\">Submit</button>\r\n</form>\r\n"

/***/ }),

/***/ "./src/app/assignment-detail/assignment-detail.component.ts":
/*!******************************************************************!*\
  !*** ./src/app/assignment-detail/assignment-detail.component.ts ***!
  \******************************************************************/
/*! exports provided: AssignmentDetailComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AssignmentDetailComponent", function() { return AssignmentDetailComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var rxjs__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! rxjs */ "./node_modules/rxjs/_esm5/index.js");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
/* harmony import */ var rxjs_operators__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! rxjs/operators */ "./node_modules/rxjs/_esm5/operators/index.js");
/* harmony import */ var _services_assignment_data_assignment_data_service_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ../services/assignment-data/assignment-data-service.service */ "./src/app/services/assignment-data/assignment-data-service.service.ts");
/* harmony import */ var _angular_forms__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! @angular/forms */ "./node_modules/@angular/forms/fesm5/forms.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};






var AssignmentDetailComponent = /** @class */ (function () {
    function AssignmentDetailComponent(route, assDataService, formBuilder) {
        this.route = route;
        this.assDataService = assDataService;
        this.formBuilder = formBuilder;
        this.submitted = false;
        this.postSuccess = false;
        this.error = false;
        this.errorReason = '';
    }
    AssignmentDetailComponent.prototype.ngOnInit = function () {
        this.assignmentName = this.route.paramMap.pipe(Object(rxjs_operators__WEBPACK_IMPORTED_MODULE_3__["switchMap"])(function (params) { return Object(rxjs__WEBPACK_IMPORTED_MODULE_1__["of"])(params.get('name')); }));
        this.sectionName = this.route.paramMap.pipe(Object(rxjs_operators__WEBPACK_IMPORTED_MODULE_3__["switchMap"])(function (params) { return Object(rxjs__WEBPACK_IMPORTED_MODULE_1__["of"])(params.get('section')); }));
        this.assForm = this.formBuilder.group({
            assName: ['', _angular_forms__WEBPACK_IMPORTED_MODULE_5__["Validators"].required],
            secName: ['', _angular_forms__WEBPACK_IMPORTED_MODULE_5__["Validators"].required],
            name: ['', _angular_forms__WEBPACK_IMPORTED_MODULE_5__["Validators"].required],
            textArea: ['', _angular_forms__WEBPACK_IMPORTED_MODULE_5__["Validators"].required],
        });
    };
    Object.defineProperty(AssignmentDetailComponent.prototype, "f", {
        get: function () { return this.assForm.controls; },
        enumerable: true,
        configurable: true
    });
    AssignmentDetailComponent.prototype.onSubmit = function () {
        var _this = this;
        this.error = false;
        this.postSuccess = false;
        this.submitted = true;
        if (this.assForm.invalid) {
            return;
        }
        var data = {
            'assignment': {
                'name': this.f.assName.value,
                'section': this.f.secName.value,
                'submitter': this.f.name.value,
            },
            'text': this.f.textArea.value
        };
        this.assDataService.addSubmission(data).catch(function (err) {
            if (err) {
                _this.error = true;
                _this.errorReason = err.message;
            }
        }).then(function (res) {
            if (res) {
                _this.postSuccess = true;
            }
        });
    };
    AssignmentDetailComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-assignment-detail',
            template: __webpack_require__(/*! ./assignment-detail.component.html */ "./src/app/assignment-detail/assignment-detail.component.html"),
            styles: [__webpack_require__(/*! ./assignment-detail.component.css */ "./src/app/assignment-detail/assignment-detail.component.css")]
        }),
        __metadata("design:paramtypes", [_angular_router__WEBPACK_IMPORTED_MODULE_2__["ActivatedRoute"],
            _services_assignment_data_assignment_data_service_service__WEBPACK_IMPORTED_MODULE_4__["AssignmentDataServiceService"],
            _angular_forms__WEBPACK_IMPORTED_MODULE_5__["FormBuilder"]])
    ], AssignmentDetailComponent);
    return AssignmentDetailComponent;
}());



/***/ }),

/***/ "./src/app/assignment/assignment.component.css":
/*!*****************************************************!*\
  !*** ./src/app/assignment/assignment.component.css ***!
  \*****************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IiIsImZpbGUiOiJzcmMvYXBwL2Fzc2lnbm1lbnQvYXNzaWdubWVudC5jb21wb25lbnQuY3NzIn0= */"

/***/ }),

/***/ "./src/app/assignment/assignment.component.html":
/*!******************************************************!*\
  !*** ./src/app/assignment/assignment.component.html ***!
  \******************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "\r\n<div *ngFor=\"let assignment of assignments\">\r\n  <a [routerLink]=\"'/courses/'+ assignment.section + '/assignments/' + assignment.name\">{{assignment.name}}</a>\r\n</div>\r\n\r\n"

/***/ }),

/***/ "./src/app/assignment/assignment.component.ts":
/*!****************************************************!*\
  !*** ./src/app/assignment/assignment.component.ts ***!
  \****************************************************/
/*! exports provided: AssignmentComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AssignmentComponent", function() { return AssignmentComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
/* harmony import */ var rxjs__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! rxjs */ "./node_modules/rxjs/_esm5/index.js");
/* harmony import */ var rxjs_operators__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! rxjs/operators */ "./node_modules/rxjs/_esm5/operators/index.js");
/* harmony import */ var _services_assignment_data_assignment_data_service_service__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ../services/assignment-data/assignment-data-service.service */ "./src/app/services/assignment-data/assignment-data-service.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};





var AssignmentComponent = /** @class */ (function () {
    function AssignmentComponent(route, assignmentDataService) {
        this.route = route;
        this.assignmentDataService = assignmentDataService;
    }
    AssignmentComponent.prototype.ngOnInit = function () {
        // This code gets the :section parameter out of the route
        this.section = this.route.paramMap.pipe(Object(rxjs_operators__WEBPACK_IMPORTED_MODULE_3__["switchMap"])(function (params) { return Object(rxjs__WEBPACK_IMPORTED_MODULE_2__["of"])(params.get('section')); }));
        this.getAssignments();
    };
    AssignmentComponent.prototype.getAssignments = function () {
        var _this = this;
        this.assignmentDataService.getAssignments().then(function (res) {
            _this.assignments = res;
        });
    };
    AssignmentComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-assignment',
            template: __webpack_require__(/*! ./assignment.component.html */ "./src/app/assignment/assignment.component.html"),
            styles: [__webpack_require__(/*! ./assignment.component.css */ "./src/app/assignment/assignment.component.css")]
        }),
        __metadata("design:paramtypes", [_angular_router__WEBPACK_IMPORTED_MODULE_1__["ActivatedRoute"],
            _services_assignment_data_assignment_data_service_service__WEBPACK_IMPORTED_MODULE_4__["AssignmentDataServiceService"]])
    ], AssignmentComponent);
    return AssignmentComponent;
}());



/***/ }),

/***/ "./src/app/course-selection/course-selection.component.css":
/*!*****************************************************************!*\
  !*** ./src/app/course-selection/course-selection.component.css ***!
  \*****************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".active {\r\n\tfont-weight: bold;\r\n}\r\n\r\n\r\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvY291cnNlLXNlbGVjdGlvbi9jb3Vyc2Utc2VsZWN0aW9uLmNvbXBvbmVudC5jc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7Q0FDQyxrQkFBa0I7Q0FDbEIiLCJmaWxlIjoic3JjL2FwcC9jb3Vyc2Utc2VsZWN0aW9uL2NvdXJzZS1zZWxlY3Rpb24uY29tcG9uZW50LmNzcyIsInNvdXJjZXNDb250ZW50IjpbIi5hY3RpdmUge1xyXG5cdGZvbnQtd2VpZ2h0OiBib2xkO1xyXG59XHJcblxyXG4iXX0= */"

/***/ }),

/***/ "./src/app/course-selection/course-selection.component.html":
/*!******************************************************************!*\
  !*** ./src/app/course-selection/course-selection.component.html ***!
  \******************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<ul class=\"nav\">\r\n  <li class=\"nav-item\" *ngFor=\"let course of (courses|async)\">\r\n    <a class=\"nav-link\" [routerLink]=\"'/courses/'+course.section\" routerLinkActive=\"active\">{{course.section}}: {{course.title}}</a>\r\n  </li>\r\n</ul>\r\n\r\n<div *ngIf=\"courseSection|async\">\r\n\t<app-section-selector [section]=\"courseSection|async\"></app-section-selector>\r\n</div>\r\n"

/***/ }),

/***/ "./src/app/course-selection/course-selection.component.ts":
/*!****************************************************************!*\
  !*** ./src/app/course-selection/course-selection.component.ts ***!
  \****************************************************************/
/*! exports provided: CourseSelectionComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "CourseSelectionComponent", function() { return CourseSelectionComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _models_syllabus_data_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../models/syllabus-data.service */ "./src/app/models/syllabus-data.service.ts");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
/* harmony import */ var rxjs__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! rxjs */ "./node_modules/rxjs/_esm5/index.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};




var CourseSelectionComponent = /** @class */ (function () {
    function CourseSelectionComponent(router, syllabusDataService) {
        this.router = router;
        this.syllabusDataService = syllabusDataService;
    }
    CourseSelectionComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.courses = this.syllabusDataService.getCourses();
        this.router.events.subscribe(function (routerEvent) {
            if (routerEvent instanceof _angular_router__WEBPACK_IMPORTED_MODULE_2__["RoutesRecognized"]) {
                // This is ugly, but I was able to reach deep into the router to find our section.
                // The reason I'm doing this is that we are currently OUTSIDE of the router-outlet
                // component so the ActiveRoute is not hooked up in this component
                // I don't expect this to work outside of the current version of Angular
                // BUG: Also note that this breaks down on PageNotFoundComponent since it doesn't have a parameter
                var section = routerEvent.state.root['_routerState']['_root'].children[0].value.params.section;
                _this.courseSection = Object(rxjs__WEBPACK_IMPORTED_MODULE_3__["of"])(section);
            }
        });
    };
    CourseSelectionComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-course-selection',
            template: __webpack_require__(/*! ./course-selection.component.html */ "./src/app/course-selection/course-selection.component.html"),
            styles: [__webpack_require__(/*! ./course-selection.component.css */ "./src/app/course-selection/course-selection.component.css")]
        }),
        __metadata("design:paramtypes", [_angular_router__WEBPACK_IMPORTED_MODULE_2__["Router"],
            _models_syllabus_data_service__WEBPACK_IMPORTED_MODULE_1__["SyllabusDataService"]])
    ], CourseSelectionComponent);
    return CourseSelectionComponent;
}());



/***/ }),

/***/ "./src/app/homepage/homepage.component.css":
/*!*************************************************!*\
  !*** ./src/app/homepage/homepage.component.css ***!
  \*************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IiIsImZpbGUiOiJzcmMvYXBwL2hvbWVwYWdlL2hvbWVwYWdlLmNvbXBvbmVudC5jc3MifQ== */"

/***/ }),

/***/ "./src/app/homepage/homepage.component.html":
/*!**************************************************!*\
  !*** ./src/app/homepage/homepage.component.html ***!
  \**************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<p>Welcome to Campus courseware!</p>\r\n<app-assignment></app-assignment>\r\n"

/***/ }),

/***/ "./src/app/homepage/homepage.component.ts":
/*!************************************************!*\
  !*** ./src/app/homepage/homepage.component.ts ***!
  \************************************************/
/*! exports provided: HomepageComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "HomepageComponent", function() { return HomepageComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var HomepageComponent = /** @class */ (function () {
    function HomepageComponent() {
    }
    HomepageComponent.prototype.ngOnInit = function () {
    };
    HomepageComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-homepage',
            template: __webpack_require__(/*! ./homepage.component.html */ "./src/app/homepage/homepage.component.html"),
            styles: [__webpack_require__(/*! ./homepage.component.css */ "./src/app/homepage/homepage.component.css")]
        }),
        __metadata("design:paramtypes", [])
    ], HomepageComponent);
    return HomepageComponent;
}());



/***/ }),

/***/ "./src/app/models/syllabus-data.service.ts":
/*!*************************************************!*\
  !*** ./src/app/models/syllabus-data.service.ts ***!
  \*************************************************/
/*! exports provided: SyllabusDataService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "SyllabusDataService", function() { return SyllabusDataService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/fesm5/http.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var SyllabusDataService = /** @class */ (function () {
    function SyllabusDataService(http) {
        this.http = http;
        this.url = '/v1/courses';
    }
    SyllabusDataService.prototype.getCourses = function () {
        return this.http.get(this.url);
    };
    SyllabusDataService.prototype.getCourse = function (section) {
        return this.http.get(this.url + "/" + section);
    };
    SyllabusDataService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [_angular_common_http__WEBPACK_IMPORTED_MODULE_1__["HttpClient"]])
    ], SyllabusDataService);
    return SyllabusDataService;
}());



/***/ }),

/***/ "./src/app/page-not-found/page-not-found.component.css":
/*!*************************************************************!*\
  !*** ./src/app/page-not-found/page-not-found.component.css ***!
  \*************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IiIsImZpbGUiOiJzcmMvYXBwL3BhZ2Utbm90LWZvdW5kL3BhZ2Utbm90LWZvdW5kLmNvbXBvbmVudC5jc3MifQ== */"

/***/ }),

/***/ "./src/app/page-not-found/page-not-found.component.html":
/*!**************************************************************!*\
  !*** ./src/app/page-not-found/page-not-found.component.html ***!
  \**************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<h2>Page not found</h2>\r\n"

/***/ }),

/***/ "./src/app/page-not-found/page-not-found.component.ts":
/*!************************************************************!*\
  !*** ./src/app/page-not-found/page-not-found.component.ts ***!
  \************************************************************/
/*! exports provided: PageNotFoundComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "PageNotFoundComponent", function() { return PageNotFoundComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var PageNotFoundComponent = /** @class */ (function () {
    function PageNotFoundComponent() {
    }
    PageNotFoundComponent.prototype.ngOnInit = function () {
    };
    PageNotFoundComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-page-not-found',
            template: __webpack_require__(/*! ./page-not-found.component.html */ "./src/app/page-not-found/page-not-found.component.html"),
            styles: [__webpack_require__(/*! ./page-not-found.component.css */ "./src/app/page-not-found/page-not-found.component.css")]
        }),
        __metadata("design:paramtypes", [])
    ], PageNotFoundComponent);
    return PageNotFoundComponent;
}());



/***/ }),

/***/ "./src/app/section-selector/section-selector.component.css":
/*!*****************************************************************!*\
  !*** ./src/app/section-selector/section-selector.component.css ***!
  \*****************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".active {\r\n\tfont-weight: bold;\r\n}\r\n\r\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvc2VjdGlvbi1zZWxlY3Rvci9zZWN0aW9uLXNlbGVjdG9yLmNvbXBvbmVudC5jc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7Q0FDQyxrQkFBa0I7Q0FDbEIiLCJmaWxlIjoic3JjL2FwcC9zZWN0aW9uLXNlbGVjdG9yL3NlY3Rpb24tc2VsZWN0b3IuY29tcG9uZW50LmNzcyIsInNvdXJjZXNDb250ZW50IjpbIi5hY3RpdmUge1xyXG5cdGZvbnQtd2VpZ2h0OiBib2xkO1xyXG59XHJcbiJdfQ== */"

/***/ }),

/***/ "./src/app/section-selector/section-selector.component.html":
/*!******************************************************************!*\
  !*** ./src/app/section-selector/section-selector.component.html ***!
  \******************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<ul class=\"nav\">\r\n  <li class=\"nav-item\" *ngFor=\"let section of sections\">\r\n    <a class=\"nav-link\" [routerLink]=\"section.url\" routerLinkActive=\"active\">{{section.title}}</a>\r\n  </li>\r\n</ul>\r\n\r\n"

/***/ }),

/***/ "./src/app/section-selector/section-selector.component.ts":
/*!****************************************************************!*\
  !*** ./src/app/section-selector/section-selector.component.ts ***!
  \****************************************************************/
/*! exports provided: SectionSelectorComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "SectionSelectorComponent", function() { return SectionSelectorComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var SectionSelectorComponent = /** @class */ (function () {
    function SectionSelectorComponent() {
    }
    SectionSelectorComponent.prototype.ngOnInit = function () {
        // console.log(`ngInit: ${this.section}`);
    };
    SectionSelectorComponent.prototype.ngOnChanges = function () {
        // console.log(`ngOnChanges: ${this.section}`);
        this.sections = [
            { title: 'Syllabus', url: "/courses/" + this.section + "/syllabus" },
            { title: 'Assignments', url: "/courses/" + this.section + "/assignments" },
            { title: 'Quizzes', url: "/courses/" + this.section + "/quizzes" }
        ];
    };
    __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Input"])(),
        __metadata("design:type", String)
    ], SectionSelectorComponent.prototype, "section", void 0);
    SectionSelectorComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-section-selector',
            template: __webpack_require__(/*! ./section-selector.component.html */ "./src/app/section-selector/section-selector.component.html"),
            styles: [__webpack_require__(/*! ./section-selector.component.css */ "./src/app/section-selector/section-selector.component.css")]
        }),
        __metadata("design:paramtypes", [])
    ], SectionSelectorComponent);
    return SectionSelectorComponent;
}());



/***/ }),

/***/ "./src/app/services/assignment-data/assignment-data-service.service.ts":
/*!*****************************************************************************!*\
  !*** ./src/app/services/assignment-data/assignment-data-service.service.ts ***!
  \*****************************************************************************/
/*! exports provided: AssignmentDataServiceService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AssignmentDataServiceService", function() { return AssignmentDataServiceService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/fesm5/http.js");
/* harmony import */ var _utility_utility_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../utility/utility.service */ "./src/app/services/utility/utility.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var AssignmentDataServiceService = /** @class */ (function () {
    function AssignmentDataServiceService(http, utility) {
        this.http = http;
        this.utility = utility;
    }
    AssignmentDataServiceService.prototype.getAssignments = function () {
        return this.http.get(this.utility.getRootURL() + '/v1/assignments').toPromise();
    };
    AssignmentDataServiceService.prototype.addAssignment = function (assignment) {
        return this.http.post(this.utility.getRootURL() + '/v1/assignments', assignment).toPromise();
    };
    AssignmentDataServiceService.prototype.getAssignment = function (name) {
        return this.http.get(this.utility.getRootURL() + '/v1/assignments/' + name).toPromise();
    };
    AssignmentDataServiceService.prototype.updateAssignment = function (name, assignment) {
        return this.http.put(this.utility.getRootURL() + '/v1/assignments/' + name + '?section=' + assignment.section, assignment).toPromise();
    };
    AssignmentDataServiceService.prototype.getAssignmentGrade = function (name) {
        return this.http.get(this.utility.getRootURL() + '/v1/assignments/' + name + '/grades').toPromise();
    };
    AssignmentDataServiceService.prototype.addAssignmentGrade = function (name, grade) {
        return this.http.post(this.utility.getRootURL() + '/v1/assignments/' + name + '/grades', grade).toPromise();
    };
    AssignmentDataServiceService.prototype.addSubmission = function (submission) {
        return this.http.post(this.utility.getRootURL() + '/v1/submissions', submission).toPromise();
    };
    AssignmentDataServiceService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [_angular_common_http__WEBPACK_IMPORTED_MODULE_1__["HttpClient"], _utility_utility_service__WEBPACK_IMPORTED_MODULE_2__["UtilityService"]])
    ], AssignmentDataServiceService);
    return AssignmentDataServiceService;
}());



/***/ }),

/***/ "./src/app/services/utility/utility.service.ts":
/*!*****************************************************!*\
  !*** ./src/app/services/utility/utility.service.ts ***!
  \*****************************************************/
/*! exports provided: UtilityService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "UtilityService", function() { return UtilityService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _environments_environment__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../../../environments/environment */ "./src/environments/environment.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var UtilityService = /** @class */ (function () {
    function UtilityService() {
    }
    UtilityService.prototype.getRootURL = function () {
        return _environments_environment__WEBPACK_IMPORTED_MODULE_1__["environment"].host + ':' + _environments_environment__WEBPACK_IMPORTED_MODULE_1__["environment"].port;
    };
    UtilityService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])({
            providedIn: 'root'
        }),
        __metadata("design:paramtypes", [])
    ], UtilityService);
    return UtilityService;
}());



/***/ }),

/***/ "./src/app/syllabus/syllabus.component.css":
/*!*************************************************!*\
  !*** ./src/app/syllabus/syllabus.component.css ***!
  \*************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".inline-title {\r\n\tfont-weight: bold;\r\n\tpadding-top: 2em;\r\n}\r\n.title {\r\n\tpadding-top: 2em;\r\n\tfont-weight: bold;\r\n\tfont-size: 130%;\r\n}\r\n\r\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInNyYy9hcHAvc3lsbGFidXMvc3lsbGFidXMuY29tcG9uZW50LmNzcyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiQUFBQTtDQUNDLGtCQUFrQjtDQUNsQixpQkFBaUI7Q0FDakI7QUFDRDtDQUNDLGlCQUFpQjtDQUNqQixrQkFBa0I7Q0FDbEIsZ0JBQWdCO0NBQ2hCIiwiZmlsZSI6InNyYy9hcHAvc3lsbGFidXMvc3lsbGFidXMuY29tcG9uZW50LmNzcyIsInNvdXJjZXNDb250ZW50IjpbIi5pbmxpbmUtdGl0bGUge1xyXG5cdGZvbnQtd2VpZ2h0OiBib2xkO1xyXG5cdHBhZGRpbmctdG9wOiAyZW07XHJcbn1cclxuLnRpdGxlIHtcclxuXHRwYWRkaW5nLXRvcDogMmVtO1xyXG5cdGZvbnQtd2VpZ2h0OiBib2xkO1xyXG5cdGZvbnQtc2l6ZTogMTMwJTtcclxufVxyXG4iXX0= */"

/***/ }),

/***/ "./src/app/syllabus/syllabus.component.html":
/*!**************************************************!*\
  !*** ./src/app/syllabus/syllabus.component.html ***!
  \**************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div *ngIf=\"selectedCourse\">\r\n\r\n<h1>{{(selectedCourse | async)?.section}}: {{(selectedCourse | async)?.title}}</h1>\r\n\r\n<div><span class=\"inline-title\">Description:</span>  {{(selectedCourse|async)?.description}}</div>\r\n<div><span class=\"inline-title\">Book Info:</span>    {{(selectedCourse|async)?.bookInfo}}</div>\r\n<div><span class=\"inline-title\">Meeting Time:</span> {{(selectedCourse|async)?.meetingTime}}</div>\r\n\r\n<div class=\"title\">Calendar</div>\r\n<table>\r\n\t<tr *ngFor=\"let day of (selectedCourse|async)?.calendar\">\r\n\t\t<td>{{day}}</td>\r\n\t</tr>\r\n</table>\r\n\r\n<div class=\"title\">Grading Scale</div>\r\n<table>\r\n\t<tr *ngFor=\"let grade of (selectedCourse|async)?.gradingScale\">\r\n\t\t<td>{{grade}}</td>\r\n\t</tr>\r\n</table>\r\n\r\n<div class=\"title\">University Information</div>\r\n<p>{{(selectedCourse|async)?.universityInfo}}</p>\r\n\r\n</div>\r\n<div *ngIf=\"!selectedCourse\">\r\nNo course selected.\r\n</div>\r\n"

/***/ }),

/***/ "./src/app/syllabus/syllabus.component.ts":
/*!************************************************!*\
  !*** ./src/app/syllabus/syllabus.component.ts ***!
  \************************************************/
/*! exports provided: SyllabusComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "SyllabusComponent", function() { return SyllabusComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _models_syllabus_data_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../models/syllabus-data.service */ "./src/app/models/syllabus-data.service.ts");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
/* harmony import */ var rxjs_operators__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! rxjs/operators */ "./node_modules/rxjs/_esm5/operators/index.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};




var SyllabusComponent = /** @class */ (function () {
    function SyllabusComponent(route, syllabusDataService) {
        this.route = route;
        this.syllabusDataService = syllabusDataService;
    }
    SyllabusComponent.prototype.ngOnInit = function () {
        var _this = this;
        // This code gets the :section parameter out of the route
        this.selectedCourse = this.route.paramMap.pipe(Object(rxjs_operators__WEBPACK_IMPORTED_MODULE_3__["switchMap"])(function (params) { return _this.syllabusDataService.getCourse(params.get('section')); }));
    };
    SyllabusComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-syllabus',
            template: __webpack_require__(/*! ./syllabus.component.html */ "./src/app/syllabus/syllabus.component.html"),
            styles: [__webpack_require__(/*! ./syllabus.component.css */ "./src/app/syllabus/syllabus.component.css")]
        }),
        __metadata("design:paramtypes", [_angular_router__WEBPACK_IMPORTED_MODULE_2__["ActivatedRoute"],
            _models_syllabus_data_service__WEBPACK_IMPORTED_MODULE_1__["SyllabusDataService"]])
    ], SyllabusComponent);
    return SyllabusComponent;
}());



/***/ }),

/***/ "./src/environments/environment.ts":
/*!*****************************************!*\
  !*** ./src/environments/environment.ts ***!
  \*****************************************/
/*! exports provided: environment */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "environment", function() { return environment; });
// This file can be replaced during build by using the `fileReplacements` array.
// `ng build --prod` replaces `environment.ts` with `environment.prod.ts`.
// The list of file replacements can be found in `angular.json`.
var environment = {
    production: false,
    host: 'http://localhost',
    port: '8080'
};
/*
 * For easier debugging in development mode, you can import the following file
 * to ignore zone related error stack frames such as `zone.run`, `zoneDelegate.invokeTask`.
 *
 * This import should be commented out in production mode because it will have a negative impact
 * on performance if an error is thrown.
 */
// import 'zone.js/dist/zone-error';  // Included with Angular CLI.


/***/ }),

/***/ "./src/main.ts":
/*!*********************!*\
  !*** ./src/main.ts ***!
  \*********************/
/*! no exports provided */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_platform_browser_dynamic__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/platform-browser-dynamic */ "./node_modules/@angular/platform-browser-dynamic/fesm5/platform-browser-dynamic.js");
/* harmony import */ var _app_app_module__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./app/app.module */ "./src/app/app.module.ts");
/* harmony import */ var _environments_environment__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./environments/environment */ "./src/environments/environment.ts");




if (_environments_environment__WEBPACK_IMPORTED_MODULE_3__["environment"].production) {
    Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["enableProdMode"])();
}
Object(_angular_platform_browser_dynamic__WEBPACK_IMPORTED_MODULE_1__["platformBrowserDynamic"])().bootstrapModule(_app_app_module__WEBPACK_IMPORTED_MODULE_2__["AppModule"])
    .catch(function (err) { return console.error(err); });


/***/ }),

/***/ 0:
/*!***************************!*\
  !*** multi ./src/main.ts ***!
  \***************************/
/*! no static exports found */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(/*! E:\Class-files-repo\P422 Web Enterprise Systems\Final\client\src\main.ts */"./src/main.ts");


/***/ })

},[[0,"runtime","vendor"]]]);
//# sourceMappingURL=main.js.map