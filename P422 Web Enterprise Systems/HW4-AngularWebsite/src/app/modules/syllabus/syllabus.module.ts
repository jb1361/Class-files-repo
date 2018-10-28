import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { SyllabusComponent } from './syllabus/syllabus.component';
import { SyllabusInfoComponent } from './component/syllabus-info/syllabus-info.component';
import { CalendarComponent } from './component/calendar/calendar.component';
import { UniversityInfoComponent } from './component/university-info/university-info.component';

@NgModule({
  imports: [
    CommonModule
  ],
  declarations: [SyllabusComponent, SyllabusInfoComponent, CalendarComponent, UniversityInfoComponent]
})
export class SyllabusModule { }
