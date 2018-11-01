import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { SyllabusInfoComponent } from './component/syllabus-info/syllabus-info.component';
import { CalendarComponent } from './component/calendar/calendar.component';
import { UniversityInfoComponent } from './component/university-info/university-info.component';
import {SyllabusComponent} from './component/syllabus/syllabus.component';
import {MaterialModule} from '../material/material.module';

@NgModule({
  imports: [
    CommonModule,
    MaterialModule
  ],
  declarations: [SyllabusComponent, SyllabusInfoComponent, CalendarComponent, UniversityInfoComponent]
})
export class SyllabusModule { }
