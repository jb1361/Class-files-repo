import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { AppComponent } from './app.component';
import {RouterModule} from '@angular/router';
import {ROUTES} from './app.routes';
import {MaterialModule} from './modules/material/material.module';
import {SyllabusModule} from "./modules/syllabus/syllabus.module";
import {Data} from "./data";

@NgModule({
  declarations: [
    AppComponent
  ],
  imports: [
    BrowserModule,
    RouterModule.forRoot(ROUTES),
    MaterialModule,
    SyllabusModule
  ],
  providers: [Data],
  bootstrap: [AppComponent]
})
export class AppModule { }
