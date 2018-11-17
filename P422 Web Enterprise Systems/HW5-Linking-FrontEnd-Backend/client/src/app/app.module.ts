import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { HttpClientModule } from '@angular/common/http';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { FormsModule } from '@angular/forms';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { SyllabusComponent } from './syllabus/syllabus.component';
import { AssignmentComponent } from './assignment/assignment.component';
import { PageNotFoundComponent } from './page-not-found/page-not-found.component';
import { AssignmentDetailComponent } from './assignment-detail/assignment-detail.component';
import { CourseSelectionComponent } from './course-selection/course-selection.component';
import { SectionSelectorComponent } from './section-selector/section-selector.component';
import { HomepageComponent } from './homepage/homepage.component';

@NgModule({
  declarations: [
    AppComponent,
    SyllabusComponent,
    AssignmentComponent,
    PageNotFoundComponent,
    AssignmentDetailComponent,
    CourseSelectionComponent,
    SectionSelectorComponent,
    HomepageComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    NgbModule,
    FormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule {
  selectedCourse: string;
  setActive(course: string) {
    this.selectedCourse = course;
  }
}
