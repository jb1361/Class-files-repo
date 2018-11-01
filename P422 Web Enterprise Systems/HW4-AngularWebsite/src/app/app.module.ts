import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { AppComponent } from './app.component';
import {RouterModule} from '@angular/router';
import {ROUTES} from './app.routes';
import {MaterialModule} from './modules/material/material.module';
import {SyllabusModule} from './modules/syllabus/syllabus.module';
import {CourseData, Courses} from './data';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';

@NgModule({
  declarations: [
    AppComponent
  ],
  imports: [
    BrowserModule,
    BrowserAnimationsModule,
    RouterModule.forRoot(ROUTES),
    MaterialModule,
    SyllabusModule
  ],
  providers: [CourseData, Courses],
  bootstrap: [AppComponent]
})
export class AppModule { }
